	#include "linkedlist.h"

	//Initiates the head of the list with first element
	LList* initializeList() {
		LList* pHead = (LList*)malloc(sizeof(LList));		//Allocated header pointer  for the Linked List
		if (pHead != NULL) {
			pHead->head_node = NULL;
			pHead->num_elements = 0;						//Initial number of elements = 0
			return pHead;
		}
		else
			return NULL;							


	}

	//Insert new element in order
	int insertElement(LList* head, int elem) {

		BOOL success = FALSE;		//Indicates the return status of the insertion

		//Empty not initialized
		if (head == NULL) {
			printf("List not initialized\n");
			success = FALSE;
		}
		//List initialized 
		else {
			LNode* head_node = head->head_node;
			//Allocates memory for new element
			LNode* new_elem = (LNode*)malloc(sizeof(LNode));	//Allocated new node for the new element off the list
			if (new_elem != NULL) {
				new_elem->value = elem;		//Update the value (data) to be inserted in the list

				//If list is empty
				if (head_node == NULL) {
					//List empty, adding head of the list
					new_elem->next = NULL;	//Only element on the list, next is NULL
					head->head_node = new_elem;	//Header points to the newly created element
				}
				//List not empty
				else {
					//Insertion beginning of the list
					if (elem < head_node->value) {
						new_elem->next = head_node;		//New head points to the old head
						head->head_node = new_elem;		//Update new head
					}
					//Insert middle of the list
					else {
						LNode* current = head_node->next;			//Current node being checked
						LNode* previous = head_node;				//Previously checked node
						BOOL insertionCompleted = FALSE;			//Indicates element has been inserted

						while (current != NULL && insertionCompleted == FALSE) {	//Iterate over the list checking for the right place to insert element
							//Insertion point is found
							if (elem < current->value) {
								previous->next = new_elem;			//Previous node points to new node
								new_elem->next = current;			//New node inserted before current analysed node
								insertionCompleted = TRUE;			//Indicate insertion has been completed
							}
							previous = current;						//Save node that has been analysed
							current = current->next;				//Check next node
						}
						//Insertion end of the list
						if (current == NULL & insertionCompleted == FALSE) {	//If checked all the elements and no insertion made (insert end of list)
							previous->next = new_elem;							//Last element points to the new element
							new_elem->next = NULL;								//New element points to NULL
						}
					}
				}
				
				success = TRUE;
				head->num_elements++;	//Update header counter for number of elements
			}
			//Memory allocation failed
			else 
				success = FALSE;

		}
		return success;

	}

	//Print all the items from the list ordered
	void printList(LList* head) {

		if (head != NULL) {				//Check if list is not initialized
			LNode* current = head->head_node;

			while (current != NULL) {		//Print all the values
				printf("[ %d ] ", current->value);
				current = current->next;
			}
			printf("\n");
		}
		
	}

	//Search for an specific element from the list
	void searchElement(LList* head, int elem) {
		if (head != NULL)							//Check if list has been initialized
		{
			LNode *current = head->head_node;		//To iterate over the list. Initial value is the first element of the list
			BOOL isElementFound = FALSE;			//Indicate that the item was found

			while (current != NULL && isElementFound == FALSE)		//Iterate through the list looking for the element
			{
				if (current->value == elem) {						//If item found
					printf("[SUCCESS] Element %d found!\n", elem);
					isElementFound = TRUE;
				}
				current = current->next;
			}
			if (isElementFound == FALSE)			//If item not found after checking the whole list
				printf("[FAILED] Element %d not found \n", elem);
			
		}
		else
			printf("[ERROR] Element does not exist - list not initialised. \n");		//If list not initialized
		


	}

	void removeElement(LList* head, int elem) {

		//List not initialized
		if (head == NULL) 
		{
			printf("[ERROR] List not initialized - Could not remove element\n");
		}
		else {
			//Empty list
			if (head->head_node == NULL) 
			{
				printf("[ERROR] List empty - Could not remove element\n");
			}
			else 
			{
				LNode* current = head->head_node; //Temporary variable to iterate through the list

				//Remove first element
				if (current->value == elem)
				{
					head->head_node = current->next;	//Update the new header
					free(current);						//Free old head of the list
				}
				//Remove middle element
				else
				{
					BOOL isElementFound = FALSE;
					LNode *previous = head->head_node; //Save the previous pointer to update the links after removal
					current = current->next;
					while (current != NULL && isElementFound == FALSE)  //Iterate through the list until end of list or element is found
					{
						if (current->value == elem) //If element found
						{
							previous->next = current->next;
							isElementFound = TRUE;
							free(current);	
						}
						else
							current = current->next;
					}
					//If element was removed, free memory previously allocated
					if (isElementFound == FALSE)
						printf("[ERROR] - Element does not exist - Could not remove element\n");
				}
			}
		}
	}

