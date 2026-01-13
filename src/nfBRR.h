/*
 * This is the renderer lib
 *
 * It's an interface for specific implementations
 *  and provide a dynamic render for better performance
 *  or for crazy tags
 */

#ifndef nfBgfRenderer_H
#define nfBgfRenderer_H

#include "nfDef.h"
#include <stdio.h>

int parseHTML(const char *html, unsigned int htmlSize, bgfObject *objPtr);

int renderBGFObj(bgfObject *obj, window *win);

int renderBGFFile(FILE *filePointer, window *win);

#endif // !nfBgfRenderer_H

