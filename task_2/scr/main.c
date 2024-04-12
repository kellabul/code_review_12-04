#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DENSITY 21500


double CalculateVolume(double radius){
    double volume = (4.0 / 3.0) * M_PI * pow(radius, 3);
    return volume;
}

int main() {
  double radius = 0;
  scanf("%lf", &radius);
  double volume = CalculateVolume(radius);
  double result = DENSITY * volume;
  printf("%.0lf", result);
}