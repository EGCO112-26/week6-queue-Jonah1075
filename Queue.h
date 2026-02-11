

typedef struct {
	 NodePtr headPtr,tailPtr;
	int size;
}Queue;


void enqueue_struct(Queue* q, int x){
  Node *new_node=(Node*) malloc(sizeof(Node));
if(new_node){ 
    new_node->data = x;
    new_node->nextPtr = NULL;
      /* Finish enqueue */
    if(q->size == 0) q->headPtr = new_node; 
    else q->tailPtr->nextPtr = new_node;
    q->tailPtr = new_node;
    q->size++;
 }
}


int dequeue_struct(Queue *q){
    if(q->headPtr == NULL)
        return -1;

    NodePtr t = q->headPtr;
    int value = t->data;

    q->headPtr = t->nextPtr;

    if(q->headPtr == NULL)
        q->tailPtr = NULL;

    free(t);
    q->size--;

    return value;
}
