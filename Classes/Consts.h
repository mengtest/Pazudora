#ifndef Consts_h__
#define Consts_h__

// ��ʉ𑜓x
static const float RESOLUTION_X = 640;
static const float RESOLUTION_Y = 960;

// Windows�\�����̉�ʔ{��
static const float ZOOM_FACTOR_FOR_WINDOWS = 0.7f;

// ��
static const int COLUMN_COUNT = 6;
// �s��
static const int ROW_COUNT = 5;

// �����̐�
static const int ATTRIBUTE_NUM = 6;

// �����̂ɍŒ���K�v�Ȑ�
static const int REQUIED_MATCH_NUM = 3;

// �S�̍U���ɕK�v�ȃh���b�v��
static const int ATTACK_TO_ALL_NUM = 5;

// �h���b�v���ړ��\�Ȏ��ԁi�b�j
static const float MAX_TOUCH_DURATION = 50.0f;

// �h���b�v�̃T�C�Y(�s�N�Z��)
static const float DROP_SIZE = 100;
// �h���b�O���̃h���b�v�̃T�C�Y��
static const float DRAGGING_DROP_SIZE_RATIO = 1.15f;
// �h���b�v�̉�ʉ��[�̃}�[�W��
static const float DROP_BOTTOM_MARGIN = 20;

// �h���b�v��������ہi�R���{�j�̊Ԋu�i�b�j
static const float REMOVE_DROP_INTERVAL = 0.4f;
// �h���b�v��������̂ɗv���鎞��
static const float FALL_DROP_DURATION = 0.2f;
// �h���b�v�������Ă���`�F�b�N����܂ł̎���
static const float DELAY_AFTER_FALL_DROP = 0.2f;
// �R���{�ōU���͂��`���[�W�����Ԋu�i�b�j
static const float CHARGE_BY_COMBO_DURATION = 0.5f;
// �U���̓`���[�W�G�t�F�N�g�̎��ԁi�b�j
static const float ATTACK_CHAGE_EFFECT_DURATION = 0.25f;
// ���������o�[���m�̍U���Ԋu�i�b�j
static const float MEMBERS_ATTACK_INTERVAL = 0.15f;
// �����̍U���G�t�F�N�g�J�n���璅�e�܂ł̎��ԁi�b�j
static const float ATTACK_EFFECT_DURATION = 0.3f;
// �p�[�e�B�̃��C�t�Q�[�W������̂ɂ����鎞��
static const float PARTY_APPLY_DAMAGE_DURATION = 0.5f;
// �G�p�[�e�B��y���W
static const float ENEMY_PARTY_Y = 700;
// �G1�̍U���Ԋu�i�b�j
static const float ENEMY_ATTACK_INTERVAL = 0.5f;
// �G�̍U���G�t�F�N�g�̎��ԁi�b�j
static const float ENEMY_ATTACK_EFFECT_DURATION = 0.2f;
// �G�̍U�����󂯂ă��C�t�Q�[�W������̂ɗv���鎞�ԁi�b�j
static const float ENEMY_ATTACK_DAMAGE_DURATION = 0.3f;



// �h���b�v�̃^�O
static const int TAG_DROP = 10000;

// �R���{�\���̃^�O
static const int TAG_COMBO_LABEL = 20000;

static const int TAG_SHAKE_ACTION = 30000;

enum Z_ORDER
{
	Z_BG,
	Z_ENEMY,
	Z_ENEMY_DAMAGE,
	Z_PARTY,
	Z_PARTY_ATTACK_EFFECT,
	Z_LIFE_GAUGE,
	Z_CURE_POWER_LABEL,
	Z_PARTY_DAMAGE,
	Z_DROP,
	Z_SWAPPING_DROP,
	Z_DRAGGING_DROP,
	Z_COMBO,
	Z_CHAGE_ATTACK_EFFECT,
};

#endif // Consts_h__