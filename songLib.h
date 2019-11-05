struct song_node * table[27];
int getIndex(char * artist);
void addSong(char * songName, char * artistName);
void print_library();
struct song_node * find(char * song, char * artist);
void artistThere(char * artist);
void printOneArtist(char * artist);
void printLetter(char a);
void delete(char * song, char * artist);
void shuffle();
void free_library();

