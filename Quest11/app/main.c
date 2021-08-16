#include <stdio.h>
#include <scandir.h>

int main(int argc, char **argv)
{
    char path[255] = { 0 };

    printf("Would you kindly enter your path?\n");
    scanf("%s", path);
    dir_scaner(path);

    return 0;
}