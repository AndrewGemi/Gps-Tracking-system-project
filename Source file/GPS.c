#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Service/TM4C123.h"
#include "../Headers/GPIO.h"
#include "../Headers/UART.h"
#include "../Headers/LED.h"
#include "../Headers/GPS.h"
#include "../Headers/SysTick_init.h"
#include "../Headers/Distance.h"
#include "../Headers/LCD.h"

double latitude;
double longitude;
char Valid;
char lat[15];
char NorS;
char lon[15];
char EorW;
char GPS_logName[10] = "$GPRMC,";
char* Longitude1;
char* direction;
char* direction2;
char* Latitude1;
char counter = 0;
char recievedChar;
char i = 0;
char flag = 1;
char GPRMC[100];
int parse_gps_data(double* latitude, double* longitude)
{

	
	char c;

	
	int j = 0;
	
	//$GPRMC,203522.00,A,5109.0262308,N,11401.8407342,W,0.004,133.4,130522,0.0,E,D*2B
	
   
	c = UART5_ReadChar();
	if (c == '$')
	{
		
		c = UART5_ReadChar();
		if (c == 'G')
		{
			 c = UART5_ReadChar();
			
			if (c == 'P')
			{
				 c = UART5_ReadChar();
				
				if (c == 'R')
				{
					 c = UART5_ReadChar();
					
					if (c == 'M')
					{
						c = UART5_ReadChar();
						
						if (c == 'C')
						{
							c = UART5_ReadChar();
							
							if (c == ',')
							{

								// this will recieve Time section
								do {
									
									c = UART5_ReadChar();    //#######this will recieve ',' before it exits the loop???

								} while (c != ',');
								c = UART5_ReadChar();
								

								if (c == 'A')   // means that this NMEA is valid 
								{
							

									c = UART5_ReadChar(); // this will recieve ','
									for (j = 0; j < 100; j++) {
										c = UART5_ReadChar();
										

										if (c != '*')
										{
											GPRMC[j] = c;

										}
										else
										{
											break;
										}
									}
									Latitude1 = strtok(GPRMC, ","); //important
									direction = strtok(NULL, ",");
									Longitude1 = strtok(NULL, ","); //important
									direction2 = strtok(NULL, ",");

									*longitude = atof(Longitude1);
									
									
									*latitude = atof(Latitude1);
									
									return 1;



								}

							}
							else
							{
								return 0;
							}



						}

					}


				}
			}
		}
	}

	return 0;
}

