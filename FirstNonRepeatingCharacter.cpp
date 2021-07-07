// First Non Repeating Character from a stream of Characters

#include <iostream>
#define MAX_CHAR 256
using namespace std;

struct node 
{
	char a;
	struct node *next, *prev;
};

void appendNode(struct node** head_ref, struct node** tail_ref, char x)
{
	struct node* temp = new node;
	temp->a = x;
	temp->prev = temp->next = NULL;

	if (*head_ref == NULL) 
	{
		*head_ref = *tail_ref = temp;
		return;
	}
	
	(*tail_ref)->next = temp;
	temp->prev = *tail_ref;
	*tail_ref = temp;
}

void removeNode(struct node** head_ref,	struct node** tail_ref, struct node* temp)
{
	if (*head_ref == NULL)
		return;

	if (*head_ref == temp)
		*head_ref = (*head_ref)->next;
		
	if (*tail_ref == temp)
		*tail_ref = (*tail_ref)->prev;

	if (temp->next != NULL)
		temp->next->prev = temp->prev;

	if (temp->prev != NULL)
		temp->prev->next = temp->next;

	delete (temp);
}

void findFirstNonRepeating()
{
	struct node* inDLL[MAX_CHAR];

	bool repeated[MAX_CHAR];

	struct node *head = NULL, *tail = NULL;

	for (int i = 0; i < MAX_CHAR; i++) 
	{
		inDLL[i] = NULL;
		repeated[i] = false;
	}

	char stream[] = "codingispassionandpassionislove";
	
	for (int i = 0; stream[i]; i++) 
	{
		char x = stream[i];
		cout << x;

		if (!repeated[x]) 
		{
			if (inDLL[x] == NULL) 
			{
				appendNode(&head, &tail, stream[i]);
				inDLL[x] = tail;
			}
			
			else
			{
				removeNode(&head, &tail, inDLL[x]);
				inDLL[x] = NULL;
				repeated[x]	= true;
			}
		}

		if (head != NULL)
			cout<< head->a << endl;
	}
}

int main()
{
	findFirstNonRepeating();

	return 0;
}

