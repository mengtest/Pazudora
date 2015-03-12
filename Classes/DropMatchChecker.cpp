#include "DropMatchChecker.h"

static const int UNMARKED = -1;
static const int UNMATCHED_MARK = 0;

DropMatchChecker::DropMatchChecker(Drop* drops[][COLUMN_COUNT])
: _drops(drops)
, _groupId(0)
{
	// ��͌��ʃe�[�u���i_resultTable�j�̏�����
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			_resultTable[row][column] = UNMARKED;
		}
	}
}

std::vector<std::vector<Drop*>> DropMatchChecker::analyze(Drop* drops[][COLUMN_COUNT])
{
	auto instance = new DropMatchChecker(drops);

	return instance->analyze();
}

std::vector<std::vector<Drop*>> DropMatchChecker::analyze()
{
	// �}�X����͂��Ă����B
	// �����ɏ�����}�X�ɂ͓����ԍ�������B
	// �����Ȃ��}�X�ɂ�0������B
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			_groupId++;

			auto index = PositionIndex(row, column);

			// ��͍ς݂̏ꍇ�̓X�L�b�v����
			if (isAlreadyMarked(index))
				continue;

			_currentAttribute = _drops[row][column]->getAttribute();

			markAndDig(index);
		}
	}

	std::vector<std::vector<Drop*>> matchedDrops;

	// _resultTable���瓯���ԍ��̃h���b�v���E���Ă����A
	// 3�ȏ゠��΁A�ŏI���ʂ�vector�ɒǉ�����B
	for (int id = 1; id < _groupId; id++)
	{
		std::vector<Drop*> aSetOfDrops;

		for (int row = 0; row < ROW_COUNT; row++)
		{
			for (int column = 0; column < COLUMN_COUNT; column++)
			{
				if (_resultTable[row][column] == id)
				{
					aSetOfDrops.push_back(_drops[row][column]);
				}
			}
		}

		if (aSetOfDrops.size() >= REQUIED_MATCH_NUM)
		{
			matchedDrops.push_back(aSetOfDrops);
		}
	}

	return matchedDrops;
}


void DropMatchChecker::markAndDig(const PositionIndex& index)
{
	if (_resultTable[index.row][index.column] != UNMARKED)
	{
		// ���Ƀ`�F�b�N�ς݂ł���}�X�ł��邽�߁A�������Ȃ�
		return;
	}
	else if (_resultTable[index.row][index.column] == UNMARKED)
	{
		// �Ƃ肠�����`�F�b�N�ς݂Ƃ���
		_resultTable[index.row][index.column] = UNMATCHED_MARK;
	}

	static const PositionIndex directions[4] =
	{
		PositionIndex::LEFT,
		PositionIndex::UP,
		PositionIndex::RIGHT,
		PositionIndex::DOWN,
	};

	// �����̎���4���������������̏ꍇ�A�@��i�߂�i1�}�X�i��ł܂������������J��Ԃ��j�B
	for (auto direction : directions)
	{
		const auto nextIndex = index + direction;

		if (canDig(nextIndex))
			markAndDig(nextIndex);
	}

	// �E�����ɓ������̃h���b�v�������Ă��邩���ׁA�����Ă����猻�݂�groupId����������
	checkAndMark(index, PositionIndex::RIGHT, REQUIED_MATCH_NUM);

	// ������ɓ������̃h���b�v�������Ă��邩���ׁA�����Ă����猻�݂�groupId����������
	checkAndMark(index, PositionIndex::UP, REQUIED_MATCH_NUM);
}

bool DropMatchChecker::isDropSameAttribute(const PositionIndex& index)
{
	return (_drops[index.row][index.column]->getAttribute() == _currentAttribute);
}

bool DropMatchChecker::isAlreadyMarked(const PositionIndex& index)
{
	return (_resultTable[index.row][index.column] >= 0);
}

bool DropMatchChecker::canDig(const PositionIndex& index)
{
	if (index.isInvalid())
		return false;

	if (!isDropSameAttribute(index))
		return false;

	if (isAlreadyMarked(index))
		return false;

	return true;
}

void DropMatchChecker::checkAndMark(const PositionIndex& origin, const PositionIndex& direction, int requiredNum)
{
	Attribute attribute = _drops[origin.row][origin.column]->getAttribute();
	
	// �����͈͂̃}�X�ɁA�ȉ��̂��̂��܂܂�Ă�����A�����Ă��Ȃ��Ƃ������ƂȂ̂Œ����I��
	// �E�����ȃ}�X
	// �E�قȂ鑮���̃}�X
	for (int i = 0; i < requiredNum; i++)
	{
		const auto posIndex = (origin + (direction * i));

		if (posIndex.isInvalid())
		{
			return;
		}

		if (!isDropSameAttribute(posIndex))
		{
			return;
		}
	}

	// �����܂ŗ����瑵���Ă���Ƃ������ƂȂ̂ŁAgroupId����������
	for (int i = 0; i < requiredNum; i++)
	{
		const auto posIndex = (origin + (direction * i));

		_resultTable[posIndex.row][posIndex.column] = _groupId;
	}
}

void DropMatchChecker::mark(const PositionIndex& index)
{
	_resultTable[index.row][index.column] = _groupId;
}
