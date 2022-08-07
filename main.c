#include <stdio.h>
#include "LinusList.h"

int main(){
    int i;
    LinkedList lista = createList();
    Node *y;
    for(i = 0; i < 10; i++){
        y = malloc(sizeof(Node));
        y->item = i;
        y->next = NULL;
        lista.add(&lista, y);
    }
    lista.printList(&lista);
    for(i = 0; i < 3; i++){
        y = lista.get(&lista, i * 2);
        lista.delete(&lista, y);
        lista.printList(&lista);
    }
    for(i = 0; i < 3; i++){
        y = lista.get(&lista, i * 2);
        lista.removeLinus(&lista, y);
        lista.printList(&lista);
    }
    printf("el programa acabo correctamente.\n");
    return 0;
}