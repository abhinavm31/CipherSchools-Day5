// Merge Two Sorted Linked Lists

#include <iostream>
using namespace std;

struct Node 
{
	int key;
	struct Node* next;
};

Node* reverseList(Node* head)
{
	if (head->next == NULL)
		return head;

	Node* rest = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;

	return rest;
}

Node* sortedMerge(Node* a, Node* b)
{
	a = reverseList(a);
	b = reverseList(b);

	Node* head = NULL;

	Node* temp;

	while (a != NULL && b != NULL) 
	{
		if (a->key >= b->key) 
		{
			temp = a->next;
			a->next = head;
			head = a;
			a = temp;
		}
	
		else 
		{
			temp = b->next;
			b->next = head;
			head = b;
			b = temp;
		}
	}

	while (a != NULL) 
	{
		temp = a->next;
		a->next = head;
		head = a;
		a = temp;
	}

	while (b != NULL) 
	{
		temp = b->next;
		b->next = head;
		head = b;
		b = temp;
	}

	return head;
}

void printList(struct Node* Node)
{
	while (Node != NULL) 
	{
		cout << Node->key << " ";
		Node = Node->next;
	}
}

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->next = NULL;

	return temp;
}

int main()
{
	struct Node* res = NULL;

	Node* a = newNode(5);

	a->next = newNode(10);
	a->next->next = newNode(15);
	a->next->next->next = newNode(40);

	Node* b = newNode(2);

	b->next = newNode(3);
	b->next->next = newNode(20);

	printList(a);

	printList(b);

	res = sortedMerge(a, b);

	printList(res);

	return 0;
}

