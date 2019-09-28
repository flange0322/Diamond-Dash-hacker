#pragma once
#include<windows.h>
#include<tchar.h>

#define GAP 40 //兩個寶石的間隔為 40 個像素
#define RowCount 9  //盤面上有幾個 row
#define ColCount 10 //盤面上有幾個 column
#define StartX 530 //x軸的起始位置
#define StartY 350 //y軸的起始位置

//初始化
int initial();
//取得盤面的顏色
void getColors(COLORREF plat[][ColCount]);
//點擊寶石
//r 為 row number 由 0 開始
//c 為 column number，由 0 開始
void clickPlat(int r, int c);