/* 
 * BAŞLIK: Çift Yönlü Bağlı Liste İşlemleri
 * AÇIKLAMA: Çift yönlü bağlı listede araya ekleme, silme ve
 * liste üzerinde ileri ve geri yönde gezinti (traversal) işlemlerini gerçekleştirir.
 */

#include <stdio.h>
#include <stdlib.h>

/* 
 * YAPI: Node
 * AÇIKLAMA: Çift yönlü bağlı listenin düğüm yapısı
 */
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

/* 
 * FONKSİYON: insertAtHead
 * AÇIKLAMA: Listenin başına eleman ekler.
 */
void insertAtHead(struct Node **head, int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
}

/* 
 * FONKSİYON: insertAfter
 * AÇIKLAMA: Verilen bir düğümden sonra (araya) yeni bir düğüm ekler.
 */
void insertAfter(struct Node *prevNode, int val) {
    if (prevNode == NULL)
        return;

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != NULL)
        prevNode->next->prev = newNode;

    prevNode->next = newNode;
}

/* 
 * FONKSİYON: deleteNode
 * AÇIKLAMA: Verilen düğümü listeden siler.
 */
void deleteNode(struct Node **head, struct Node *del) {
    if (*head == NULL || del == NULL)
        return;

    if (*head == del)
        *head = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

/* 
 * FONKSİYON: traverseForward
 * AÇIKLAMA: Listeyi baştan sona doğru gezer.
 */
void traverseForward(struct Node *head) {
    struct Node *temp = head;
    printf("Ileri traversal: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* 
 * FONKSİYON: traverseBackward
 * AÇIKLAMA: Listeyi sondan başa doğru gezer.
 */
void traverseBackward(struct Node *head) {
    struct Node *temp = head;

    if (temp == NULL)
        return;

    while (temp->next != NULL)
        temp = temp->next;

    printf("Geri traversal: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

/* 
 * FONKSİYON: main
 * AÇIKLAMA: Double Linked List işlemlerini test eder.
 */
int main() {
    struct Node *head = NULL;

    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtHead(&head, 30);

    insertAfter(head->next, 25); // araya ekleme

    traverseForward(head);
    traverseBackward(head);

    deleteNode(&head, head->next); // bir düğüm silme

    traverseForward(head);

    return 0;
}
