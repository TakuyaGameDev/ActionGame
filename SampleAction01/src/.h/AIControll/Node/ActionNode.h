#pragma once
#include <memory>
#include <string>
#include <vector>

class Node;

// どんなふるまいをするのかの親クラス
class ActionNode
{
public:
	ActionNode();
	~ActionNode();
private:
protected:
	// ふるまい名
	std::string name_;
	// 階層ナンバー(現在自分が木構造の何番目に存在するかの番号)
	int hierarchy_no_;
	// 優先順位ナンバー(行動の優先順位を決定する番号)
	int priority_no_;
	// 子ども
	std::vector<Node*> children_;

};

