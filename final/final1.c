#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int a=0, c=0;
	double beta = 0,b=0;
	while (1)
	{
		scanf("%d %d %lf", &a, &c, &beta);
		if (a <= 0 || c <= 0 || beta <= 0 || beta >= 180)
		{
			printf("Invalid\n");
		}
		else
		{
			b = a * a + c * c - 2 * a * c * cos(beta / 180 * 3.1415926);
			b = sqrt(b);
			if (a + b > c && a + c > b && b + c > a)
			{
				printf("%.2lf\n", b);
			}
			else
			printf("Invalid\n");
		}
	}
}