#ifndef BUTTON_IN //二重include防止

#define BUTTON_IN
#include "DxLib.h"
#include "Color_tool.h"
#include "Mouse.h"

#define BUTTON_MINE 6
#define BUTTON_DRAW_TOOL 32
#define PALLET_MAX 256

#define GET_X 0
#define GET_Y 1
#define GET_KIND 2

#define LOAD 0
#define SAVE 1
#define NEW 2



#define PALLET 48 //カラーパレット

static int button_img[256];	//ボタンの画像たち

static int button_img_load = 0;



class Button
{
public:
	Button *before;	//逆ポ
	Button *after; //順ポ
	Button(int type,int X,int Y);
	virtual void Draw(int set_draw_tool);
	int Select_Check(int mouse_x,int mouse_y,int naw_seting_tool);

	int on_mouse = 0;

//プライベートなところまで見せてくれる
	int Get_Sta(int type) {
		switch (type)
		{
		case GET_X:
			return x;
		case GET_Y:
			return y;
		case GET_KIND:
			return kind;
		default:
			return 0;
		}
	}
private:
	int x, y;
	int kind;
	int pushing = 0;//ボタンが押されているかどうか
	int size_x = 16; int size_y = 16;

};










inline Button::Button(int type, int X, int Y)
{
	x = X;
	y = Y;
	if (button_img_load == 0) {
		button_img_load = 1;
		LoadDivGraph("img/icon.png", 256, 16, 16, 16, 16, button_img);
	}
	kind = type;
}

inline void Button::Draw(int set_draw_tool)
{
	DrawGraph(x, y, button_img[kind], TRUE);
	if (on_mouse == 1) {
		DrawGraph(x, y, button_img[255], TRUE);
	}
	if (set_draw_tool == kind) {
		DrawGraph(x, y, button_img[254], TRUE);
	}
}


inline int Button::Select_Check(int mouse_x, int mouse_y,int naw_seting_tool)
{
	//マウスがこのボタン上に乗っているか判定
	if (mouse_x > x && mouse_y > y && mouse_x < x + size_x && mouse_y < y + size_y) {
		on_mouse = 1;
		
//マウスが乗って且つこのボタンの上で押された
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && pushing == 0) {
			pushing = 1;
		}
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0 ) {
			if (pushing == 1) {//マウスが乗って且つこのボタンの上で離された
				pushing = 0;
				return kind;
			}
			else {//どこかの馬の骨のボタンが離された

			}
		}
	}
	else {
		pushing = 0;
		on_mouse = 0;
	}
	return naw_seting_tool;
}



#endif
