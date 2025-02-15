#pragma once
#include "en.h"
const int EnemyNum = 10;//敵の数
extern En enemy[EnemyNum];//敵
extern int explodese;//爆発SE

void initstage1Enemy();//敵の初期化
void updatestage1Enemy();//敵の更新
void drawstage1Enemy();//敵の描画

void initstage2Enemy();//敵の初期化
void updatestage2Enemy();//敵の更新
void drawstage2Enemy();//敵の描画

void initstage3Enemy();//敵の初期化
void updatestage3Enemy();//敵の更新
void drawstage3Enemy();//敵の描画

bool canEnemyShot(En enemy);//弾が撃てるか確認

void straightShot(int rad, En ene, int shifty);//真っすぐ撃つ
void aimShot(En ene);//狙って撃つ

void explosion(En ene);//爆発発生関数

void tossin(En ene);//牛の突進関数