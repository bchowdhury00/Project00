struct song_node * addFront(struct song_node * prev, char * songName, char * artistName){
  struct song_node *newNode = malloc(sizeof(struct song_node));
  int counter;
  for (counter = 0; counter < 100; counter++){
    if (*(songName + counter) != "\0" && counter != 99) 
      (newNode->name)[counter] = *(songName + counter);
    else{
      (newNode->name)[counter] = "\0";
      break;
    }
  }
  for (counter = 0; counter < 100; counter++){
    if (*(artistName + counter) != "\0" && counter != 99) 
      (newNode->artist)[counter] = *(artistName + counter);
    else{
      (newNode->artist)[counter] = "\0";
      break;
    }
  }
  newNode.nextNode = prev;
  return newNode;
}

struct song_node * alphabeticalAddition(struct song_node * first, char * songName, char * artistName){
  
	  
