#pragma once
#include "en.h"
const int EnemyNum = 10;//“G‚Ì”
extern En enemy[EnemyNum];//“G
extern int explodese;//”š”­SE

void initstage1Enemy();//“G‚Ì‰Šú‰»
void updatestage1Enemy();//“G‚ÌXV
void drawstage1Enemy();//“G‚Ì•`‰æ

void initstage2Enemy();//“G‚Ì‰Šú‰»
void updatestage2Enemy();//“G‚ÌXV
void drawstage2Enemy();//“G‚Ì•`‰æ

void initstage3Enemy();//“G‚Ì‰Šú‰»
void updatestage3Enemy();//“G‚ÌXV
void drawstage3Enemy();//“G‚Ì•`‰æ

bool canEnemyShot(En enemy);//’e‚ªŒ‚‚Ä‚é‚©Šm”F

void straightShot(int rad, En ene, int shifty);//^‚Á‚·‚®Œ‚‚Â
void aimShot(En ene);//‘_‚Á‚ÄŒ‚‚Â

void explosion(En ene);//”š”­”­¶ŠÖ”