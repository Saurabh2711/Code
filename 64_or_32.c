#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    long wordBits = sysconf(_SC_WORD_BIT);
    if (wordBits == -1 && errno == EINVAL)
        return EXIT_FAILURE;
    else
        printf("%ld\n", wordBits);
    return EXIT_SUCCESS;
}