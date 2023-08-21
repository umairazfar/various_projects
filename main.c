#include <stdio.h>
#include <stdlib.h>	//need to add this to use pointers

typedef struct Node
{
    int data;
    struct Node* next;
} node; //instead of writing struct Node, we can just write node

typedef struct List
{
    node* head;
    node* tail;
} queue;    //instead of writing struct List, we can just write queue

void append(int, queue*);
void discard(queue*);   //cannot name it remove as it is already taken
void print(queue*);

int main() {
    // Write C code here
    printf("Single Linked List\n");
    queue* _list = (queue*)malloc(sizeof(queue)); //it was not working without declaring a pointer
    append(10, _list);  //append 10
    append(20, _list);  //append 20
    append(30, _list);  //append 30
    print(_list);       //printing list (10, 20, 30)
    discard(_list);     //removing 10
    print(_list);       //printing list (20, 30)
    discard(_list);     //removing 20
    discard(_list);     //removing 30
    discard(_list);     //nothing to remove hence it will say queue is empty
    print(_list);       //nothing to print
    free(_list);        //freeing list memory to avoid memory leak
    return 0;
}

void append(int data, queue* _list)
{
    node* temp = (node*)malloc(sizeof(node*));
    temp->data = data;
    temp->next = NULL;
    
    if(_list->head == NULL) //check if head is NULL so make head point towards the new node
    {
        _list->head = temp;
        _list->tail = temp;
    }
    else    //Add the new node to the tail and move the tail
    {
        _list->tail->next = temp;
        _list->tail = temp;
    }
}

void print(queue* _list)    //print the passed queue
{
    node* temp = _list->head;
    while (temp != NULL)
    {
        printf("\nelement: %d", temp->data);
        temp=temp->next;
    }
}

void discard(queue* _list)  //remove the first element of queue
{
    if(_list->head == NULL)
    {
        printf("\nqueue is empty!");
    }
    else
    {
        node* temp = _list->head;           //make temp point towards head
        _list->head = _list->head->next;    //move the head forward
        printf("\nElement discarded: %d", temp->data);
        free(temp); //free the node to avoid memory leak
    }
}