/* * BAŞLIK: Max Heap Yapılandırması (Heapify)
 * AÇIKLAMA: Bir diziyi max-heap kuralına (ebeveyn > çocuk) uygun hale getirir.
 */
#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i, l = 2*i + 1, r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        int temp = arr[i]; arr[i] = arr[largest]; arr[largest] = temp;
        heapify(arr, n, largest);
    }
}