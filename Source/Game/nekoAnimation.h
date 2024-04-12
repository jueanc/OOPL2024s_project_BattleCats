namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѿ߫}�ʵe
	/////////////////////////////////////////////////////////////////////////////

	class nekoAnimation 
	{
	public:
		nekoAnimation();
		nekoAnimation(string name);
		void LoadCatBitmap();						//Ū���Ϥ�
		void OnMove();							//�ʵe�}�l����
		void ShowBitmap();							//�N�ʵe��ܦb�e��
		int  GetX1();							//���o�Ϥ�X(��)�y��
		int  GetX2();							//���o�Ϥ�X(�k)�y��
		int  GetY();							//���o�Ϥ�Y�y��
		void SetCoordinate(int NewX,int NewY);	//�]�w�Ϥ��y��
		void MoveForward();//�V�e����
		bool GetIsAlive();						//���o�O�_�٬���
		int	 GetAttack();						//���o�����O
		int	 GetHealth();						//���o��O
		void SetHealth(int NewHealth);			//�����O��
		int  GetAnimationNumber();				//���o�{�b�ʵe������@�i
		void SetCurrentBitmap(int);				//�]�w�ثe�ʵe
		int  GetHeadGap();						//�^�Ǩ����ڶ��Z
		int  GetHeadPosition();					//�^�Ǩ����Y�����y��
		string GetNekoStatus();					//�^�ǿ߫}�ثe���A
		int	 GetOriginHealth();					//���o��l��O
	private:
		CMovingBitmap image;		// �߫}�ʵe����
		int x1, y;				// X(��),Y�y��
		int x2;					// X(�k)
		bool IsAlive;			// �O�_����
		int range;				// ����i�������d��
		int headGap;			// ����Ϥ��_�l��m���Z
		int health;				//����ͩR��
		int attack;				//��������O
		int attackDelay;		//��������W�v
		int delay;				//�h�p��ثe�w�gDelay�F�X��
		void die();				//�P�_��O�p�󵥩�s�A���߫h���榹���
		int walkAnimationStart;	//�Ĥ@�Ӧ樫�ʵe
		int walkAnimationEnd;	//�̫�@�Ӧ樫�ʵe
		int attackAnimationStart;//�Ĥ@�ӧ����ʵe
		int attackAnimationEnd;	//�̫�@�ӧ����ʵe
		int deathAnimationStart;//�Ĥ@�Ӧ��`�ʵe
		int deathAnimationEnd;	//�̫�@�Ӧ��`�ʵe
		int deathDelay;			//���h�ʵe����ɶ�
		int deathHeightChange;	//���h����Y�y�нվ�
		int moveSpeed;			//���Ⲿ�ʳt��
		int walkAnimationSpeed;	//�樫�ʵe�t��
		int attackAnimationSpeed;//�����ʵe�t��
		string nekoType;		//�߫}����
		bool isOnScreen;		//�P�_����O�_�b�e���W
		int OriginHealth;		//��l��O
	};
}