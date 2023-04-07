#ifndef __SEARCH_TREE_TABLE_H__
#define __SEARCH_TREE_TABLE_H__

#include "BaseTable.h"

using namespace std;

struct TreeNode
{
	Data d;
	int diff;
	TreeNode* pRight;
	TreeNode* pLeft;
	TreeNode* pParent;
};

class SearchTreeTable : public BaseTable {
	TreeNode* pRoot;
	void TempPrint(TreeNode* p)
	{
		if (p != nullptr)
		{
			TempPrint(p->pLeft);
			std::cout << p->d.key << ":\t" << p->d.polynomString << std::endl;
			TempPrint(p->pRight);
		}
	}
public:
	SearchTreeTable() : BaseTable() { pRoot = nullptr; }
	void balance(int& a, int& b, int p);
	void rotateLeft(TreeNode* a);
	void rotateRight(TreeNode* a);
	void rotateBigLeft(TreeNode* a);
	void rotateBigRight(TreeNode* a);
	void changeBalance(TreeNode* p, int a);
	void insert(const Data& d);
	Data* find(const string key); 
	void deleteByKey(const string& key);
	void print();
	~SearchTreeTable() {}
};
#endif
