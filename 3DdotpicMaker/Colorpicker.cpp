#include "Colorpicker.h"




void Pallet::Select_Check(Mouse * point)
{
	//マウスがこのボタン上に乗っているか判定
	if (point->x > x &&point->y > y && point->x < x + size_x && point->y < y + size_y) {
		on_mouse = 1;

		//マウスが乗って且つこのボタンの上で押された
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && pushing == 0) {
			pushing = 1;
		}
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0) {
			if (pushing == 1) {//マウスが乗って且つこのボタンの上で離された
				pushing = 0;
				point->set_plt[1] = plt_num;
				point->set_color[1] = color;
			}
			else {//どこかの馬の骨のボタンが離された

			}
		}
		if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0 && pushing == 0) {
			pushing = 1;
		}
		if ((GetMouseInput() & MOUSE_INPUT_RIGHT) == 0) {
			if (pushing == 1) {//マウスが乗って且つこのボタンの上で離された
				pushing = 0;
				point->set_plt[0] = plt_num;
				point->set_color[0] = color;
			}
			else {//どこかの馬の骨のボタンが離された

			}
		}
	}
	else {
		pushing = 0;
		on_mouse = 0;
	}
}



void Pallet::Draw(int select1, int select2, int img[5])
{
	DrawGraph(x, y, img[0], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, color.A);
	DrawBox(x, y, x + size_x, y + size_y, GetColor(color.R * 255, color.G * 255, color.B * 255), TRUE);
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
	DrawGraph(x, y, img[1], TRUE);

	if (on_mouse == 1) {
		DrawGraph(x, y, img[4], TRUE);
	}
	if (select1 == plt_num || select2 == plt_num) {
		DrawGraph(x, y, img[3], TRUE);
	}
}

void Pallet::Set_Color(Pallet * plt, Colorset c_set)
{
	plt->color = c_set;
}


int Pallet::Get_num()
{
	return plt_num;
}



void color_bar::Set_Value(double value1, double value2)
{
	truevalue[0] = value1;
	truevalue[1] = value2;
}

void color_bar::UpDate(Mouse * point)
{
	if (point->x > x && point->y > y && point->x < x + size_x && point->y < y + size_y) {
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
			truevalue[0] = (point->x - x) / size_x;
		}
		if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {
			truevalue[1] = (point->x - x) / size_x;
		}
	}


	for (int i = 0; i < 2; i++)
	{
		if (truevalue[i] > 1) {
			truevalue[i] = 1.0;
		}
		if (truevalue[i] < 0) {
			truevalue[i] = 0.0;
		}
		value[i] += (truevalue[i] - value[i]) / 10;
	}

}


void color_bar::Draw()
{
	DrawGraph(x, y, bar_img[8], TRUE);
	DrawGraph(value[0] * size_x + x - 8, y, maker_img[0], TRUE);
	DrawGraph(value[1] * size_x + x - 8, y, maker_img[1], TRUE);

	DrawGraph(x, y, bar_img[kind], TRUE);
	

}