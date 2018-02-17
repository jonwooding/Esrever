#include "list.h"

/* Add node after pos */
void
e_listAdd(eListHead *node, eListHead *pos)
{
    eListHead tmp = *pos;
    pos->next = node;
    node->prev = pos;
    node->next = tmp.next;

    // fix up the ring if pos is a head
    if (pos->prev == pos)
    {
        pos->prev = node;
    }

}

/* Find last node of head and add node there */
void
e_listAddTail(eListHead *node, eListHead *head)
{
    e_listAdd(node, head->prev);
    head->prev = node;
}

void
e_listDel(eListHead *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

