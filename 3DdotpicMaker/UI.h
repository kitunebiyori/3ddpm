#ifndef UI //二重include防止

#define UI

//表示などのUI周りの処理を行いたいときの命令群

#include "DxLib.h"

#define NUMIMG_X 8

static int num_img[10];	

void UI_SetUp();//UI周りの初期化

void Draw_Num(int x, int y, int num);//1桁目の右上座標を代入する

#endif
