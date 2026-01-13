
#include "main.h"
#include "nfGGI.h"
#include "nfBRR.h"
#include "nfDef.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG


int nf_initWindow(window *win, const char *fileToRender) {
  int err;

  FILE *filePointer = fopen(fileToRender, "r+");
  if (filePointer == NULL) {
    return nf_FileNotFound;
  }

  // *win = startWindow("Test window", 800, 600);
  // if (*win == NULL) {
  //   printf("win Error");
  //   return nf_FailStartWindow;
  // }

  bgfObject obj;

  err = parseHTML("<p>test</p>", sizeof("<p>test</p>"), &obj);
  if (err != nf_Ok) {
    printf("Failed creating BGF obj");
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
  return nf_Ok;
}
