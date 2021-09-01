#include <stdio.h>
#include <scandir.h>
#include <stdbool.h>
#include "tempf.h"


extern char *optarg;
extern int optind, opterr, optopt;


int main(int argc, char **argv)
{
    char *file;
    bool all = true;
    int ret;
    int m;

       if (argc == 1) {
        printf("Try to use -h for help\n");
        return 0;
    }

    while ((ret = getopt(argc, argv, "hf:m:")) != -1) {
        switch(ret) {

            case 'h' : {
                printf("Usage of  programm:\nUse -f[filename] to see necessary information\n\
Use -m[1-12] to see information about certain month.\n");
                return 0;
            }

            case 'f' : {
                file = optarg;
                break; 
            }

            case 'm' : {
                m = atoi(optarg);
                all = false;
                if ((m < 1) || (m > 12)){
                    printf ("Invalid argument of month\n");
                    return 0;
                } 
                break;
            }
        }
    }
    meas_scan(file, m, all);

    return 0;
}
