#include <stdio.h>
#include "DLL.h"

typedef struct Varchar{
  dll charLL;
  int maxLength; 
}Varchar;

void createVarchar(Varchar *vch, int maxLen){
  createDll(&vch->charLL);
  vch->maxLength = maxLen;
}

int len(Varchar *vch){
  return length(&vch->charLL);
}

void insertChar(Varchar *vch, char ch){
  if (len(vch)==0)
    insertIntoEmpty(&vch->charLL, ch);
  else if (len(vch)>=vch->maxLength)
    return;
  else
    insertEnd(&vch->charLL, ch);
}

void reverse(Varchar *vch)
{
  node *left=vch->charLL.head,*right=vch->charLL.last;
  int i=0, temp;
  for(i=0;i<len(vch)/2;i++)
    {
      temp=left->data;
      left->data=right->data;
      right->data=temp;
      left=left->next;
      right=right->prev;
    }
}
void lstrip(Varchar *vch,char ch){
  node *toDelete;
  while(vch->charLL.head->data == ch){
    vch->charLL.length--;
    toDelete = vch->charLL.head;
    vch->charLL.head = toDelete->next;
    free(toDelete);
  }
}

void rstrip(Varchar *vch,char ch){
  node *toDelete;
  while(vch->charLL.last->data == ch){
    vch->charLL.length--;
    toDelete = vch->charLL.last;
    vch->charLL.last = toDelete->prev;
    free(toDelete);
  }
}

void strip(Varchar *vch, char ch){
  rstrip(vch,ch);
  lstrip(vch,ch);
}
void display(Varchar *vch){
  int i;
  node *cur = vch->charLL.head;
  for(i=0;i<len(vch);i++)
    {
      printf("%c",cur->data);
      cur=cur->next;
    }
}
