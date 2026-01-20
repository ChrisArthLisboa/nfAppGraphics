
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


int nf_g_initWindow(nf_g_window *win) {

  nf_g_startWindow(win, "Test window", 800, 600);
  if (*win == NULL) {
    fprintf(stderr, "ErrorMsg: in step nf_g_startWindow at line 18");
    return nf_g_FAILSTARTWINDOW;
  }

  return nf_g_OK;
}

int nf_g_renderWindow(nf_g_window *win, const char *fileToRender) {
  int err;
  
  FILE *filePointer = fopen(fileToRender, "r+");
  if (filePointer == NULL) {
    fprintf(stderr, "ErrorMsg: in step nf_g_renderWindow at line 27");
    return nf_g_FILENOTFOUND;
  }

  err = nf_g_renderBGFFile(filePointer, win);
  if (err != nf_g_OK) {
    fclose(filePointer);
    fprintf(stderr, "ErrorMsg: in step nf_g_renderBGFFile at line 36 | ErrorCode: %d", err);
    return err;
  }

  nf_g_bgfObject obj;

  err = nf_g_parseHTML("<p>test</p>", sizeof("<p>test</p>"), &obj);
  if (err != nf_g_OK) {
    fprintf(stderr, "ErrorMsg: in step nf_g_parseHTML at line 38 | ErrorCode: %d", err);
    fclose(filePointer);
    return err;
  }

#ifdef DEBUG

  #if defined (__BYTE_ORDER__) && __BYTE_ORDER__ == __BIG_ENDIAN__
    uint16_t objSize = ( obj[0] << 8 ) | ( obj[1] );
  #else
    uint16_t objSize = ( obj[1] << 8 ) | ( obj[0] );
  #endif

  for (int i = 0; i < objSize; i++) {
    printf("0b%08b\n", obj[i]);
  }

  for (int i = 3; i < objSize; i++) {
    printf("%c", obj[i]);
  }
  printf("\n");

#endif // !DEBUG

  free(obj);
  fclose(filePointer);
  return nf_g_OK;
}
