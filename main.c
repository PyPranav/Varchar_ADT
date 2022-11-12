#include "Varchar.h"
#include <stdio.h>
int main() {
  int maxLen,lengthVar,i,choice=0,temp;
  Varchar vch;
  char c=' ',stripch;
  printf("Enter max length of varchar: ");
  scanf("%d", &maxLen);
  createVarchar(&vch,maxLen);
  printf("Enter length of String: ");
  scanf("%d", &lengthVar);
  scanf("%c",&c);
  printf("Enter String: ");
  for(i=0;i<lengthVar;i++){
    scanf("%c",&c);
    insertChar(&vch, c);
  }
   
  while(choice!=4){
	  printf("1. Display\n2. Reverse\n3. Strip\n4. Exit\nInput Choice: ");
	  scanf("%d", &choice);
	  switch(choice){
	  	case 1:
	  	  printf("Stored String is : ");
		  display(&vch);
		  if (maxLen>len(&vch))
		      temp = maxLen-len(&vch);
		  else temp = 0;
		  printf("\n%d spaces used and %d spaces freed\n",len(&vch), temp);
		  break;
		case 2:
		  reverse(&vch);
		  printf("After Reverse: ");
		  display(&vch);
		  printf("\n");
		  break;
		case 3:
		  printf("Enter char to strip: ");
		  scanf("%c",&stripch);
		  scanf("%c",&stripch);
		  strip(&vch, stripch);
		  printf("After Strip: ");
		  display(&vch);
		  printf("\n");
		  break;
		case 4:
		  continue;
		default:
		  printf("Enter valid choice!\n");
	  }
  }
  return 0;
}
