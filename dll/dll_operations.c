#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *prev;
	struct Node *next;
}*node; node head = NULL;


node create_Node() {
	node temp = (node)malloc(sizeof(struct Node));
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

void insert_at_begg(node *head, int data) {
	node new_node = create_Node();
	new_node->data = data;
	if(*head == NULL) {
		*head = new_node;
		return;
	}
	new_node->next = *head;
	(*head)->prev = new_node;
	(*head) = new_node;
}

void insert_at_end(node *head, int data) {
	node new_node = create_Node();
	node temp = *head;
	new_node->data = data;
	if(*head == NULL) {
		*head = new_node;
		return;
	}
	while(temp->next!=NULL) {
		temp = temp->next;
	}
	temp->next = new_node;
	new_node->prev = temp;
}

void delete_from_begg(node *head) {
	if(*head == NULL) {
			printf("\nThe list is empty");
			return;
	}
	node temp = *head;
	if(temp->prev == NULL && temp->next == NULL) {
		printf("\nThe list is now empty");
		*head = (*head)->next;
		return;
	}
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}

void delete_from_end(node *head) {
	if(*head == NULL) {
		printf("\nThe list is empty");
		return;
	}
	node temp = *head;
	if(temp->prev == NULL && temp->next == NULL) {
		printf("\nThe list is now empty");
		*head = (*head)->next;
		return;
	}
	while(temp->next->next!=NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
}

void search(node head, int data) {
		node temp = head;
		static int count = 0;
		if(temp == NULL) {
				printf("\nThe item is not in the list.");
				return;
		}
		if(temp->data == data) {
			printf("%d",temp->data);
			printf("\nThe value is present in the list at index %d",count);
			count = 0;
			return;
		}
		else {
			count++;
			search(temp->next,data);
		}
}

void insert_at_pos(node *head,int data, int pos) {
		if(pos<0) {
			printf("\nInvalid operation");
			return;
		}
		if(pos == 0) {
			insert_at_begg(head,data);
			return;
		}
		else {
			node new_node = create_Node();
			new_node->data = data;
			node temp = *head;
			for(int i = 0;i < pos-1; i++) {
				if(temp->next == NULL)
					return;
				temp = temp->next;
			}
			new_node->next = temp->next;
			temp->next = new_node;
		}
}

void delete_from_pos(node *head,int pos) {
	if(pos<0) {
		printf("\nInvalid operation");
		return;
	}
		node temp = *head;
		if(temp == NULL)
			return;
		if(pos == 0) {
				delete_from_begg(head);
				return;
		}
		else {
			for(int i = 0; i< pos; i++) {
				if(temp->next == NULL)
					return;	//print out of bound

				temp = temp->next;
			}
			if(temp->next == NULL) {
					delete_from_end(head);
					return;
			}
			(temp->prev)->next = temp->next;
			(temp->next)->prev = temp->prev;
			free(temp);
		}
}

void display(node head) {
	node temp = head;
	while(temp!=NULL) {
		printf("%d<==>",temp->data);
		temp = temp->next;
	}
}

void insert_before_data(node *head,int pos_data, int data) {
	node temp = *head;
	int pos = 0;
	while(temp->data != pos_data) {
		temp = temp->next;
		pos++;
	}
	insert_at_pos(head,data,pos);
}

void insert_after_data(node *head,int pos_data, int data) {
	node temp = *head;
	int pos = 0;
	while(temp->data != pos_data) {
		temp = temp->next;
		pos++;
	}
	insert_at_pos(head,data,pos+1);
}

void delete_before_data(node *head,int data) {
		node temp = *head;
		int pos = 0;
		while (temp->data != data) {
			temp = temp->next;
			pos++;
		}
		delete_from_pos(head,pos-1);
}

void delete_after_data(node *head,int data) {
		node temp = *head;
		int pos = 0;
		while (temp->data != data) {
			temp = temp->next;
			pos++;
		}
		delete_from_pos(head,pos+1);
}



void main() {
	int choice,data,pos;
	while(1) {
		printf("\n\n***Doubly Linked List Operations***\n1.Insert at front\n2.Insert at end\n3.Delete from front\n4.Delete from end.\n5.Search a value\n6.Insert at position\n7.Delete from position\n8.Insert before data\n9.Insert after data\n10.Delete before data\n11.Delete after data\n12.Exit.\nEnter your choice : ");
		scanf("%d",&choice);
		switch (choice) {
			case 1:
				printf("\nEnter the value you want to insert : ");
				scanf("%d",&data);
				insert_at_begg(&head,data);
				display(head);
				break;
			case 2:
				printf("\nEnter the value you want to insert : " );
				scanf("%d",&data);
				insert_at_end(&head,data);
				display(head);
				break;
			case 3:
				delete_from_begg(&head);
				display(head);
				break;
			case 4:
				delete_from_end(&head);
				display(head);
				break;
			case 5:
				printf("\nEnter the value you want to search : ");
				scanf("%d",&data);
				search(head,data);
				break;
			case 6:
				printf("\nEnter the value you want to insert : ");
				scanf("%d",&data);
				printf("\nEnter the position : ");
				scanf("%d",&pos);
				insert_at_pos(&head,data,pos);
				display(head);
				break;
			case 7:
				printf("\nEnter the position : ");
				scanf("%d",&pos);
				delete_from_pos(&head,pos);
				display(head);
				break;
			case 8:
				printf("\nEnter the value you want to insert : ");
				scanf("%d",&data);
				printf("\nEnter the data before which you want to insert : ");
				scanf("%d",&pos);
				insert_before_data(&head,pos,data);
				display(head);
				break;
			case 9:
				printf("\nEnter the value you want to insert : ");
				scanf("%d",&data);
				printf("\nEnter the data after which you want to insert : ");
				scanf("%d",&pos);
				insert_after_data(&head,pos,data);
				display(head);
				break;
			case 10:
				printf("\nEnter the value before which you want to delete : ");
				scanf("%d",&data);
				delete_before_data(&head,data);
				display(head);
				break;
			case 11:
				printf("\nEnter the value after which you want to delete : ");
				scanf("%d",&data);
				delete_after_data(&head,data);
				display(head);
				break;
				case 12:
					exit(0);
		}
	}
}
