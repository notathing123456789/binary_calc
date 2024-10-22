#include "DLL.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Initializes the DLL
 */
void DLL_init(DLL *dll) {
    dll->head = NULL;
    dll->tail = NULL;
}

/**
 * Creates a node
 */
DLL_node *createNode(int data) {
    DLL_node *dlln = (DLL_node *)malloc(sizeof(DLL_node));
    if (dlln == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    dlln->data = data;  // Corrected the data assignment
    dlln->prev = NULL;
    dlln->next = NULL;
    return dlln;
}

/**
 * Inserts at the head in O(1)
 */
void insertAtHead(DLL *dll, int data) {
    DLL_node *temp = createNode(data);
    if (temp == NULL) {
        printf("Memory full\n");
        return;
    }

    temp->next = dll->head;  // New node points to the old head

    if (dll->head != NULL) {
        dll->head->prev = temp;  // Old head's prev points to new node
    } else {
        dll->tail = temp;  // If list was empty, tail points to new node
    }

    dll->head = temp;  // Head now points to new node
}

/**
 * Inserts at the tail in O(1)
 */
void insertAtTail(DLL *dll, int data) {
    DLL_node *temp = createNode(data);
    if (temp == NULL) {
        printf("Memory full\n");
        return;
    }

    temp->prev = dll->tail;  // New node's prev points to old tail

    if (dll->tail != NULL) {
        dll->tail->next = temp;  // Old tail's next points to new node
    } else {
        dll->head = temp;  // If list was empty, head points to new node
    }

    dll->tail = temp;  // Tail now points to new node
}

/**
 * Removes from the tail in constant time
 */
void removeAtTail(DLL *dll) {
    if (dll->tail == NULL) return;  // If list is empty, nothing to remove

    DLL_node *temp = dll->tail;

    if (dll->head == dll->tail) {
        // If there's only one node, both head and tail become NULL
        dll->head = dll->tail = NULL;
    } else {
        dll->tail = dll->tail->prev;  // Update tail to the previous node
        dll->tail->next = NULL;  // New tail's next is NULL
    }

    free(temp);  // Free the old tail node
}

/**
 * Removes from the head in constant time
 */
void removeAtHead(DLL *dll) {
    if (dll->head == NULL) return;  // If list is empty, nothing to remove

    DLL_node *temp = dll->head;

    if (dll->head == dll->tail) {
        // If there's only one node, both head and tail become NULL
        dll->head = dll->tail = NULL;
    } else {
        dll->head = dll->head->next;  // Update head to the next node
        dll->head->prev = NULL;  // New head's prev is NULL
    }

    free(temp);  // Free the old head node
}

/**
 * Prints the list by iterating through it
 */
void printList(DLL *dll) {
    printf("[");

    DLL_node *temp = dll->head;
    while (temp != NULL) {
        printf(" %d", temp->data);
        if (temp->next != NULL) {
            printf(",");  // Print comma only between elements
        }
        temp = temp->next;
    }

    printf(" ]\n");
}
