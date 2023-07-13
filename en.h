#pragma once
#include <map>
extern int playerimg;
extern int shotimg;
extern int leafimg;
extern bool clearflag1;//1面のクリアフラグ
extern bool clearflag2;//2面のクリアフラグ
extern bool clearflag3;//3面のクリアフラグ
enum EnemyType
{
	ENEMY1,//敵タイプ１
	ENEMY2,//敵タイプ２
	ENEMY3,//敵タイプ３
	ENEMY4,//敵タイプ４
	ENEMY5, //敵タイプ５
	usi, niwatori,
};
struct MovePattern
{
	double vx;
	double vy;
};
//円の構造体
struct En
{
	EnemyType type;//敵の種類
	double x;//X座標
	double y;//Y座標
	double r;//半径
	int color;//円の色
	bool fill;//塗りつぶすか否か
	double vx;//横の移動量
	double vy;//縦の移動量
	double vvx;//横の移動量の増量
	double vvy;//縦の移動量の増量
	bool enable;//有効フラグ（生きてるか、死んでるか）
	int cooltime;//連射できないようにするタイマー
	bool onecount;//一回だけ回す用の変数
	int hakkenntime;//見つかった時に止まるようにする
	int counter;
	int spawnTiming;//出現タイミング
	std::map<int, MovePattern> pattern;

	int hp;//体力
	int inv;//無敵時間
	int nage;

};

bool isHit(En en1, En en2);//当たり判定関数

bool isRight(En shot, En target);//進行方向の右にいるか
void RotVec(En& shot, double r);