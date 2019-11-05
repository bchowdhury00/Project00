#include <stdio.h>
#include <stdlib.h>
#include "myTunes.h"

struct song_node * addFront(struct song_node * prev, char * songName, char * artistName){
  struct song_node * newNode = malloc(sizeof(struct song_node));
  int counter;
  for (counter = 0; counter < 100; counter++){
    if (counter != 99 ||  *(songName + counter) != NULL)
      *((newNode->name)+ counter) = *(songName + counter);
    else
      *((newNode->name) + counter) = NULL;
  }
  for (counter = 0; counter < 100; counter++){
    if (counter != 99 || *(songName + counter) != NULL)
      *((newNode->artist) + counter) = *(artistName + counter);
    else
      *((newNode->artist) + counter) = NULL;
  }
  newNode->next = prev;
  return newNode;
}

struct song_node * alphaAdd(struct song_node * first, char * newSong, char * newArtist){
  if (first == NULL || (strcmp(newArtist,&(first->artist)) < 0))
    return addFront(first,newSong,newArtist);
  struct song_node * place = first;
  struct song_node * newNode = malloc(sizeof(struct song_node));
  int counter;
  for (counter = 0; counter < 100; counter++){
    if (counter != 99 ||  *(newSong + counter) != NULL)
      *((newNode->name)+ counter) = *(newSong + counter);
    else
      *((newNode->name) + counter) = NULL;
  }
  for (counter = 0; counter < 100; counter++){
    if (counter != 99 || *(newArtist + counter) != NULL)
      *((newNode->artist) + counter) = *(newArtist + counter);
    else
      *((newNode->artist) + counter) = NULL;
  }
  while (place->next != NULL && strcmp(newArtist,place->artist) >= 0 ){
    char * pArtist = &((place->next)->artist);
    if (strcmp(newArtist,pArtist) < 0){
      newNode->next = (place->next)->next;
      place->next = newNode;
      return first;
    }
    if (strcmp(newArtist,pArtist) == 0){
      char * pSong = &((place->next)->name);
      if (strcmp(newSong,pSong) < 0){
	newNode->next = (place->next)->next;
	place->next = newNode;
	return first;
      }
      if (strcmp(newSong,pSong) == 0){
	printf("This song already exists in your library");
	return first;
      }
    }
    place = place->next;
  }
  newNode->next = place->next;
  place->next = newNode;
  return first;
}

struct song_node *findFirstSong(struct song_node * first, char * yourArtist){
  if (first == NULL)
    return NULL;
  if (strcmp(&(first->artist),yourArtist) == 0)
    return first;
  return findFirstSong(first->next,yourArtist);
}

struct song_node * findSong(struct song_node * first, char *song, char *yourArtist){
  if (first == NULL)
    return NULL;
  if (strcmp(&(first->artist),yourArtist) == 0 && strcmp(&(first->name),song)==0)
    return first;
  return findSong(first->next,song,yourArtist);
}

void printListHelper(struct song_node * first){
  if (first == NULL)
    return;
  int counter;
  for (counter = 0; counter < 99; counter++){
    if (*(first->name + counter) != NULL)
	printf("%c",*(first->name + counter));
    else
      break;
  }
  printf(" by ");
  for (counter = 0; counter < 99; counter++){
    if (*(first->artist + counter) != NULL)
      printf("%c",*(first->artist + counter));
    else
      break;
  }
  printf(", ");
  return printListHelper(first->next);
}

void print_list(struct song_node *first){
  printf("[");
  printListHelper(first);
  printf("]\n");
}

void print_node(struct song_node *ptr){
  if (ptr == NULL){
    printf("not found\n");
    return;
  }
  int counter;
  char * song = &(ptr->name);
  char * artist = &(ptr->artist);
  for (counter = 0; counter < strlen(ptr->name); counter++)
    printf("%c",*(song + counter));
  printf(" by ");
  for (counter = 0; counter < strlen(ptr->artist); counter++)
    printf("%c",*(artist + counter));
  printf("\n");
  return;
}

struct song_node * removeNode(struct song_node * first, struct song_node * remove){
  if (first == NULL)
    return NULL;
  if (first == remove){
    struct song_node * newHead = first->next;
    free(first);
    return newHead;
  }
  struct song_node * place = first;
  while (place->next != remove && place->next != NULL)
    place = place->next;
  place->next = (place->next)->next;
  free(remove);
  return first;
}

struct song_node * free_list(struct song_node * first){
  if(first == NULL)
    return first;
  struct song_node * next = first->next;
  free(first);
  return free_list(next);
}

int helperSize(struct song_node * first,int n){
  if (first == NULL)
    return n;
  return helperSize(first->next,n + 1);
}

int size(struct song_node * first){
  return helperSize(first,0);
}

struct song_node * randomNode(struct song_node * first){
  int counter = rand() % size(first);
  struct song_node * ranAns = first;
  while (counter != 0){
    ranAns = ranAns->next;
    counter--;
  }
  return ranAns;
}




    
    
  
 
    
 
      
