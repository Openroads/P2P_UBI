struct UserFile
{
	int user;
	int *files;
	int fileAmount;
};

int hasFile(int v, int file, int size, struct UserFile *userFile);
int dfs(int **matrix, int size, int begin, int file, struct UserFile *userFile);
int bfs(int **matrix, int size, int user, int file, struct UserFile *userFile);
int belmanFord(int **matrix, int size, int user, int file, struct UserFile *userFile);
int prim(int **matrix, int size, int user, int file, struct UserFile *userFile);
int dijkstra(int **matrix, int size, int begin, int file, struct UserFile *userFile);
int kruskal(int **matrix, int size, int begin, int file, struct UserFile *userFile);
int floydMarshall(int **matrix, int size, int begin, int file, struct UserFile *userFile);
