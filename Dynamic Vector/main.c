#include "Vector.h"

void main() {
	Vector v1;

	//Initialize vector
	initialise_Vector(&v1, 5);					//Initialize vector with max 5 int elements

	//Check if vector was initialized successfully
	if (v1.pBaseVector != NULL) {

		//New vector allocated info
		printf("Number of elements: %d \n", v1.nNumber_Elements);				
		printf("Memory size allocated: %d bytes\n", v1.nMax_Elements*sizeof(int));					//Memory size allocated bytes
		printf("Base address of pointer: %p \n\n\n", v1.pBaseVector);
	
	
		//Adding elements at the end of the vector
		pushBack(&v1, 31);					
		pushBack(&v1, 1);
		pushBack(&v1, 40);
		pushBack(&v1, -10);
		pushBack(&v1, 99);
		//Adding 6th element, reallocation needed
		pushBack(&v1, 101);
		printf("New memory size allocated: %d bytes\n", v1.nMax_Elements * sizeof(int));					//Memory size allocated bytes

		//Print array
		printVector(&v1);


		//Deallocate vector
		deallocate_Vector(&v1);
		if (v1.pBaseVector == NULL) {
			printf("\V1 deallocated\n\n");
		}
		else {
			printf("\nError - memory not deallocated\n\n");
		}
	}

}
