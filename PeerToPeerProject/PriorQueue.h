
struct slistEl
{
  struct slistEl * next;
  int data;
  int priority;

};

void showQueue(struct slistEl *head);
void addToQueue(struct slistEl **head, int value, int weight);
int takeFromQueue(struct slistEl **head);
int isEmpty(struct slistEl *head);