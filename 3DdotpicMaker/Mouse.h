#ifndef SELECT_MOUSE //��dinclude�h�~

#define SELECT_MOUSE

#include "DxLib.h"
#include "Color_tool.h"

#define MOUSE_X 16
#define MOUSE_Y 17

#define DONT_HAVE_TOOL -1 //�|�C���^�������c�[����ێ����Ă��Ȃ����



#define NO_PALLET -1	//�p���b�g�͑I������Ă��Ȃ�


static int mouse_img[16];
static int mouse_img_load = 0;

static int have_color_img[4];
static int HC_img_load = 0;

class Mouse
{

	int kind;
	void Get_Point();

public:
	Mouse();
	void Update(); //�}�C�t���[���X�V������
	void Draw();
	int x, y;
	int Set_DrawTool = DONT_HAVE_TOOL;
	int set_plt[2] = {NO_PALLET,NO_PALLET};		//�I������Ă�p���b�g
	Colorset set_color[2] = {};	//�I������Ă���F���
	int newcolorsetpltnum[2] = { -1,-1 };
	Colorset palletnewcolor[2] = {};//�p���b�g�̐V�����F
};

class HaveColor
{
public:
	HaveColor();
	void UpDate(Mouse *point);
	void Draw(Mouse *point);

private:
	int x = 320;
	int y = 576;
	int size_x = 128;
	int size_y = 32;
	int pushing=0;
	int on_mouse = 0;
	Colorset color[2];
	Colorset midcolor[9]; //���ԐF

};







inline Mouse::Mouse()//�}�E�X�̏�����
{
	kind = 0;
	if (mouse_img_load == 0) { //����̂݉摜�̓ǂݍ���
		mouse_img_load = 1;
		LoadDivGraph("img/mouse.png", 16, 4, 4, 32, 32, mouse_img);
		LoadGraph("img/selectcolor.png");
	}
}

inline void Mouse::Update()
{
	Get_Point();
}

inline void Mouse::Get_Point()
{
	GetMousePoint(&x, &y);
}

inline void Mouse::Draw()
{
	DrawGraph(x - MOUSE_X, y - MOUSE_Y, mouse_img[kind], TRUE);
}



#endif
