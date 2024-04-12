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

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g), maxNeko(20)
{
}

CGameStateRun::~CGameStateRun()
{
	for (int i = 0; i < maxNeko; i++) {
		Neko[i] = nekoAnimation("Cat");
	}
}

void CGameStateRun::OnBeginState()
{
	CAudio::Instance()->Load(AUDIO_GAME, "resources/music/TokyoHot.mp3");	//Play �C������
	CAudio::Instance()->Play(AUDIO_GAME, true);
	for (int i = 0; i < maxNeko; i++) {
		Neko[i] = nekoAnimation("Cat");
	}
}

void CGameStateRun::OnMove()		// ���ʹC������
{
	Button.SetTopLeft();
	time_t Time = time(0);
	//time_t catButtonTime = 0;

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
	//�����ʡA�Ȯɪ�
	Dog[0].SetTopLeft(Dog[0].GetLeft() + 1, Dog[0].GetTop());

	currentNekoQuantity = 0;
	for (int i = 0; i < maxNeko; i++) {
		if (Neko[i].GetNekoStatus() == "IsOnScreen") {		//�p��{�b�b�e���W���߫}
			currentNekoQuantity += 1;
		}
	}

}

void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
{
	Button.LoadBitmap();

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

	//�߫}���ʰʵe

	for (int i = 0; i < 50 ;i++) {
		Cat[i].LoadBitmapByString({
		"resources/cats/cat/move1.bmp",
		"resources/cats/cat/move2.bmp",
		"resources/cats/cat/move3.bmp",
		"resources/cats/cat/move4.bmp",
		"resources/cats/cat/move5.bmp",
			},RGB(255, 0, 0));
		Cat[i].SetTopLeft(800, 400);

		Tank_Cat[i].LoadBitmapByString({
		"resources/cats/Tank_cat/move1.bmp",
		"resources/cats/Tank_cat/move2.bmp",
		"resources/cats/Tank_cat/move3.bmp",
		"resources/cats/Tank_cat/move4.bmp"
			}, RGB(255, 0, 0));
		Tank_Cat[i].SetTopLeft(800, 330);

		//�ĤH�A�Ȯɩ�
		Dog[i].LoadBitmapByString({
		"resources/enemy/Dog/move0.bmp",
		"resources/enemy/Dog/move1.bmp",
		"resources/enemy/Dog/move2.bmp",
		"resources/enemy/Dog/move3.bmp"
			}, RGB(255, 0, 0));

		Dog[i].SetTopLeft(-10, 400);
		Dog[i].SetAnimation(50, false);

		for (int i = 0; i < maxNeko; i++) {
			Neko[i].LoadCatBitmap();
		}
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

	if ((point.x >= 171 && point.x <= 302) && (point.y >=580&& point.y <= 680) && (catButton.GetFrameIndexOfBitmap() == 0)) {
		catButtonTime = time(0);
		catButton.SetFrameIndexOfBitmap(1);

		Cat[Cat_Counter].SetAnimation(50, false);
		Cat_Counter += 1 ;
	}

	if ((point.x >= 322 && point.x <= 453) && (point.y >= 580 && point.y <= 680) && (Tank_catButton.GetFrameIndexOfBitmap() == 0)) {
		Tank_catButtonTime = time(0);
		Tank_catButton.SetFrameIndexOfBitmap(1);

		Tank_Cat[Tank_Cat_Counter].SetAnimation(50, false);
		Tank_Cat_Counter += 1;		
	}

}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
	string nekoName[10] = { "Cat","Tank Cat","Axe Cat","Gross Cat","Cow Cat","Bird Cat","Fish Cat","Lizard Cat","Titan Cat","Cat" };
	//eraser.SetMovingLeft(false);
	if (currentNekoQuantity < maxNeko && Button.isAffordable(point.x, point.y)) {//�ثe�߫}�ƶq�p��maxNeko�Υثe���B�O���������U�~������
		Button.SetClicked(point.x, point.y);			//�B�z���U���s���ʧ@
		for (int i = 0; i < 10; i++) {
			int findDisappearNeko = 0;					//��XNeko�}�C���@�ӿ߫}�w���h���ܼ�	
			if (Button.checkNowClicked(i) == true) {	//���U���s�������ΧP�_��������
				if (activateNeko < maxNeko) {			//�p�G�w���X���߫}�p��20���AreadyToFightNeko�N�̧ǥ[�@
					readyToFightNeko += 1;
					currentNekoQuantity += 1;			//�ثe�e���W�߫}�`�ƥ[�@
					Neko[readyToFightNeko] = nekoAnimation(nekoName[Button.getButtonNum(point.x, point.y)]);//�ǤJ�߫}���W�r�M����J�߫}���
					Neko[readyToFightNeko].LoadCatBitmap();		//�hŪ���ӿ߫}���Ϥ�
				}
			}
		}
	}
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

	Button.ShowBitmap();
	background.ShowBitmap(); //��a��
	catButton.ShowBitmap(); //�߫}���s
	Tank_catButton.ShowBitmap();
	Dog[0].ShowBitmap();
	for (int i = 0; i < activateNeko; i++) {
		Neko[i].ShowBitmap();
	}

	//�o�̬O�P�_�߫}���s�O�_�Q�I��
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


}
