/* 
 * BAŞLIK: Graflarda Kümeleme (Cluster Extraction)
 * AÇIKLAMA: Komşuluk matrisi (adjacency matrix) kullanılarak
 * graf içerisindeki bağlantılı bileşenleri (cluster) DFS yardımıyla bulur.
 */

#include <stdio.h>

#define MAX 10

/* 
 * FONKSİYON: dfs
 * AÇIKLAMA: DFS kullanarak bir cluster içindeki düğümleri ziyaret eder.
 */
void dfs(int adj[MAX][MAX], int visited[], int n, int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(adj, visited, n, i);
        }
    }
}

/* 
 * FONKSİYON: findClusters
 * AÇIKLAMA: Graf içindeki tüm bağlantılı bileşenleri (cluster) bulur.
 */
void findClusters(int adj[MAX][MAX], int n) {
    int visited[MAX] = {0};
    int clusterCount = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            clusterCount++;
            printf("Cluster %d: ", clusterCount);
            dfs(adj, visited, n, i);
            printf("\n");
        }
    }
}

/* 
 * FONKSİYON: main
 * AÇIKLAMA: Örnek bir graph üzerinde cluster çıkarma işlemini test eder.
 */
int main() {
    int n = 6;

    int adj[MAX][MAX] = {
        {0,1,1,0,0,0},
        {1,0,1,0,0,0},
        {1,1,0,0,0,0},
        {0,0,0,0,1,1},
        {0,0,0,1,0,1},
        {0,0,0,1,1,0}
    };

    findClusters(adj, n);

    return 0;
}
