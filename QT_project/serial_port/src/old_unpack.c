#include <math.h>
#include <stdio.h>
#include <string.h>
#include "../inc/data_unpack.h"
#include "../inc/global.h"

#define USART_BUF_SIZE 1000
#define MAX_GPS_BUF_ROW_COUNT 2

void INS_data_unpack(void) {
  int Check;  //Ð£Ñé

  int GPS_BUF_NBR_COUNT = 0;
  int GPS_BUF_ROW_COUNT = 0;
  char GPS_BUFFER[MAX_GPS_BUF_ROW_COUNT][220];  // UART received data

  //	char temp[300] =
  //"$GPRMC,130825.00,A,3101.7301945,N,12126.2849083,E,0.004,310.5,150518,0.0,E,A*37\r\n#HEADING3A,COM1,0,55.5,FINESTEERING,1998,467616.200,00040000,d3de,12916;SOL_COMPUTED,NARROW_INT,-1.000000000,253.447845459,-1.762298584,0.200,2.719476938,15.215157509,V82L,10,8,8,8,04,00,30,03*a17e755e\r\n";

  int i = 0;

  u8 temp[300] = {0};
  u16 validLength = lengthOfValidDataFromUsart3;
  for (i = 0; i < validLength; i++) {
    temp[i] = ValidDataFromUsart3[i];
  }

  //	printf("len: %d\r\n", validLength);
  if (validLength < 275 || validLength > 295) return;
  // if(validLength!=208)return;
  // printf("data: %s\r\n", temp);

  i = 0;
  stcRTK_Data.hour = 0;
  stcRTK_Data.min = 0;
  stcRTK_Data.sec = 0;
  stcRTK_Data.latitude = 0;
  stcRTK_Data.longitude = 0;
  stcRTK_Data.Speed = 0;
  stcRTK_Data.Real_Angle = 0;

  // info sorting.
  while (temp[GPS_BUF_NBR_COUNT] != '$')  // find the first '$'
  {
    if (!(GPS_BUF_NBR_COUNT < USART_BUF_SIZE))
      break;
    else
      GPS_BUF_NBR_COUNT++;
  }

  // fill next row when meeting '\n'
  for (; GPS_BUF_NBR_COUNT < USART_BUF_SIZE; GPS_BUF_NBR_COUNT++) {
    if ((temp[GPS_BUF_NBR_COUNT] != '\n')) {
      GPS_BUFFER[GPS_BUF_ROW_COUNT][i] = temp[GPS_BUF_NBR_COUNT];
      i++;
    } else {
      GPS_BUFFER[GPS_BUF_ROW_COUNT][i] = '\n';
      GPS_BUFFER[GPS_BUF_ROW_COUNT][i + 1] = '\0';  // add '\0' to the string.
      GPS_BUF_ROW_COUNT++;
      i = 0;
      break;
    }
  }

  // info sorting.
  while (temp[GPS_BUF_NBR_COUNT] != '#')  // find the first '#'
  {
    if (!(GPS_BUF_NBR_COUNT < USART_BUF_SIZE))
      break;
    else
      GPS_BUF_NBR_COUNT++;
  }

  // fill next row when meeting '\n'
  for (; GPS_BUF_NBR_COUNT < USART_BUF_SIZE; GPS_BUF_NBR_COUNT++) {
    if ((temp[GPS_BUF_NBR_COUNT] != '\n')) {
      GPS_BUFFER[GPS_BUF_ROW_COUNT][i] = temp[GPS_BUF_NBR_COUNT];
      i++;
    } else {
      GPS_BUFFER[GPS_BUF_ROW_COUNT][i] = '\n';
      GPS_BUFFER[GPS_BUF_ROW_COUNT][i + 1] = '\0';  // add '\0' to the string.
      GPS_BUF_ROW_COUNT++;
      i = 0;
      break;
    }
  }

  //	printf("1=%s",GPS_BUFFER[0]);
  //	printf("2=%s",GPS_BUFFER[1]);

  //===================================================½âGPRMC===================================================
  for (i = 2, Check = GPS_BUFFER[0][1]; GPS_BUFFER[0][i] != '*'; i++) {
    Check = Check ^ GPS_BUFFER[0][i];
  }

  //Èç¹û×îºóµÄÐ£ÑéÎ»ÊÇ×ÖÄ¸£¬Ôò×ªÎª½ô¸ú9Ö®ºóµÄÅÅÁÐ
  if (GPS_BUFFER[0][i + 1] >= 65) {
    GPS_BUFFER[0][i + 1] = GPS_BUFFER[0][i + 1] - 7;
  }
  if (GPS_BUFFER[0][i + 2] >= 65) {
    GPS_BUFFER[0][i + 2] = GPS_BUFFER[0][i + 2] - 7;
  }

  //"$GPRMC,173843,A,3349.896,N,11808.521,W,000.0,360.0,230108,013.4,E*69\r\n"
  //Ð£ÑéÕýÈ·£¬Ôò½øÈë½â°ü
  if (Check == (GPS_BUFFER[0][i + 1] - 48) * 16 + (GPS_BUFFER[0][i + 2] - 48)) {
    GPS_BUF_NBR_COUNT = 0;
    //============Ëø¶¨Ê±¼äÇ°µÄ","£¨µÚÒ»¸ö¶ººÅ£©============
    while (GPS_BUFFER[0][GPS_BUF_NBR_COUNT] != ',') {
      GPS_BUF_NBR_COUNT++;
    }
    stcRTK_Data.hour = (GPS_BUFFER[0][GPS_BUF_NBR_COUNT + 1] - 48) * 10 +
                       (GPS_BUFFER[0][GPS_BUF_NBR_COUNT + 2] - 48);
    stcRTK_Data.min = (GPS_BUFFER[0][GPS_BUF_NBR_COUNT + 3] - 48) * 10 +
                      (GPS_BUFFER[0][GPS_BUF_NBR_COUNT + 4] - 48);
    stcRTK_Data.sec = (GPS_BUFFER[0][GPS_BUF_NBR_COUNT + 5] - 48) * 10 +
                      (GPS_BUFFER[0][GPS_BUF_NBR_COUNT + 6] - 48);
    //============Ëø¶¨Î³¶ÈµÄÐ¡Êýµã£¨µÚÈý¸ö¶ººÅÖ®ºóµÄ"."£©============
    for (i = 0; i != 3 || GPS_BUFFER[0][GPS_BUF_NBR_COUNT] != '.';
         GPS_BUF_NBR_COUNT++) {
      if (GPS_BUFFER[0][GPS_BUF_NBR_COUNT] == ',') i++;
      // printf("i=%d\n",i);
    }

    //============½âÎ³¶È============
    for (i = 1; GPS_BUFFER[0][GPS_BUF_NBR_COUNT - i] != ',';
         i++)  // Calculating the integral part
    {
      stcRTK_Data.latitude +=
          (double)(GPS_BUFFER[0][GPS_BUF_NBR_COUNT - i] - 48) *
          pow(10.0, i - 1);
    }
    for (i = 1; GPS_BUFFER[0][GPS_BUF_NBR_COUNT + i] != ',';
         i++)  // Calculating the decimal part
    {
      if (i == 7) break;
      stcRTK_Data.latitude +=
          (double)(GPS_BUFFER[0][GPS_BUF_NBR_COUNT + i] - 48) * pow(10.0, -i);
    }
    //============¼ÓÕý¸º============
    while (GPS_BUFFER[0][GPS_BUF_NBR_COUNT] != ',') {
      GPS_BUF_NBR_COUNT++;
    }
    if (GPS_BUFFER[0][GPS_BUF_NBR_COUNT + 1] == 'S') {
      stcRTK_Data.latitude = -stcRTK_Data.latitude;
    }

    //============Ëø¶¨¾­¶ÈµÄÐ¡Êýµã============
    for (i = 0; i != 2 || GPS_BUFFER[0][GPS_BUF_NBR_COUNT] != '.';
         GPS_BUF_NBR_COUNT++) {
      if (GPS_BUFFER[0][GPS_BUF_NBR_COUNT] == ',') i++;
      // printf("i=%d\n",i);
    }
    //============½â¾­¶È============
    for (i = 1; GPS_BUFFER[0][GPS_BUF_NBR_COUNT - i] != ',';
         i++)  // Calculating the integral part
    {
      stcRTK_Data.longitude +=
          (double)(GPS_BUFFER[0][GPS_BUF_NBR_COUNT - i] - 48) *
          pow(10.0, i - 1);
    }
    for (i = 1; GPS_BUFFER[0][GPS_BUF_NBR_COUNT + i] != ',';
         i++)  // Calculating the decimal part
    {
      if (i == 7) break;
      stcRTK_Data.longitude +=
          (double)(GPS_BUFFER[0][GPS_BUF_NBR_COUNT + i] - 48) * pow(10.0, -i);
    }
    //============¼ÓÕý¸º============
    while (GPS_BUFFER[0][GPS_BUF_NBR_COUNT] != ',') {
      GPS_BUF_NBR_COUNT++;
    }
    if (GPS_BUFFER[0][GPS_BUF_NBR_COUNT + 1] == 'W') {
      stcRTK_Data.longitude = -stcRTK_Data.longitude;
    }

    //============Ëø¶¨ËÙ¶ÈµÄÐ¡Êýµã============
    for (i = 0; i != 2 || GPS_BUFFER[0][GPS_BUF_NBR_COUNT] != '.';
         GPS_BUF_NBR_COUNT++) {
      if (GPS_BUFFER[0][GPS_BUF_NBR_COUNT] == ',') i++;
      // printf("i=%d\n",i);
    }
    //============½âËÙ¶È============
    for (i = 1; GPS_BUFFER[0][GPS_BUF_NBR_COUNT - i] != ',';
         i++)  // Calculating the integral part
    {
      stcRTK_Data.Speed += (double)(GPS_BUFFER[0][GPS_BUF_NBR_COUNT - i] - 48) *
                           pow(10.0, i - 1);
    }
    for (i = 1; GPS_BUFFER[0][GPS_BUF_NBR_COUNT + i] != ',';
         i++)  // Calculating the decimal part
    {
      stcRTK_Data.Speed +=
          (double)(GPS_BUFFER[0][GPS_BUF_NBR_COUNT + i] - 48) * pow(10.0, -i);
    }

    printf("%.7lf,%.7lf,OLD\r\n", stcRTK_Data.latitude, stcRTK_Data.longitude);
    //¶È·ÖÃë×ªÎª¶È£ºDecimal Degrees = Degrees + minutes/60 + seconds/3600
    stcRTK_Data.latitude =
        (int)stcRTK_Data.latitude / 100 +
        (stcRTK_Data.latitude - ((int)stcRTK_Data.latitude / 100) * 100) / 60;
    stcRTK_Data.longitude =
        (int)stcRTK_Data.longitude / 100 +
        (stcRTK_Data.longitude - ((int)stcRTK_Data.longitude / 100) * 100) / 60;

    printf("%.7lf,%.7lf,NEW\r\n", stcRTK_Data.latitude, stcRTK_Data.longitude);

    //		printf("hour =%d\r\n",stcRTK_Data.hour);
    //		printf("min=%d	sec=%d  RTK_latitude =%.7lf  RTK_longitude=%.7lf
    //", stcRTK_Data.min, stcRTK_Data.sec, stcRTK_Data.latitude,
    // stcRTK_Data.longitude); printf("Speed=%lf\r\n",stcRTK_Data.Speed);
  }

  //===================================================½âHEADING3A===================================================
  GPS_BUF_NBR_COUNT = 0;
  while (GPS_BUFFER[1][GPS_BUF_NBR_COUNT] != ';')  // find the first ';'
  {
    GPS_BUF_NBR_COUNT++;
  }
  for (i = 0; i != 3 || GPS_BUFFER[1][GPS_BUF_NBR_COUNT] != '.';
       GPS_BUF_NBR_COUNT++)  // find the poit of Real_Angle
  {
    if (GPS_BUFFER[1][GPS_BUF_NBR_COUNT] == ',') i++;
    // printf("i=%d\n",i);
  }
  for (i = 1; GPS_BUFFER[1][GPS_BUF_NBR_COUNT - i] != ',';
       i++)  // Calculating the integral part
  {
    stcRTK_Data.Real_Angle +=
        (float)(GPS_BUFFER[1][GPS_BUF_NBR_COUNT - i] - 48) * pow(10.0, i - 1);
  }
  for (i = 1; GPS_BUFFER[1][GPS_BUF_NBR_COUNT + i] != ',';
       i++)  // Calculating the decimal part
  {
    if (i == 4) break;
    stcRTK_Data.Real_Angle +=
        (float)(GPS_BUFFER[1][GPS_BUF_NBR_COUNT + i] - 48) * pow(10.0, -i);
  }
  //	printf("RTK_Angle=%f\r\n",stcRTK_Data.Real_Angle);
  //	printf("===============================================================================================================================");
  //	printf("\r\n");
}
