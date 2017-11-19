#include "UI.h"

void UI_SetUp()
{
	LoadDivGraph("img/num.png",10,10,1,8,12,num_img);
}

void Draw_Num(int x, int y, int num)
{
	int printnum = 0;
	num = abs(num);//マイナスは処理できないので絶対値をとる
	while (num >= 10)
	{
		printnum = num % 10;
		num -= printnum;
		DrawGraph(x - NUMIMG_X, y, num_img[printnum], TRUE);
	}
	DrawGraph(x - NUMIMG_X, y, num_img[num], TRUE);
}

void Draw_Base() { //基本UIの表示

}
