/*
 * This is the general graphical interface 
 * 
 * It's made to provide a interface to use any graphical 
 *  system that can start a window and draw to screen
 *
 * It's separated to provide multiple possibilities in the linking phase
 *  with this can be implemented using DX12, DX11, Wayland or Xorg or any other api
 *  having been implemented it's as simple as linking
 */

#ifndef nfGGI_H
#define nfGGI_H

#include "main.h"

window startWindow(const char *winTitle, int width, int height);

int drawToWindow(window *win, void *obj);


#endif // nfGGI_H
