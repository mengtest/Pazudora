#ifndef PartyMember_h__
#define PartyMember_h__

#include "cocos2d.h"
USING_NS_CC;
#include "Enemy.h"

#include "Attribute.h"

class PartyMember : public Sprite
{
public:
	static PartyMember* create(std::string imageFileName, Attribute attribute, float attack, float cure);
	bool init(std::string imageFileName, Attribute attribute, float attack, float cure);
	Attribute getAttribute();
	int getCurePower();
	void initAttackPower();
	// �h���b�v�����ɂ��U���͂̉��Z
	// dropNum : �������h���b�v�̐�
	// 3�����̏ꍇ�́A�U���͂̑f�_�����Z�����B
	// 4�����̏ꍇ�́A�U���͂̑f�_�~1.25�{�����Z�����B
	// 5�����̏ꍇ�́A�U���͂̑f�_�~1.5�{�����Z�����B
	// 6�����̏ꍇ�́A�U���͂̑f�_�~1.75�{�����Z�����B
	// �ȉ����l
	void addAttackPowerByEraseDrop(int dropNum);
	// �R���{�ɂ��U���͂̉��Z
	// 1�R���{�̍U���͂�1�{�ł���B
	// 2�R���{�̏ꍇ��1.25�{�A
	// 3�R���{�̏ꍇ��1.5�{�A
	// 4�R���{�̏ꍇ��1.75�{�c
	// �ȉ����l
	void addAttackPowerComboRate(float amount);
	// �ςݗ��Ă��U���͂�ԋp����
	// �i�����_�ȉ��J��グ�j
	int getAttackPower();
	// �G�ɍU�����s��
	void attack(Enemy* enemy, float delay);
	// �G�S�̂ɍU�����s��
	void attackToAll(std::vector<Enemy*> eneimes, float delay);
	// �U���͑S�̍U�����H
	bool isAttackToAll();

private:
	Attribute _attribute;
	// �U���͑f�_
	float _attackBase;
	// �񕜗͑f�_
	float _cure;
	// ���݂́i�ϗ����́j�U����
	float _attackPower;
	// �R���{�ɂ��{��
	float _comboRate;
	// �U���̓��x��
	Label* _attackPowerLabel;
	// �S�̍U����
	bool _attackToAll;

	// �U���́i�_���[�W�ʁj�̕����̍X�V�i�A�j���[�V�����t���j
	void updateAttackPowerLabel(int power);
};

#endif // PartyMember_h__
