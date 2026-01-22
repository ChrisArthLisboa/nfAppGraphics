/*
 * Definition of constants, macros and types
 */

#ifndef nfAGDefinitions_H
#define nfAGDefinitions_H

#include <stdint.h>
typedef enum nf_g_ErrorCodes {
  nf_g_OK,
  nf_g_FILENOTFOUND,
  nf_g_FAILCREATEOBJ, // maybe create have a bin segment and the line that broke
  nf_g_FAILRENDERINGOBJ,
  nf_g_FAILSTARTWINDOW,
  nf_g_NOTIMPLEMENTED
} nf_g_errors;

typedef uint8_t *nf_g_window;

/**
 * Specifications:
 *  byte 0 and 1 = complete size of the object considering themselves
 *  byte 2 = type of the object
 *  rest = whats inside the object (please be only text)
 */
typedef uint8_t *nf_g_bgfObject;

#endif // !nfAGDefinitions_H
