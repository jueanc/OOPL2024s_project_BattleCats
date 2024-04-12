#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include <ctime>

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
{
}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
	CAudio::Instance()->Load(AUDIO_GAME, "resources/music/TokyoHot.mp3");	//Play 遊戲音樂
	CAudio::Instance()->Play(AUDIO_GAME, true);
}

void CGameStateRun::OnMove()		// 移動遊戲元素
{
	Button.SetTopLeft();
/*
	time_t Time = time(0);
	time_t catButtonTime = 0;

	if ( Time - catButtonTime >1) {
		catButton.SetFrameIndexOfBitmap(0);
	}
	if (Time - Tank_catButtonTime > 1) {
		Tank_catButton.SetFrameIndexOfBitmap(0);
	}
	if (Cat_Counter != 0) {
		for (int i = 0; i < Cat_Counter; i++) {
			Cat[i].SetTopLeft(Cat[i].GetLeft() - 1, Cat[i].GetTop());
		}
	}
	
	if (Tank_Cat_Counter != 0) {
		for (int i = 0; i < Tank_Cat_Counter; i++) {
			Tank_Cat[i].SetTopLeft(Tank_Cat[i].GetLeft() - 1, Tank_Cat[i].GetTop());
		}
	}
	*/
	//狗移動，暫時的
	Dog[0].SetTopLeft(Dog[0].GetLeft() + 1, Dog[0].GetTop());

}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	Button.LoadBitmap();

	background.LoadBitmapByString({
	"resources/pic/grass.bmp"
		});
	background.SetTopLeft(0, 0);
	
	
	tower.LoadBitmapByString({
	"resources/tower/tower.bmp"
		}, RGB(255, 0, 0));
	tower.SetTopLeft(915, 265);

	//貓咪移動動畫

	for (int i = 0; i < 50 ;i++) {

		//敵人，暫時放的
		Dog[i].LoadBitmapByString({
		"resources/enemy/Dog/move0.bmp",
		"resources/enemy/Dog/move1.bmp",
		"resources/enemy/Dog/move2.bmp",
		"resources/enemy/Dog/move3.bmp"
			}, RGB(255, 0, 0));

		Dog[i].SetTopLeft(-10, 400);
		Dog[i].SetAnimation(50, false);
	}

}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	Button.SetClicked(point.x, point.y);
	/*
	if (Button.SetClicked == true) {



	}

	if ((point.x >= 171 && point.x <= 302) && (point.y >=580&& point.y <= 680) && (catButton.GetFrameIndexOfBitmap() == 0)) {
		catButtonTime = time(0);
		catButton.SetFrameIndexOfBitmap(1);

		Cat[Cat_Counter].SetAnimation(50, false);
		Cat_Counter += 1 ;
	}

	*/

}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnShow()
{

	background.ShowBitmap(); //草地圖

	tower.ShowBitmap();

	Dog[0].ShowBitmap();
	Button.ShowBitmap();
	//這裡是判斷貓咪按鈕是否被點擊


	/*
	for (int i = 0, i <10,i++){
	
		if (nekoButton[i].checkNowClicked != 0) {
		for (int i = 0; i < checkNowClicked; i++) {
			Cat[i].ShowBitmap();
		}
	}
	
}






	if (Cat_Counter != 0) {
		for (int i = 0; i < Cat_Counter; i++) {
			Cat[i].ShowBitmap();
		}
	}

	if (Cat_Counter != 0) {
		for (int i = 0; i < Cat_Counter; i++) {
			Cat[i].ShowBitmap();
		}
	}
	if (Tank_Cat_Counter != 0) {
		for (int i = 0; i < Tank_Cat_Counter; i++) {
			Tank_Cat[i].ShowBitmap();
		}
	}	

	
	*/

}
