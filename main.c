#include "myTunes.h"
#include <stdlib.h>
int main(){
  struct song_node *head = NULL;
  char song0[] = "Here Comes The Sun";
  char artist0[] = "The Beatles";
  head = addFront(head, &song0, &artist0);
  printList(head);
}
