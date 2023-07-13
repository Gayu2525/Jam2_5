//�G�𑀍삷��֐����������t�@�C��
#include "en.h"
#include "DxLib.h"
#include <math.h>
#include "shot.h"
#include "enemyshot.h"
#include "enemy.h"
#include "player.h"
#include "effect.h"
#include "game.h"
extern bool gameOverFlag;//�Q�[���I�[�o�[����
En enemy[EnemyNum];//�G

extern int explodese= LoadSoundMem("maou_se_battle_explosion06.mp3");//����SE

extern bool clearflag1 = false;

//�G�̏�����
void initstage1Enemy()
{
	//LoadSoundMem("maou_se_battle_explosion06.mp3");

	enemy[0].x = 900;
	enemy[0].y = 200;
	enemy[0].r = 30;
	enemy[0].color = GetColor(255, 0, 0);
	enemy[0].fill = true;
	enemy[0].enable = true;
	enemy[0].vx = -2.0;
	enemy[0].vy = 0.0;
	enemy[0].onecount = true;
	enemy[0].hakkenntime = 5;
	enemy[0].hp = 1;
	enemy[0].type = usi;


	enemy[1].x = 1500;
	enemy[1].y = 400;
	enemy[1].r = 30;
	enemy[1].color = GetColor(255, 0, 0);
	enemy[1].fill = true;
	enemy[1].enable = true;
	enemy[1].vx = -2.0;
	enemy[1].vy = 0.0;
	enemy[1].onecount = true;
	enemy[1].hakkenntime = 5;
	enemy[1].hp = 1;
	enemy[1].type = usi;

	//3�̖ڂ̓G
	enemy[2].x = 2000;
	enemy[2].y = 200;
	enemy[2].r = 30;
	enemy[2].color = GetColor(255, 0, 0);
	enemy[2].fill = true;
	enemy[2].enable = true;
	enemy[2].vx = -2.0;
	enemy[2].vy = 0.0;
	enemy[2].onecount = true;
	enemy[2].hakkenntime = 5;
	enemy[2].hp = 1;
	enemy[2].type = usi;

	//2�̖ڂ̓G
	enemy[3].x = 2500;
	enemy[3].y = 400;
	enemy[3].r = 30;
	enemy[3].color = GetColor(255, 0, 0);
	enemy[3].fill = true;
	enemy[3].enable = true;
	enemy[3].vx = -2.0;
	enemy[3].vy = 0.0;
	enemy[3].onecount = true;
	enemy[3].hakkenntime = 5;
	enemy[3].hp = 1;
	enemy[3].type = usi;

	//3�̖ڂ̓G
	enemy[4].x = 3000;
	enemy[4].y = 200;
	enemy[4].r = 30;
	enemy[4].color = GetColor(255, 0, 0);
	enemy[4].fill = true;
	enemy[4].enable = true;
	enemy[4].vx = -2.0;
	enemy[4].vy = 0.0;
	enemy[4].onecount = true;
	enemy[4].hakkenntime = 5;
	enemy[4].hp = 1;
	enemy[4].type = usi;

	//2�̖ڂ̓G
	enemy[5].x = 3500;
	enemy[5].y = 400;
	enemy[5].r = 30;
	enemy[5].color = GetColor(255, 0, 0);
	enemy[5].fill = true;
	enemy[5].enable = true;
	enemy[5].vx = -2.0;
	enemy[5].vy = 0.0;
	enemy[5].onecount = true;
	enemy[5].hakkenntime = 5;
	enemy[5].hp = 1;
	enemy[5].type = usi;

	//3�̖ڂ̓G
	enemy[6].x = 4000;
	enemy[6].y = 200;
	enemy[6].r = 30;
	enemy[6].color = GetColor(255, 0, 0);
	enemy[6].fill = true;
	enemy[6].enable = true;
	enemy[6].vx = -2.0;
	enemy[6].vy = 0.0;
	enemy[6].onecount = true;
	enemy[6].hakkenntime = 5;
	enemy[6].hp = 1;
	enemy[6].type = usi;

	//2�̖ڂ̓G
	enemy[7].x = 4500;
	enemy[7].y = 400;
	enemy[7].r = 30;
	enemy[7].color = GetColor(255, 0, 0);
	enemy[7].fill = true;
	enemy[7].enable = true;
	enemy[7].vx = -2.0;
	enemy[7].vy = 0.0;
	enemy[7].onecount = true;
	enemy[7].hakkenntime = 5;
	enemy[7].hp = 1;
	enemy[7].type = usi;

	//3�̖ڂ̓G
	enemy[8].x = 5000;
	enemy[8].y = 200;
	enemy[8].r = 30;
	enemy[8].color = GetColor(255, 0, 0);
	enemy[8].fill = true;
	enemy[8].enable = true;
	enemy[8].vx = -2.0;
	enemy[8].vy = 0.0;
	enemy[8].onecount = true;
	enemy[8].hakkenntime = 5;
	enemy[8].hp = 1;
	enemy[8].type = usi;

	//2�̖ڂ̓G
	enemy[9].x = 5500;
	enemy[9].y = 400;
	enemy[9].r = 30;
	enemy[9].color = GetColor(255, 0, 0);
	enemy[9].fill = true;
	enemy[9].enable = true;
	enemy[9].vx = -2.0;
	enemy[9].vy = 0.0;
	enemy[9].onecount = true;
	enemy[9].hakkenntime = 5;
	enemy[9].hp = 1;
	enemy[9].type = usi;
	

}
//�^�������e������
void straightShot(int rad, En ene, int shifty)
{
	//�e�������ȂƂ��̂ݏ����l���Z�b�g���L���ɂ���
	for (int j = 0; j < EnemyShotNum; j++)
	{
		//���Ă�e���݂���
		if (enemyshot[j].enable == false) {
			//�e������
			enemyshot[j].x = ene.x;
			enemyshot[j].y = ene.y + shifty;
			double PI = 3.14159265358979323846264338;
			double minrad = PI / 180.0;//1�x�̃��W�A��
			double speed = 3.0;//���x
			enemyshot[j].vx = speed * cos(minrad * rad);
			enemyshot[j].vy = speed * sin(minrad * rad);
			enemyshot[j].enable = true;
			enemyshot[j].type = ene.type;
			enemyshot[j].vvx = -enemyshot[j].vx * 0.002;
			enemyshot[j].vvy = -enemyshot[j].vy * 0.002;
			break;
		}
	}
}

//�_���Č���
void aimShot(En ene)
{
	//�e�����Ă���
//�e�������ȂƂ��̂ݏ����l���Z�b�g���L���ɂ���
	for (int j = 0; j < EnemyShotNum; j++)
	{
		//���Ă�e���݂���
		if (enemyshot[j].enable == false) {
			//�e������
			enemyshot[j].x = ene.x;
			enemyshot[j].y = ene.y;

			double speed = 3.0;//���x
			double dx = player.x - ene.x;//�v���C���[�ƓG��x�����̋���
			double dy = player.y - ene.y;//�v���C���[�ƓG��y�����̋���
			double d = sqrt(dx * dx + dy * dy);//�G�ƃv���C���[�Ƃ̋���
			enemyshot[j].vx = speed * (dx / d);//x�̈ړ���
			enemyshot[j].vy = speed * (dy / d);//y�̈ړ���
			enemyshot[j].enable = true;
			enemyshot[j].type = ene.type;
			enemyshot[j].vvx = enemyshot[j].vx * 0.01;
			enemyshot[j].vvy = enemyshot[j].vy * 0.01;
			break;
		}
	}
}

//���̓ːi�֐�
void tossin(En ene) {
	for (int j = 0; j < EnemyShotNum; j++)
	{
		if (enemy[j].onecount == true && enemy[j].type == usi && enemy[j].hakkenntime <= 0) {
			double speed = 5.0;//���x
			double dx = player.x - ene.x;//�v���C���[�ƓG��x�����̋���
			double dy = player.y - ene.y;//�v���C���[�ƓG��y�����̋���
			double d = sqrt(dx * dx + dy * dy);//�G�ƃv���C���[�Ƃ̋���
			enemy[j].vx = speed * (dx / d);//x�̈ړ���
			enemy[j].vy = speed * (dy / d);//y�̈ړ���
			enemy[j].onecount = false;
		}
	}
}

//���������֐�
void explosion(En ene)
{
	for (int i = 0; i < EffectNum; i++)
	{
		if (effe[i].enable == false)
		{
			effe[i].enable = true;
			effe[i].x = ene.x - 60;
			effe[i].y = ene.y - 60;
			effe[i].animeNo = 0;
			break;
		}
	}
}
//�G�̍X�V
void updatestage1Enemy()
{
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy[i].enable == true) {
			//�G�������œ�����
			if (enemy[i].pattern.find(enemy[i].counter) != enemy[i].pattern.end())
			{
				enemy[i].vx = enemy[i].pattern[enemy[i].counter].vx;
				enemy[i].vy = enemy[i].pattern[enemy[i].counter].vy;
			}
			enemy[i].counter++;
			enemy[i].x = enemy[i].x + enemy[i].vx;
			enemy[i].y = enemy[i].y + enemy[i].vy;

			//�e�𔭎˂���
			if (canEnemyShot(enemy[i]))
			{
				//�O�{�V���b�g
				if (enemy[i].type == ENEMY1) {
					straightShot(175, enemy[i], 0);
					straightShot(180, enemy[i], 0);
					straightShot(185, enemy[i], 0);
				}
				if (enemy[i].type == ENEMY2) {
					straightShot(180, enemy[i], -10);
					straightShot(180, enemy[i], 10);
				}
				if (enemy[i].type == ENEMY3) {
					aimShot(enemy[i]);
				}
				if (enemy[i].type == ENEMY4) {
					straightShot(180, enemy[i], 0);
				}
				if (enemy[i].type == ENEMY5) {
					straightShot(180, enemy[i], -10);
					straightShot(180, enemy[i], 10);
				}
				if (enemy[i].type == usi && player.x + 500 > enemy[i].x) {
					enemy[i].hakkenntime--;
					if (enemy[i].hakkenntime > 0) {
						enemy[i].vx = 0;
					}
					if (enemy[i].hakkenntime == 0) {
						tossin(enemy[i]);
					}
				}
				enemy[i].cooltime = 30;
			}

			if (isHit(player, enemy[i]) && player.hp == 0)
			{
				//�������Ă���
				player.hp--;
				player.inv = 150;
			}

			for (int j = 0; j < ShotNum; j++) {
				//�G�ƒe�Ƃ̓����蔻��
				if (shot[j].enable == true) {
					if (isHit(shot[j], enemy[i]))
					{
						//�������Ă���
						enemy[i].hp--;//�G�Ƀ_���[�W
						shot[j].enable = false;//�e�𖳌�
						//break;
					}
				}

				if (leaf1[j].enable == true) {
					if (isHit(leaf1[j], enemy[i]))
					{
						//�������Ă���
						enemy[i].hp--;//�G�Ƀ_���[�W
						leaf1[j].enable = false;//�e�𖳌�
						//break;
					}
				}

				if (leaf2[j].enable == true) {
					if (isHit(leaf2[j], enemy[i]))
					{
						//�������Ă���
						enemy[i].hp--;//�G�Ƀ_���[�W
						leaf2[j].enable = false;//�e�𖳌�
						//break;
					}
				}

				if (leaf3[j].enable == true) {
					if (isHit(leaf3[j], enemy[i]))
					{
						//�������Ă���
						enemy[i].hp--;//�G�Ƀ_���[�W
						leaf3[j].enable = false;//�e�𖳌�
						//break;
					}
				}

				if (leaf4[j].enable == true) {
					if (isHit(leaf4[j], enemy[i]))
					{
						//�������Ă���
						enemy[i].hp--;//�G�Ƀ_���[�W
						leaf4[j].enable = false;//�e�𖳌�
						//break;
					}
				}

			}
			//�G��HP��0�ɂȂ�����
			if (enemy[i].hp == 0) {
				enemy[i].enable = false;
				PlaySoundMem(explodese, DX_PLAYTYPE_BACK);
				explosion(enemy[i]);//����
				if (gameOverFlag == false) {
					score++;//�P�t���[�����ƂɂP�_���Z
				}
			}
			/*
			if (enemy[0].hp == 0)
			{
				clearflag1 = true;//�N���A�t���O���I���ɂ���
			}*/

			//�e���₷����
			if (enemy[i].cooltime > 0) {
				enemy[i].cooltime--;
			}
		}
	}
}

//�G�̕`��
void drawstage1Enemy()
{
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy[i].enable == true) {
			DrawCircle(enemy[i].x, enemy[i].y, enemy[i].r, enemy[i].color, enemy[i].fill);
		}
	}
}
//�e�����Ă邩�m�F����֐�
bool canEnemyShot(En enemy)
{
	//�e���₦�Ă���
	if (enemy.cooltime <= 0) {
		if (enemy.x >= 0 &&
			enemy.x < 800 &&
			enemy.y>0 &&
			enemy.y < 600)
		{
			//��ʂ̒��ɂ���
			return true;
		}
	}

	return false;
}