#include <stdio.h>
#include <stdlib.h>

int findShortestPath(int G[6][6], int Vertices, int Edges, int edge[20][2], int Source) {
    int i, j, u, v, k, distance[20], parent[20], flag = 1;

    for (i = 0; i < Vertices; i++) {
        distance[i] = 999;
        parent[i] = -1;
    }

    distance[Source - 1] = 0;

    for (i = 0; i < Vertices - 1; i++) {
        for (k = 0; k < Edges; k++) {
            u = edge[k][0];
            v = edge[k][1];

            if (distance[u] + G[u][v] < distance[v]) {
                distance[v] = distance[u] + G[u][v];
                parent[v] = u;
            }
        }
    }

    for (k = 0; k < Edges; k++) {
        u = edge[k][0];
        v = edge[k][1];

        if (distance[u] + G[u][v] < distance[v]) {
            flag = 0;
            break;
        }
    }

    printf("Destination\tCost\tPath\n");
    if (flag) {
        for (i = 0; i < Vertices; i++) {
            int nodes[10], b = 9, next;
            nodes[b--] = i;
            next = parent[i];
            nodes[b--] = next;

            while (next != -1) {
                next = parent[next];
                nodes[b--] = next;
            }

            if (distance[i] == 999)
                printf("\n%d\t\t%d\t", i, nodes[-1]);
            else
                printf("\n%d\t\t%d\t", i, distance[i]);

            for (int h = 10; h > 0; h--) {
                if (nodes[h] == -1) {
                    for (int g = h + 1; g < 10; g++) {
                        if (g == 9)
                            printf("%d", nodes[g]);
                        else
                            printf("%d-->", nodes[g]);
                    }
                    break;
                }
            }
        }
    }
    return flag;
}

int main() {
    int Vertices = 6, edge[20][2];
    int i, j, k = 0;

    int graph[6][6] = {
        {0, 1, 5, 0, 0, 0},
        {1, 0, 3, 4, 0, 0},
        {5, 3, 0, 5, 9, 0},
        {0, 4, 5, 0, 2, 6},
        {0, 0, 9, 2, 0, 3},
        {0, 0, 0, 6, 3, 0}
    };

    printf("The Adjacency Matrix representation of graph\n");
    for (i = 0; i < Vertices; i++) {
        for (j = 0; j < Vertices; j++) {
            printf("%d\t", graph[i][j]);
            if (graph[i][j] != 0)
                edge[k][0] = i, edge[k++][1] = j;
        }
        printf("\n");
    }

    for (i = 0; i < Vertices; i++) {
        printf("\n----------------------------\n");
        printf("\tSource vertex %d\n", i);
        findShortestPath(graph, Vertices, k, edge, i + 1);
    }
    return 0;
}
