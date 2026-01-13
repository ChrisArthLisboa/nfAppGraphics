/*
 * Definition of constants, macros and types
 */

#ifndef nfAGDefinitions_H
#define nfAGDefinitions_H

#include <stdint.h>
enum nf_AG_ErrorCodes {
  nf_Ok,
  nf_FileNotFound,
  nf_FailCreateObj, // maybe create have a bin segment and the line that broke
  nf_FailRenderingObj,
  nf_FailStartWindow,
  nf_NotImplemented
};

typedef uint8_t *window;

/**
 * Specifications:
 *  byte 0 and 1 = complete size of the object considering themselves
 *  byte 2 = type of the object
 *  rest = whats inside the object (please be only text)
 */
typedef uint8_t *bgfObject;

#endif // !nfAGDefinitions_H
