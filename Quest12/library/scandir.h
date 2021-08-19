#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <stdbool.h>

void print_type(struct stat *st);
void print_dir_contents(const char *strdir, bool all, bool req);