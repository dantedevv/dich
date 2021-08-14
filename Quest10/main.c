#include "copy.h"

#include <stdio.h>
#include <stdint.h>




int main(int argc, char **argv)
{
    char fname1[100] = { 0 };
    char fname2[100] = { 0 };

    size_t size1;
    FILE *f1;
   
    printf("Would you kindly enter source and destination file?\n");
    scanf("%s%s", fname1, fname2);

    f1 = fopen(fname1, "rb");
    if (f1 == NULL) {
        printf("File does not exist. ERROR!\n");
        return -1;
    }

    fseek(f1, 0, SEEK_END);
    size1 = ftell(f1);

    fclose(f1);

    char BUFF[size1];

    load_from_file(&BUFF, fname1, size1);
    save_to_file(&BUFF, fname2,size1);
    

    return 0;
}