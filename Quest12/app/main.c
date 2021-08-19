#include <stdio.h>
#include <scandir.h>
#include <stdbool.h>


extern char *optarg;
extern int optind, opterr, optopt;

int main(int argc, char **argv)
{
    char *path;
    bool all = false;
    bool req = false;
    int ret;

       if (argc == 1) {
        printf("Try to use -h for help\n");
        return 0;
    }

    while ((ret = getopt(argc, argv, "had:f:")) != -1) {
        switch(ret) {

            case 'h' : {
                printf("Usage of ls kind programm:\nUse -d[path] to see elements in a directory\n\
Use -f[path] to recursive mode (DO NOT USE with -d!!!)\nUse -a to see all files with ./ & ../\n");
                return 0;
            }
            case 'a' : {
                all = true;
                break;
            }
            case 'd' : {
                path = optarg;
                break;
            }
            case 'f' : {
                path = optarg;
                req = true;
                break;
            }
        }
    }
    print_dir_contents(path, all,req);

    return 0;
}