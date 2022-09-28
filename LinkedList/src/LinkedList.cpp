#include "LinkedList.h"

#include <iostream>

using namespace std;

LinkedList::LinkedList() {}

LinkedList::~LinkedList()
{
    clear();
}

void LinkedList::add(int value)
{
    Node *prev = getNode();

    if (prev == nullptr)
    {
        head = new Node{value, nullptr, nullptr};
        return;
    }

    prev->next = new Node{value, prev, nullptr};
}

void LinkedList::insert(int index, int value)
{
    Node *next = getNode(index);

    if (next == nullptr)
    {
        head = new Node{value, nullptr, nullptr};
        return;
    }

    Node *prev = next->prev;
    Node *node = new Node{value, prev, next};
    next->prev = node;

    if (prev == nullptr)
    {
        head = node;
    }
    else
    {
        prev->next = node;
    }
}

void LinkedList::remove(int index)
{
    Node *node = getNode(index);

    if (node == nullptr)
    {
        return;
    }

    if (node->prev == nullptr)
    {
        head = node->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
    }
    else
    {
        node->prev->next = node->next;
        if (node->next != nullptr)
        {
            node->next->prev = node->prev;
        }
    }

    delete node;
}

void LinkedList::sort()
{
    Node *condition = nullptr;

    while (condition != head)
    {
        Node *ptr = head;

        while (ptr->next != condition)
        {
            if (ptr->value > ptr->next->value)
            {
                int temp = ptr->value;
                ptr->value = ptr->next->value;
                ptr->next->value = temp;
            }
            ptr = ptr->next;
        }
        condition = ptr;
    }
}

void LinkedList::clear()
{
    Node *ptr = head;

    while (ptr)
    {
        Node *next = ptr->next;
        delete ptr;
        ptr = next;
    }

    head = nullptr;
}

void LinkedList::printForwardOrder()
{
    int index = 0;
    Node *ptr = head;

    while (ptr)
    {
        cout << "[" << index++ << "]" << ptr->value << endl;
        ptr = ptr->next;
    }
}

void LinkedList::printReverseOrder()
{
    int index = 0;
    Node *ptr = getNode();

    while (ptr)
    {
        cout << "[" << --index << "]" << ptr->value << endl;
        ptr = ptr->prev;
    }
}

Node *LinkedList::getNode(int index)
{
    index = (index < 0) ? 0 : index;

    if (head == nullptr)
    {
        return nullptr;
    }

    int i = 0;
    Node *ptr = head;

    while (i++ < index && ptr->next != nullptr)
    {
        ptr = ptr->next;
    }

    return ptr;
}
