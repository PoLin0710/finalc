#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* f1, * f2, * r;
	f1 = fopen("file1.txt", "r");
	f2 = fopen("file2.txt", "r");
	r = fopen("result3.txt", "w");

	double num[200];

	int pr = 0;

	while (fscanf(f1, "%lf", &num[pr]) != EOF)
	{
		pr++;
	}

	double x;

	while (fscanf(f2, "%lf", &x) != EOF)
	{
		int repeat = 0;
		for (int i = 0; i < pr; i++)
		{
			if (num[i] == x)
			{
				repeat = 1;
				break;
			}
		}
		if (!repeat)
			num[pr++] = x;
	}

	for (int i = 0; i < pr; i++)
	{
		for (int j = i + 1; j < pr-1; j++)
		{
			if (num[i] > num[j])
			{
				double temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
	for (int i = 0; i < pr; i++)
		fprintf(r, "%.1lf ", num[i]);
	fclose(f1, f2, r);
}