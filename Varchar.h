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
  for(i=0;i<len(&vch)/2;i++)
    {
      temp=left->data;
      left->data=right->data;
      right->data=temp;
      left=left->next;
      right=right->prev;
    }
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
