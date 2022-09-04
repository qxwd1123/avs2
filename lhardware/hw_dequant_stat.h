#ifndef __HW_DEQUANT_STAT_H
#define __HW_DEQUANT_STAT_H

#include "hw_global.h"

typedef struct {
  uint32_t upper_only;
  uint32_t left_only;
  uint32_t ul_only;
  uint32_t total;
} coeff_stat;

void hw_dequant_stat_init();

void hw_dequant_stat_destroy();

void hw_dequant_stat_frame_next(int32_t frame_idx);

void hw_dequant_stat_frame_done();

void hw_dequant_stat_update_dqcoeff(const int32_t width, const int32_t height,
                                    const int32_t **const resi);
#endif