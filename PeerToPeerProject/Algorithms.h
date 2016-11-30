struct UserFile
{
	int user;
	int *files;
	int fileAmount;
};


int dfs(int **matrix, int size, int begin, int file, struct UserFile *userFile);
int bfs(int **matrix, int size, int user, int file, struct UserFile *userFile);
int belmanFord(int **matrix, int size, int user, int file, struct UserFile *userFile);
int prim(int **matrix, int size, int user, int file, struct UserFile *userFile);
int dijkstra(int **matrix, int size, int begin, int file, struct UserFile *userFile);

