#ifndef EnemyParty_h__
#define EnemyParty_h__

#include "cocos2d.h"
#include "Enemy.h"

USING_NS_CC;

class Party;

class EnemyParty : public Node
{
public:
	//============================================================
	// public �����o�[�֐�
	//============================================================

	// �C���X�^���X����
	static EnemyParty* create();
	bool init();

	// �����Ă��邷�ׂĂ̓G��ԋp����B
	const std::vector<Enemy*> getActiveEnemies();

	// �^�[����i�߂�i�U���܂ł̎c��^�[���������炷�j
	void incrementTurn();

	// �e�����o�[�̍U���B
	// �U���܂ł̎c��^�[�������[���̃����X�^�[�ɍU����������B
	// onComplete : �G�̍U���������Ɏ��{���鏈����n���B
	void attack(Party* party, std::function<void()> onComplete);

	// �S�ł������H
	bool isWipedOut();

private:
	//============================================================
	//�����o�[�ϐ�
	//============================================================

	std::vector<Enemy*> _enemies;

	//============================================================
	// private �����o�[�֐�
	//============================================================

	void alignCenter();

};


#endif // EnemyParty_h__
