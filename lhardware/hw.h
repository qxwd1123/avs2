#ifndef __HW_H
#define __HW_H

#include <stdint.h>
#include <stdbool.h>

void hw_global_init();
void hw_global_destroy();
void hw_global_set_input_fn(char *input_fn);
void hw_global_frame_next();
void hw_global_frame_done();

void hw_dequant_stat_update_dqcoeff(const int32_t width, const int32_t height,
                                    const int32_t **const resi);

void hw_dequant_stat_update_dqcoeff_uv(const int32_t width,
                                       const int32_t height,
                                       const int32_t *const resi);

#endif