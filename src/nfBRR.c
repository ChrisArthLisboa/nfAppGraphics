
#include "nfBRR.h"
#include "main.h"
#include "nfDef.h"
#include "nfGGI.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parseHTML(const char *html, unsigned int htmlSize, bgfObject *objPtr) {
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
  
  *objPtr = (bgfObject) malloc(objSize);
  if (!*objPtr) {
    return nf_FailCreateObj;
  }

  bgfObject obj = *objPtr;
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
  return nf_Ok;
}

int renderBGFFile(FILE *filePointer, window *win) {
  
  return nf_NotImplemented;
}
