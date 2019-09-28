#include "blitz.h"
#include<stdio.h>
#include <Windows.h>
#define TITLESTR "Diamond Dash �b Facebook �W - Google Chrome" //Browser�����D
#define SUBTITLESTR "Diamond Dash �b Facebook �W"
#define ChromeMainWinClass "Chrome_WidgetWin_1"  //Chrome�����O�W��
#define ChromTabWinClass "Chrome_WidgetWin_0"
#define ChromeWidgetClass "Chrome_RenderWidgetHostHWND"



HWND winHandle; //���o�s����������
HWND mainWin;//���o�s�����D����

/*
���o��ӽL�����A�C���_�۪���l�����ȡC
�Ҩ��o�������ȳ̫�|�x�s�bplat�G���}�C���C
*/
void convertOriginalColor(COLORREF plat[][ColCount]);
//���obrowser�� handle
void getWindowHandle();
//���o (x, y) �I�W������l����
void getOriginalColorIndex(COLORREF plat[][ColCount], int x, int y);


//��l�ơA���o�C��������handle�A�H�γ]�w�칳�����_�I�C
int initial()
{
	getWindowHandle();
	if (winHandle == NULL)
		return -1;
	else
		return 1;
}

//���o�L���W���C�@���_�۪��C��C
void getColors(COLORREF plat[][ColCount])
{
	getOriginalColorIndex(plat, StartX, StartY);

}

//���o (x, y) �I�W������l����
void getOriginalColorIndex(COLORREF plat[][ColCount], int x, int y)
{
	//���oflash�C�����e��
	HDC hDc = ::GetDC(mainWin);
	HDC hComDC = ::CreateCompatibleDC(hDc);
	HBITMAP hBitMap = ::CreateCompatibleBitmap(hDc, 2000, 2000);
	::SelectObject(hComDC, hBitMap);
	BitBlt(hComDC, 0, 0, 2000, 2000, hDc, 0, 0, SRCCOPY);

	for (int i = 0; i < RowCount; i++)
	{
		for (int j = 0; j < ColCount; j++)
		{
			//���o��l��������
			COLORREF value = GetPixel(hComDC, x + j * GAP, y + i * GAP);
			plat[i][j] = value;
		}
	}
}

void getWindowHandle()
{
	//���o�s�����D����
	winHandle = FindWindow(_T(ChromeMainWinClass), _T(TITLESTR));
	mainWin = FindWindowEx(winHandle, NULL, _T(ChromeWidgetClass), NULL);
	mainWin = FindWindowEx(winHandle, NULL, _T(ChromTabWinClass), _T(SUBTITLESTR));
}


//�I���Y���_��
void clickPlat(int r, int c)
{
	if (c != 0 || r != 0)
	{
		int locX = StartX + c * GAP;
		int locY = StartY + r * GAP;
		printf("click location:(%d, %d)\n", locX, locY);


		//�b (fromX, fromY)���a��ηƹ��I�@�U
		SendMessage(winHandle, WM_LBUTTONDOWN, MK_LBUTTON, (locY << 16) | locX);
		SendMessage(winHandle, WM_LBUTTONUP, 0, (locY << 16) | locX);
	}
}