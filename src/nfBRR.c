
#include "nfBRR.h"
#include "nfDef.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// head
// body
// p
// input
// div
// img
// audio
int nf_g_parseHTML(
  const char *html,
  unsigned int htmlSize,
  nf_g_bgfObject *objPtr
) {
  int objSize = 3; // 2 for size + 1 for type
  
  uint8_t tagSize = 0;
  htmlSize -= 1; // Null terminator
  for (int i = 0; html[i] != '>'; i++) {
    htmlSize -= 2;
    tagSize++;
  }
  htmlSize -= 3;
  tagSize++;

  objSize += htmlSize;
  
  *objPtr = (nf_g_bgfObject) malloc(objSize);
  if (!*objPtr) {
    return nf_g_FAILCREATEOBJ;
  }

  nf_g_bgfObject obj = *objPtr;
  memset(obj, 0, objSize);

  memcpy(obj, &objSize, sizeof(uint16_t));
  switch (html[1]) {
    case 'p': {
      obj[2] = 0b00000001;
      break;
    }
    case 'a': {
      obj[2] = 0b00000010;
      break;
    }
  }

  memcpy(obj+3, html+tagSize, objSize-3);
  return nf_g_OK;
}

int nf_g_renderBGFFile(FILE *filePointer, nf_g_window *win) {
  
  return nf_g_NOTIMPLEMENTED;
}
