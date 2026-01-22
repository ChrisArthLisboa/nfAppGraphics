
/*
 *
 * This Library was inspired by this talk 
 *  https://youtu.be/AmrBpxAtPrI?si=aPeMFqWQXBA6F8kl
 *
 * It's a lib called NoFussAppGraphics(nfAG) meant to be a library that 
 *  can make graphics in any language as easy as in the web while being performant
 *  and keeping multiplatform using linking strategies
 */

#ifndef nfAG_H
#define nfAG_H

#include "nfDef.h"

nf_g_errors nf_g_initWindow(nf_g_window *win);

nf_g_errors nf_g_renderWindow(
  nf_g_window *win,
  const char *fileToRender
);

nf_g_errors nf_g_finalizeWindow(nf_g_window *win);

#endif
