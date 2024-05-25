#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int value;
	struct LNode* next;

}LNode;

typedef struct {
	struct LNode* head_node;
	unsigned int num_elements;
}LList;


#define FALSE 0
#define TRUE 1
typedef int BOOL;

LList* initializeList();
int insertElement(LList* head, int elem);
void removeElement(LList* head, int elem);
void printList(LList* head);
void searchElement(LList* head, int elem);
void removeElement(LList* head, int elem);
void destroyList(LList* head);