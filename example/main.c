
#include "../src/main.h"

#include <stdio.h>

int main(int argc, char **argv) {

  int err;
  window win;

  err = nf_initWindow(&win, "/home/lisboa/Documents/git/nfAppGraphics/example/test.bgf");
  if (err != nf_Ok) {
    printf("Error: Something went wrong. errCode: %d\n", err);
    return 1;
  }

}
