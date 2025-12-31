/* * BAŞLIK: DFS (Depth First Search) Uygulaması
 * AÇIKLAMA: Yığın yapısını kullanarak grafın derinliklerine doğru arama yapar.
 */
#include <stdio.h>

void DFS(int adj[10][10], int visited[10], int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++)
        if (adj[v][i] && !visited[i]) DFS(adj, visited, i, n);
}