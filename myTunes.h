struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};
struct song_node * addFront(struct song_node * prev, char * songName, char * artistName);
void printlistHelper(struct song_node * first);
void printList(struct song_node * first);
