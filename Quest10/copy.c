#include "copy.h"

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>


int load_from_file(void *element, const char *fname, size_t size)
{
    FILE *f;
    size_t sz;
     
    f = fopen(fname, "rb");
    if (f == NULL) {
        printf("File does not exist. ERROR!\n");
        return -1;
    }
    
    fread(element, size, 1, f);
    fclose(f);

    return 0;
}

int save_to_file(const void *element, const char *fname, size_t size)
{
    FILE *f;
    size_t sz;

    f = fopen(fname, "wb");
    if (f == NULL) {
        printf("Copying FAILED!!!\n");
        return -1;
    }

    fwrite(element, size, 1, f);
    fseek(f, 0, SEEK_END);

    sz = ftell(f);
    
    fclose(f);

    printf("Copying is complete. Transfered %lu bytes\n", sz);

    return 0;
}