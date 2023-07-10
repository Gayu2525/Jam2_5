#include"DxLib.h"
#include"UI.h"
#include"player.h"
void drawUI()
{
	DrawFormatString(0, 0, GetColor(255, 255, 0), "HP %d ", player.hp);
}