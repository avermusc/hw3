#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  if (head == NULL){
    smaller = NULL;
    larger = NULL;
    return;
  }
  Node* temp = head->next;
  llpivot(temp, smaller, larger, pivot);
  if (head->val > pivot){
    head->next = larger;
    larger = head;
  }
  else{
    head->next = smaller;
    smaller = head;
  }
  head = NULL;
}


