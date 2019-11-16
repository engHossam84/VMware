

/*
Coding interview on hacker rank - Reverse a string using linked list
*/

#include <iostream>
using namespace std;

class ListNode
{
public:
	ListNode(char val)
		:data(val), nextPtr(nullptr)
	{}


	char data;
	ListNode * nextPtr;

};


ListNode * ReverseList(ListNode * head)
{
	if (head == nullptr)
		return head;

	ListNode * prev = nullptr;
	ListNode * current = head;
	ListNode * next = current->nextPtr;

	while (current != nullptr)
	{
		next = current->nextPtr;
		current->nextPtr = prev;
		prev = current;
		current = next;
			
	}
	return prev;

}

int main()
{
	ListNode * head = new ListNode('h');
	head->nextPtr = new ListNode('o');
	head->nextPtr->nextPtr = new ListNode('s');
	head->nextPtr->nextPtr->nextPtr = new ListNode('a');
	head->nextPtr->nextPtr->nextPtr->nextPtr = new ListNode('m');

	ListNode * output = ReverseList(head);

	while (output)
	{
		cout << output->data << " ";
		output = output->nextPtr;
	}
	cout << endl;
	return 0;

}
