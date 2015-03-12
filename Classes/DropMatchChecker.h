#ifndef DropMatchChecker_h__
#define DropMatchChecker_h__

#include "cocos2d.h"
USING_NS_CC;
#include "Consts.h"
#include "Drop.h"
#include "PositionIndex.h"

// �h���b�v�̔Ֆʉ�͌N
class DropMatchChecker
{
public:
	// �h���b�v�̔Ֆʂ���͂��A������h���b�v�̏W���̏W����ԋp����B
	// ������h���b�v�������ꍇ�͒����[����vector��ԋp����B
	// ���ʂ̕��я��͖{�ƃp�Y�h�������B
	//   �������E��
	//   ��i��ɍs���č����E
	//   ��i��ɍs���č����E
	//   �Ƃ������Ƀ`�F�b�N���A�����������ƂȂ��Ă���B
	static std::vector<std::vector<Drop*>> analyze(Drop* drops[][COLUMN_COUNT]);

private:
	// �Ֆʂ̃|�C���^
	Drop* (*_drops)[COLUMN_COUNT];
	// ��͌��ʃe�[�u���B
	// �����ɏ�����ꏊ�͓����ԍ�(groupId)���U����B
	// �����: -1
	// ��͍ς݁i�����Ȃ��j: 0
	// ��͍ς݁i������j: 1�ȏ�̒l
	int _resultTable[ROW_COUNT][COLUMN_COUNT];
	// ��͌��ʂɐU�邽�߂̔ԍ��B
	int _groupId;
	// ���ݒ������̑���
	Attribute _currentAttribute;

	// �R���X�g���N�^�iprivate�j
	DropMatchChecker(Drop* drops[][COLUMN_COUNT]);
	// ��͎��s
	std::vector<std::vector<Drop*>> analyze();
	// �w�肵���}�X����͂��A���ʂ���͌��ʃe�[�u���ɏ������ށB
	// �ċA�I�ɗאڂ���}�X����͂��Ă����B
	// ��������3�ȏ����ł���ꍇ�A�����ԍ����U����B
	// �����Ȃ��ꍇ�A0���������ށB
	void markAndDig(const PositionIndex& index);
	// �w�肵���ꏊ�̃h���b�v�Ɠ����������H
	bool isDropSameAttribute(const PositionIndex& index);
	// �w�肵���ꏊ�͊��ɉ�͍ς݂��H
	bool isAlreadyMarked(const PositionIndex& index);
	// �w�肵���ꏊ�͌@��i�߂邱�Ƃ��\���H�i��͉\���H�j
	bool canDig(const PositionIndex& index);
	// �����F�̃h���b�v�������Ă��邩�ǂ������`�F�b�N���A
	// �����Ă���΁A���݂�groupId���������ށB
	// origin : �N�_
	// direction : ���ׂ�����BPositionIndex::RIGHT�܂���PositionIndex::UP���w�肷��B
	// requiredNum : �u�������v�Ƃ���Œ���B
	void checkAndMark(const PositionIndex& origin, const PositionIndex& direction, int requiredNum);
	// �w�肵���ꏊ�Ɍ��݂�groupId����������
	void mark(const PositionIndex& index);
};


#endif // DropMatchChecker_h__
