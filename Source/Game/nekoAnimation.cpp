#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "nekoLibrary.h"
//#include "rivalAnimation.h"			//需先匯入才能讀取
#include "nekoAnimation.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// class nekoAnimation 貓咪動畫的函式定義
	/////////////////////////////////////////////////////////////////////////////
	


	nekoAnimation::nekoAnimation()
	{
	}

	nekoAnimation::nekoAnimation(string name)
	{
		nekoType = name;
		nekoLibrary data(nekoType);//產生此物件的初始值

		x1 = x2 = data.originX;
		y = data.originY;
		IsAlive = true;
		isOnScreen = false;
		range = data.range;
		OriginHealth = data.health;
		health = data.health;
		attack = data.attack;
		attackDelay = data.attackDelay;		//framework一秒執行10次延遲12次就等於1.2秒執行一次
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
		nekoLibrary data(nekoType);//產生此物件的初始值
		for (int i = 0; i < data.imageQuantity; i++)
			image.LoadBitmap(data.imageList(nekoType,i), RGB(255, 0, 0));
		image.SetAnimation(walkAnimationSpeed,false);				//貓咪動畫轉換延遲速度
	}

	void nekoAnimation::OnMove()
	{
		x2 = x1 + image.GetLeft();								//將X2設定為圖片最右邊的X座標
		image.ShowBitmap();											//貓咪動畫開始變換
	}

	void nekoAnimation::ShowBitmap()
	{
		if (IsAlive == true)			//若角色還活著會顯示在畫面
		{
			image.SetTopLeft(x1, y);								// 設定貓咪座標
			image.ShowBitmap();											//貼上貓咪
			
		}
		else if (IsAlive == false && deathDelay < (deathAnimationEnd - deathAnimationStart)) {	//擊退時要將角色的Y座標做調整
			image.SetTopLeft(x1, y-deathHeightChange);
			image.ShowBitmap();
			isOnScreen = false;
		}
		//死亡就不顯示在畫面
	}

	int nekoAnimation::GetX1()								//取得X(左)座標
	{
		return x1;
	}

	int nekoAnimation::GetX2()								//取得X(右)座標
	{
		return x2;
	}

	int nekoAnimation::GetY()								//取得Y座標
	{
		return y;
	}

	void nekoAnimation::SetCoordinate(int NewX, int NewY)		//設定座標
	{
		x1 = NewX;
		y = NewY;
	}

	void nekoAnimation::MoveForward()
	{

		die();						//判斷體力小於等於零，成立則執行此函數
		if (!IsAlive)				//若死亡就不在執行以下程式碼
			return;

		isOnScreen = true;			//設定角色在畫面上為真
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
		if (health <= 0)					 //判斷體力小於等於零，成立則執行此函數
		{
			IsAlive = false;
			if (deathDelay == 0) {			//體力小於等於零後先初始化讓動畫變成第一張擊退動畫
				image.SetAnimation(attackAnimationSpeed,false);
				image.SetFrameIndexOfBitmap(deathAnimationStart);
				deathDelay++;
				image.ShowBitmap();
			}		
			else if (deathDelay < (deathAnimationEnd - deathAnimationStart)) {	//擊退動畫開始播放直到播完
				image.ShowBitmap();
				deathDelay++;
			}
			
		}

	}

	string nekoAnimation::GetNekoStatus()
	{
		if (isOnScreen == true) {			//是否在畫面上
			return "IsOnScreen";
		}
		else if (IsAlive == true) {			//還活著或還沒派出
			return "IsAlive";
		}
		else if (IsAlive == false && (deathAnimationEnd - deathAnimationStart) > deathDelay) {		//播放擊退時的狀態
			return "beak back";
		}
		else if (IsAlive == false && (deathAnimationEnd - deathAnimationStart) + 20 > deathDelay) {	//減掉貓咪總數的延遲
			deathDelay += 1;
			return "delay";
		}
		else if (IsAlive == false && (deathAnimationEnd - deathAnimationStart) + 20 == deathDelay) {//延遲結束貓咪總數減1
			deathDelay += 1;
			return "currentNekoQuantityMinusOne";
		}
		else if ((deathAnimationEnd - deathAnimationStart) + 20 < deathDelay) {						//已完成任務可讓下一隻貓咪取代
			return "replaceable";
		}
		return "replaceable";
	}
	int nekoAnimation::GetOriginHealth()
	{
		return OriginHealth;
	}
}