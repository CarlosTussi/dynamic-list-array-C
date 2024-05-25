#pragma once

#include "Tools.h"



typedef struct {
	int* pBaseVector;
	unsigned int nMax_Elements;
	unsigned int nNumber_Elements;
}Vector;

/*
* Vector functions definitions
* 
*/

BOOL initialise_Vector(Vector* pVector, unsigned int size);
void deallocate_Vector(Vector* pvector);
BOOL pushBack(Vector* pVector, int elem);
void printVector(Vector* pVector);
