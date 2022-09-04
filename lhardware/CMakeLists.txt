#
# SPDX-License-Identifier: (GPL-2.0+ OR MIT)
#
# Copyright (c) 2022 Rockchip Electronics Co., Ltd
#

include_directories(../lcommon/inc)

add_library(lhardware STATIC
    "hw_global.h"
    "hw_global.c"
    "hw_dequant_stat.h"
    "hw_dequant_stat.c"
)

if( CONFIG_HW )
target_compile_definitions( lhardware PUBLIC CONFIG_HW=1)
endif()
if( CONFIG_HW_DEQUANT )
target_compile_definitions( lhardware PUBLIC CONFIG_HW_DEQUANT=1)
endif()
