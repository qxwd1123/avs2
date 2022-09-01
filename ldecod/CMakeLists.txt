###############################################################
# copyright 2016-2016, Jiang GUO, Yimin ZHOU, UESTC           #
###############################################################

include_directories(inc ../lcommon/inc)

set(DIR_SRCS
inc/AEC.h
inc/annexb.h
inc/biaridecod.h
inc/block.h
inc/codingUnit.h
inc/DecAdaptiveLoopFilter.h
inc/global.h
inc/header.h
inc/pos_info.h
inc/vlc.h
inc/wquant.h
src/AEC.c
src/biaridecod.c
src/bitstream.c
src/block.c
src/b_frame.c
src/codingUnit.c
src/context_ini.c
src/DecAdaptiveLoopFilter.c
src/header.c
src/image.c
src/ldecod.c
src/loopfilter.c
src/output.c
src/pos_info.c
src/vlc.c
src/wquant.c
)

add_executable(ldecod ${DIR_SRCS})
target_link_libraries(ldecod lcommon m)
