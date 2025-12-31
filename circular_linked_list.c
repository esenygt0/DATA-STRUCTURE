/* 
 * BAŞLIK: Dairesel Bağlı Liste (Circular Linked List)
 * AÇIKLAMA: Son düğümün başa bağlandığı dairesel bağlı listede
 * araya ekleme, silme ve liste üzerinde gezinti (traversal) işlemlerini gerçekleştirir.
 */

#include <stdio.h>
#include <stdlib.h>

/* 
 * YAPI: Node
 * AÇIKLAMA: Dairesel bağlı liste düğüm yapısı
 */
struct Node {
    int data;
    struct Node *next;
};

/* 
 * FONKSİYON: insertAtEnd
 * AÇIKLAMA: Dairesel bağlı listenin sonuna eleman ekler.
 */
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = *head;
}

/* 
 * FONKSİYON: insertAfter
 * AÇIKLAMA: Verilen bir düğümden sonra (araya) yeni bir düğüm ekler.
 */
void insertAfter(struct Node *prevNode, int data) {
    if (prevNode == NULL)
        return;

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

/* 
 * FONKSİYON: deleteNode
 * AÇIKLAMA: Verilen değere sahip düğümü listeden siler.
 */
void deleteNode(struct Node **head, int key) {
    if (*head == NULL)
        return;

    struct Node *curr = *head;
    struct Node *prev = NULL;

    // Tek düğümlü liste
    if (curr->next == curr && curr->data == key) {
        free(curr);
        *head = NULL;
        return;
    }

    // Baş düğüm siliniyorsa
    if (curr->data == key) {
        while (curr->next != *head)
            curr = curr->next;

        curr->next = (*head)->next;
        free(*head);
        *head = curr->next;
        return;
    }

    // Diğer düğümler
    prev = *head;
    curr = (*head)->next;

    while (curr != *head) {
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

/* 
 * FONKSİYON: traverse
 * AÇIKLAMA: Dairesel bağlı listeyi baştan sona doğru gezer.
 */
void traverse(struct Node *head) {
    if (head == NULL)
        return;

    struct Node *temp = head;
    printf("Traversal: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

/* 
 * FONKSİYON: main
 * AÇIKLAMA: Circular Linked List işlemlerini test eder.
 */
int main() {
    struct Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    insertAfter(head, 15); // araya ekleme

    traverse(head);

    deleteNode(&head, 20); // silme

    traverse(head);

    return 0;
}
