#ifndef Enemy_h__
#define Enemy_h__

#include "cocos2d.h"
#include "Attribute.h"

USING_NS_CC;

// �G���
enum class EnemyKind
{
	ENEMY1,
	ENEMY2,
	ENEMY3,
};

// �z���Ă�̂őO���錾
class Party;
class PartyMember;

// �G�N���X
class Enemy : public Node
{
public:

	//============================================================
	// public �����o�[�֐�
	//============================================================

	// �C���X�^���X����
	static Enemy* create(EnemyKind kind);

	// ������
	bool init(EnemyKind kind);

	// �󂯂�_���[�W���v�Z����
	int calcDamage(PartyMember* partyMember);

	// �󂯂�_���[�W���v�Z����
	int calcDamage(int attackPower, Attribute attribute);

	// �s�����x�ύX�iHP�Q�[�W�̕s�����x�ύX�̂��߁j
	void setOpacity(GLubyte opacity) override;

	// �_���[�W��^����
	void applyDamage(int damage);

	// �^�[����i�߂�i�U���܂ł̎c��^�[���������炷�j
	void incrementTurn();

	// ������ԋp����B
	Attribute getAttribute();

	// ���݂�HP��ԋp����B
	int getLife();

	// �ő�HP��ԋp����
	int getMaxLife();

	// �w�肵�������Ɏア���H�i�_���[�W�{���j
	bool isValnerableTo(Attribute attribute);

	// �w�肵�������ɋ������H�i�_���[�W�����j
	bool hasResistanceTo(Attribute attribute);

	// �����Ă��邩�H
	bool isAlive();

	// �U���܂ł̎c��^�[������ԋp����B
	int getRemainingTurnForAttack();

	// �v���C���[���U������
	void attack(Party* party);

	// �U���܂ł̎c��^�[���������Z�b�g����
	void resetRemainingTurnForAttack();

private:
	//============================================================
	//�����o�[�ϐ�
	//============================================================

	// �ő僉�C�t�iHP�����l�j
	int _maxLife;
	// ���C�t�iHP�j
	int _life;
	// �Q�[�W�ɕ\������Ă��郉�C�t��
	int _displayedLife;
	// �U����
	int _attackPower;
	// ����
	Attribute _attribute;
	// �U���Ԋu�i�^�[�����j
	int _attackInterval;
	// �U���܂ł̎c��^�[����
	int _remainingTurnForAttack;
	// �U���܂ł̎c��^�[�������x��
	Label* _remainingTurnForAttackLabel;
	// ���C�t�Q�[�W
	ProgressTimer* _lifeGauge;

	//============================================================
	// private �����o�[�֐�
	//============================================================

	// �U���܂ł̎c��^�[�������x������������
	void initRemainingTurnForAttackLabel();

	// �U���܂ł̎c��^�[�������x�����X�V����
	void updateRemainingTurnForAttackLabel();
	
	// ���C�t�Q�[�W����������
	void initLifeGauge(float width);

	// ���C�t�Q�[�W�X�V
	void updateLifeGauge();

	// ���S���̏���
	void die();
};

#endif // Enemy_h__
