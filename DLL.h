#ifndef DLL_H
#define DLL_H
// Define the structure for a doubly linked list node
struct DLL_node
{
    int data;
    struct DLL_node *prev;
    struct DLL_node *next;
};

typedef struct DLL_node DLL_node;

struct DLL{
    DLL_node *head;
    DLL_node *tail;
};

typedef struct DLL DLL;

void DLL_init(DLL *dll);
void removeAtHead(DLL *head);
DLL_node *createNode(int data);
void removeAtTail(DLL *head);
void insertAtHead(DLL *head, int data);
void insertAtTail(DLL *head, int data);
void printList(DLL *head);

#endif