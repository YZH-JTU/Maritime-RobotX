#include "../inc/data_unpack.h"
#include "../../globalvar/inc/globalvar.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

void INS_data_unpack(char *temp) {
  int BUF_NBR_COUNT = 0;
  int i = 0;

  while (temp[BUF_NBR_COUNT] != '$') {
    BUF_NBR_COUNT++;
  }  

  if(temp[BUF_NBR_COUNT+1] == 'H'){
    float temp_heading_angle = 0;
    //============Find the "." of Heading angle (the first ".")============
    while (temp[BUF_NBR_COUNT] != '.') {
      BUF_NBR_COUNT++;
    }
    for (i = 1; temp[BUF_NBR_COUNT - i] != ',';
         i++)  // Calculating the integral part
    {
      temp_heading_angle += (float)(temp[BUF_NBR_COUNT - i] - 48) * pow(10.0, i - 1);
      // printf("%f  ", (float)(temp[BUF_NBR_COUNT - i] - 48));
      // printf("%f  ", pow(10.0, i - 1));
      // printf("%f\n", (float)(temp[BUF_NBR_COUNT - i] - 48) * pow(10.0, i - 1));
    }
    for (i = 1; temp[BUF_NBR_COUNT + i] != ',';
         i++)  // Calculating the decimal part
    {
      temp_heading_angle += (float)(temp[BUF_NBR_COUNT + i] - 48) * pow(10.0, -i);
      // printf("%f  ", (float)(temp[BUF_NBR_COUNT + i] - 48));
      // printf("%f  ", pow(10.0, -i));
      // printf("%f\n", (float)(temp[BUF_NBR_COUNT + i] - 48) * pow(10.0, -i));
    }

    heading_angle = temp_heading_angle;
  }
}

void GPS_data_unpack(char *temp) {
  int BUF_NBR_COUNT = 0;
  int i = 0;

  //============锁定纬度的小数点============
  for (i = 0; i != 3 || temp[BUF_NBR_COUNT] != '.'; BUF_NBR_COUNT++) {
    if (temp[BUF_NBR_COUNT] == ',') i++;
    // printf("i=%d\n",i);
  }

  //============解纬度============
  for (i = 1; temp[BUF_NBR_COUNT - i] != ',';
       i++)  // Calculating the integral part
  {
    latitude += (double)(temp[BUF_NBR_COUNT - i] - 48) * pow(10.0, i - 1);
  }
  for (i = 1; temp[BUF_NBR_COUNT + i] != ',';
       i++)  // Calculating the decimal part
  {
    if (i == 7) break;
    latitude += (double)(temp[BUF_NBR_COUNT + i] - 48) * pow(10.0, -i);
  }
  //============加正负============
  while (temp[BUF_NBR_COUNT] != ',') {
    BUF_NBR_COUNT++;
  }
  if (temp[BUF_NBR_COUNT + 1] == 'S') {
    latitude = -latitude;
  }

  //============锁定经度的小数点============
  for (i = 0; i != 2 || temp[BUF_NBR_COUNT] != '.'; BUF_NBR_COUNT++) {
    if (temp[BUF_NBR_COUNT] == ',') i++;
    // printf("i=%d\n",i);
  }
  //============解经度============
  for (i = 1; temp[BUF_NBR_COUNT - i] != ',';
       i++)  // Calculating the integral part
  {
    longitude += (double)(temp[BUF_NBR_COUNT - i] - 48) * pow(10.0, i - 1);
  }
  for (i = 1; temp[BUF_NBR_COUNT + i] != ',';
       i++)  // Calculating the decimal part
  {
    if (i == 7) break;
    longitude += (double)(temp[BUF_NBR_COUNT + i] - 48) * pow(10.0, -i);
  }
  //============加正负============
  while (temp[BUF_NBR_COUNT] != ',') {
    BUF_NBR_COUNT++;
  }
  if (temp[BUF_NBR_COUNT + 1] == 'W') {
    longitude = -longitude;
  }
}
