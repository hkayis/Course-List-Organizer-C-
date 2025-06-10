#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist_int.h"

void createlist(node_t *head[],FILE*inp) {
	LType item;
	node_t* per;
	int id;
	while(fscanf(inp, "%d  %[^:]:%[^\n]", &id, item.name, item.time) != EOF) {
		per = head[id-1];
		
			head[id-1] = addBeginning(head[id-1], item);
		
	}
}
void display(node_t* hp) {
	node_t* dummy = hp;
	LType data;
	while (dummy != NULL) {
		data = dummy->data;
		printf("%s  %s->\n",data.name,data.time);
		dummy = dummy->next;
		
	}
	printf("NULL\n");
}
int main(void) {
	FILE* inp = fopen("courses.txt", "r");
	LType arr;
	node_t* head[3];
	for (int k = 0; k < 3; k++) {
		head[k] = NULL;
	}
	int id;
	
	createlist(head, inp);
	fclose(inp);
	printf("Aerobics\n");
	display(head[0]);
	printf("Zumba\n");
	display(head[1]);
	printf("Pilates\n");
	display(head[2]);
}