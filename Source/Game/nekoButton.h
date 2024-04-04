namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class������ܨ�����s����O
	// 
	/////////////////////////////////////////////////////////////////////////////

	class nekoButton {
	public:
		nekoButton();
		void LoadBitmap();				//Ū���Ϥ�
		void ShowBitmap();				//��ܹϤ�
		void SetTopLeft();				//�]�w�y��
		void SetIsClicked(int buttonNum,bool clicked);//�]�w�O�_�Q���U
		void SetClicked(int pointX,int pointY);//�]�w���U�ɪ��ʧ@
		bool checkNowClicked(int nekoNumber);				//�^�ǲ{�b�O���O���U�h����������
		int  getClickedTimes();			//���o���b����onShow�AmoveForward�AloadBitmap������ƶq
		void setClickedTimes(int number);			//�]�w���s���U����;
		int  getButtonNum(int pointX, int pointY);			//���o�Q���U���s�����X
		void updateAffordable(int currentMoney);			//��s�ثe�o���߬O�_�������������X
		bool isAffordable(int pointX, int pointY);			//�^�ǥثe�������O�_�ଣ�X�o���߫}
		int  costMoney(int nekoNumber);						//������
	private:
		static CMovingBitmap button[30];		//���s�ϧ�
		int xGap;						//���s�P���s������X���Z
		int yGap;						//���s�P���s������Y���Z
		bool isBmpLoaded;				// �O�_�w�g���J�ϧ�
		bool isClicked[10];				//���s�O�_�Q���U
		int x[10];						//���sx�y��
		int y[10];						//���sy�y��
		int buttonDelay[10];			//���s���N�o�ɶ�
		int delay[10];					//���s�ثe����ɶ�
		int clickedTimes;				//���s���U������
		int affordable[10];				//�P�_�ثe�������O�_�ଣ�X�o���߫}
		string nekoName[10] = { "Cat","Tank Cat","Axe Cat","Gross Cat","Cow Cat","Bird Cat","Fish Cat","Lizard Cat","Titan Cat" };
	};
}