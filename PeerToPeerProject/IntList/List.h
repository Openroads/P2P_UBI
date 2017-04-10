struct listEl
{
  struct listEl * next;
  int data;

};

void showList(struct listEl *head);
void addToList(struct listEl **head, int value);
int get(struct listEl **head);
int isEmpty(struct listEl *head);
int isInList(struct listEl *head,int value);