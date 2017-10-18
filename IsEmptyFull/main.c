#include <stdio.h>
#include <stdlib.h>

#define max_s 100

typedef int elem;
typedef struct {
	elem list[max_s];
	int legth;
}IsList;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(IsList *L) {
	L->legth = 0;
}

int is_empty(IsList *L) {
	if (L->legth == 0) return 1;
	else return 0;
}

int is_full(IsList *L) {
	if (L->legth == max_s) return 1;
	else return 0;
}

void display(IsList *L) {
	for (int i = 0; i < L->legth; i++) printf("%d\n", L->list[i]);
}

void add(IsList *L, int pos, elem item) {
	if (is_full(L)) {
		printf("오류: 메모리가 부족합니다.\n\n");
		exit(1);
	}
	if (pos >= 0 && pos <= L->legth) {
		for (int i = L->legth - 1; i >= pos; i--) L->list[i + 1] = L->list[i];
		L->list[pos] = item;
		L->legth++;
	}
}

elem rm(IsList *L, int pos) {
	elem item;
	if (pos < 0 || pos >= L->legth) error("아이쿠 실수. 위치오류");
	item = L->list[pos];
	for (int i = pos; i < (L->legth - 1); i++) L->list[i] = L->list[i + 1];
	L->legth--;
	return item;
}

int main() {
	IsList A;
	IsList *pA;

	init(&A);
	add(&A, 0, 10);
	add(&A, 0, 20);
	add(&A, 0, 10);
	add(&A, 2, 25);
	display(&A);
	printf("\n\n");

	pA = (IsList *)malloc(sizeof(IsList));
	init(pA);
	add(pA, 0, 10);
	add(pA, 0, 20);
	add(pA, 0, 10);
	add(pA, 2, 25);
	display(pA);
	free(pA);
}