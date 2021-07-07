//Reorder Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int data;
	struct Node* next;
};

struct Node* newNode(int key)
{
	struct Node* temp = malloc(sizeof(struct Node));
	temp->data = key;
	temp->next = NULL;
	return temp;
}

void printlist(struct Node* head)
{
	while (head) 
	{
		printf("%d ", head->data);
	
		if (head->next)
			printf("->");
	
		head = head->next;
	}
	
	printf("\n");
}

void rearrange(struct Node** head, struct Node* last)
{
	if (!last)
		return;

	rearrange(head, last->next);

	if (!(*head)->next)
		return;

	if ((*head) != last && (*head)->next != last) 
	{
		struct Node* tmp = (*head)->next;
		(*head)->next = last;
		last->next = tmp;
		*head = tmp;
	}
	
	else 
	{
		if ((*head) != last)
			*head = (*head)->next;
		(*head)->next = NULL;
	}
}

int main()
{
	struct Node* head = newNode(1);

	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);

	printlist(head);

	struct Node* tmp = head;

	rearrange(&tmp, head);

	printlist(head);

	return 0;
}

