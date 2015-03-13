#ifndef Party_h__
#define Party_h__

#include "cocos2d.h"
USING_NS_CC;

#include "PartyMember.h"
#include "EnemyParty.h"
#include "Enemy.h"

class Party : public Node
{
private:
	// �G�̎c��HP�ꎞ�ۑ��p�e�[�u���B
	// �U���Ώۂ����߂鎞�Ɏg���B
	// key=�G, value=�c��HP
	typedef std::map<Enemy*, int> EnemyLifeTable;

public:
	static Party* create();
	bool init();

	// �h���b�v�����ɂ��U���͂���щ񕜗ʂ̉��Z
	// dropNum : �������h���b�v�̐�
	// 3�����̏ꍇ�́A�U���͂̑f�_�����Z�����B
	// 4�����̏ꍇ�́A�U���͂̑f�_�~1.25�{�����Z�����B
	// 5�����̏ꍇ�́A�U���͂̑f�_�~1.5�{�����Z�����B
	// 6�����̏ꍇ�́A�U���͂̑f�_�~1.75�{�����Z�����B
	// �ȉ����l�B�񕜂ɂ��Ă����l�B
	void addPowerByEraseDrop(Attribute attribute, int dropNum);

	// �R���{�ɂ��U���͂̉��Z
	// 1�R���{�̍U���͂�1�{�ł���B
	// 2�R���{�̏ꍇ��1.25�{�A
	// 3�R���{�̏ꍇ��1.5�{�A
	// 4�R���{�̏ꍇ��1.75�{�c
	// �ȉ����l�B�񕜂ɂ��Ă����l�B
	void addComboRate(float amount);

	// �e�����o�[�̒~�ς��ꂽ�U���͂�����������
	void initMembersAttackPower();

	// �p�[�e�B�Ƀ_���[�W��^����i�H�炤�j
	void applyDamage(int damage);
	
	// �h���b�v�����ɂ��A�U���́i�܂��͉񕜗́j���`���[�W����鎞�̃G�t�F�N�g�𔭐�������
	void fireChargeEffect(const Vec2& startPosition, Attribute attribute);

	// �S�����o�[��ԋp����
	const std::vector<PartyMember*> getMembers();

	// �����p�[�e�B���G�p�[�e�B���U�������A�̗�������{����B
	// �i�U���Ώۂ̌���A�U���G�t�F�N�g�̔����A�_���[�W���f�A�G���Łj
	// �߂�l�Ƃ��āA�S�U������������̂ɗv���鎞�ԁi�b�j��ԋp����B
	float doAttackSequence(EnemyParty* enemyParty);

	// �ǂ̓G�ɍU�����s���΂悢�������肵�A�U���Ώۂ̓G��ԋp����B
	// �ȉ��A��ɂ���قǗD��x��
	// �E�ꌂ�œ|���鍂HP�̓G
	// �E�ꌂ�œ|�����HP�̓G
	// �E�ꌂ�ł͓|���Ȃ���HP�̓G
	// �E�ꌂ�ł͓|���Ȃ���HP�̓G
	Enemy* decideAttackTarget(std::vector<Enemy*> enemies, EnemyLifeTable enemyLifeTable, PartyMember* member);

	// �����Ă��邩�H
	bool isAlive();

private:
	// �p�[�e�B�[�����o�[�̔z��
	std::vector<PartyMember*> _members;
	// ���C�t�Q�[�W
	ProgressTimer* _lifeGauge;
	int _maxLife;
	int _life;
	// �񕜗ʑf�_
	int _curePowerBase;
	// �ςݗ��Ă��񕜗�
	int _curePower;
	// �񕜗ʃR���{��
	float _cureComboRate;
	// �񕜗ʃ��x��
	Label* _curePowerLabel;

	void loadMembers();
	// ���C�t�Q�[�W���X�V����
	void updateLifeGauge(int newValue, int maxValue);
	void addAttackPowerByEraseDrop(Attribute attribute, int dropNum);
	void addCurePowerByEraseDrop(int dropNum);
	void addCurePowerRate(float amount);
	void initCurePowerLabel();
	void updateCurePowerLabel(int newValue);
	void initLifeGauge();
	int getCurePower();

	// �w�肵���G���ꌂ�ŎE���邩�H
	// ���������o�[�̗ݐύU���͂Ƒ����Ȃǂ��l������B
	static bool canKill(Enemy* target, int remainingLife, PartyMember* member);
};

#endif // Party_h__
