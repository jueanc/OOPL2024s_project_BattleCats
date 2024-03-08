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
// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
{
}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
}

void CGameStateRun::OnMove()							// ���ʹC������
{
	time_t Time = time(0);
	//time_t catButtonTime = 0;

	if ( Time - catButtonTime >1) {
		catButton.SetFrameIndexOfBitmap(0);
	}

	if (Time - Tank_catButtonTime > 1) {
		Tank_catButton.SetFrameIndexOfBitmap(0);
	}
}

void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
{
	background.LoadBitmapByString({
	"resources/pic/grass.bmp",
		});
	background.SetTopLeft(0, 0);
	
	background.LoadBitmapByString({
	"resources/pic/grass.bmp",
		});
	background.SetTopLeft(0, 0);	


	catButton.LoadBitmapByString({
	"resources/pic/Cat_text.bmp",
	"resources/pic/Cat_text_dark.bmp"
		});
	catButton.SetTopLeft(171, 580);

	Tank_catButton.LoadBitmapByString({
	"resources/pic/Tank Cat_text.bmp",
	"resources/pic/Tank Cat_text_dark.bmp"
		});
	Tank_catButton.SetTopLeft(322, 580);

}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
	
	if ((point.x >= 171 && point.x <= 302) && (point.y >=580&& point.y <= 680) && (catButton.GetFrameIndexOfBitmap() == 0)) {
		catButtonTime = time(0);
		catButton.SetFrameIndexOfBitmap(1);
	}




	if ((point.x >= 322 && point.x <= 453) && (point.y >= 580 && point.y <= 680) && (Tank_catButton.GetFrameIndexOfBitmap() == 0)) {
		Tank_catButtonTime = time(0);
		Tank_catButton.SetFrameIndexOfBitmap(1);
	}

}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnShow()
{
	background.ShowBitmap();
	catButton.ShowBitmap();
	Tank_catButton.ShowBitmap();
}
