#include "Varchar.h"
#include <stdio.h>
int main() {
  int maxLen,lengthVar,i;
  Varchar vch;
  char c=' ';
  printf("Enter max length of varchar: ");
  scanf("%d", &maxLen);
  createVarchar(&vch,maxLen);
  printf("Enter length of String: ");
  scanf("%d", &lengthVar);
  scanf("%c",&c);
  for(i=0;i<lengthVar;i++){
    scanf("%c",&c);
    insertChar(&vch, c);
  }
  reverse(&vch);
  display(&vch);
  return 0;
}