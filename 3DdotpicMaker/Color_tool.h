#ifndef COLOR_TOOL_IN //二重include防止

#define COLOR_TOOL_IN


#include "DxLib.h"


class SelectingColor {
	int R, G, B ,A= 0;
public:
	SelectingColor() {
		R, G, B, A = 0;
	}
	void Set_SelectColor(int red, int green, int blue, int arufa);

};


struct Colorset	//色セット
{
	double R, G, B = 0.0;
	int A = 0;
};





#endif
