//プレイヤーの弾を操作する関数を書いたファイル
#include "en.h"
#include "DxLib.h"
#include "shot.h"

En shot[ShotNum];//落花生
En leaf[ShotNum];//Thousant Leaf
//弾の初期化
void initShot()
{
	for (int i = 0; i < ShotNum; i++) {
		shot[i].r = 10;
		shot[i].color = GetColor(255, 255, 0);
		shot[i].fill = true;
		shot[i].vx = 10.0;
		shot[i].vy = 0.0;
		shot[i].enable = false;

		shotimg = LoadGraph("落花生.png");

		leaf[i].r = 5;
		leaf[i].color = GetColor(255, 255, 0);
		leaf[i].fill = true;
		leaf[i].vx = 5.0;
		leaf[i].vy = 2.5;
		leaf[i].enable = false;

		shotimg = LoadGraph("葉っぱ.png");
	}
}
//弾の更新
void updateShot()
{
	//弾が有効なときに弾を動かす
	for (int i = 0; i < ShotNum; i++)
	{
		if (shot[i].enable == true) {
			shot[i].x = shot[i].x + shot[i].vx;
			shot[i].y = shot[i].y + shot[i].vy;
			if (shot[i].x >= 800) {
				shot[i].enable = false;
			}
		}

		if (leaf[i].enable == true) {
			leaf[i].x = leaf[i].x + leaf[i].vx;
			leaf[i].y = leaf[i].y + leaf[i].vy;
			if (leaf[i].x >= 800 || leaf[i].y >= 600) {
				leaf[i].enable = false;
			}
		}
	}
}
//弾の描画
void drawShot()
{
	for (int i = 0; i < ShotNum; i++) {
		if (shot[i].enable == true)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 127);//半透明
			DrawCircle(shot[i].x, shot[i].y, shot[i].r, shot[i].color, shot[i].fill);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//不透明
			DrawCircle(shot[i].x, shot[i].y, shot[i].r * 0.5, shot[i].color, shot[i].fill);

			DrawGraph(shot[i].x-40, shot[i].y - 35, shotimg, true);
		}
	}
}