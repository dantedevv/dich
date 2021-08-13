#include "copy.h"

#include <stdio.h>
#include <stdint.h>




int main(int argc, char **argv)
{
   char fname1[100] = { 0 };
   char fname2[100] = { 0 };
   
   size_t size1, size2;

   FILE *f1;
   FILE *f2;

    printf("Would you kindly enter source and destination file?\n");
    scanf("%s%s", fname1, fname2);

   f1 = fopen(fname1, "rb");
    if (f1 == NULL) {
        printf("ZALOOPA!\n");
        return -1;
    }

    fseek(f1, 0, SEEK_END);
    size1 = ftell(f1);

    fclose(f1);

   load_from_file(f1, fname1, size1);
   save_to_file(f1, fname2,size1);

   f2 = fopen(fname2, "rb");
    if (f2 == NULL) {
        printf("ZALOOPA!\n");
        return -1;
    }

    fseek(f2, 0, SEEK_END);
    size2 = ftell(f2);

    fclose(f2);

    printf("Copying is complete. Transfered %lu bytes", size2);
   
    return 0;
}