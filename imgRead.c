#include<stdio.h>
#include<ncurses.h>

int main(int argc, const char *argv[])
{
	FILE *fp=fopen(argv[1],"r");
	char ch;
	
	initscr();
	cbreak();
	noecho();

	while(!feof(fp))
	{
		ch=fgetc(fp);
		switch(ch){
			case '0':
				addch((unsigned char)169);
				break;
			case '1':
				addch((unsigned char)170);
				break;
			case '2':
				addch((unsigned char)171);
				break;
			case '3':
				addch((unsigned char)172);
				break;
			case '4':
				addch((unsigned char)173);
				break;
			case '5':
                                addch((unsigned char)174);
				break;
			case '6':
                                addch((unsigned char)175);
                                break;
			case '7':
                                addch((unsigned char)176);
                                break;
			case '8':
                                addch((unsigned char)177);
                                break;
                      	case '9':
				addch((unsigned char)178);
				break;
			default:
				addch(ch);
				break;
			
		}
	}

	
	getch();
	endwin();
	return 0;
}
