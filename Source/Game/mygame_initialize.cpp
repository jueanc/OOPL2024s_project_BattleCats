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
// �o��class���C�����C���}�Y�e������
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g) : CGameState(g)
{

}

void CGameStateInit::OnInit()
{
	//
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC

	load_background();
	//
	ShowInitProgress(0, "Start Catting...");	// �@�}�l��loading�i�׬�0%

	ShowInitProgress(66, "Initialize...");
	Sleep(200);
	//
	// �}�l���J���
	//
	//Sleep(1000);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
	//
	// ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
	//
}

void CGameStateInit::OnBeginState()
{

}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) //����U����
{
	if (nChar == VK_SPACE) {
			GotoGameState(GAME_STATE_RUN);		// ������GAME_STATE_RUN
			CAudio::Instance()->Stop(AUDIO_BEGIN);
	}

}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point) //����U�ƹ�
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
	CAudio::Instance()->Load(AUDIO_BEGIN, "resources/music/beginning.mp3");	//Play �}�Y����
	CAudio::Instance()->Play(AUDIO_BEGIN, true);
}

void CGameStateInit::draw_text() {


	/*
	CDC *pDC = CDDraw::GetBackCDC();

	//* Print title 
	CTextDraw::ChangeFontLog(pDC, 36, "�L�n������", RGB(255, 255, 255));
	CTextDraw::Print(pDC, 79, 228, "Game Framework Practice");

	//* Print info 
	CTextDraw::ChangeFontLog(pDC, 24, "�L�n������", RGB(255, 255, 255));
	CTextDraw::Print(pDC, 182, 431, "Press any key to start");

	CDDraw::ReleaseBackCDC();	
	*/

}
