// find the minimum cost spanning tree of a given undirect graph using Kruska's agorithm.

#include <stdio.h>

struct Edge {
    int u,v,w;
};

int main() {
    int V = 9,E=14;
    

    struct Edge edges[] = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11},
        {2, 3, 7}, {2, 8, 2}, {2, 5, 4}, {3, 4, 9},
        {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1},
        {6, 8, 6}, {7, 8, 7}
    };


    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                
                edges[j+1]=temp;
            }
        }
    }
 

    int parent[9];
    for (int i = 0; i < V; i++) parent[i] = i;

    int minCost = 0, count = 0;
    printf("Selected Edges for MST:\n");


    for (int i = 0; i < E; i++) {
        int rootU = edges[i].u;
        int rootV = edges[i].v;

        // Parent find karo
        while (parent[rootU] != rootU) rootU = parent[rootU];
        while (parent[rootV] != rootV) rootV = parent[rootV];

        if (rootU != rootV) {
            printf("%d -- %d == %d\n", edges[i].u, edges[i].v, edges[i].w);
            minCost += edges[i].w;
            parent[rootU] = rootV; 
            count++;
        }
        
        if (count == V - 1) break; 
    }

    printf("\nTotal Minimum Cost = %d\n", minCost);
    return 0;
}