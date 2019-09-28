#include<stdio.h>
#include<conio.h>
#include<time.h>
#include "blitz.h"
#include <iostream>
using namespace std;
//在畫面上印出遊戲的盤面
void showColors(COLORREF plat[][ColCount]);
void getPos(COLORREF plat[][ColCount], int* r, int* c);

void main()
{
	//遊戲的盤面
	COLORREF plat[RowCount][ColCount];
	srand(unsigned int(time(NULL)));

	getchar();
	//取得視窗
	int result = initial();
	if (result == -1)
		printf("ERROR\n");
	else
	{
		while (1)
		{
			int ar = 0;
			int ac = 0;
			getColors(plat);
			showColors(plat);
			getPos(plat, &ar, &ac);
			clickPlat(ar, ac);
			//Sleep(100); //休息 0.2 秒
		}
	}
}


void getPos(COLORREF plat[][ColCount], int* r, int* c)
{
	for (int i = 0; i < RowCount; i++)
	{
		for (int j = 0; j < ColCount; j++)
		{
			if(plat[i][j] == 7794171 || plat[i][j] == 8781046 || plat[i][j] == 13170675 || plat[i][j] == 7330559 || plat[i][j] == 8452591 || plat[i][j] == 9500133 || plat[i][j] == 11730943 || plat[i][j] == 16121082)
			{
				*r = i;
				*c = j;
				continue;
			}

			if (j <= 7 && plat[i][j + 1] == plat[i][j] && plat[i][j + 2] == plat[i][j])
			{
				*r = i;
				*c = j;
				continue;
			}
			else if (j >= 2 && plat[i][j - 1] == plat[i][j] && plat[i][j - 2] == plat[i][j])
			{
				*r = i;
				*c = j;
				continue;
			}
			else if (i <= 6 && plat[i + 1][j] == plat[i][j] && plat[i + 2][j] == plat[i][j])
			{
				*r = i;
				*c = j;
				continue;
			}
			else if (i >= 2 && plat[i - 1][j] == plat[i][j] && plat[i - 2][j] == plat[i][j])
			{
				*r = i;
				*c = j;
				continue;
			}
			else if (j <= 8 && i <= 7 && ((plat[i][j + 1] == plat[i][j] && plat[i + 1][j + 1] == plat[i][j]) || (plat[i + 1][j] == plat[i][j] && plat[i + 1][j + 1] == plat[i][j])))
			{
				*r = i;
				*c = j;
				continue;
			}
			else if (j <= 8 && i >= 1 && ((plat[i][j + 1] == plat[i][j] && plat[i - 1][j + 1] == plat[i][j]) || (plat[i - 1][j] == plat[i][j] && plat[i - 1][j + 1] == plat[i][j])))
			{
				*r = i;
				*c = j;
				continue;
			}
			else if (j >= 1 && i <= 7 && ((plat[i][j - 1] == plat[i][j] && plat[i + 1][j - 1] == plat[i][j]) || (plat[i + 1][j] == plat[i][j] && plat[i + 1][j - 1] == plat[i][j])))
			{
				*r = i;
				*c = j;
				continue;
			}
			else if (j >= 1 && i >= 1 && ((plat[i][j - 1] == plat[i][j] && plat[i - 1][j - 1] == plat[i][j]) || (plat[i - 1][j] == plat[i][j] && plat[i - 1][j - 1] == plat[i][j])))
			{
				*r = i;
				*c = j;
				continue;
			}
		}
	}
}

void showColors(COLORREF plat[][ColCount])
{
	for (int i = 0; i < RowCount; i++)
	{
		for (int j = 0; j < ColCount; j++)
		{
			if (plat[i][j] == 58623)
				printf("%s  ", "黃");
			else if (plat[i][j] == 12121536)
				printf("%s  ", "綠");
			else if (plat[i][j] == 7956991)
				printf("%s  ", "紅");
			else if (plat[i][j] == 16662455)
				printf("%s  ", "紫");
			else if (plat[i][j] == 16551424)
				printf("%s  ", "藍");
			else
				printf("%s ", "特");
		}
		printf("\n");
	}
	printf("=========================================================================\n");
}