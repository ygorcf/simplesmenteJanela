/*

  Display *dpy = XOpenDisplay(NIL);
  
  int blackColor = BlackPixel(dpy, DefaultScreen(dpy));
  int whiteColor = WhitePixel(dpy, DefaultScreen(dpy));

  Window w = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), 0, 0, 
				     200, 100, 0, blackColor, blackColor);
  XSelectInput(dpy, w, StructureNotifyMask);
  XMapWindow(dpy, w);
  GC gc = XCreateGC(dpy, w, 0, NIL);
  XSetForeground(dpy, gc, whiteColor);
  for(;;) {
	    XEvent e;
	    XNextEvent(dpy, &e);
	    if (e.type == MapNotify)
		  break;
      }
  //XDrawLine(dpy, w, gc, 10, 60, 180, 20);
  XFlush(dpy);
*/