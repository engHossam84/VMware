/*
Given two balanced binary trees, tree A and tree B, 
determine if B is a subset of A. Tree A has a very large number of nodes (e.g., 1 million), 
and tree B has a much smaller amount of nodes (e.g., 1000)
*/

#include <iostream>
using namespace std;

class TreeNode
{
public:
	explicit TreeNode(int val)
		:data(val), leftPtr(nullptr), rightPtr(nullptr)
	{}

	int getData() const
	{
		return data;
	}

	int data;
	TreeNode * leftPtr;
	TreeNode * rightPtr;
};

bool isIdentical(TreeNode * t1, TreeNode * t2)
{
	if (t1 == nullptr && t2 == nullptr)
		return true;

	if (t1 == nullptr || t2 == nullptr)
		return false;

	return (t1->data == t2->data && isIdentical(t1->leftPtr, t2->leftPtr) && isIdentical(t1->rightPtr, t2->rightPtr));


}

bool isSubTree(TreeNode * t1, TreeNode * t2)
{
	if (t2 == nullptr)
		return true;

	if (t1 == nullptr && t2 != nullptr)
		return false;

	if (isIdentical(t1, t2))
		return true;

	return (isSubTree(t1->leftPtr, t2) || isSubTree(t1->rightPtr, t2));

}

int main()
{
	// TREE 1 
	/* Construct the following tree
	26
	/   \
	10     3
	/    \     \
	4      6      3
	\
	30
	*/
	TreeNode *T = new TreeNode(26);
	T->rightPtr = new TreeNode(3);
	T->rightPtr->rightPtr = new TreeNode(3);
	T->leftPtr = new TreeNode(10);
	T->leftPtr->leftPtr = new TreeNode(4);
	T->leftPtr->leftPtr->rightPtr = new TreeNode(30);
	T->leftPtr->rightPtr = new TreeNode(6);

	// TREE 2 
	/* Construct the following tree
	10
	/    \
	4      6
	\
	30
	*/
	TreeNode *S = new TreeNode(10);
	S->rightPtr = new TreeNode(6);
	S->leftPtr = new TreeNode(4);
	S->leftPtr->rightPtr = new TreeNode(30);


	if (isSubTree(T, S))
		cout << "Tree 2 is subtree of Tree 1";
	else
		cout << "Tree 2 is not a subtree of Tree 1";

	cout << endl;
	return 0;
}
