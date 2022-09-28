#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <climits>

typedef struct _Node
{
    int value;
    struct _Node *prev;
    struct _Node *next;
} Node;

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void add(int value);
    void insert(int index, int value);
    void remove(int index);
    void clear();
    void printForwardOrder();
    void printReverseOrder();

private:
    Node *getNode(int index = INT_MAX);

    Node *head = nullptr;
};
#endif
