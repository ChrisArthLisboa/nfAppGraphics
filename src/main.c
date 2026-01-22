#include "main.h"
#include "nfGGI.h"
#include "nfBRR.h"
#include "nfDef.h"

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG

nf_g_errors nf_g_initWindow(nf_g_window *win) {

  nf_g_startWindow(win, "Test window", 800, 600);
  if (*win == NULL) {
    fprintf(
      stderr,
      "ErrorMsg: in step nf_g_startWindow at line 18"
    );
    return nf_g_FAILSTARTWINDOW;
  }

  return nf_g_OK;
}

nf_g_errors nf_g_renderWindow(
  nf_g_window *win,
  const char *fileToRender
) {
  int err;
  
  FILE *filePointer = fopen(fileToRender, "r+");
  if (filePointer == NULL) {
    fprintf(
      stderr,
      "ErrorMsg: in step fopen at line 31"
    );
    return nf_g_FILENOTFOUND;
  }

  err = nf_g_renderBGFFile(filePointer, win);
  if (err != nf_g_OK) {
    fclose(filePointer);
    fprintf(
      stderr,
      "ErrorMsg: in step nf_g_renderBGFFile at line 36 | ErrorCode: %d",
      err
    );
    return err;
  }

  fclose(filePointer);
  return nf_g_OK;
}

nf_g_errors nf_g_finalizeWindow(nf_g_window *win) {

  nf_g_closeWindow(win);
  free(win);
  return nf_g_OK;
}


