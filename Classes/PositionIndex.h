#ifndef Position_h__
#define Position_h__

// �h���b�v�̈ʒu�i�s/��j�p�\����
class PositionIndex
{
public:
	int row;
	int column;

	PositionIndex();
	PositionIndex(int aRow, int aColumn);

	// �����ȃC���f�b�N�X�̏ꍇ��true��ԋp����
	bool isInvalid() const;
	// ��̋�����ԋp����B1�}�X����Ă���ꍇ��1�A�΂߂�2
	static int distance(const PositionIndex& a, const PositionIndex& b);

	PositionIndex operator+(const PositionIndex& p) const;
	PositionIndex operator-(const PositionIndex& p) const;
	PositionIndex operator*(int amount) const;
	bool operator==(const PositionIndex& p) const;

	// �����ȍ��W��\��
	static const PositionIndex INVALID_INDEX;

	// ��������\��
	static const PositionIndex LEFT;
	// �������\��
	static const PositionIndex UP;
	// �E������\��
	static const PositionIndex RIGHT;
	// ��������\��
	static const PositionIndex DOWN;
};

#endif // Position_h__
