#include <stdlib.h>
#include <stdio.h>
#include "hexreader.h"

int log_cache_hit(unsigned long adr) {
    printf("HIT:  0x%lx\n", adr);
    return 0;
}

/**
 * 
 **/
int log_cache_miss(unsigned long adr, unsigned long evicted_adr) {
    printf("MISS: 0x%lx -EVICTED-> 0x%lx\n", adr, evicted_adr);
    return 0;
}
