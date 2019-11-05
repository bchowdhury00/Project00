#include <stdio.h>
#include <stdlib.h>
#include "myTunes.c"
#include "songLib.h"

int getIndex(char * artist){
  char a = artist[0];
  int n = a % 65;
  if (n > 25 || n < 0){
    return 26;
  }
  return n;
}

void addSong(char * songName, char * artistName){
  struct song_node * headNode = table[getIndex(artistName)];
  table[getIndex(artistName)] = alphaAdd(headNode,songName,artistName);
  return;
}



void print_library(){
  int counter;
  for (counter =0; counter < 27; counter++)
    if (table[counter] != NULL){
      printf("%c list:\n",((char)(65 + counter)));
      print_list(table[counter]);
    }
  return;
}

struct song_node * find(char * artist, char * song){
  struct song_node * head = table[getIndex(artist)];
  return findSong(head,song,artist);
}

void artistThere(char * artist){
  struct song_node * head = table[getIndex(artist)];
  if (findFirstSong(head,artist) == NULL){
    printf("Artist Not Found\n");
    return;
  }
  printf("Artist found!\n");
  return;
}

void printOneArtist(char * artist){
  struct song_node * node= table[getIndex(artist)];
  while (node != NULL){
    if (strcmp(&(node->artist),artist) == 0)
      print_node(node);
    node = node->next;
  }
  return;
}

void printLetter(char a){
  int n = a % 65;
  if (n > 25 || n < 0){
    n= 26;
  }
  struct song_node * letter = table[n];
  print_list(letter);
  return;
}

void delete(char * song, char * artist){
  struct song_node * head = table[getIndex(artist)];
  struct song_node * remove = find(artist,song);
  table[getIndex(artist)] = removeNode(head,remove);
  return;
}

void shuffle(){
  int counter;
  for (counter =0; counter < 27; counter++)
    if (table[counter] != NULL)
      print_node(randomNode(table[counter]));
}
    
  
void free_library(){
  int counter;
  for (counter =0; counter < 27; counter++)
    if (table[counter] != NULL)
      table[counter] = free_list(table[counter]);
  return;
}
