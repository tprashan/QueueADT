// # include "../../LinkedList/-LinkedListADT/linkedList.h"
# include "linkedList.h"	

typedef struct queue Queue;

struct queue{
	LinkedList* list;
	node_ptr* Front;
	node_ptr* Rear;
};

Queue createQueue(void);
int push(Queue queue, void * data);
void * pop(Queue queue);