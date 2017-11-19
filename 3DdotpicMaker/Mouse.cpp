#include "Mouse.h"

HaveColor::HaveColor()
{
	x = x;
	y = y;
	if (HC_img_load == 0) { //初回のみ画像の読み込み
		LoadDivGraph("img/selectcolor.png", 4, 1, 4, 128, 32, have_color_img);
		HC_img_load = 1;
	}
}

void HaveColor::UpDate(Mouse * point)
{
	color[0] = point->set_color[0];
	color[1] = point->set_color[1];
	if (point->x > x  && point->y > y && point->x < x + 16 &&point->y < y + 32) {
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
			point->newcolorsetpltnum[0] = point->set_plt[0];
			point->palletnewcolor[0] = color[0];
		}
		if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {
			point->newcolorsetpltnum[1] = point->set_plt[1];
			point->palletnewcolor[1] = color[0];
		}
	}
	if (point->x > x+112  && point->y > y && point->x < x + 128 && point->y < y + 32) {
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
			point->newcolorsetpltnum[0] = point->set_plt[0];
			point->palletnewcolor[0] = color[1];
		}
		if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {
			point->newcolorsetpltnum[1] = point->set_plt[1];
			point->palletnewcolor[1] = color[1];
		}
	}
	double dr, dg, db, da;
	dr = color[1].R - color[0].R; dg = color[1].G - color[0].G; db = color[1].B - color[0].B; da = color[1].A - color[0].A;
	for (int i = 0; i < 6; i++)
	{
		midcolor[i].R = color[0].R + dr / 7 * (i + 1);
		midcolor[i].G = color[0].G + dg / 7 * (i + 1);
		midcolor[i].B = color[0].B + db / 7 * (i + 1);
		midcolor[i].A = color[0].A + da / 7 * (i + 1);

		if (point->x > x + 16 + 16 * i && point->y > y && point->x < x + 32 + 16 * i &&point->y < y + 16) {
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 ) {
				point->newcolorsetpltnum[0] = point->set_plt[0];
				point->palletnewcolor[0] = midcolor[i];
				point->set_plt[0] = NO_PALLET;

			}
			if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {
				point->newcolorsetpltnum[1] = point->set_plt[1];
				point->palletnewcolor[1] = midcolor[i];
				point->set_plt[1] = NO_PALLET;
			}
		}

	}
	for (int i = 6; i < 9; i++)
	{
		midcolor[i].R = color[0].R + dr / 4 * (i - 5);
		midcolor[i].G = color[0].G + dg / 4 * (i - 5);
		midcolor[i].B = color[0].B + db / 4 * (i - 5);
		midcolor[i].A = color[0].A + da / 4 * (i - 5);
		if (point->x > x + 16 + 32 * (i-6) && point->y > y+16 && point->x < x + 48 + 32 * (i-6) &&point->y < y + 32) {
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
				point->newcolorsetpltnum[0] = point->set_plt[0];
				point->palletnewcolor[0].R = midcolor[i].R;
				point->palletnewcolor[0].G = midcolor[i].G;
				point->palletnewcolor[0].B = midcolor[i].B;
				point->palletnewcolor[0].A = midcolor[i].A;
				point->set_plt[0] = NO_PALLET;
			}
			if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {
				point->newcolorsetpltnum[1] = point->set_plt[1];
				point->palletnewcolor[1].R = midcolor[i].R;
				point->palletnewcolor[1].G = midcolor[i].G;
				point->palletnewcolor[1].B = midcolor[i].B;
				point->palletnewcolor[1].A = midcolor[i].A;
				point->set_plt[1] = NO_PALLET;
			}
		}
	}

/*
	//マウスがこのボタン上に乗っているか判定
	if (point->x > x && point->y > y && point->x < x + size_x &&point->y < y + size_y) {
		on_mouse = 1;

		//マウスが乗って且つこのボタンの上で押された
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && pushing == 0) {
			pushing = 1;
		}
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0) {
			if (pushing == 1) {//マウスが乗って且つこのボタンの上で離された
				pushing = 0;
				point->set_plt[0] = NO_PALLET;
				point->set_plt[1] = NO_PALLET;

			}
			else {//どこかの馬の骨のボタンが離された

			}
		}
	}
	else {
		pushing = 0;
		on_mouse = 0;
	}
	*/
}

void HaveColor::Draw(Mouse * point)
{
	DrawGraph(x, y, have_color_img[1], TRUE);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, color[1].A);
	DrawBox(x + 112, y, x + size_x, y + size_y, GetColor(color[1].R * 255, color[1].G * 255, color[1].B * 255), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, color[0].A);
	DrawBox(x, y, x + 16, y + 32, GetColor(color[0].R * 255, color[0].G * 255, color[0].B * 255), TRUE);
	for (int i = 0; i < 6; i++)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, midcolor[i].A);
		DrawBox(x + 16 + i * 16, y, x + 32 + i * 16, y + 16, GetColor(midcolor[i].R * 255, midcolor[i].G * 255, midcolor[i].B * 255), TRUE);
	}
	for (int i = 6; i < 9; i++)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, midcolor[i].A);
		DrawBox(x + 16 + (i - 6) * 32, y + 16, x + 48 + (i - 6) * 32, y + 32, GetColor(midcolor[i].R * 255, midcolor[i].G * 255, midcolor[i].B * 255), TRUE);
	}
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
	DrawGraph(x, y, have_color_img[2], TRUE);

}