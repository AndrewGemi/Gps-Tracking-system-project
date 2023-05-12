#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Service/TM4C123.h"
#include "../Headers/Distance.h"

double a;
double c;
double d;
double lat11 ;
  double long11;
  double lat22 ;
  double long22;

double ToDegree(double angle) {
    return (int)(angle / 100) + (angle - (int)(angle / 100) * 100) / 60.0;
}
double ToRadian(double angle) {
    return (angle * PI / 180);
}
double CalculateDistance(double latitude_1, double longitude_1, double latitude_2, double longitude_2)
{
    
   double lat11 = ToRadian((latitude_1));
   double long11 = ToRadian((longitude_1));
   double lat22 = ToRadian((latitude_2));
   double long22 = ToRadian((longitude_2));


    // Calculate the great circle distance using the Haversine formula
    a = (sin((lat22 - lat11) / 2) * sin((lat22 - lat11) / 2)) + cos(lat11) * cos(lat22) * sin((long22 - long11) / 2) * sin((long22 - long11) / 2);
    c = 2 * atan2(sqrt(a), sqrt(1 - a));
    d = 6371000 * c; // Earth's radius in m 

    return d;


}
