#pragma once
#include <functional>
#include <map>
#include <array>
#include <string>
#include "BaseScene.h"

// ���̓^�[��
enum class PHASE_TYPE
{
    ACTOR,
    ANIMATION,
    LOOP,
    MAX
};

// InputID��begin�̒�`
static PHASE_TYPE begin(PHASE_TYPE)
{
    return PHASE_TYPE::ACTOR;
}
// InputID��end�̒�`
static PHASE_TYPE end(PHASE_TYPE)
{
    return PHASE_TYPE::MAX;
}
// InputID++�̒�`
static PHASE_TYPE operator++(PHASE_TYPE& id)
{
    return (id = PHASE_TYPE(std::underlying_type<PHASE_TYPE>::type(id) + 1));
}
// �������g��Ԃ��֐�
static PHASE_TYPE operator*(PHASE_TYPE id)
{
    return id;
}

using InputBoxPosition = std::array<BoxRect, static_cast<int>(PHASE_TYPE::MAX)>;

// �e�����ݒ������V�[��
class StartUp :
    public BaseScene
{
public:
    StartUp();
    ~StartUp();
    // �X�V
    UniqueScene Update(UniqueScene own, const std::shared_ptr<KeyInput>& key, const std::shared_ptr<MouseInput>& mouse);
    // ������
    bool Init(void);
    // �`��
    void Draw(void);
private:
    // ���݂̓��̓^�[��
    PHASE_TYPE nowPhase_;
    Vector2I mouse_;
    // �e�����̃e�L�X�g�{�b�N�X�̏��(position,size)
    InputBoxPosition textBox_;
    // �摜�v���r���[�{�b�N�X
    BoxRect imagePreviewBox_;
    // �A�j���[�V�������ꗗ�\���{�b�N�X
    BoxRect animationListBox_;
    // �摜�T�C�Y
    Vector2I imgSize_;
    // ���Z�b�g�{�^��
    BoxRect resetBtn_;
    // ���Z�b�g�{�^�������\�ȃt���O
    bool isAbleReset_;
    // �i�r�Q�[�V�����p�̕�����
    std::array<std::string, static_cast<int>(PHASE_TYPE::MAX)> navStr_;
    std::map<PHASE_TYPE, std::function<void(char*)>> functionMap_;
};

