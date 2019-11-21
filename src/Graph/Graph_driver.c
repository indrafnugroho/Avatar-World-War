#include "Graph.h"
#include <stdio.h>

int main() {
    int n, i, j;
    i = 0; j = 0;
    Graph g;;
    GraphCreate(&g);
    printf("[GRAPH DRIVER]\n\nnumber of nodes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        GraphNewVertexLast(&g);
    }
    printf("Nodes to connect (i, j), input negetive to stop:\n");
    do {
        printf("> ");
        scanf("%d %d", &i, &j);
        if (i >= 0 && j >= 0) {
            GraphAddEdgeIdx(&g, i, j);
            GraphAddEdgeIdx(&g, j, i);
        }
    } while (i >= 0 && j >= 0);
    printf("Nodes Connected\n");
    for (i = 0; i < GraphSize(g); i++) {
        for (j = 0; j < GraphSize(g); j++) {
            if (GraphIsAdjacentIdx(g, i, j)) {
                printf("%d -> %d\n", i, j);
            }
        }
    }
}
