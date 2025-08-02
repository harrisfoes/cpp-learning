#include <X11/Xlib.h>
#include <stdio.h>
#include <err.h>


static Display* dpy;
static int scr;
static Window root;

#define POSX   500
#define POSY   500
#define WIDTH  500
#define HEIGHT 500
#define BORDER 15

int main ()
{
	Window win;

	if ((dpy = XOpenDisplay(NULL)) == NULL)
		err(1, "Can't open display");

	/* get default screen and root window */
	scr = DefaultScreen(dpy);
	root = RootWindow(dpy, scr);
	
	/* Create our simple window */
	win = XCreateSimpleWindow(dpy, root, POSX, POSY, WIDTH, HEIGHT, BORDER, BlackPixel(dpy, scr), WhitePixel(dpy,scr));

	/* Map our window to display servers */
	XMapWindow(dpy, win);

	printf("blabla \n");

	return 0;
}





