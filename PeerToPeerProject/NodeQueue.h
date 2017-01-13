#include "Node.h"
struct slistEl
{
  struct slistEl * next;
  struct Node *data;
  int priority;

};

void showNodeQueue(struct slistEl *head);
void addNodeToQueue(struct slistEl **head, struct Node *value, int weight);
struct Node* takeNodeFromQueue(struct slistEl **head);
int isEmptyNodeQueue(struct slistEl *head);
int isNodeInQueue(struct slistEl *head,struct Node *value);