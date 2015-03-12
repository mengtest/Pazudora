#ifndef GameScene_h__
#define GameScene_h__

#include "cocos2d.h"
#include "Consts.h"
#include "Drop.h"
#include "ComboLabel.h"
#include "Party.h"
#include "EnemyParty.h"

USING_NS_CC;

namespace{
	// �Q�[����Ԏ��
	enum class State
	{
		GAME_START,
		WAITING_INPUT,
		TOUCHING,
		ERASING,
		CHARGE_ATTACK_POWER,
		PARTY_ATTACK,
		AFTER_PARTY_ATTACK,
		ENEMY_ATTACK,
		AFTER_ENEMY_ATTACK,
		GAME_OVER,
		GAME_CLEAR,
	};
}

class GameScene : public Scene
{
public:
	//============================================================
	// public �����o�[�֐�
	//============================================================
	static GameScene* create();
	bool init();
	void update(float delta) override;
	
	// �s,�񂩂���W���v�Z���A�ԋp����B
	// row : �s�ԍ��B��ʉ���0�B
	// column : ��ԍ��B��ʍ���0�B
	static Vec2 calcDropPosition(const PositionIndex& positionIndex);

private:
	//============================================================
	//�����o�[�ϐ�
	//============================================================

	// �h���b�O���̏ꏊ
	PositionIndex _touchingPositionIndex;
	
	// �Q�[���̏��
	State _state;

	// �h���b�v���ړ��\�Ȏc�莞��
	float _remainingTouchTime;
	
	// �S�h���b�v�̔z��
	Drop* _drops[ROW_COUNT][COLUMN_COUNT];

	// �R���{��
	int _comboCount;

	// �R���{�̃��x�����l�߂Ă����L���[
	std::queue<ComboLabel*> _comboLabels;

	// �����p�[�e�B
	Party* _party;

	// �G�p�[�e�B
	EnemyParty* _enemyParty;

	// �h���b�O���̃h���b�v
	Drop* _draggingDrop;

	// �h���b�O���̃h���b�v�i�\���p�j
	Sprite* _draggingDropSprite;

	//============================================================
	// private �����o�[�֐�
	//============================================================

	void changeState(State newState);

	// �^�b�`�C�x���g��o�^����
	void registerTouchEvent();

	// �Ֆʂ̏������B�Ֆʂ��h���b�v�Ŗ�����
	void initDrops();

	// �󂢂Ă���ꏊ�Ƀh���b�v��ǉ�����
	void fillEmpty();

	// �h���b�v�𗎂Ƃ��ċ󂢂Ă�}�X���l�߂�
	void fallDrops();

	// �p�[�e�B������
	void initParty();
	
	// �h���b�v�������邩�`�F�b�N���A������Ȃ�����B
	// �������ꍇ�́A�V�����h���b�v���o��������B
	// �����Ă܂����g�imatchTest�j���ĂԁB
	void matchTest();
	
	// �w�肵�����W�ɑ��݂���h���b�v���擾����B
	// �w�肵�����W�Ƀh���b�v�����݂��Ȃ��ꍇ��nullptr��ԋp����B
	Drop* getDrop(const Vec2& position);

	// 2�̃h���b�v�̈ʒu����������
	void swapDrop(PositionIndex a, PositionIndex b);
	
	// ��ʍ��W����PositionIndex�i�h���b�v�̍s/��j���v�Z����
	// ���W���͈͊O�ł���ꍇ��PositionIndex::INVALID_INDEX��ԋp����
	PositionIndex getPositionIndexFromPosition(const Vec2& position);

	// ��ʍ��W����PositionIndex�i�h���b�v�̍s/��j���v�Z����B
	// ���W���͈͊O�ł���ꍇ�́A�␳���Ĕ͈͓��ɂ������̂�ԋp����B
	PositionIndex getPositionIndexFromPositionClamp(const Vec2& position);

	// �����̃h���b�v�̒��S���W���v�Z���A�ԋp����
	Vec2 calcCenterOfDrops(const std::vector<Drop*>& drops);

	// �R���{�\���𐶐����AScene��Add����
	void createComboDisplay(const Vec2& position, int comboCount, float delay);

	// �h���b�O���̃h���b�v�̕\���p�X�v���C�g���쐬
	void createDraggingDropSpriteAndAdd(const Vec2& position);

	// �h���b�v�������̌��ʉ����Đ�
	void playEraseDropSE(int comboCount);

	// �G�p�[�e�B������
	void initEnemyParty();
};

#endif // GameScene_h__
