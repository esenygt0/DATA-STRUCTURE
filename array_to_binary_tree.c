/* 
 * BAŞLIK: Diziden İkili Ağaç Oluşturma
 * AÇIKLAMA: Seviye düzeninde (level-order) verilen bir diziyi
 * rekürsif olarak ikili ağaç (binary tree) yapısına dönüştürür.
 */

#include <stdio.h>
#include <stdlib.h>

/* 
 * YAPI: Node
 * AÇIKLAMA: İkili ağaç düğüm yapısı
 */
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

/* 
 * FONKSİYON: buildTree
 * AÇIKLAMA: Diziyi level-order mantığıyla binary tree'ye dönüştürür.
 */
struct Node* buildTree(int arr[], int i, int n) {
    if (i >= n)
        return NULL;

    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = arr[i];

    root->left  = buildTree(arr, 2 * i + 1, n);
    root->right = buildTree(arr, 2 * i + 2, n);

    return root;
}

/* 
 * FONKSİYON: inorder
 * AÇIKLAMA: Ağacı inorder traversal ile dolaşır.
 */
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* 
 * FONKSİYON: freeTree
 * AÇIKLAMA: Ağaçtaki tüm düğümleri bellekten temizler.
 */
void freeTree(struct Node* root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

/* 
 * FONKSİYON: main
 * AÇIKLAMA: Diziden ağaç oluşturma işlemini test eder.
 */
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node* root = buildTree(arr, 0, n);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
