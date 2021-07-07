//Reverse Alternate K Nodes

#include <bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* next;
};

node * _kAltReverse(node *node, int k, bool b);

node *kAltReverse(node *head, int k)
{
	return _kAltReverse(head, k, true);
}

node * _kAltReverse(node *Node, int k, bool b)
{
	if(Node == NULL)
		return NULL;
	
	int count = 1;
	node *prev = NULL;
	node *current = Node;
	node *next;
	
	while(current != NULL && count <= k)
	{
		next = current->next;
	
		if(b == true)
			current->next = prev;
				
		prev = current;
		current = next;
		count++;
	}
		
	if(b == true)
	{
		Node->next = _kAltReverse(current, k, !b);
		return prev;		
	}
		
	else
	{
		prev->next = _kAltReverse(current, k, !b);
		return Node;	
	}
}

void push(node** head_ref, int new_data)
{
	node* new_node = new node();

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void printList(node *node)
{
	int count = 0;

	while(node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
		count++;
	}
}

int main(void)
{
	node* head = NULL;
	int i;

	for(i = 20; i > 0; i--)
		push(&head, i);

	printList(head);

	head = kAltReverse(head, 3);

	printList(head);

	return(0);
}




