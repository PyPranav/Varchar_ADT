#include<stdio.h>
#include "DLL.c"
int main()
{
  dll dl;
  createdll(&dl);
  insertIntoEmpty(&dl,100);
  insertBegin(&dl,50);
  insertEnd(&dl,200);
  insertEnd(&dl,100000);
  insertAtPosition(&dl,400,2);
  
  printf("\n%d deleted\n",deleteBegin(&dl));
  deleteEnd(&dl);
  // deleteatposition(&dl,2);
  
  
  display(&dl);
  printf("\nLength of the doubly linked list is :  %d",length(&dl));
  return 0;
}