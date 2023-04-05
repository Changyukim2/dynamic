#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_STACK_SIZE 10

typedef int element;

typedef struct {
	int* data;
	int capacity;
	int top;
}Stacktype;

void init_stack(Stacktype* s) {

	s->top = -1;
	s->capacity = -1;
	s->data = (element*)malloc(s->capacity * sizeof(element));

}

int is_empty(Stacktype* s) {

	return (s->top == -1);

}
int is_full(Stacktype* s) {
	return (s->top == (s->capacity - 1));
}


void push(Stacktype* s, element item) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	if(s != NULL)
		s->data[++(s->top)] = item;

}

element pop(Stacktype* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		return -1;
	}
	else return s->data[(s->top)--];
}

int main(void) {
	Stacktype s;
	init_stack(&s);

	printf("--------Using dynamic---------\n");
	srand(time(NULL));
	int rand_num = rand() % 100;

	for (int i = 1; i <= 30; i++) {
		int rand_num = rand() % 99 + 1;
		
		if (rand_num % 2 == 0) {
			push(&s, rand_num);
			printf("반복수:%d  push %d\n", i, rand_num);
		}
		else {
			printf("반복수: %d  pop %d\n", i, pop(&s));
		}
	}
}















