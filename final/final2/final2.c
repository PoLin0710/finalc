#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct menu {
	char name[10];
	int money;
}Menu;

int main()
{
	Menu menu[100];
	int mpr = 0;
	FILE* M, * O, * R;
	M = fopen("final2/menu.txt", "r");
	O = fopen("final2/order.txt", "r");
	R = fopen("final2/result2.txt", "w");
	while (fscanf(M, "%s %d", menu[mpr].name, &menu[mpr].money) != EOF)
	{
		mpr++;
	}
	Menu temp;
	int money = 0;
	while (fscanf(O, "%s", temp.name) != EOF)
	{
		if (temp.name[0] == '#')
		{
			fprintf(R, "%d\n", money);
			money = 0;
		}
		else
		{
			fscanf(O, "%d", &temp.money);
			for (int i = 0; i < mpr; i++)
			{
				if (strcmp(menu[i].name, temp.name) == 0)
				{
					money += (menu[i].money * temp.money);
					break;
				}
			}
		}
	}
	fclose(R, O, M);

}