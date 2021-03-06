#include <stdio.h>
#include <stdlib.h>
void Display();
void InsertFirst();
void InsertLast();
int Count_Node();
void InsertBetween();
void DeleteFirst();
void DeleteLast();
void DeleteBetween();

struct node
{
	int data;
	struct node* next;
};
typedef struct node  NODE;
typedef struct node* PNODE;

PNODE head = NULL;

int main() 
{
	int choice = 0;
	int cnt = 0;
	
	while(1)
	{
		puts("*****MENU START*****");
		puts("1. Display");
		puts("2. Count Node");
		puts("3. Insert First");
		puts("4. Insert Last");
		puts("5. Insert Between");
		puts("6. Delete First");
		puts("7. Delete Last");
		puts("8. Delete Between");
		puts("100. Exit");
		puts("*****MENU END*****");
		printf("Enter Choice = ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
					Display();
					break;
			case 2:
					cnt = Count_Node();
					printf("Total Nodes = %d\n",cnt);
					break;
			case 3:
					InsertFirst();
					break;
			case 4:
					InsertLast();
					break;
			case 5:
					InsertBetween();
					break;
			case 6:
					DeleteFirst();
					break;
			case 7:
					DeleteLast();
					break;
			case 8:
					DeleteBetween();
					break;
			case 100:
					return 0;
			default:
					printf("Invalid Choice");
		}
	}
	return 0;
}
void Display()
{
	PNODE temp = head;
	
	if(head == NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d->",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
	return;
}
void InsertFirst()
{
	PNODE ptr  = NULL;
	int value  = 0;
	char text[10];
	
	ptr = (PNODE)malloc(sizeof(NODE));
	if(ptr==NULL)
	{
		printf("Memory not allocated\n");
		return;
	}
	printf("Enter Value = ");
	scanf("%s",text);

	if(sscanf(text,"%d",&value) != 1)
	{
		puts("Invalid Inputs : Put integer numbers only");
		return;
	}
	
	ptr->data = value;
	ptr->next = NULL;
	
	if(head==NULL)
	{
		head = ptr;
	}
	else
	{
		ptr->next = head;
		head = ptr;
	}
	return;
}

void InsertLast()
{
	PNODE ptr  = NULL;
	PNODE temp = head;
	int value  = 0;
	char text[10];
	
	ptr = (PNODE)malloc(sizeof(NODE));
	
	if(ptr==NULL)
	{
		printf("Memory not allocated\n");
		return;
	}
	
	printf("Enter Value = ");
	scanf("%s",text);

	if(sscanf(text,"%d",&value) != 1)
	{
		puts("Invalid Inputs : Put integer numbers only");
		return;
	}
	
	ptr->data = value;
	ptr->next = NULL;
	
	if(head==NULL)
	{
		head = ptr;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = ptr;
	}
	return;
}

int Count_Node()
{
	int cnt = 0;
	PNODE temp = head;
	
	if(head==NULL)
	{
		return cnt;
	}
	else
	{
		while(temp!=NULL)
		{
			cnt++;
			temp = temp->next;
		}
		return cnt;
	}
}

void InsertBetween()
{
	PNODE ptr  = NULL;
	PNODE temp = head;
	int value  = 0;
	int pos    = 0;
	char text[10];
	
	ptr = (PNODE)malloc(sizeof(NODE));
	if(ptr==NULL)
	{
		printf("Memory not allocated\n");
		return;
	}
	printf("Enter Position = ");
	scanf("%d",&pos);
	
	if(pos<1 || pos > Count_Node()+1)
	{
		printf("Invalid Position\n");
		return;
	}
	
	printf("Enter Value = ");
	scanf("%s",text);

	if(sscanf(text,"%d",&value) != 1)
	{
		puts("Invalid Inputs : Put integer numbers only");
		return;
	}
	
	ptr->data = value;
	ptr->next = NULL;
	
	if(pos==1)
	{
		if(head==NULL)
		{
			head = ptr;
		}
		else
		{
			ptr->next = head;
			head = ptr;
		}	
	}
	else if(pos == Count_Node()+1)
	{
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}	
		temp->next = ptr;
	}
	else
	{
		while(pos>2)
		{
			temp = temp->next;
			pos--;
		}
		ptr->next = temp->next;
		temp->next = ptr;
	}
	return;
}
void DeleteFirst()
{
	PNODE temp = head;
	
	if(head==NULL)
	{
		printf("List is empty!! Can not delete\n");
		return;
	}
	else if(temp->next==NULL)
	{
		free(temp);
		head = NULL;
	}
	else
	{
		head = temp->next;	
		free(temp);
	}
	printf("Node Deleted Successfully\n");
	return;
}

void DeleteLast()
{
	PNODE temp = head;
	
	if(head == NULL)
	{
		printf("List is empty!! Can not delete\n");
		return;
	}
	else if(temp->next==NULL)
	{
		free(temp);
		head = NULL;
	}
	else
	{
		while(temp->next->next!=NULL)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
	}
	printf("Node Deleted Successfully\n");
}

void DeleteBetween()
{
	PNODE temp = head;
	PNODE temp1 = NULL;
	int pos = 0;
	
	printf("Enter Position = ");
	scanf("%d",&pos);
	
	if(pos<1 || pos > Count_Node())   
	{
		printf("Invalid Position\n");
		return;
	}
	
	if(pos==1)
	{
		if(head==NULL)
		{
			printf("List is empty!! Can not delete\n");
			return;
		}
		else if(temp->next==NULL)
		{
			free(temp);
			head = NULL;
		}
		else
		{
			head = temp->next;	
			free(temp);
		}
	}
	else if(pos==Count_Node())
	{
		while(temp->next->next!=NULL)
			{
				temp = temp->next;
			}
			free(temp->next);
			temp->next = NULL;
	}
	else
	{
		while(pos>2)
		{
			temp = temp->next;
			pos--;
		}
		temp1 = temp->next;
		temp->next = temp1->next;
		free(temp1);
	}
	printf("Node Deleted Successfully\n");
	return;
}
