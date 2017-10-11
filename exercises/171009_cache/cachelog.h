#include <stdlib.h>
#include <stdio.h>

/**
 * Logs a cache hit.
 * Input is the address that was hit.
 **/
int log_cache_hit(unsigned long adr);

/**
 * Logs a cache miss.
 * First input is the address that resulted in the cache miss
 * Second input is the address that was evicted from the cache 
 **/
int log_cache_miss(unsigned long adr, unsigned long evicted_adr);
