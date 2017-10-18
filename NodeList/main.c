#include <stdio.h>
#include <stdlib.h>

typedef int elem;
typedef struct NodeList {
	elem data;
	struct NodeList *link;
} NodeList;

void insert(NodeList **head, NodeList *pos, NodeList *new) {
	if (*head = NULL) {
		new->link = NULL;
		*head = new;
	}
	else if (pos == NULL) {
		new->link = *head;
		*head = new;
	}
	else {
		new->link = pos->link;
		pos->link = new;
	}
}

