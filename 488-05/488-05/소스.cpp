#include <stdio.h>
#include <math.h>

double square(double n);
double cube(double n);

int main()
{
	double n = 2;
	
	printf("Á¤¼ö¸¦ ÀÔ·Â½Ã¿À: ");
	scanf_s("%lf", &n);

	printf("Á¦°ö: %.0f\n", square(n));
	printf("¼¼Á¦°ö: %.0f\n", cube(n));
	printf("´Ù¼¸Á¦°ö: %.0f\n", square(n)*cube(n));

	return 0;
}

double square(double n) {
	return pow(n, 2);
}

double cube(double n) {
	return pow(n, 2)*n;
}