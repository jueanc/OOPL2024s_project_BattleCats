namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѿ߫}��Ų�����߫}���U�����
	// 
	/////////////////////////////////////////////////////////////////////////////

	class nekoLibrary {
	public:
		//����򥻸��
		nekoLibrary(string name);
		int range;				//����i�������d��
		int health;				//����ͩR��
		int attack;				//��������O
		int attackDelay;		//��������W�v
		int walkAnimationStart;	//�Ĥ@�Ӧ樫�ʵe
		int walkAnimationEnd;	//�̫�@�Ӧ樫�ʵe
		int attackAnimationStart;//�Ĥ@�ӧ����ʵe
		int attackAnimationEnd;	//�̫�@�ӧ����ʵe
		int deathAnimationStart;//�Ĥ@�Ӧ��`�ʵe
		int deathAnimationEnd;	//�̫�@�Ӧ��`�ʵe
		int deathHeightChange;	//���h����Y�y�нվ�
		int moveSpeed;			//���Ⲿ�ʳt��
		char *imageList(string name,int);//�^�Ǩ���Ϥ�
		int imageQuantity;		//�Ϥ��ƶq
		int headGap;			//����Ϥ��_�l��m���Z
		int originX;			//����_�lX��m
		int originY;			//����_�lY��m
		int walkAnimationSpeed;	//�樫�ʵe�t��
		int attackAnimationSpeed;//�����ʵe�t��
		int buttonDelay;		//�i���X�߫}������ɶ�
		int cost;				//���X�߫}�ݪ�O�����B
	};


}