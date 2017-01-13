#include "Node.h"
struct listEl
{
  struct listEl * next;
  struct Node *data;

};

void showNodeList(struct listEl *head);
void addNodeToList(struct listEl **head, struct Node *value);
struct Node* getFirstNode(struct listEl **head);
int isNodeListEmpty(struct listEl *head);
int isNodeInList(struct listEl *head,struct Node *value);