/*	Uiversal_queue.h -- 队列头文件	*/

#include "Head.h"

/*	Define data type	*/

typedef struct node
{
	Item item ;
	struct node * next ;
} Node ;
typedef struct queue
{
	Node * front ;
	Node * rear ;
	int current ;
} * Queue ;

/*	Proclaim interface functions	*/

Bool Initialize_Q (Queue * const pq) ;

Bool IsEmpty_Q (const Queue * const pq) ;

Bool Insert_Q (Queue * const pq, const Item * const pi) ;

Bool Delete_Q (Queue * const pq, Item * const pi) ;

void Traversal_Q (const Queue * const pq, void (* pfun) (const Item * const pi)) ;

void Release_Q (const Queue * const pq) ;