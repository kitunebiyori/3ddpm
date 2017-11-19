#ifndef COLER_IN //二重include防止

#define COLER_IN


#include "DxLib.h"

#define COLOR_R 0
#define COLOR_G 1
#define COLOR_B 2
#define COLOR_H 0
#define COLOR_S 1
#define COLOR_V 2
#define COLOR_A 3

int max_color;//最大値をとっている色の定数を代入する
int min_color;//最小値をとっている色の定数を代入する


class RGBset
{
public:
	RGBset(double h, double s, double v,int a);
	~RGBset();
	void set_RGB();
private:
	int x = 448;
	int y = 576;
	int color[4] = {};

};

RGBset::RGBset(double h, double s, double v, int a)
{
	float r = v;
	float g = v;
	float b = v;
	if (s > 0.0f) {
		h *= 6.0f;
		int i = (int)h;
		float f = h - (float)i;
		switch (i) {
		default:
		case 0:
			g *= 1 - s * (1 - f);
			b *= 1 - s;
			break;
		case 1:
			r *= 1 - s * f;
			b *= 1 - s;
			break;
		case 2:
			r *= 1 - s;
			b *= 1 - s * (1 - f);
			break;
		case 3:
			r *= 1 - s;
			g *= 1 - s * f;
			break;
		case 4:
			r *= 1 - s * (1 - f);
			g *= 1 - s;
			break;
		case 5:
			g *= 1 - s;
			b *= 1 - s * f;
			break;
		}
	}
	color[COLOR_R] = r * 255;
	color[COLOR_G] = g * 255;
	color[COLOR_B] = b * 255;

}

RGBset::~RGBset()
{
}




class HSVset
{
public:
	HSVset(int r,int g,int b,int a);
	~HSVset();
	void set_HSV();
private:

	int x = 448;
	int y = 576;
	double color[4] = {};
};

HSVset::HSVset(int r, int g, int b, int a)
{
	float max = r > g ? r : g;
	max = max > b ? max : b;
	float min = r < g ? r : g;
	min = min < b ? min : b;
	color[COLOR_H] = max - min;
	if (color[COLOR_H] > 0.0f) {
		if (max == r) {
			color[COLOR_H] = (g - b) / color[COLOR_H];
			if (color[COLOR_H] < 0.0f) {
				color[COLOR_H] += 6.0f;
			}
		}
		else if (max == g) {
			color[COLOR_H] = 2.0f + (b - r) / color[COLOR_H];
		}
		else {
			color[COLOR_H] = 4.0f + (r - g) / color[COLOR_H];
		}
	}
	color[COLOR_H] /= 6.0f;
	color[COLOR_S] = (max - min);
	if (max != 0.0f)
		color[COLOR_S] /= max;
	color[COLOR_V] = max;
	color[COLOR_A] = a;
}

HSVset::~HSVset()
{
}

#endif
