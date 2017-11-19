#ifndef COLOR_PICKER //��dinclude�h�~

#define COLOR_PICKER //�p���b�g�֘A�̖��ߌQ�ł�
#include "DxLib.h"
#include "Mouse.h"

#define PALLET 48 //�J���[�p���b�g

static int bar_img[9];
static int maker_img[2];
static int bar_img_load=0;


static int plt_img_load = 0;
static int plt_img[5];

void Plt_SetUp();


class Pallet
{
public:
	Pallet *before;	//�t�|
	Pallet *after; //���|
	Pallet(int type, int X, int Y, int num) {
		color.R = 0.001*GetRand(1000);
		color.G = 0.001*GetRand(1000);
		color.B = 0.001*GetRand(1000);
		color.A = 155 + GetRand(100);
		x = X;
		y = Y;
		if (plt_img_load == 0) {
			plt_img_load = 1;
			LoadDivGraph("img/pallet.png", 5, 5, 1, 16, 16, plt_img);
		}
		plt_num = num;
	}
	void Select_Check(Mouse *point);
	void Draw(int select1, int select2,int img[5]=plt_img);
	void Set_Color(Pallet *plt, Colorset c_set);//�w�肳�ꂽ�p���b�g�ԍ��Ɏw��F������
	int Get_num();
private:

	int on_mouse = 0;
	int x, y;
	int kind;
	int pushing = 0;//�{�^����������Ă��邩�ǂ���
	int size_x = 16; int size_y = 16;
	int plt_num;
	Colorset color;
};



class color_bar
{
public:
	color_bar(int type);
	~color_bar();
	void Set_Value(double value1, double value2);
	void Change_RGBtoHSV();
	void Change_HSVtoRGB();
	void UpDate(Mouse *point);
	void Draw();
private:
	int x, y = 0;
	int size_x = 128;
	int size_y = 16;
	double truevalue[2] = {}; //�^�̒l ��1�F��2�F�𓯎��ɏ�������
	double value[2] = {};//�l
	int kind=0;

};

inline color_bar::color_bar(int type)
{
	kind = type;
	if (bar_img_load == 0) {
		bar_img_load = 1;
		LoadDivGraph("img/colorpicker.png", 9, 1, 9, 128, 32, bar_img);
		LoadDivGraph("img/maker.png", 2, 2, 1, 7, 16, maker_img);

	}
}

inline color_bar::~color_bar()
{
}





#endif