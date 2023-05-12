#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Service/TM4C123.h"
#include "Headers/GPIO.h"
#include "Headers/UART.h"
#include "Headers/LED.h"
#include "Headers/GPS.h"
#include "Headers/SysTick_init.h"
#include "Headers/Distance.h"
#include "Headers/LCD.h"


extern double latitude;
extern double longitude;
extern char Valid;
extern char lat[15];
extern char NorS;
extern char lon[15];
extern char EorW;
double lat1, long1;
double g_distance ;
double CheckDistance_to_end_point ;
int flag1 = 0;
double lat2 = 0;
double long2 = 0;
double final_latitude= 30.084410;
double final_longitude= 31.3492241;
int x;
int main(void)
{
    
    // Set up GPIO & LCD
    initPortF();
    LCD_init();
    // Set up UART for GPS communication
		UART0_Init(9600);
    UART5_Init(9600);
		LCD_message("Hello...");
			led(LED_BLUE);
	
    // Main loop
    while (1)
    {  
				//GPSRead();		
							
			x = parse_gps_data(&lat1,&long1);//Read and Parse GPS data to get latitude and longitude if data is invalid it will not go in the loop 
				 while(x){
        lat1 = ToDegree(lat1);
				 
        long1= ToDegree(long1);
				 
        if (lat2 != 0 && long2 != 0 )  // this prevent calculation distance if we are at the starting point 
        {
            flag1 = 1;
        }
        else {
            led(LED_TURQOIS);
            delay(16000000, 2);
            led(0);
             }
        
        if (flag1)
        {
            g_distance += CalculateDistance(lat2,long2 , lat1, long1); // accumulating distance 
        }
        
        // Check if we have reached the end point
        CheckDistance_to_end_point = CalculateDistance(lat1,long1,final_latitude,final_longitude);
				LCD_message("Keep going!...");
        if (CheckDistance_to_end_point < 5 && CheckDistance_to_end_point > 0.1)
        {
            led(LED_YELLOW);
           // LCD_message("Keep going!Almost there...");
           // delay(5);
        }
        if (CheckDistance_to_end_point < 0.1)
        {
            
            led(LED_GREEN); 
            //LCD_message_Dis(CheckDistance_to_end_point);
            LCD_message_Dis(g_distance);    //total distance covered
            //delay(16000000,5);
            goto end;
        }
        if (CheckDistance_to_end_point > 5)
        {
            led(LED_RED);
            //LCD_message_Dis(CheckDistance_to_end_point);
            //delay(16000000,5);

        }
       // Save latitude and longitude to global variables
        lat2 = lat1;
        long2 = long1;
			}
			
    }
		end :
		return 1;
}


