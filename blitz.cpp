#include "blitz.h"
#include<stdio.h>
#include <Windows.h>
#define TITLESTR "Diamond Dash 在 Facebook 上 - Google Chrome" //Browser的標題
#define SUBTITLESTR "Diamond Dash 在 Facebook 上"
#define ChromeMainWinClass "Chrome_WidgetWin_1"  //Chrome的類別名稱
#define ChromTabWinClass "Chrome_WidgetWin_0"
#define ChromeWidgetClass "Chrome_RenderWidgetHostHWND"



HWND winHandle; //取得瀏覽器的視窗
HWND mainWin;//取得瀏覽器主視窗

/*
取得整個盤面中，每個寶石的原始像素值。
所取得的像素值最後會儲存在plat二維陣列中。
*/
void convertOriginalColor(COLORREF plat[][ColCount]);
//取得browser的 handle
void getWindowHandle();
//取得 (x, y) 點上面的原始像素
void getOriginalColorIndex(COLORREF plat[][ColCount], int x, int y);


//初始化，取得遊戲視窗的handle，以及設定抓像素的起點。
int initial()
{
	getWindowHandle();
	if (winHandle == NULL)
		return -1;
	else
		return 1;
}

//取得盤面上的每一個寶石的顏色。
void getColors(COLORREF plat[][ColCount])
{
	getOriginalColorIndex(plat, StartX, StartY);

}

//取得 (x, y) 點上面的原始像素
void getOriginalColorIndex(COLORREF plat[][ColCount], int x, int y)
{
	//取得flash遊戲的畫布
	HDC hDc = ::GetDC(mainWin);
	HDC hComDC = ::CreateCompatibleDC(hDc);
	HBITMAP hBitMap = ::CreateCompatibleBitmap(hDc, 2000, 2000);
	::SelectObject(hComDC, hBitMap);
	BitBlt(hComDC, 0, 0, 2000, 2000, hDc, 0, 0, SRCCOPY);

	for (int i = 0; i < RowCount; i++)
	{
		for (int j = 0; j < ColCount; j++)
		{
			//取得原始的像素值
			COLORREF value = GetPixel(hComDC, x + j * GAP, y + i * GAP);
			plat[i][j] = value;
		}
	}
}

void getWindowHandle()
{
	//取得瀏覽器主視窗
	winHandle = FindWindow(_T(ChromeMainWinClass), _T(TITLESTR));
	mainWin = FindWindowEx(winHandle, NULL, _T(ChromeWidgetClass), NULL);
	mainWin = FindWindowEx(winHandle, NULL, _T(ChromTabWinClass), _T(SUBTITLESTR));
}


//點擊某個寶石
void clickPlat(int r, int c)
{
	if (c != 0 || r != 0)
	{
		int locX = StartX + c * GAP;
		int locY = StartY + r * GAP;
		printf("click location:(%d, %d)\n", locX, locY);


		//在 (fromX, fromY)的地方用滑鼠點一下
		SendMessage(winHandle, WM_LBUTTONDOWN, MK_LBUTTON, (locY << 16) | locX);
		SendMessage(winHandle, WM_LBUTTONUP, 0, (locY << 16) | locX);
	}
}