#include "sinus.h"

void sinus()
{
	int angle_degree;
	double angle_radian, pi, value;
	printf("\nOblicz tablice f. sinus");
	pi = 4.0*atan(1.0);

	angle_degree = 0.0;
	for(angle_degree = 0; angle_degree <=360; angle_degree+=10)
	{
		angle_radian = pi * angle_degree/180.0;
		value = sin(angle_radian);

		printf("%3d %f\n", angle_degree, value);
	}
}
