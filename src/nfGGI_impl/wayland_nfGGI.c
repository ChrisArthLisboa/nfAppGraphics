
#include "../nfDef.h"
#include "../nfGGI.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wayland-client-core.h>
#include <wayland-client-protocol.h>
#include <wayland-client.h>

void nf_g_startWindow(
  nf_g_window *win,
  const char *winTitle,
  int width,
  int height
) {

  *win = (nf_g_window) malloc(sizeof(uintptr_t)*1);

  struct wl_display *disp = wl_display_connect(NULL);
  if (!disp) {
    *win = NULL;
    return;
  }
  // struct wl_registry *reg = wl_display_get_registry(disp);

  memcpy(win+0, &disp, sizeof(uintptr_t));
  
  // new thread/process
  while (wl_display_dispatch(disp) != -1) {
    
  }
}


int nf_g_drawToWindow(nf_g_window *win, void *obj) {


  return nf_g_OK;
}

void nf_g_closeWindow(nf_g_window *win) {

  free(win);
}
