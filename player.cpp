//プレイヤーを操作する関数を書いたファイル
#include "en.h"
#include "DxLib.h"
#include "shot.h"
#include "player.h"

En player;//プレイヤー
int shotse;//ショットSE
int leafcooltime = 0;
//プレイヤーの初期化
void initPlayer()
{
	shotse = LoadSoundMem("maou_se_battle16.mp3");
	player.x = 100;
	player.y = 200;
	player.r = 10;
	player.color = GetColor(255, 255, 255);
	player.fill = true;
	player.cooltime = 0;

	playerimg = LoadGraph("player_1.png");
}

//プレイヤーの更新
void updatePlayer()
{
	//プレイヤーを動かす
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		player.x = player.x + 3.0;
	}
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		player.x = player.x - 3.0;
	}
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		player.y = player.y - 3.0;
	}
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		player.y = player.y + 3.0;
	}
	if (player.x < 0) {
		//もし左端に出たら
		player.x = 0;
	}
	if (player.x >= 800) {
		//もし右端に出たら
		player.x = 800;
	}
	if (player.y < 0) {
		//もし左端に出たら
		player.y = 0;
	}
	if (player.y >= 600) {
		//もし右端に出たら
		player.y = 600;
	}

	//弾を撃つ処理
	if (CheckHitKey(KEY_INPUT_N) == 1)
	{
		//弾が無効なときのみ初期値をセットし有効にする
		for (int i = 0; i < ShotNum; i++)
		{
			//撃てる弾をみつける
			if (shot[i].enable == false && player.cooltime <= 0) {
				//弾を撃つ
				shot[i].x = player.x;
				shot[i].y = player.y;
				shot[i].enable = true;
				player.cooltime = 50;//連射速度　小さいほど連射できる
				PlaySoundMem(shotse, DX_PLAYTYPE_BACK);
			}
			

			if (leaf1[i].enable == false && leafcooltime <= 0) {
				
				leaf1[i].x = player.x;
				leaf1[i].y = player.y;
				leaf1[i].enable = true;
			}

			if (leaf2[i].enable == false && leafcooltime <= 0) {

				leaf2[i].x = player.x;
				leaf2[i].y = player.y;
				leaf2[i].enable = true;
			}

			if (leaf3[i].enable == false && leafcooltime <= 0) {

				leaf3[i].x = player.x;
				leaf3[i].y = player.y;
				leaf3[i].enable = true;
			}

			if (leaf4[i].enable == false && leafcooltime <= 0) {

				leaf4[i].x = player.x;
				leaf4[i].y = player.y;
				leaf4[i].enable = true;
				leafcooltime = 20;
				break;
			}
		}
	}
	//銃を冷やす処理
	if (player.cooltime > 0) {
		player.cooltime--;
	}
	if (leafcooltime > 0) {
		leafcooltime--;
	}
}

//プレイヤーの描画
void drawPlayer()
{
	DrawCircle(player.x, player.y, player.r, player.color, false);
	
	DrawGraph(player.x - 115, player.y - 60, playerimg, true);
}