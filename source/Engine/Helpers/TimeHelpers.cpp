#ifndef __TIMEHELPERS_CPP
#define __TIMEHELPERS_CPP

#include <3ds.h>

namespace Madeline {
    namespace Helpers {
        u64 GetTimeNowMilliseconds() {
            return svcGetSystemTick() / CPU_TICKS_PER_MSEC;
        }
    }
}

#endif