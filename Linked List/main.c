#include "linkedlist.h"


int main() {

	LList* head;
	LList* errorHead= NULL;


	//Initializing list
	head = initializeList();


	//Inserting element
	if (head != NULL) {
		insertElement(head, 5);	 //Inserting on empty list
		insertElement(head, 7);  //Inserting last element
		insertElement(head, -1); //Inserting first element
		insertElement(head, 4);  //Inserting in the middle
	
		//Iterating
		printList(head);			//Print list

		//Search for element
		searchElement(head, -1);		//Search head element
		searchElement(head, 4);			//Search middle element
		searchElement(head, 7);			//Search last element
		searchElement(errorHead, 74);	//Search for inexistant element

		//Removing Element
		printf("\n\nOriginal list: ");	//Print original list before the removals
		printList(head);

		removeElement(head, -1);		//Remove head element
		printf("Head element removed: ");
		printList(head);

		removeElement(head, 5);			//Remove middle element
		printf("Middle element removed: ");
		printList(head);

		removeElement(head, 7);			//Remove last element
		printf("Last element removed: ");
		printList(head);

		removeElement(head, 4);			//Make list empty
		printf("List empty: ");
		printList(head);

		removeElement(head, 99);				//Trying to remove element that does not exist
		removeElement(errorHead, 88);			//Trying to remove from unitialized list
		removeElement(head, 1);					//Removing from empty list



		//Inserting to destroy
		printf("\n\n");
		insertElement(head, 91);	 //Inserting on empty list
		insertElement(head, 92);  //Inserting last element
		insertElement(head, 93); //Inserting first element
		insertElement(head, 94);  //Inserting in the middle

		printList(head);
		printf("Destroying list...\n");
		destroyList(head);

	}

}