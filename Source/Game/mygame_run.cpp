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
	CAudio::Instance()->Load(AUDIO_GAME, "resources/music/TokyoHot.mp3");	//Play �C������
	CAudio::Instance()->Play(AUDIO_GAME, true);
}

void CGameStateRun::OnMove()		// ���ʹC������
{
	Button.SetTopLeft();

	if (Button.checkNowClicked(0)){
		Cat_Counter += 1;
	}
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
	//�����ʡA�Ȯɪ�
	/*
	
	if (1) {
		Dog[0].SetTopLeft(Dog[0].GetLeft() + 1, Dog[0].GetTop());
		for (int i = 0; i < Cat_Counter; i++) {
			Cat[i].SetTopLeft(Cat[i].GetLeft() - 1, Cat[i].GetTop());
		}
	}	
	*/


}

void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
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

	EnemyTower.LoadBitmapByString({
	"resources/tower/TowerOfSaviors.bmp"
		}, RGB(255, 0, 0));
	EnemyTower.SetTopLeft(25, 235);	




	//�߫}���ʰʵe

	for (int i = 0; i < 20 ;i++) {
		
		Cat[i].LoadBitmapByString({
		"Resources/cats/cat/move4.bmp",
		"Resources/cats/cat/move1.bmp",
		"Resources/cats/cat/move2.bmp",
		"Resources/cats/cat/move3.bmp",
			}, RGB(255, 0, 0));

		Cat[i+20].LoadBitmapByString({
		"Resources/cats/cat/attack1.bmp",
		"Resources/cats/cat/attack2.bmp",
		"Resources/cats/cat/attack3.bmp",
		"Resources/cats/cat/attack4.bmp",
		"Resources/cats/cat/attack5.bmp",
		"Resources/cats/cat/attack6.bmp",
		"Resources/cats/cat/attack7.bmp"
			}, RGB(255, 0, 0));


		//�ĤH�A�Ȯɩ�
		Dog[i].LoadBitmapByString({
		"resources/enemy/Dog/move0.bmp",
		"resources/enemy/Dog/move1.bmp",
		"resources/enemy/Dog/move2.bmp",
		"resources/enemy/Dog/move3.bmp"
			}, RGB(255, 0, 0));

		Dog[i+20].LoadBitmapByString({
		"resources/enemy/Dog/attack0.bmp",
		"resources/enemy/Dog/attack1.bmp",
		"resources/enemy/Dog/attack2.bmp",
		"resources/enemy/Dog/attack3.bmp",
		"resources/enemy/Dog/attack4.bmp",
		"resources/enemy/Dog/attack5.bmp"
			}, RGB(255, 0, 0));

		Dog[i].SetTopLeft(-50, 420);
		Dog[i].SetAnimation(50, false);
		Dog[i+20].SetAnimation(50, false);
		Cat[i].SetTopLeft(900, 420);
		Cat[i].SetAnimation(50, false);
		Cat[i + 20].SetAnimation(50, false);
	}

}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
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
	int j = 0;
	background.ShowBitmap(); //��a��
	tower.ShowBitmap();
	EnemyTower.ShowBitmap();
	Button.ShowBitmap();

	//�o�̬O�P�_�߫}���s�O�_�Q�I��
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

	if (1) {
		Dog[0].SetTopLeft(Dog[0].GetLeft() + 1, Dog[0].GetTop());
		for (int i = 0; i < Cat_Counter; i++) {
			Cat[i].SetTopLeft(Cat[i].GetLeft() - 1, Cat[i].GetTop());
		}
	}


	*/


	for (int i = 0; i < Cat_Counter; i++) {
		if (CMovingBitmap::IsOverlap(Cat[i], Dog[0]) ==1) {
	
			Cat[i+20].SetTopLeft(Cat[i].GetLeft(), 420);
			Dog[20].SetTopLeft(Dog[0].GetLeft(), 420);
			
			Cat[i+20].ShowBitmap();
			Dog[20].ShowBitmap();

		}
		else {
			Dog[0].SetTopLeft(Dog[0].GetLeft() + 1, Dog[0].GetTop());
			Cat[i].SetTopLeft(Cat[i].GetLeft() - 1, Cat[i].GetTop());
			//Cat[i].SetTopLeft(Cat[i+20].GetLeft(), 420);
			//Dog[0].SetTopLeft(Dog[20].GetLeft(), 420);

			
			Dog[0].ShowBitmap();
			Cat[i].ShowBitmap();
		}

	}



}
