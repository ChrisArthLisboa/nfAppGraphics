
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

int nf_initWindow(window *win, const char *fileToRender);

int parseHTML(
  const char *html, // For now
  bgfObject *obj
);

int nf_closeWindow(window *win);

#endif
