//Detect and remove loop in Linked List

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
	int key;
	struct Node* next;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

void printList(Node* head)
{
	while (head != NULL) 
	{
		cout << head->key << " ";
		head = head->next;
	}
	cout << endl;
}

void detectAndRemoveLoop(Node* head)
{
	if (head == NULL || head->next == NULL)
		return;

	Node *slow = head, *fast = head;

	slow = slow->next;
	fast = fast->next->next;

	while (fast && fast->next) 
	{
		if (slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow == fast)
	{
		slow = head;

		if(slow == fast) 
		{
			while(fast->next != slow) fast = fast->next;
		}
		
		else 
		{
			while (slow->next != fast->next) 
			{
				slow = slow->next;
				fast = fast->next;
			}
		}

		fast->next = NULL;
	}
}


int main()
{
	Node* head = newNode(50);

	head->next = head;

	head->next = newNode(20);

	head->next->next = newNode(15);

	head->next->next->next = newNode(4);

	head->next->next->next->next = newNode(10);

	head->next->next->next->next->next = head;

	detectAndRemoveLoop(head);

	printList(head);

	return 0;
}

