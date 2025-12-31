/* * BAŞLIK: Diziden İkili Ağaç Oluşturma
 * AÇIKLAMA: Seviye düzeninde (level-order) verilen bir diziyi ağaç yapısına dönüştürür.
 */
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *left, *right; };

struct Node* buildTree(int arr[], int i, int n) {
    struct Node* root = NULL;
    if (i < n) {
        root = (struct Node*)malloc(sizeof(struct Node));
        root->data = arr[i];
        root->left = buildTree(arr, 2 * i + 1, n);
        root->right = buildTree(arr, 2 * i + 2, n);
    }
    return root;
}
