#include "tempf.h"


int meas_scan(const char *file, const int month, bool all)
{
  int i = 0;
  int yearmax, yearmin;
  int yearsum = 0;
  int averyear = 0;

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
  printf("Scanned lines %d All %s\n", i, all ? "TRUE" : "FALSE");

  int Nelements = i;
  
  yearmax = yearmin = m[0].temp;

  for (int i = 0; i <= Nelements; i++){
    if (m[i].temp > yearmax) yearmax = m[i].temp;
    if (m[i].temp < yearmin) yearmin = m[i].temp;
    yearsum += m[i].temp;
  }
  averyear = yearsum / Nelements;

  if (all){
    printf("Information of %d year:\nMax temp = %d\nMin temp = %d\nAverage temp = %d\n", m[0].year, yearmax, yearmin, averyear); 
    for (int i = 1; i <= 12; i++) temp_stat(m, i, Nelements);
  }
  else temp_stat(m, month, Nelements);

    fclose(f);
    return 0;
}

void temp_stat(meas *m, const int crtmonth, int Nelements)
{
  int tmax, tmin;
  int tsum = 0;
  int avertemp = 0;
  int n_found = 1;

  tmax = tmin = m[0].temp;

  for (int i = 0; i < Nelements; i++){
    if (m[i].month == crtmonth){
      if (m[i].temp > tmax) tmax = m[i].temp;
      if (m[i].temp > tmax) tmax = m[i].temp;

      tsum += m[i].temp;
      n_found++;
    }
  }
  avertemp = tsum / n_found;

  printf("Information of %d month:\nMax temp = %d\nMin temp = %d\nAverage temp = %d\n", crtmonth, tmax, tmin, avertemp);
}
  