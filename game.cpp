#include "DxLib.h"
#include "game.h"
//ゲーム関連の情報
int score = 0;//点数
bool gameOverFlag = false;//ゲームオーバー判定

//ゲームの初期化
void initGame()
{

}
//ゲーム内容の更新
void updateGame()
{

}
//ゲーム情報の描画
void drawGame()
{
	DrawFormatString(0, 30, GetColor(255, 255, 0), "年俸 %d 円", score);

	if (gameOverFlag == true) {
		DrawFormatString(350, 300, GetColor(255, 0, 0), "ゲームオーバー");
	}
}