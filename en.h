#pragma once
#include <map>
extern int playerimg;
extern int shotimg;
extern int leafimg;
extern bool clearflag1;//1�ʂ̃N���A�t���O
extern bool clearflag2;//2�ʂ̃N���A�t���O
extern bool clearflag3;//3�ʂ̃N���A�t���O
enum EnemyType
{
	ENEMY1,//�G�^�C�v�P
	ENEMY2,//�G�^�C�v�Q
	ENEMY3,//�G�^�C�v�R
	ENEMY4,//�G�^�C�v�S
	ENEMY5, //�G�^�C�v�T
	usi, niwatori,
};
struct MovePattern
{
	double vx;
	double vy;
};
//�~�̍\����
struct En
{
	EnemyType type;//�G�̎��
	double x;//X���W
	double y;//Y���W
	double r;//���a
	int color;//�~�̐F
	bool fill;//�h��Ԃ����ۂ�
	double vx;//���̈ړ���
	double vy;//�c�̈ړ���
	double vvx;//���̈ړ��ʂ̑���
	double vvy;//�c�̈ړ��ʂ̑���
	bool enable;//�L���t���O�i�����Ă邩�A����ł邩�j
	int cooltime;//�A�˂ł��Ȃ��悤�ɂ���^�C�}�[
	bool onecount;//��񂾂��񂷗p�̕ϐ�
	int hakkenntime;//�����������Ɏ~�܂�悤�ɂ���
	int counter;
	int spawnTiming;//�o���^�C�~���O
	std::map<int, MovePattern> pattern;

	int hp;//�̗�
	int inv;//���G����
	int nage;

};

bool isHit(En en1, En en2);//�����蔻��֐�

bool isRight(En shot, En target);//�i�s�����̉E�ɂ��邩
void RotVec(En& shot, double r);