#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "nekoLibrary.h"
//#include "rivalAnimation.h"			//�ݥ��פJ�~��Ū��
#include "nekoAnimation.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// class nekoAnimation �߫}�ʵe���禡�w�q
	/////////////////////////////////////////////////////////////////////////////
	


	nekoAnimation::nekoAnimation()
	{
	}

	nekoAnimation::nekoAnimation(string name)
	{
		nekoType = name;
		nekoLibrary data(nekoType);//���ͦ����󪺪�l��

		x1 = x2 = data.originX;
		y = data.originY;
		IsAlive = true;
		isOnScreen = false;
		range = data.range;
		OriginHealth = data.health;
		health = data.health;
		attack = data.attack;
		attackDelay = data.attackDelay;		//framework�@�����10������12���N����1.2�����@��
		delay = 1;
		walkAnimationStart = data.walkAnimationStart;
		walkAnimationEnd = data.walkAnimationEnd;
		attackAnimationStart = data.attackAnimationStart;
		attackAnimationEnd = data.attackAnimationEnd;
		deathAnimationStart = data.deathAnimationStart;
		deathAnimationEnd = data.deathAnimationEnd;
		deathDelay = 0;
		deathHeightChange = data.deathHeightChange;
		moveSpeed = data.moveSpeed;
		headGap = data.headGap;
		walkAnimationSpeed = data.walkAnimationSpeed;
		attackAnimationSpeed = data.attackAnimationSpeed;
	}

	void nekoAnimation::LoadCatBitmap()
	{
		nekoLibrary data(nekoType);//���ͦ����󪺪�l��
		for (int i = 0; i < data.imageQuantity; i++)
			image.LoadBitmap(data.imageList(nekoType,i), RGB(255, 0, 0));
		image.SetAnimation(walkAnimationSpeed,false);				//�߫}�ʵe�ഫ����t��
	}

	void nekoAnimation::OnMove()
	{
		x2 = x1 + image.GetLeft();								//�NX2�]�w���Ϥ��̥k�䪺X�y��
		image.ShowBitmap();											//�߫}�ʵe�}�l�ܴ�
	}

	void nekoAnimation::ShowBitmap()
	{
		if (IsAlive == true)			//�Y�����٬��۷|��ܦb�e��
		{
			image.SetTopLeft(x1, y);								// �]�w�߫}�y��
			image.ShowBitmap();											//�K�W�߫}
			
		}
		else if (IsAlive == false && deathDelay < (deathAnimationEnd - deathAnimationStart)) {	//���h�ɭn�N���⪺Y�y�а��վ�
			image.SetTopLeft(x1, y-deathHeightChange);
			image.ShowBitmap();
			isOnScreen = false;
		}
		//���`�N����ܦb�e��
	}

	int nekoAnimation::GetX1()								//���oX(��)�y��
	{
		return x1;
	}

	int nekoAnimation::GetX2()								//���oX(�k)�y��
	{
		return x2;
	}

	int nekoAnimation::GetY()								//���oY�y��
	{
		return y;
	}

	void nekoAnimation::SetCoordinate(int NewX, int NewY)		//�]�w�y��
	{
		x1 = NewX;
		y = NewY;
	}

	void nekoAnimation::MoveForward()
	{

		die();						//�P�_��O�p�󵥩�s�A���߫h���榹���
		if (!IsAlive)				//�Y���`�N���b����H�U�{���X
			return;

		isOnScreen = true;			//�]�w����b�e���W���u
			x1 -= moveSpeed;
			x2 -= moveSpeed;
			OnMove();
	}

	bool nekoAnimation::GetIsAlive()
	{
		return IsAlive;
	}

	int nekoAnimation::GetAttack()
	{
		return attack;
	}

	int nekoAnimation::GetHealth()
	{
		return health;
	}

	void nekoAnimation::SetHealth(int NewHealth)
	{
		health = NewHealth;
	}

	int nekoAnimation::GetAnimationNumber()
	{
		return image.GetFrameIndexOfBitmap();
	}

	void nekoAnimation::SetCurrentBitmap(int x)
	{
		image.SetFrameIndexOfBitmap(x);
	}

	int nekoAnimation::GetHeadGap()
	{
		return headGap;
	}

	int nekoAnimation::GetHeadPosition()
	{
		return x1 + headGap;
	}

	void nekoAnimation::die()
	{
		if (health <= 0)					 //�P�_��O�p�󵥩�s�A���߫h���榹���
		{
			IsAlive = false;
			if (deathDelay == 0) {			//��O�p�󵥩�s�����l�����ʵe�ܦ��Ĥ@�i���h�ʵe
				image.SetAnimation(attackAnimationSpeed,false);
				image.SetFrameIndexOfBitmap(deathAnimationStart);
				deathDelay++;
				image.ShowBitmap();
			}		
			else if (deathDelay < (deathAnimationEnd - deathAnimationStart)) {	//���h�ʵe�}�l���񪽨켽��
				image.ShowBitmap();
				deathDelay++;
			}
			
		}

	}

	string nekoAnimation::GetNekoStatus()
	{
		if (isOnScreen == true) {			//�O�_�b�e���W
			return "IsOnScreen";
		}
		else if (IsAlive == true) {			//�٬��۩��٨S���X
			return "IsAlive";
		}
		else if (IsAlive == false && (deathAnimationEnd - deathAnimationStart) > deathDelay) {		//�������h�ɪ����A
			return "beak back";
		}
		else if (IsAlive == false && (deathAnimationEnd - deathAnimationStart) + 20 > deathDelay) {	//��߫}�`�ƪ�����
			deathDelay += 1;
			return "delay";
		}
		else if (IsAlive == false && (deathAnimationEnd - deathAnimationStart) + 20 == deathDelay) {//���𵲧��߫}�`�ƴ�1
			deathDelay += 1;
			return "currentNekoQuantityMinusOne";
		}
		else if ((deathAnimationEnd - deathAnimationStart) + 20 < deathDelay) {						//�w�������ȥi���U�@���߫}���N
			return "replaceable";
		}
		return "replaceable";
	}
	int nekoAnimation::GetOriginHealth()
	{
		return OriginHealth;
	}
}