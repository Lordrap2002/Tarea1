#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList LinkedList;
typedef struct Node Node;

struct Node{
    int item;
    Node *next;
};

struct LinkedList{
   Node *head;
   void (*add) (LinkedList *, Node *);
   Node* (*get) (LinkedList *, int);
   void (*delete) (LinkedList *, Node *);
   void (*removeLinus) (LinkedList *, Node *);
   void (*printList) (LinkedList *);
};

void add(LinkedList *l, Node *entry ){
    Node **walk = &(l->head);
    while(*walk){
        walk = &(*walk)->next;
    }
    *walk = entry;
}

Node* get(LinkedList *l, int n){
    Node *node = l->head;
    while(n){
        node = node->next;
        n--;
    }
    return node;
}

void delete(LinkedList *l, Node *entry){
    Node *prev = NULL, *walk = l->head;
    while(walk != entry){
        prev = walk;
        walk = walk->next;
    }
    if(!prev){
        l->head = entry->next;
    }else{
        prev->next = entry->next;
    }
    free(entry);
}

void removeLinus(LinkedList *l, Node *entry){
    Node **indirect = &(l->head);
    while((*indirect) != entry){
        indirect = &(*indirect)->next;
    }
    *indirect = entry->next;
    free(entry);
}

void printList(LinkedList *l){
    Node *walk = l->head;
    while(walk){
        printf("%d ", walk->item);
        walk = walk->next;
    }
    printf("\n");
}

LinkedList createList(){
   LinkedList l;
   l.head = NULL;
   l.add = &add;
   l.delete = &delete;
   l.get = &get;
   l.removeLinus = &removeLinus;
   l.printList = &printList;
   return l;
}

#endif