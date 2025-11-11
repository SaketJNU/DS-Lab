#include <stdio.h>

#define MAX 10  // Maximum number of vertices

void displayMatrix(int adj[MAX][MAX], int n) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adj[MAX][MAX];   // Adjacency matrix
    int n, edges;        // Number of vertices and edges
    int origin, dest;    // Source and destination vertices
    int isDirected;
    printf("\nEnter 1 for Directed Graph,  and, 0 for Undirected Graph: ");
    scanf("%d", &isDirected);
    // Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // Input edges
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (origin destination): ", i + 1);
        scanf("%d %d", &origin, &dest);

        if (origin >= n || dest >= n || origin < 0 || dest < 0) {
            printf("Invalid edge! Please enter valid vertices (0-%d)\n", n - 1);
            i--;  // Repeat this iteration
        } else {
            adj[origin][dest] = 1;
            if (!isDirected)
                adj[dest][origin] = 1;
        }
    }

    // Display adjacency matrix
    displayMatrix(adj, n);

    return 0;
}
