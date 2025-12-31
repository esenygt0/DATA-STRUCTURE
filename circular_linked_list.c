/* * BAŞLIK: Dairesel Bağlı Liste (Circular List)
 * AÇIKLAMA: Son düğümün başa bağlandığı liste yapısında ekleme ve silme.
 */
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) temp = temp->next;
        temp->next = newNode;
        newNode->next = *head;
    }

}
