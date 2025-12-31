/* * BAŞLIK: Dizi Eleman Yönetimi
 * AÇIKLAMA: Verilen bir dizide kaydırma yaparak eleman ekler veya siler.
 */
#include <stdio.h>

void add(int arr[], int *n, int idx, int val) {
    for (int i = *n; i > idx; i--) arr[i] = arr[i-1];
    arr[idx] = val; (*n)++;
}

void del(int arr[], int *n, int idx) {
    for (int i = idx; i < *n - 1; i++) arr[i] = arr[i+1];
    (*n)--;
}