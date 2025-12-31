/* 
 * BAŞLIK: DFS (Depth First Search) Uygulaması
 * AÇIKLAMA: Rekürsif yaklaşım kullanarak graf üzerinde
 * derinlik öncelikli arama (DFS) işlemini gerçekleştirir.
 */

#include <stdio.h>

#define MAX 10

/* 
 * FONKSİYON: DFS
 * AÇIKLAMA: Verilen graf üzerinde DFS traversal yapar.
 */
void DFS(int adj[MAX][MAX], int visited[MAX], int v, int n) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(adj, visited, i, n);
        }
    }
}

/* 
 * FONKSİYON: main
 * AÇIKLAMA: DFS algoritmasını test eder.
 */
int main() {
    int n = 5;
    int visited[MAX] = {0};

    int adj[MAX][MAX] = {
        {0,1,1,0,0},
        {1,0,0,1,0},
        {1,0,0,1,1},
        {0,1,1,0,0},
        {0,0,1,0,0}
    };

    printf("DFS Traversal: ");
    DFS(adj, visited, 0, n);
    printf("\n");

    return 0;
}
