struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};
struct song_node * addFront(struct song_node * prev, char * songName, char * artistName);
struct song_node * alphaAdd(struct song_node * first, char * newSong, char * newArtist);
struct song_node *findFirstSong(struct song_node * first, char * yourArtist);
struct song_node * findSong(struct song_node * first, char *song, char *yourArtist);
void printListHelper(struct song_node * first);
void print_list(struct song_node * first);
void print_node(struct song_node *ptr);
struct song_node * removeNode(struct song_node * first, struct song_node * remove);
struct song_node * free_list(struct song_node * first);
int helperSize(struct song_node * first,int n);
int size(struct song_node * first);
struct song_node * randomNode(struct song_node * first);
