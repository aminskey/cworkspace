#ifndef __ACORN_H__
#define __ACORN_H__

#include <ncurses.h>
#include <strings.h>
#include <string.h>

int __ch;
short __col;
char __str[200];

WINDOW *__win;
MEVENT __evnt;

extern char drva[];
extern char drvc[];
extern char drvd[];
extern char drve[];
extern char drvz[];
extern char home[];
extern char drives[];

extern void drvchck();
extern void bluescreen();

extern void wpaint();
extern int touch();


extern void mzclock();
extern int term();
extern char *login();

extern char* nreverse();
extern char* replace();

extern char* login();

#define paint(__ch, __col) wpaint(stdscr, __ch, __col)
#define mtouchwin(__win, __evnt) touch(getbegy(__win), getbegx(__win),getmaxy(__win),getmaxx(__win),__evnt) 
#define reverse(__str) nreverse(__str,0,strlen(__str)-1)

#define MAXY getmaxy(stdscr)
#define MAXX getmaxx(stdscr)

#endif
