#pragma once
#include "en.h"
const int EnemyNum = 10;//�G�̐�
extern En enemy[EnemyNum];//�G
extern int explodese;//����SE

void initstage1Enemy();//�G�̏�����
void updatestage1Enemy();//�G�̍X�V
void drawstage1Enemy();//�G�̕`��

void initstage2Enemy();//�G�̏�����
void updatestage2Enemy();//�G�̍X�V
void drawstage2Enemy();//�G�̕`��

void initstage3Enemy();//�G�̏�����
void updatestage3Enemy();//�G�̍X�V
void drawstage3Enemy();//�G�̕`��

bool canEnemyShot(En enemy);//�e�����Ă邩�m�F

void straightShot(int rad, En ene, int shifty);//�^����������
void aimShot(En ene);//�_���Č���

void explosion(En ene);//���������֐�

void tossin(En ene);//���̓ːi�֐�