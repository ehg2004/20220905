#include "list.h"

/* */
List* merge (List *A, List *B)
{
  List * l1 = A;
  List * l2 = B;
  List * l3 = NULL;


  while (l1->next!=NULL)
  { 
    l3=insert(l3,l1);
    while (l2->next!=NULL)
    {
      if((l2->data)>l3->data)
      {
        insert(l3, l2->data);
        break;
      }


      l2=l2->next;
    }
    l1=l1->next;
  }
  return(l3);
}

/* */
int main () {
  int k;
  List *A = NULL, *B = NULL;
  for (k = 10; k >= 0; k -= 2) 
    A = insert (A, k);
  for (k = 19; k >= 0; k -= 2) 
    B = insert (B, k);
  print (A);
  print (B);
  List *C = merge (A, B);
  print (C);
  destroy (C);
  return 0;
}
