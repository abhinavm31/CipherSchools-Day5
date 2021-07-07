//Remove Duplicates from Sorted Linked List

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
	int data;
	Node* next;

	Node()
	{
		data = 0;
		next = NULL;
	}
};

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void printList(Node* node)
{
	while (node != NULL) 
	{
		cout << node->data << " ";
		node = node->next;
	}
}

void removeDuplicates(Node* head)
{
	unordered_map<int, bool> track;
	Node* temp = head;

	while (temp) 
	{
		if (track.find(temp->data) == track.end()) 
		{
			cout << temp->data << " ";
		}
		
		track[temp->data] = true;
		temp = temp->next;
	}
}

int main()
{
	Node* head = NULL;

	push(&head, 20);
	push(&head, 13);
	push(&head, 13);
	push(&head, 11);
	push(&head, 11);
	push(&head, 11);

	printList(head);

	removeDuplicates(head);

	return 0;
}


