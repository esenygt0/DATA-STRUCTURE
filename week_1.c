/* * BAŞLIK: Seyrek Matris (Sparse Matrix) Dönüşümü
 * AÇIKLAMA: Çok sayıda sıfır içeren bir matrisi, sadece anlamlı verileri 
 * tutacak şekilde (satır, sütun, değer) formatına çevirir.
 */
#include <stdio.h>

int main() {
    int matrix[3][3] = {{0,0,5}, {0,8,0}, {0,0,0}};
    int sparse[10][3], k = 0;

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(matrix[i][j] != 0) {
                sparse[k][0] = i; // Satır indeksi
                sparse[k][1] = j; // Sütun indeksi
                sparse[k][2] = matrix[i][j]; // Değer
                k++;
            }

    printf("Satir Sutun Deger\n");
    for(int i=0; i<k; i++) printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    return 0;
}