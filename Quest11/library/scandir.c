#include "scandir.h"


void dir_scaner(const char *path)
{
    DIR *dir;
    struct dirent *entry;
    struct stat file_info;
    char full_name[255] = { 0 };

    dir = opendir(path);

    if(dir){
        while(entry = readdir(dir)){
            if(entry->d_name[0] == '.'){
                continue;
            }

            memset(full_name, 0, 255);
            sprintf(full_name, "%s/%s", path, entry->d_name);
            full_name[254] = 0;

            if(stat(entry->d_name, &file_info == 0)){
                printf(" %s\n", full_name);
            }
        }
    }
}