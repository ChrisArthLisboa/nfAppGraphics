
#include "../src/main.h"

#include <stdio.h>

int main(int argc, char **argv) {

  int err;
  nf_g_window win;

  err = nf_g_initWindow(&win);
  if (err != nf_g_OK) {
    fprintf(stderr, "ErrorMsg: in step nf_g_initWindow at line 11 | ErrorCode: %d", err);
    return 1;
  }
  err = nf_g_renderWindow(&win, "./test.bgf");
  if (err != nf_g_OK) {
    fprintf(stderr, "ErrorMsg: in step nf_g_renderWindow at line 16 | ErrorCode: %d", err);
    return 1;
  }

  nf_g_finalizeWindow(&win);
}
