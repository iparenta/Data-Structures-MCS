#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head; // global variable - pointer to head node.

struct Node* GetNewNode(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next =NULL;
    return newNode;
};

void InsertAtHead(int x){
    struct Node* newNode = GetNewNode(x);

    if(head == NULL){
        head = newNode;
        return;
    };

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
};

void Print(){
    struct Node* temp = head;
    printf("Forward: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
};

void ReversePrint(){
    struct Node* temp = head;
    if(temp == NULL)return; //empty list, exit
    //Going to last node
    while(temp->next != NULL){
        temp = temp->next;
    };
    //Traversing backward using prev pointer
    printf("Reverse: ");
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->prev;
    };
    printf("\n");
};

//Inserts a Node at tail of Doubly linked list
void InsertAtTail(int x) {
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	while(temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}

int main(){
    head = NULL;
    InsertAtHead(2); Print(); ReversePrint();
    InsertAtHead(4); Print(); ReversePrint();
    InsertAtHead(6); Print(); ReversePrint();
    InsertAtTail(1); Print(); ReversePrint();
    InsertAtTail(3); Print(); ReversePrint();
    InsertAtTail(5); Print(); ReversePrint();
    
};
