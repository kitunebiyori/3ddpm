#ifndef MAIN_IN //ìÒèdincludeñhé~

#define MAIN_IN

#include "DxLib.h"
#include "Mouse.h"
#include "Button.h"
#include "DrawTool.h"
#include "Colorpicker.h"
void Main_loop();

void Set_Button();



void Create_Button(	Button *botan);
void Create_Pallet(Pallet *paretto);
void Pallet_Tool(Mouse *point);

#endif