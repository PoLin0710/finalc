#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void find(char maze[][11], int start[])
{
	for (int i = 0; i < 11; i++)
	{
		if (maze[i][0] == '.')
		{
			start[0] = 0;
			start[1] = i;
			break;
		}
	}
}

void findend(char maze[][11], int start[], int x, int y,int dir) //°g®c¥D­n§PÂ_
{
	if (maze[y][x] == 'O')
	{	
		start[0] = x;
		start[1] = y;
		return;
	}
	if (maze[y][10] == '.' && x == 10)
	{
		maze[y][x] = 'X';
		return;
	}
	maze[y][x] = 'X';

	int checkrighty[4] = {1,0,-1,0};
	int checkrightx[4] = {0,-1,0,1};
	int checktowardy[4] = { 0,1,0,-1 };
	int checktowardx[4] = { 1,0,-1,0 };

	if (maze[y + checkrighty[dir]][x + checkrightx[dir]] != '#')
	{
		y += checkrighty[dir];
		x += checkrightx[dir];
		dir = (dir + 1) % 4;
	}
	else
	{
		if (maze[y + checktowardy[dir]][x + checktowardx[dir]] == '#')
			dir = dir - 1 < 0 ? 3 : dir - 1;
		dir = dir - 1 < 0 ? 3 : dir - 1;
	}
	findend(maze, start, x, y, dir);
}

void print(char maze[][11])
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	FILE* Input;
	if ((Input = fopen("final5/input.txt", "r")) == NULL)
	{
		printf("error");
		return 0;
	}
	char maze[4][11][11];
	int num;
	fscanf(Input,"%d ", &num);
	for (int i = 0; i < num; i++) //input
	{
		for (int j = 0; j < 11; j++)
		{
			for (int k = 0; k < 11; k++)
			{
				maze[i][j][k] = fgetc(Input);
			}
			fgetc(Input);
		}
	}
	
	int start[2] = { -1,-1 };
	find(maze[0], start);

	for (int i = 0; i < num; i++)
	{
		findend(maze[i], start, start[0], start[1], 0);
		print(maze[i]);
	}
}