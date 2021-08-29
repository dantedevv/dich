#include "tempf.h"


int meas_scan(const char *file, const int month, bool all)
{
  
  int i = 0;

  meas m[10000];

  FILE *f = fopen(file, "r");
  if (!f) {
    printf("Error opening file\n");
    return -2;
  }

  while (!feof(f)) {
    int scanfret = fscanf(f, "%d;%d;%d;%d;%d;%d",
                  &m[i].year,
                  &m[i].month,
                  &m[i].day,
                  &m[i].hour,
                  &m[i].minute,
                  &m[i].temp);

      if (scanfret !=6){
        printf("Wrong format of data in file!\n");
        return -2;
      }

      i++;
    }
  if (all){
    for (int i = 1; i <= 12; i++) temp_stat(m, i);
  }
  else temp_stat(m,month);

    fclose(f);
    return 0;
}

void temp_stat(meas *m, const int crtmonth)
{
  int tmax = 0;
  int tmin = 0;
  int tsum = 0;
  int avertemp = 0;
  int i = 0;


    while (m[i].month == crtmonth){
      if (m[i].temp > tmax) tmax = m[i].temp;
      if (m[i].temp < tmin) tmin = m[i].temp;

      tsum += m[i].temp;
      i++;
    }
  
  avertemp = tsum / i;
  printf("Information of %d month:\nMax temp = %d\nMin temp = %d\nAverage temp = %d\n", m->month, tmax, tmin, avertemp);
  
  if(m[i].month == 0) {
    printf ("Not enought data!!!\n");
    return;
  }

}
  