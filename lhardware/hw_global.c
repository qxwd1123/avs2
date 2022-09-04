#include "hw_global.h"
#include "hw_dequant_stat.h"
#include <limits.h>
#include <unistd.h>

hw_global_t *hw_global;

void hw_global_init() {
  hw_global = (hw_global_t *)malloc(sizeof(hw_global_t));
  hw_global->frame_idx = 0;
  hw_global->input_fn = NULL;
  hw_global->output_fn = NULL;
#if CONFIG_HW_DEQUANT
  hw_dequant_stat_init();
#endif
}

void hw_global_destroy() {
#if CONFIG_HW_DEQUANT
  hw_dequant_stat_destroy();
#endif
  free(hw_global->input_fn);
  free(hw_global->output_fn);
  free(hw_global);
}

void hw_global_set_input_fn(char *input_fn) {
  hw_global->input_fn = (char *)malloc(strlen(input_fn) + 1);
  memcpy(hw_global->input_fn, input_fn, strlen(input_fn) + 1);
  char *pfnc = input_fn;
  for (char *pCur = input_fn; *pCur != '\0'; pCur++) {
    if (*pCur == '/') pfnc = pCur + 1;
  }
  char cwd[PATH_MAX] = { 0 };
  assertf(getcwd(cwd, sizeof(cwd)) != NULL) fprintf(stderr, "getcwd failed\n");
  hw_global->output_fn =
      (char *)calloc(strlen(pfnc) + strlen(cwd) + 6 + 1, sizeof(char));
  strcat(hw_global->output_fn, cwd);
  strcat(hw_global->output_fn, "/stat/");
  strcat(hw_global->output_fn, pfnc);
}

void hw_global_frame_next() {
#if CONFIG_HW_DEQUANT
  hw_dequant_stat_frame_next(hw_global->frame_idx);
#endif
  hw_global->frame_idx++;
}

void hw_global_frame_done() {
#if CONFIG_HW_DEQUANT
  hw_dequant_stat_frame_done();
#endif
}
