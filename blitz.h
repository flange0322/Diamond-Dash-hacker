#pragma once
#include<windows.h>
#include<tchar.h>

#define GAP 40 //����_�۪����j�� 40 �ӹ���
#define RowCount 9  //�L���W���X�� row
#define ColCount 10 //�L���W���X�� column
#define StartX 530 //x�b���_�l��m
#define StartY 350 //y�b���_�l��m

//��l��
int initial();
//���o�L�����C��
void getColors(COLORREF plat[][ColCount]);
//�I���_��
//r �� row number �� 0 �}�l
//c �� column number�A�� 0 �}�l
void clickPlat(int r, int c);