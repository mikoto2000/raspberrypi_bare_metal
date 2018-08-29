#include "core.h"

uint8 get_core_id(void) {
    uint32 mpidr_el1 = get_mpidr_el1();
    uint8 core_id = mpidr_el1 & 0xFF;
    return core_id;
}

