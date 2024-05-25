#include "Vector.h"


#define EXPANSION_SIZE 20 //Expansion size: 20 new elements each expansion

BOOL initialise_Vector(Vector* pVector, unsigned int size) {

	pVector->nNumber_Elements = 0;
	pVector->pBaseVector = (int*)malloc(sizeof(int) * size);

	if (pVector->pBaseVector != NULL) {
		pVector->nMax_Elements = size;
		return TRUE;

	}
	else {
		return FALSE;
	}
}


void deallocate_Vector(Vector* pVector) {

	if (pVector->pBaseVector != NULL)
	{
		free(pVector->pBaseVector);
		pVector->pBaseVector = NULL;
	}


}

BOOL pushBack(Vector* pVector, int elem) {

	BOOL success = FALSE;

	//CHeck if vector has been initialized
	if (pVector != NULL) {
		//Check if pointer to the beginning of vector not NULL
		if (pVector->pBaseVector != NULL) {
			//If there is enough space
			if (pVector->nMax_Elements > pVector->nNumber_Elements)
			{
				//Insert at last position of vector
				pVector->pBaseVector[pVector->nNumber_Elements] = elem;
				pVector->nNumber_Elements++;
				success = TRUE;
			}
			//Not enough space
			else {
				//Reallocation
				//Deciding the size to increase: Using heuristic (Linear Amortised Constant Time)
				int* pNewArray = (int*)malloc(sizeof(int) * pVector->nMax_Elements + EXPANSION_SIZE);

				if (pNewArray != NULL) {
					//Both vectors allocated in memory
					//Copy elements from old vecetor to new one
					for (int i = 0; i < pVector->nNumber_Elements; i++) 
						pNewArray[i] = pVector->pBaseVector[i];

					//Deallocate old vector
					free(pVector->pBaseVector);

					//Update the start of the vector to point to the new vector
					pVector->pBaseVector = pNewArray;
					pVector->nMax_Elements += EXPANSION_SIZE;

					//Update the new total number of elements
					pVector->pBaseVector[pVector->nNumber_Elements] = elem;
					pVector->nNumber_Elements++;
					

				}
			}
		}

	}

	return success;
}

void printVector(Vector* pVector) {
	if (pVector != NULL) {
		if (pVector->pBaseVector != NULL) {
			for (int i = 0; i < pVector->nNumber_Elements; i++) {
				printf("[ %d ]", pVector->pBaseVector[i]);
			}
		}
	}

	printf("\n");
}