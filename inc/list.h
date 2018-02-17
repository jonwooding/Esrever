#include "types.h"

#ifndef LIST_H
#define LIST_H

static void
e_listAdd(eListHead *node, eListHead *head);

static void
e_listAddTail(eListHead *node, eListHead *head);

static void
e_listDel(eListHead *node);

#define LIST_HEAD_INIT(list)		\
	{ &(list), &(list) }

#define INIT_LIST_HEAD(list)		\
	eListHead list = LIST_HEAD_INIT(list)

/* Returns uint of 0->member which is offset of member */
#define e_offsetof(type, member) \
	((eu32)&((type*)0)->member)

/* Get struct of type from node */
#define e_listEntry(node, type, member)    \
    (type*)((node)-e_offsetof(type, member))

#define e_listFirstEntry(head, type, member) \
	e_listEntry((head)->next, type, member)

#define e_listNextEntry(node, type, member) \
	e_listEntry((node)->member.next, type, member)

#define e_listLastEntry(head, type, member) \
	e_listEntry((head)->prev, type, member)

/* Iterate over list head with nodes named node */
#define e_listForEach(node, head)          \
    for (node = (head)->next;           \
         node != head;              \
         node = (node)->next)

#define e_listForEachPrev(node, head)          \
    for (node = (head)->prev;           \
         node != head;              \
         node = (node)->prev)

#define e_listForEachSafe(node, head) \
	eListHead *tmp; \
	for (node =(head)->next, tmp = node; \
		 node != head; \
		 node = tmp, tmp = (node)->next )

// node is a type*
#define e_listForEachEntry(node, head, type, member)				\
	for (node = e_listFirstEntry(head, type, member);	\
	     &node->member != (head);					\
	     node = e_listNextEntry(node, type, member))

#define e_listForEachEntrySafe(node, head, type, member)			\
	eListHead *tmp;\
	for (node = e_listFirstEntry(head, type, member),	\
		tmp = e_listNextEntry(node, type, member);			\
	     &node->member != (head); 					\
	     node = tmp, tmp = e_listNextEntry(tmp, type, member))



#endif
