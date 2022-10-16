#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;

}node;
typedef struct dll
{
    node *head;
    node *last;
    int length;
}dll;
void createdll(dll *dl)
{
    dl->head=NULL;
    dl->last=NULL;
    dl->length=0;
}
int insempty(dll *dl)
{
    return(dl->head==NULL && dl->last==NULL && dl->length==0);
}
void insertempty(dll *dl,int n)
{
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    ptr->data=n;
    ptr->next=NULL;
    ptr->prev=NULL;
    dl->head=ptr;
    dl->last=ptr;
    dl->length++;

}
void insertbegin(dll *dl,int n)
{
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    ptr->data=n;
    ptr->next=dl->head;
    dl->head->prev=ptr;
    ptr->prev=NULL;
    dl->head=ptr;
    dl->length++;
}
void insertend(dll *dl,int n)
{
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    ptr->data=n;
    ptr->prev=dl->last;
    dl->last->next=ptr;
    ptr->next=NULL;
    dl->last=ptr;
    dl->length++;
}
void insertatposition(dll *dl,int n,int pos)
{   
    int i=1;
    node *ptr,*current;
    ptr=(node *)malloc(sizeof(node));
    current=dl->head;
    while(i!=pos-1)
    {
        current=current->next;
        i++;
    }
    ptr->data=n;
    ptr->next=current->next;
    current->next->prev=ptr;
    ptr->prev=current;
    current->next=ptr;
    dl->length++;
}
void display(dll *dl)
{
	node *current;
	current=dl->head;
	while(current!=NULL)
	{
	printf("%d ",current->data);
	current=current->next;
	}
}


int length(dll *dl)
{
    return(dl->length);
}

int deleteonly(dll *dl)
{
    int ele;
    node *todelete;
    todelete=dl->head;
    ele=todelete->data;
    dl->head=NULL;
    dl->last=NULL;
    dl->length--;
    free(todelete);
return ele;
}

int deletebegin(dll *dl)
{
    int ele;
    node *todelete;
    todelete=dl->head;
    ele=todelete->data;
    dl->head=todelete->next;
    dl->head->prev=NULL;
    free(todelete);
    dl->length--;
return ele;
}

int deleteend(dll *dl)
{
    int ele;
    node *todelete;
    todelete=dl->last;
    ele=todelete->data;
    dl->last=todelete->prev;
    dl->last->next=NULL;
    free(todelete);
    dl->length--;
return ele;
}

int deleteatposition(dll *dl,int pos)
{
    int i=1,ele;
    node *todelete,*current;
    current=dl->head;
    while(i!=pos-1)
    {
        current=current->next;
        i++;
    }
    todelete=current->next;
    ele=todelete->data;
    current->next=todelete->next;
    todelete->next->prev=todelete->prev;
    free(todelete);
    dl->length--;
return ele;
}


void main()
{
    dll dl;
    createdll(&dl);
    insertempty(&dl,100);
    insertbegin(&dl,50);
    insertend(&dl,200);
    insertend(&dl,100000);
    insertatposition(&dl,400,2);
    
    printf("\n%d \n",deletebegin(&dl));
    deleteend(&dl);
    deleteatposition(&dl,2);
    
    
    display(&dl);
    printf("\nLength of the doubly linked list is :  %d",length(&dl));
    getch();
}


