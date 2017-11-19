#include "Main.h"



Button	*B_Head = NULL;	// 先頭
Button	*B_Tail = NULL;	// 最後尾
Button	*button;
Button *botan = B_Head;
Pallet *P_Head = NULL;
Pallet *P_Tail = NULL;
Pallet *pallet;
Pallet *paretto = P_Head;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(960, 720, 16);
	ChangeWindowMode(TRUE); // ウィンドウモードに設定
	if (DxLib_Init() == -1)    // ＤＸライブラリ初期化処理
	{
		return -1;    // エラー終了
	}





	Main_loop();




	DxLib_End();        // ＤＸライブラリ使用の終了処理

	return 0;        // ソフトの終了
}

void Main_loop()
{
	Mouse point;
	Set_Button();
	HaveColor HC;

	SetMouseDispFlag(FALSE);// カーソルは消滅する
	while (ScreenFlip() == 0 && ProcessMessage() == 0)
	{
		ClearDrawScreen(); // 画面を消す
		DrawBox(0, 0, 961, 721, GetColor(180,180,180), TRUE);


		botan = B_Head;
		while (botan != NULL)
		{
			point.Set_DrawTool = botan->Select_Check(point.x, point.y, point.Set_DrawTool);
			botan->Draw(point.Set_DrawTool);
			botan = botan->after;
		}
		paretto = P_Head;
		while (paretto!=NULL)
		{
			for (int i = 0; i < 2; i++)
			{
				if (point.newcolorsetpltnum[i] == paretto->Get_num()) {
					paretto->Set_Color(paretto, point.palletnewcolor[i]);
					point.newcolorsetpltnum[i] = -1;//色セットのリセット
				}
			}
			paretto->Select_Check(&point);
			paretto->Draw(point.set_plt[0], point.set_plt[1]);
			paretto = paretto->after;
		}
		HC.UpDate(&point);
		HC.Draw(&point);
		point.Update();
		point.Draw();


		SetDrawMode(DX_DRAWMODE_NEAREST);
		SetDrawScreen(DX_SCREEN_BACK);
	}
}




void Set_Button()
{
	//ボタンの生成
	for (int i = 0; i < BUTTON_MINE; i++)
	{
		button = new Button(i, 16 * i, 0);
		Create_Button(button);
	}
	for (int i = 0; i < BUTTON_DRAW_TOOL; i++)
	{
		button = new Button(16 + i, 448 + 16 * i, 16);
		Create_Button(button);
	}
	int p_count = 0;//パレットの番号札 0~
	for (int i = 0; i < 8; i++)
	{
		for (int t = 0; t < 32; t++)
		{
			pallet = new Pallet(PALLET, 320 + 16 * i, 48 + 16 * t, p_count);
			Create_Pallet(pallet);
			p_count++;
		}

	}
}

void Create_Button(Button *botan)
{
	if (!B_Head) {
		B_Head = botan;
	}
	if (B_Tail) {
		B_Tail->after = botan;
	}
	botan->before = B_Tail;
	botan->after = NULL;
	B_Tail = botan;
}

void Create_Pallet(Pallet * paretto)
{
	if (!P_Head) {
		P_Head = paretto;
	}
	if (P_Tail) {
		P_Tail->after = paretto;
	}
	paretto->before = P_Tail;
	paretto->after = NULL;
	P_Tail = paretto;
}

void Pallet_Tool(Mouse * point)
{
}
