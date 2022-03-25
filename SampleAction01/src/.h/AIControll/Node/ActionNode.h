#pragma once
#include <memory>
#include <string>
#include <vector>

class Node;

// �ǂ�Ȃӂ�܂�������̂��̐e�N���X
class ActionNode
{
public:
	ActionNode();
	~ActionNode();
private:
protected:
	// �ӂ�܂���
	std::string name_;
	// �K�w�i���o�[(���ݎ������؍\���̉��Ԗڂɑ��݂��邩�̔ԍ�)
	int hierarchy_no_;
	// �D�揇�ʃi���o�[(�s���̗D�揇�ʂ����肷��ԍ�)
	int priority_no_;
	// �q�ǂ�
	std::vector<Node*> children_;

};

