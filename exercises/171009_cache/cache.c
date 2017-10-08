#include <stdlib.h>
#include "hexreader.h"
#include "cachelog.h"

#define ARGNUM 1

int main(int argc, char**argv) {
    if (argc != ARGNUM + 1) {
        printf("Usage:");
        printf("  %s [filename]\n", (argv[0]+2));
        printf("    Filename: a file containing a stream of line separated hex-addresses\n");
        return(0);
    }

    hexstream hs;
    hs = readstream(argv[1]);

    // Example for usage of hexstream and cachelog.
    // Remove this when you add your code.
    // This is no way near to a cache behaviour.
    for (int i = 0; i < hs.length ; i++) {
        if ((i/2) * 2 == i ) {
            log_cache_hit(hs.stream[i]);
        }
        else {
            log_cache_miss(hs.stream[i], hs.stream[i-1]);
        }
    }

    //TODO: Implement
    return 0;
}
