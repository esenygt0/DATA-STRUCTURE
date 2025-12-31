/* * BAŞLIK: Çift Yönlü Bağlı Liste İşlemleri
 * AÇIKLAMA: Araya ekleme, silme ve liste üzerinde ileri/geri gezinti sağlar.
 */
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *next, *prev; };

void insert(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = (*head);
    newNode->prev = NULL;
    if ((*head) != NULL) (*head)->prev = newNode;
    (*head) = newNode;
}

void deleteNode(struct Node** head, struct Node* del) {
    if (*head == NULL || del == NULL) return;
    if (*head == del) *head = del->next;
    if (del->next != NULL) del->next->prev = del->prev;
    if (del->prev != NULL) del->prev->next = del->next;
    free(del);

}
