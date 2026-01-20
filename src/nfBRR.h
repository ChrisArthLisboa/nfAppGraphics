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

// temporary
int nf_g_parseHTML(const char *html, unsigned int htmlSize, nf_g_bgfObject *objPtr);

int nf_g_renderBGFObj(nf_g_bgfObject *obj, nf_g_window *win);

int nf_g_renderBGFFile(FILE *filePointer, nf_g_window *win);

#endif // !nfBgfRenderer_H

