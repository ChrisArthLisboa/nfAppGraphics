
#include "../nfDef.h"
#include "../nfGGI.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wayland-client-core.h>
#include <wayland-client.h>

window startWindow(
  const char *winTitle,
  int width,
  int height
) {

  window win = (window) malloc(sizeof(uintptr_t)*1);

  struct wl_display *disp = wl_display_connect(NULL); if (!disp) {
    return NULL;
  }
  
  // new thread/process
  while (wl_display_dispatch(disp) != -1) {
    
  }

  memcpy(win+0, &disp, sizeof(uintptr_t));

  return win;
}


int drawToWindow(window *win, void *obj) {
  

  return nf_Ok;
}

int closeWindow(window *win) {

  free(win);
  return nf_Ok;
}
