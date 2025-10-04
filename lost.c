#include<string.h>
#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<signal.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#define HEIGHT getmaxy(stdscr)
#define WIDTH getmaxx(stdscr)

#define MAX_ROOMS 5

void wpaint(WINDOW *, const chtype);
int moveNotOk(int, int);
int overlap(WINDOW*, WINDOW*);
void game(void);
void quit(void);
void handle_sigint(int);
void tick(int);


Mix_Music *gm = NULL, *mn=NULL;
WINDOW *win = NULL;

int px, py;
int runCase = 1;

char msg[] = "You made it, you opened the secret door!";
char ops[] = "F6 to Exit | F5 to restart";

typedef struct {
	int x;
	int y;
} vector;

typedef struct {
	int h;
	int w;
	int y;
	int x;
} room;

room **rooms = NULL;

void createRooms();
room *newRoom(int, int, int, int);
void drawRoom(room *);
void drawRooms();

void createRooms(){
	rooms = (room **)malloc(sizeof(room *) * MAX_ROOMS);
	for (int i = 0; i < MAX_ROOMS; i++) rooms[i] = NULL;
	
	rooms[0] = newRoom(25, 25, (HEIGHT-25)/2, (WIDTH-25)/2);

	if(!rooms[0]) {
		quit(); 
		fprintf(stderr, "Could not make window\n %d %d", HEIGHT, WIDTH);
		exit(EXIT_SUCCESS);
	}
}

room* newRoom(int h, int w, int y, int x){
	room *r = malloc(sizeof(room));
	r->h = h;
	r->w = w;
	r->y = y;
	r->x = x;
	return r;
}

void drawRoom(room *r){
	if (!r) return;

    int top = r->y;
    int bottom = r->y + r->h - 1;
    int left = r->x;
    int right = r->x + r->w - 1;

    
    mvaddch(top, left, '+');
    mvaddch(top, right, '+');
    mvaddch(bottom, left, '+');
    mvaddch(bottom, right, '+');

	for(int x = left+1; x < right; x++){
		mvaddch(top, x, '-');
		mvaddch(bottom, x, '-');
	}

	for(int y = top+1; y<bottom; y++){
		mvaddch(y, left, '|');
		mvaddch(y, right, '|');	
	}
}

void drawRooms(){
	for (int i = 0; i < MAX_ROOMS; i++) {
		if(rooms[i]) drawRoom(rooms[i]);
	}
}

void setup(){
	
	initscr();
	noecho();
	cbreak();

	curs_set(0);

	win=newwin(HEIGHT/2,WIDTH/2,HEIGHT/2-getmaxy(stdscr)/4,WIDTH/2-WIDTH/4);
	createRooms();

	// In case of sigerr, then do a clean termination.
	signal(SIGINT, handle_sigint);

	start_color();
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_BLUE, COLOR_WHITE);
	init_pair(3, COLOR_BLACK, COLOR_RED);

	init_pair(4,COLOR_RED,COLOR_BLACK);
	init_pair(5,COLOR_CYAN,COLOR_BLUE);
	init_pair(6,COLOR_CYAN,COLOR_WHITE);
	init_pair(7,COLOR_MAGENTA,COLOR_RED);

	if(SDL_Init(SDL_INIT_AUDIO) < 0){
		printf("SDL could not initialize : %s\n", SDL_GetError());
		quit();
	}

	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
		printf("SDL_mixer could not initialize : %s\n", Mix_GetError());
		SDL_Quit();
		quit();
	}

	gm = Mix_LoadMUS("/home/mingo/bin/bgm.wav");
	if(gm == NULL){
		printf("Cannot Load bgm.wav: %s\n", Mix_GetError());
		SDL_Quit();
		quit();
	}

	if(!Mix_PlayingMusic()){
		Mix_PlayMusic(gm, -1);
	}
}

void quit(void){
	if (gm != NULL) {
		Mix_FreeMusic(gm);
		gm = NULL;
	}
	Mix_CloseAudio();
	SDL_Quit();
	
	// Restore terminal to normal state
	echo();
	nocbreak();
	curs_set(1);  // Make cursor visible
	refresh();    // Ensure changes take effect
	endwin();
}

int main(void){
	setup();
	while(runCase)
		game();
	quit();
	return 0;
}

void game(void)
{
	unsigned int d,b;
	int a=rand()%8;

	srand(time(NULL));

	b=rand()%HEIGHT-10;
	d=rand()%WIDTH-10;
	px=WIDTH/2;
	py=HEIGHT/2;

	attron(COLOR_PAIR(a));
	mvaddch(b,d,96|A_ALTCHARSET);
	attroff(COLOR_PAIR(a));

	refresh();
	delay_output(800);
	keypad(stdscr, true);

	attron(COLOR_PAIR(a));
	while(1)
	{
		int c = getch();
		if(py == b && px == d)
			break;
		switch(c)
		{
			case KEY_UP:    if(!moveNotOk(py-1,px)) py--; break;
			case KEY_DOWN:  if(!moveNotOk(py+1,px)) py++; break;
			case KEY_LEFT:  if(!moveNotOk(py,px-1)) px--; break;
			case KEY_RIGHT: if(!moveNotOk(py,px+1)) px++; break;
			case 'r': return;
		}
		wpaint(stdscr, 32);
		refresh();

		drawRooms();
		mvaddch(b,d,96 | (A_ALTCHARSET));	
		mvaddch(py,px, 97 | (A_ALTCHARSET));

	}
	wpaint(stdscr, 32);
	attroff(COLOR_PAIR(a));
	refresh();

	wattron(win,A_REVERSE | COLOR_PAIR(a));
	wpaint(win, 97 | (A_ALTCHARSET));
	box(win,0,0);


	mvwprintw(win,getmaxy(win)/2,(getmaxx(win)-strlen(msg))/2, msg);
	mvwprintw(win,getmaxy(win)/2+3,(getmaxx(win)-strlen(ops))/2, ops);
	wattroff(win,A_REVERSE);
	wrefresh(win);


	while(1){
		int c=getch();
		if(c==KEY_F(5))
			return;
		else if(c==KEY_F(6)){
			runCase = 0;
			return;
		}
	}
}

void wpaint(WINDOW *win, const chtype c)
{
    for (int i = 0; i < getmaxy(win); i++)
    {
        mvwhline(win, i, 0, c, getmaxx(win));
    }
}

int moveNotOk(int y, int x)
{
	int check = mvinch(y,x) & A_CHARTEXT;
	return (check != ' ');
}

int overlap(WINDOW *a, WINDOW *b){
	vector a_0 = {getbegx(a), getbegy(a)};
	vector b_0 = {getbegx(b), getbegy(b)};

	vector a_max = {a_0.x + getmaxx(a), a_0.y + getmaxy(a)};
	vector b_max = {b_0.x + getmaxx(b), b_0.y + getmaxx(b)};

	return !(a_max.x <= b_0.x ||
			 b_max.x <= a_0.x ||
			 a_max.y <= b_0.y ||
			 b_max.y <= a_0.y);
}
void handle_sigint(int s) {
	quit();
	fprintf(stderr, "The program terminated on sig: %d\n", s);
	exit(EXIT_SUCCESS);
}

void tick(int rate){
	usleep((int)(1000000/rate));
}
