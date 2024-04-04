#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "nekoLibrary.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѿ߫}��Ų�����߫}���U�����
	// 
	/////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////
	//��J�߫}�����]�w�ƭ�
	//
	/////////////////////////////////////////////////////////////////////////////
	nekoLibrary::nekoLibrary(string name)	
	{
		
		if (name == "Cat") {				//�߫}���
			range = 20;
			health = 100;
			attack = 1;
			attackDelay = 10;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 8;
			deathAnimationStart = 9;
			deathAnimationEnd = 16;
			deathHeightChange = 101;
			moveSpeed = 3;
			imageQuantity = 17;
			headGap = 27;		
			originX = 1511;
			originY = 640;
			walkAnimationSpeed = 2;	
			attackAnimationSpeed = 1;
			buttonDelay = 10;
			cost = 75;
		}
		else if (name == "Tank Cat") {		//��߸��
			range = 3;
			health = 1000;
			attack = 5;
			attackDelay = 20;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 9;
			deathAnimationStart = 10;
			deathAnimationEnd = 20;
			deathHeightChange = 53;
			moveSpeed = 3;
			imageQuantity = 21;
			headGap = 76;
			originX = 1511;
			originY = 580;
			walkAnimationSpeed = 2;
			attackAnimationSpeed = 1;
			buttonDelay = 20;
			cost = 150;
		}
		else if (name == "Axe Cat") {		//�԰��߸��
			range = 25;
			health = 200;
			attack = 30;
			attackDelay = 15;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 9;
			deathAnimationStart = 10;
			deathAnimationEnd = 21;
			deathHeightChange = 57;
			moveSpeed = 4;
			imageQuantity = 22;
			headGap = 30;
			originX = 1511;
			originY = 580;
			walkAnimationSpeed = 2;
			attackAnimationSpeed = 1;
			buttonDelay = 30;
			cost = 300;
		}
		else if (name == "Gross Cat") {		//���߿߸��
			range = 50;
			health = 400;
			attack = 200;
			attackDelay = 42;
			walkAnimationStart = 0;
			walkAnimationEnd = 5;
			attackAnimationStart = 6;
			attackAnimationEnd = 12;
			deathAnimationStart = 13;
			deathAnimationEnd = 24;
			deathHeightChange = 0;
			moveSpeed = 3;
			imageQuantity = 25;
			headGap = 221;
			originX = 1511;
			originY = 360;
			walkAnimationSpeed = 2;
			attackAnimationSpeed = 1;
			buttonDelay = 40;
			cost = 600;
		}
		else if (name == "Cow Cat") {		//���߸��
			range = 20;
			health = 200;
			attack = 30;
			attackDelay = 3;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 7;
			deathAnimationStart = 8;
			deathAnimationEnd = 17;
			deathHeightChange = 0;
			moveSpeed = 10;
			imageQuantity = 18;
			headGap = 51;
			originX = 1511;
			originY = 550;
			walkAnimationSpeed = 2;
			attackAnimationSpeed = 1;
			buttonDelay = 40;
			cost = 750;
		}
		else if (name == "Bird Cat") {		//���߸��
			range = 30;
			health = 300;
			attack = 140;
			attackDelay = 16;
			walkAnimationStart = 0;
			walkAnimationEnd = 3;
			attackAnimationStart = 4;
			attackAnimationEnd = 10;
			deathAnimationStart = 11;
			deathAnimationEnd = 20;
			deathHeightChange = 0;
			moveSpeed = 3;
			imageQuantity = 21;
			headGap = 112;
			originX = 1511;
			originY = 490;
			walkAnimationSpeed = 1;
			attackAnimationSpeed = 1;
			buttonDelay = 50;
			cost = 975;
		}
		else if (name == "Fish Cat") {		//���߸��
			range = 25;
			health = 1000;
			attack = 180;
			attackDelay = 17;
			walkAnimationStart = 0;
			walkAnimationEnd = 10;
			attackAnimationStart = 11;
			attackAnimationEnd = 16;
			deathAnimationStart = 17;
			deathAnimationEnd = 28;
			deathHeightChange = 0;
			moveSpeed = 3;
			imageQuantity = 29;
			headGap = 73;
			originX = 1511;
			originY = 510;
			walkAnimationSpeed = 1;
			attackAnimationSpeed = 1;
			buttonDelay = 60;
			cost = 1200;
		}
		else if (name == "Lizard Cat") {		//�h�i�߸��
			range = 100;
			health = 100;
			attack = 350;
			attackDelay = 40;
			walkAnimationStart = 0;
			walkAnimationEnd = 6;
			attackAnimationStart = 7;
			attackAnimationEnd = 12;
			deathAnimationStart = 13;
			deathAnimationEnd = 30;
			deathHeightChange = 0;
			moveSpeed = 3;
			imageQuantity = 31;
			headGap = 208;
			originX = 1511;
			originY = 550;
			walkAnimationSpeed = 1;
			attackAnimationSpeed = 1;
			buttonDelay = 70;
			cost = 1500;
		}
		else if (name == "Titan Cat") {		//�����߸��
			range = 25;
			health = 100;
			attack = 280;
			attackDelay = 22;
			walkAnimationStart = 0;
			walkAnimationEnd = 5;
			attackAnimationStart = 6;
			attackAnimationEnd = 26;
			deathAnimationStart = 27;
			deathAnimationEnd = 36;
			deathHeightChange = 0;
			moveSpeed = 2;
			imageQuantity = 37;
			headGap = 85;
			originX = 1511;
			originY = 400;
			walkAnimationSpeed = 3;
			attackAnimationSpeed = 1;
			buttonDelay = 80;
			cost = 1950;
		}
		else if (name == "Neko Base") {		//�߫}�D����
			range = 0;
			health = 1000;
			attack = 0;
			attackDelay = 0;
			walkAnimationStart = 0;
			walkAnimationEnd = 0;
			attackAnimationStart = 0;
			attackAnimationEnd = 0;
			deathAnimationStart = 0;
			deathAnimationEnd = 0;
			deathHeightChange = 0;
			moveSpeed = 0;
			imageQuantity = 1;
			headGap = 3;
			originX = 1650;
			originY = 419;
			walkAnimationSpeed = 1;
			attackAnimationSpeed = 1;
		}
	}
	/////////////////////////////////////////////////////////////////////////////
	//�߫}�Ϥ����J
	//
	/////////////////////////////////////////////////////////////////////////////
	char * nekoLibrary::imageList(string name,int imageNumber)
	{
		if (name == "Cat") {				//�߫}���
			char *temp[17] = { ".\\bitmaps\\�߫}\\�߫}\\�߫}0.bmp",".\\bitmaps\\�߫}\\�߫}\\�߫}1.bmp",".\\bitmaps\\�߫}\\�߫}\\�߫}2.bmp",".\\bitmaps\\�߫}\\�߫}\\�߫}3.bmp",".\\bitmaps\\�߫}\\�߫}\\����0.bmp",".\\bitmaps\\�߫}\\�߫}\\����1.bmp",".\\bitmaps\\�߫}\\�߫}\\����3.bmp",".\\bitmaps\\�߫}\\�߫}\\����4.bmp",".\\bitmaps\\�߫}\\�߫}\\����5.bmp",".\\bitmaps\\�߫}\\�߫}\\���h0.bmp",".\\bitmaps\\�߫}\\�߫}\\���h1.bmp",".\\bitmaps\\�߫}\\�߫}\\���h2.bmp",".\\bitmaps\\�߫}\\�߫}\\���h3.bmp",".\\bitmaps\\�߫}\\�߫}\\���h4.bmp",".\\bitmaps\\�߫}\\�߫}\\���h5.bmp",".\\bitmaps\\�߫}\\�߫}\\���h6.bmp",".\\bitmaps\\�߫}\\�߫}\\���h7.bmp" };
			return temp[imageNumber];
		}
		else if(name == "Tank Cat") {		//��߸��
			char *temp[21] = { ".\\bitmaps\\�߫}\\���\\�樫0.bmp",".\\bitmaps\\�߫}\\���\\�樫1.bmp",".\\bitmaps\\�߫}\\���\\�樫2.bmp",".\\bitmaps\\�߫}\\���\\�樫3.bmp",".\\bitmaps\\�߫}\\���\\����0.bmp",".\\bitmaps\\�߫}\\���\\����1.bmp",".\\bitmaps\\�߫}\\���\\����2.bmp",".\\bitmaps\\�߫}\\���\\����3.bmp",".\\bitmaps\\�߫}\\���\\����4.bmp",".\\bitmaps\\�߫}\\���\\����5.bmp",".\\bitmaps\\�߫}\\���\\���h0.bmp",".\\bitmaps\\�߫}\\���\\���h1.bmp",".\\bitmaps\\�߫}\\���\\���h2.bmp",".\\bitmaps\\�߫}\\���\\���h3.bmp",".\\bitmaps\\�߫}\\���\\���h4.bmp",".\\bitmaps\\�߫}\\���\\���h5.bmp",".\\bitmaps\\�߫}\\���\\���h6.bmp",".\\bitmaps\\�߫}\\���\\���h7.bmp",".\\bitmaps\\�߫}\\���\\���h8.bmp",".\\bitmaps\\�߫}\\���\\���h9.bmp",".\\bitmaps\\�߫}\\���\\���h10.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Axe Cat") {		//�԰��߸��
			char *temp[22] = { ".\\bitmaps\\�߫}\\�԰���\\�樫0.bmp",".\\bitmaps\\�߫}\\�԰���\\�樫1.bmp",".\\bitmaps\\�߫}\\�԰���\\�樫2.bmp",".\\bitmaps\\�߫}\\�԰���\\�樫3.bmp",".\\bitmaps\\�߫}\\�԰���\\����0.bmp",".\\bitmaps\\�߫}\\�԰���\\����1.bmp",".\\bitmaps\\�߫}\\�԰���\\����2.bmp",".\\bitmaps\\�߫}\\�԰���\\����3.bmp",".\\bitmaps\\�߫}\\�԰���\\����4.bmp",".\\bitmaps\\�߫}\\�԰���\\����5.bmp",".\\bitmaps\\�߫}\\�԰���\\���h0.bmp",".\\bitmaps\\�߫}\\�԰���\\���h1.bmp",".\\bitmaps\\�߫}\\�԰���\\���h2.bmp",".\\bitmaps\\�߫}\\�԰���\\���h3.bmp",".\\bitmaps\\�߫}\\�԰���\\���h4.bmp",".\\bitmaps\\�߫}\\�԰���\\���h5.bmp",".\\bitmaps\\�߫}\\�԰���\\���h6.bmp",".\\bitmaps\\�߫}\\�԰���\\���h7.bmp",".\\bitmaps\\�߫}\\�԰���\\���h8.bmp",".\\bitmaps\\�߫}\\�԰���\\���h9.bmp",".\\bitmaps\\�߫}\\�԰���\\���h10.bmp",".\\bitmaps\\�߫}\\�԰���\\���h11.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Gross Cat") {		//���߿߸��
			char *temp[25] = { ".\\bitmaps\\�߫}\\���߿�\\�樫0.bmp",".\\bitmaps\\�߫}\\���߿�\\�樫1.bmp",".\\bitmaps\\�߫}\\���߿�\\�樫2.bmp",".\\bitmaps\\�߫}\\���߿�\\�樫3.bmp",".\\bitmaps\\�߫}\\���߿�\\�樫4.bmp",".\\bitmaps\\�߫}\\���߿�\\�樫5.bmp",".\\bitmaps\\�߫}\\���߿�\\�樫4.bmp",".\\bitmaps\\�߫}\\���߿�\\����1.bmp",".\\bitmaps\\�߫}\\���߿�\\����2.bmp",".\\bitmaps\\�߫}\\���߿�\\����5.bmp",".\\bitmaps\\�߫}\\���߿�\\����6.bmp",".\\bitmaps\\�߫}\\���߿�\\����7.bmp",".\\bitmaps\\�߫}\\���߿�\\����8.bmp",".\\bitmaps\\�߫}\\���߿�\\���h0.bmp",".\\bitmaps\\�߫}\\���߿�\\���h1.bmp",".\\bitmaps\\�߫}\\���߿�\\���h2.bmp",".\\bitmaps\\�߫}\\���߿�\\���h3.bmp",".\\bitmaps\\�߫}\\���߿�\\���h4.bmp",".\\bitmaps\\�߫}\\���߿�\\���h5.bmp",".\\bitmaps\\�߫}\\���߿�\\���h6.bmp",".\\bitmaps\\�߫}\\���߿�\\���h7.bmp",".\\bitmaps\\�߫}\\���߿�\\���h8.bmp",".\\bitmaps\\�߫}\\���߿�\\���h9.bmp",".\\bitmaps\\�߫}\\���߿�\\���h10.bmp",".\\bitmaps\\�߫}\\���߿�\\���h11.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Cow Cat") {		//���߸��
			char *temp[18] = { ".\\bitmaps\\�߫}\\����\\�樫0.bmp",".\\bitmaps\\�߫}\\����\\�樫1.bmp",".\\bitmaps\\�߫}\\����\\�樫2.bmp",".\\bitmaps\\�߫}\\����\\�樫3.bmp",".\\bitmaps\\�߫}\\����\\����0.bmp",".\\bitmaps\\�߫}\\����\\����1.bmp",".\\bitmaps\\�߫}\\����\\����2.bmp",".\\bitmaps\\�߫}\\����\\����3.bmp",".\\bitmaps\\�߫}\\����\\���h0.bmp",".\\bitmaps\\�߫}\\����\\���h1.bmp",".\\bitmaps\\�߫}\\����\\���h2.bmp",".\\bitmaps\\�߫}\\����\\���h3.bmp",".\\bitmaps\\�߫}\\����\\���h4.bmp",".\\bitmaps\\�߫}\\����\\���h5.bmp",".\\bitmaps\\�߫}\\����\\���h6.bmp",".\\bitmaps\\�߫}\\����\\���h7.bmp",".\\bitmaps\\�߫}\\����\\���h8.bmp",".\\bitmaps\\�߫}\\����\\���h9.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Bird Cat") {		//���߸��
			char *temp[21] = { ".\\bitmaps\\�߫}\\����\\�樫0.bmp",".\\bitmaps\\�߫}\\����\\�樫1.bmp",".\\bitmaps\\�߫}\\����\\�樫2.bmp",".\\bitmaps\\�߫}\\����\\�樫3.bmp",".\\bitmaps\\�߫}\\����\\����0.bmp",".\\bitmaps\\�߫}\\����\\����1.bmp",".\\bitmaps\\�߫}\\����\\����2.bmp",".\\bitmaps\\�߫}\\����\\����3.bmp",".\\bitmaps\\�߫}\\����\\����4.bmp",".\\bitmaps\\�߫}\\����\\����5.bmp",".\\bitmaps\\�߫}\\����\\����6.bmp",".\\bitmaps\\�߫}\\����\\���h0.bmp",".\\bitmaps\\�߫}\\����\\���h1.bmp",".\\bitmaps\\�߫}\\����\\���h2.bmp",".\\bitmaps\\�߫}\\����\\���h3.bmp",".\\bitmaps\\�߫}\\����\\���h4.bmp",".\\bitmaps\\�߫}\\����\\���h5.bmp",".\\bitmaps\\�߫}\\����\\���h6.bmp",".\\bitmaps\\�߫}\\����\\���h7.bmp",".\\bitmaps\\�߫}\\����\\���h8.bmp",".\\bitmaps\\�߫}\\����\\���h9.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Fish Cat") {		//���߸��
			char *temp[29] = { ".\\bitmaps\\�߫}\\����\\�樫0.bmp",".\\bitmaps\\�߫}\\����\\�樫1.bmp",".\\bitmaps\\�߫}\\����\\�樫2.bmp",".\\bitmaps\\�߫}\\����\\�樫3.bmp",".\\bitmaps\\�߫}\\����\\�樫4.bmp",".\\bitmaps\\�߫}\\����\\�樫5.bmp",".\\bitmaps\\�߫}\\����\\�樫6.bmp",".\\bitmaps\\�߫}\\����\\�樫7.bmp",".\\bitmaps\\�߫}\\����\\�樫8.bmp",".\\bitmaps\\�߫}\\����\\�樫9.bmp",".\\bitmaps\\�߫}\\����\\�樫10.bmp",".\\bitmaps\\�߫}\\����\\����0.bmp",".\\bitmaps\\�߫}\\����\\����1.bmp",".\\bitmaps\\�߫}\\����\\����2.bmp",".\\bitmaps\\�߫}\\����\\����3.bmp",".\\bitmaps\\�߫}\\����\\����4.bmp",".\\bitmaps\\�߫}\\����\\����5.bmp",".\\bitmaps\\�߫}\\����\\���h0.bmp",".\\bitmaps\\�߫}\\����\\���h1.bmp",".\\bitmaps\\�߫}\\����\\���h2.bmp",".\\bitmaps\\�߫}\\����\\���h3.bmp",".\\bitmaps\\�߫}\\����\\���h4.bmp",".\\bitmaps\\�߫}\\����\\���h5.bmp",".\\bitmaps\\�߫}\\����\\���h6.bmp",".\\bitmaps\\�߫}\\����\\���h7.bmp",".\\bitmaps\\�߫}\\����\\���h8.bmp",".\\bitmaps\\�߫}\\����\\���h9.bmp",".\\bitmaps\\�߫}\\����\\���h10.bmp",".\\bitmaps\\�߫}\\����\\���h11.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Lizard Cat") {	//�h�i�߸��
			char *temp[31] = { ".\\bitmaps\\�߫}\\�h�i��\\�樫0.bmp",".\\bitmaps\\�߫}\\�h�i��\\�樫1.bmp",".\\bitmaps\\�߫}\\�h�i��\\�樫2.bmp",".\\bitmaps\\�߫}\\�h�i��\\�樫3.bmp",".\\bitmaps\\�߫}\\�h�i��\\�樫4.bmp",".\\bitmaps\\�߫}\\�h�i��\\�樫5.bmp",".\\bitmaps\\�߫}\\�h�i��\\�樫6.bmp",".\\bitmaps\\�߫}\\�h�i��\\����0.bmp",".\\bitmaps\\�߫}\\�h�i��\\����1.bmp",".\\bitmaps\\�߫}\\�h�i��\\����2.bmp",".\\bitmaps\\�߫}\\�h�i��\\����3.bmp",".\\bitmaps\\�߫}\\�h�i��\\����4.bmp",".\\bitmaps\\�߫}\\�h�i��\\����5.bmp",".\\bitmaps\\�߫}\\�h�i��\\���h0.bmp",".\\bitmaps\\�߫}\\�h�i��\\���h1.bmp",".\\bitmaps\\�߫}\\�h�i��\\���h2.bmp",".\\bitmaps\\�߫}\\�h�i��\\���h3.bmp",".\\bitmaps\\�߫}\\�h�i��\\���h4.bmp",".\\bitmaps\\�߫}\\�h�i��\\���h5.bmp",".\\bitmaps\\�߫}\\�h�i��\\���h6.bmp",".\\bitmaps\\�߫}\\�h�i��\\���h7.bmp",".\\bitmaps\\�߫}\\�h�i��\\���h8.bmp",".\\bitmaps\\�߫}\\�h�i��\\���h9.bmp",".\\bitmaps\\�߫}\\�h�i��\\���h10.bmp",".\\bitmaps\\�߫}\\�h�i��\\���h11.bmp",".\\bitmaps\\�߫}\\�h�i��\\���h12.bmp",".\\bitmaps\\�߫}\\�h�i��\\���h13.bmp",".\\bitmaps\\�߫}\\�h�i��\\���h14.bmp",".\\bitmaps\\�߫}\\�h�i��\\���h15.bmp",".\\bitmaps\\�߫}\\�h�i��\\���h16.bmp",".\\bitmaps\\�߫}\\�h�i��\\���h17.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Titan Cat") {	//�����߸��
			char *temp[37] = { ".\\bitmaps\\�߫}\\������\\�樫0.bmp",".\\bitmaps\\�߫}\\������\\�樫1.bmp",".\\bitmaps\\�߫}\\������\\�樫2.bmp",".\\bitmaps\\�߫}\\������\\�樫3.bmp",".\\bitmaps\\�߫}\\������\\�樫4.bmp",".\\bitmaps\\�߫}\\������\\�樫5.bmp",".\\bitmaps\\�߫}\\������\\����0.bmp",".\\bitmaps\\�߫}\\������\\����1.bmp",".\\bitmaps\\�߫}\\������\\����2.bmp",".\\bitmaps\\�߫}\\������\\����3.bmp",".\\bitmaps\\�߫}\\������\\����4.bmp",".\\bitmaps\\�߫}\\������\\����5.bmp",".\\bitmaps\\�߫}\\������\\����6.bmp",".\\bitmaps\\�߫}\\������\\����7.bmp",".\\bitmaps\\�߫}\\������\\����8.bmp",".\\bitmaps\\�߫}\\������\\����9.bmp",".\\bitmaps\\�߫}\\������\\����10.bmp",".\\bitmaps\\�߫}\\������\\����11.bmp",".\\bitmaps\\�߫}\\������\\����12.bmp",".\\bitmaps\\�߫}\\������\\����13.bmp",".\\bitmaps\\�߫}\\������\\����14.bmp",".\\bitmaps\\�߫}\\������\\����15.bmp",".\\bitmaps\\�߫}\\������\\����16.bmp",".\\bitmaps\\�߫}\\������\\����17.bmp",".\\bitmaps\\�߫}\\������\\����18.bmp",".\\bitmaps\\�߫}\\������\\����19.bmp",".\\bitmaps\\�߫}\\������\\����20.bmp",".\\bitmaps\\�߫}\\������\\���h0.bmp",".\\bitmaps\\�߫}\\������\\���h1.bmp",".\\bitmaps\\�߫}\\������\\���h2.bmp",".\\bitmaps\\�߫}\\������\\���h3.bmp",".\\bitmaps\\�߫}\\������\\���h4.bmp",".\\bitmaps\\�߫}\\������\\���h5.bmp",".\\bitmaps\\�߫}\\������\\���h6.bmp",".\\bitmaps\\�߫}\\������\\���h7.bmp",".\\bitmaps\\�߫}\\������\\���h8.bmp",".\\bitmaps\\�߫}\\������\\���h9.bmp" };
			return temp[imageNumber];
		}
		else if (name == "Neko Base") {	//�߫}�D����
			char *temp[1] = { ".\\bitmaps\\��\\tower.bmp" };
			return temp[imageNumber];
		}
		else {
			char *temp[1] = {".\\bitmaps\\�߫}\\�߫}\\�߫}0.bmp"};
			return temp[imageNumber];
		}
	}

}