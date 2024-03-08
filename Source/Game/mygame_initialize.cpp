#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include <time.h>

using namespace game_framework;
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g) : CGameState(g)
{

}

void CGameStateInit::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。

	load_background();
	//
	ShowInitProgress(0, "Start Catting...");	// 一開始的loading進度為0%

	ShowInitProgress(66, "Initialize...");
	Sleep(200);
	//
	// 開始載入資料
	//
	//Sleep(1000);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
	//
}

void CGameStateInit::OnBeginState()
{

}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) //當按下按鍵
{
	if (nChar == VK_SPACE) {
			GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
			CAudio::Instance()->Stop(AUDIO_BEGIN);
	}

}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point) //當按下滑鼠
{
	if ((point.x >= 350 && point.x <= 750) && (point.y >= 380 && point.y <= 460)) {
		GotoGameState(GAME_STATE_RUN);
		CAudio::Instance()->Stop(AUDIO_BEGIN);
	}
}

void CGameStateInit::OnShow()
{
	background.ShowBitmap();
	draw_text();
}

void CGameStateInit::load_background() {
	background.LoadBitmapByString({ "resources/pic/main.bmp" });
	background.SetTopLeft(0, 0);
	CAudio::Instance()->Load(AUDIO_BEGIN, "resources/music/beginning.mp3");	//Play 開頭音樂
	CAudio::Instance()->Play(AUDIO_BEGIN, true);
}

void CGameStateInit::draw_text() {


	/*
	CDC *pDC = CDDraw::GetBackCDC();

	//* Print title 
	CTextDraw::ChangeFontLog(pDC, 36, "微軟正黑體", RGB(255, 255, 255));
	CTextDraw::Print(pDC, 79, 228, "Game Framework Practice");

	//* Print info 
	CTextDraw::ChangeFontLog(pDC, 24, "微軟正黑體", RGB(255, 255, 255));
	CTextDraw::Print(pDC, 182, 431, "Press any key to start");

	CDDraw::ReleaseBackCDC();	
	*/

}
