/* 
 * BAŞLIK: Max Heap ve Min Heap Yapılandırması
 * AÇIKLAMA: Bir diziyi max-heap ve min-heap kurallarına uygun hale getirir.
 * Max-Heap: Ebeveyn > Çocuklar
 * Min-Heap: Ebeveyn < Çocuklar
 */

#include <stdio.h>

/* 
 * FONKSİYON: heapifyMax
 * AÇIKLAMA: Verilen diziyi max-heap kuralına göre düzenler.
 */
void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapifyMax(arr, n, largest);
    }
}

/* 
 * FONKSİYON: buildMaxHeap
 * AÇIKLAMA: Bir diziyi tamamen max-heap haline getirir.
 */
void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMax(arr, n, i);
    }
}

/* 
 * FONKSİYON: heapifyMin
 * AÇIKLAMA: Verilen diziyi min-heap kuralına göre düzenler.
 */
void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        heapifyMin(arr, n, smallest);
    }
}

/* 
 * FONKSİYON: buildMinHeap
 * AÇIKLAMA: Bir diziyi tamamen min-heap haline getirir.
 */
void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMin(arr, n, i);
    }
}

/* 
 * FONKSİYON: printArray
 * AÇIKLAMA: Diziyi ekrana yazdırır.
 */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* 
 * FONKSİYON: main
 * AÇIKLAMA: Max Heap ve Min Heap oluşturmayı test eder.
 */
int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildMaxHeap(arr, n);
    printf("Max Heap: ");
    printArray(arr, n);

    buildMinHeap(arr, n);
    printf("Min Heap: ");
    printArray(arr, n);

    return 0;
}
