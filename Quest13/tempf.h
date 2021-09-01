#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct meas {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temp;
  } meas;

int meas_scan(const char *file,const int month, bool all);
void temp_stat(meas *m, const int crtmonth, int Nelements);