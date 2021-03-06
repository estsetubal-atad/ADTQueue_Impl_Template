/**
 * @file queueLinkedList.c
 * 
 * @brief Provides an implementation of the ADT Queue with a 
 * doubly-linked list with sentinels as the underlying 
 * data structure.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "queue.h" 
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node* PtNode;

typedef struct node {
	QueueElem element;
	PtNode prev;
	PtNode next;
} Node;

typedef struct queueImpl {
	PtNode header;
	PtNode trailer;
	int size;
} QueueImpl;


PtQueue queueCreate() {

	// TODO
	
	return NULL;
}

int queueDestroy(PtQueue *ptQueue) {
	PtQueue queue = *ptQueue;
	if (queue == NULL) { return QUEUE_NULL;	}

	/* This algorithm free all nodes including sentinels */
	PtNode current = queue->header;
	while (current != NULL) {
		PtNode remove = current;
		current = current->next;
		free(remove);
	}

	free(queue);

	*ptQueue = NULL;

	return QUEUE_OK;
}

int queueEnqueue(PtQueue queue, QueueElem elem) {
	if (queue == NULL) {return QUEUE_NULL;	}

	// TODO

	return QUEUE_OK;
}

int queueDequeue(PtQueue queue, QueueElem *ptElem) {
	if (queue == NULL) {return QUEUE_NULL;	}

	if (queueIsEmpty(queue)) {return QUEUE_EMPTY;	}

	// TODO

	return QUEUE_OK;
}

int queueFront(PtQueue queue, QueueElem *ptElem) {
	if (queue == NULL) {return QUEUE_NULL;	}

	if (queueIsEmpty(queue)) {	return QUEUE_EMPTY;	}

	// TODO
	
	return QUEUE_OK;
}

int queueSize(PtQueue queue, int *ptSize) {
	if (queue == NULL) return QUEUE_NULL;

	*ptSize = queue->size;

	return QUEUE_OK;
}

bool queueIsEmpty(PtQueue queue) {
	if (queue == NULL) return true;

	return (queue->size == 0);
}

int queueClear(PtQueue queue) {
	if (queue == NULL) return QUEUE_NULL;
	
	/* Can leverage queueDequeue to free nodes 
		and decrement size */
	QueueElem elem;
	while (!queueIsEmpty(queue)) {
		queueDequeue(queue, &elem);
	}

	return QUEUE_OK;
}

void queuePrint(PtQueue queue) {
	if (queue == NULL) {
		printf("(Queue NULL) \n");
	}
	else if (queue->header->next == queue->trailer) {
		printf("(Queue Empty) \n");
	}
	else {
		printf("Queue contents (front to end): \n");
		
		// TODO
		
		printf("\n------------------------------ \n");
	}
}

