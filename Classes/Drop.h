#ifndef Drop_h__
#define Drop_h__

#include "cocos2d.h"
#include "Attribute.h"
#include "PositionIndex.h"

USING_NS_CC;

class Drop : public Sprite
{
public:
	Drop(Attribute attribute, int row, int column);
	// �����_���ȑ����̃h���b�v�𐶐�
	static Drop* create(int row, int column);
	static Drop* create(Attribute attribute, int row, int column);
	bool init();

	// ������ԋp����
	Attribute getAttribute();

	// �s/��C���f�b�N�X��ԋp����
	const PositionIndex& getPositionIndex();

	// �s/��C���f�b�N�X��ݒ肷��
	void setPositionIndex(const PositionIndex& position);

	// �ׁi�΂ߊ܂ށj�̍��W�Ɉړ�����B
	// �i�{�Ƃ̂悤�ɃN�����Ɣ���]���Ĉړ�����j
	void moveTo(const PositionIndex& dest);

	// �h���b�O�����ǂ�����ݒ肷��i�����ڂɉe������j
	void setDragging(bool isDragging);

	// �w�莞�Ԍ�ɏ��ł���
	void scheduleRemove(float delayTime);

private:
	// �w�肳�ꂽ�����̉摜�t�@�C�������擾����B
	const std::string& getImageFileName(Attribute attribute);

	// ����
	Attribute _attribute;

	// �s/��C���f�b�N�X
	PositionIndex _positionIndex;

	// �A�N�V�������L�����Z�����ė��z�ʒu�Ɉړ�����
	void setPositionToIdeal();
};

#endif