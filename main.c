#include "songLib.c"
#include <stdlib.h>
#include <time.h>
int main(){
  srand(time(NULL));
  struct song_node *head = NULL;
  char song0[] = "Here Comes The Sun";
  char artist0[] = "The Beatles";
  char song1[] = "Hey Jude";
  char song2[] = "Dreams and Nightmares";
  char artist1[] = "Meek Mill";
  char song3[] = "Marvin's Room";
  char artist2[] = "Drake";
  char song4[] = "Lucy In The Sky With Diamonds";
  printf("TESTING LINKED LIST FUNCTIONS\n");
  printf("Original Linked List:\n");
  print_list(head);
  printf("\n");
  head = addFront(head, &song0, &artist0);
  head = alphaAdd(head, &song1, &artist0);
  head = alphaAdd(head, &song2, &artist1);
  head = alphaAdd(head, &song3, &artist2);
  head = alphaAdd(head, &song4, &artist0);
  printf("After adding nodes alphabetically to Linked List// Testing print_list:\n");
  print_list(head);
  printf("\n");
  printf("Testing findFirstSong method // print_node method(prints first song from the Beatles):\n");
  print_node(findFirstSong(head,&artist0));
  printf("\n");
  printf("Testing findSong method // print_node method(prints song-Hey Jude,artist-The Beatles:\n");
  print_node(findSong(head,&song1,&artist0));
  printf("\n");
  printf("Testing randomNode method // print_node method(prints 3 random nodes)\n");
  print_node(randomNode(head));
  print_node(randomNode(head));
  print_node(randomNode(head));
  printf("\n");
  printf("Testing removeNode method(removes Marvin's Room By Drake from Linked List and then Hey Jude by the Beatles):\n");
  head = removeNode(head,findSong(head,&song3,&artist2));
  print_list(head);
  head = removeNode(head,findSong(head,&song1,&artist0));
  print_list(head);
  printf("\n");
  printf("Testing free_list method\n");
  head = free_list(head);
  print_list(head);
  printf("\n");
  printf("TESTING MUSIC LIBRARY\n");
  printf("\n");
  printf("Testing Adding Songs\n");
  char song5[] = "Nights";
  char song6[] = "White Ferrari";
  char artist3[] = "Frank Ocean";
  addSong(&song0,&artist0);
  addSong(&song1,&artist0);
  addSong(&song2,&artist1);
  addSong(&song3,&artist2);
  addSong(&song4,&artist0);
  addSong(&song5,&artist3);
  addSong(&song6,&artist3);
  print_library();
  printf("\n");
  
  printf("Testing Finding Songs in the Library\n");
  printf("looking for Here Comes the Sun By The Beatles\n");
  print_node(find(&artist0,&song0));
  printf("looking for Dreams and Nightmares by Meek Mill\n");
  print_node(find(&artist1,&song2));
  printf("looking for Lucy in the Sky with Diamonds by The Beatles\n");
  print_node(find(&artist0,&song4));
  printf("looking for Marvin's Room by the Beatles\n");
  print_node(find(&artist0,&song3));
  printf("\n");
  
  printf("Testing listing all entries under one letter\n");
  printf("The letter T\n");
  printLetter('T');
  printf("The letter F\n");
  printLetter('F');
  printf("\n");
  
  printf("Testing artist search function\n");
  printf("Checks if Frank Ocean is present in library\n");
  artistThere("Frank Ocean");
  printf("Checks if Kobe Bryant is present in library\n");
  artistThere("Kobe Bryant");
  printf("\n");

  printf("Testing one artist function\n");
  printf("printing all songs from the Beatles\n");
  printOneArtist("The Beatles");
  printf("\n");
  
  printf("Testing the shuffle functions\n");
  printf("printing a random shuffle\n");
  shuffle();
  printf("\n");

  printf("Testing delete function\n");
  printf("deleting marvins's room by drake\n");
  delete(&song3,&artist2);
  print_library();
  printf("\n");   

  printf("Testing clear library function\n");
  free_library();
  printf("Prints empty library\n");
  print_library();
  printf("\n");

}
