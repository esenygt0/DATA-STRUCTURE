/* 
 * BAŞLIK: Dizi Eleman Yönetimi
 * AÇIKLAMA: Verilen bir dizide kaydırma yaparak eleman ekleme ve
 * silme işlemlerini gerçekleştirir.
 */

#include <stdio.h>

#define MAX 100

/* 
 * FONKSİYON: add
 * AÇIKLAMA: Verilen indekse yeni bir eleman ekler.
 */
void add(int arr[], int *n, int idx, int val) {
    if (*n >= MAX || idx < 0 || idx > *n) {
        printf("Ekleme basarisiz!\n");
        return;
    }

    for (int i = *n; i > idx; i--)
        arr[i] = arr[i - 1];

    arr[idx] = val;
    (*n)++;
}

/* 
 * FONKSİYON: del
 * AÇIKLAMA: Verilen indeksteki elemani siler.
 */
void del(int arr[], int *n, int idx) {
    if (*n <= 0 || idx < 0 || idx >= *n) {
        printf("Silme basarisiz!\n");
        return;
    }

    for (int i = idx; i < *n - 1; i++)
        arr[i] = arr[i + 1];

    (*n)--;
}

/* 
 * FONKSİYON: printArray
 * AÇIKLAMA: Diziyi ekrana yazdirir.
 */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* 
 * FONKSİYON: main
 * AÇIKLAMA: Dizi ekleme ve silme işlemlerini test eder.
 */
int main() {
    int arr[MAX] = {10, 20, 30, 40};
    int n = 4;

    printArray(arr, n);

    add(arr, &n, 2, 25);   // araya ekleme
    printArray(arr, n);

    del(arr, &n, 1);      // silme
    printArray(arr, n);

    return 0;
}
