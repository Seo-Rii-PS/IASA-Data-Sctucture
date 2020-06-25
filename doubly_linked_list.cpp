#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node
{
    element data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct listNode_h
{
    Node *head;
}listNode_h;

listNode_h* l;

listNode_h* createList()
{
    listNode_h* l=(listNode_h *)malloc(sizeof(listNode_h));
    l->head=NULL;
    return l;
}
void insertNode(element item)
{
    Node* tmp=l->head;
    int cnt = 0;
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->data=item;
    newNode->prev=NULL;
    newNode->next=NULL;
    if(l->head == NULL)
    {
        l->head=newNode;
        return;
    }
    while(tmp && tmp->data >= item)
    {
        tmp=tmp->next;
        cnt++;
    }
    if(cnt==0)
    {
        tmp->prev=newNode;
        newNode->next=tmp;
        l->head = newNode;
    }
    else if(cnt!=0 && tmp->next!=NULL)
    {
        newNode->next=tmp;
        newNode->prev=tmp->prev;
        tmp->prev->next=newNode;
        tmp->prev=newNode;
    }
    else if(cnt!=0 && tmp->next==NULL)
    {
        tmp->next=newNode;
        newNode->prev=tmp;
    }
}
void deleteNode(element item)
{
    Node* tmp= l->head;
    if(l->head==NULL)
        return;
    if(tmp->data == item)
    {
        l-> head = tmp->next;
        tmp->next->prev=NULL;
    }
    else
    {
        while(tmp->data != item)
        {
            tmp=tmp->next;
        }
        if(tmp->next!=NULL)
        {
            tmp->prev->next=tmp->next;
            tmp->next->prev=tmp->prev;
        }
        else
        {
            tmp->prev->next=tmp->next;
        }
    }
    free(tmp);
    return;
}
void printList()
{
    Node* tmp=l->head;
    if(l->head==NULL)
        printf("List is Empty!\n");
    else
    {
        while(tmp!=NULL)
        {
            printf("%d ",tmp->data);
            tmp=tmp->next;
        }
        printf("\n");
    }
    return;
}
void searchNode(element item)
{
    Node* tmp=l->head;
    int flag = 0;
    while (tmp!=NULL)
    {
        if (tmp->data == item)
        {
            flag=1;
            break;
        }
        tmp = tmp->next;
    }
    if (flag==1)
        printf("%d is in the List! \n",item);
    else
        printf("%d is not in the List! \n",item);
}

int main()
{
    l=createList();
    insertNode(50);
    insertNode(30);
    insertNode(40);
    searchNode(45); //없습니다
    insertNode(45);
    searchNode(45); //있습니다
    printList(); // [50, 45, 40 30]
    deleteNode(45);
    printList(); // [50, 40, 30]
    return 0;
}