#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int i, j, n;
int x[15], y[15], z[15];  // Added z[] for 3D coordinates
float distance[10][10];

void createNetwork() {
    int x_range, y_range, z_range;
    printf("Enter the number of nodes (max 10): ");
    scanf("%d", &n);
    printf("Enter X-Coordinate range: ");
    scanf("%d", &x_range);
    printf("Enter Y-Coordinate range: ");
    scanf("%d", &y_range);
    printf("Enter Z-Coordinate range: ");
    scanf("%d", &z_range);

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        x[i] = 1 + rand() % x_range;
        y[i] = 1 + rand() % y_range;
        z[i] = 1 + rand() % z_range;  // Randomly generating z-coordinate
    }

    printf("\nX\tY\tZ\n");
    for (i = 0; i < n; i++) {
        printf("(%d, %d, %d)\n", x[i], y[i], z[i]);
    }
}

void computeDistance() {
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            distance[i][j] = sqrt(((x[j] - x[i]) * (x[j] - x[i])) + 
                                   ((y[j] - y[i]) * (y[j] - y[i])) + 
                                   ((z[j] - z[i]) * (z[j] - z[i])));  // Updated distance formula for 3D
        }
    }

    printf("\nDistance Matrix:\n\t");
    for (i = 0; i < n; i++) {
        printf("\t%d", i + 1);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%d\t", i + 1);
        for (j = 0; j < n; j++) {
            printf("%f\t", distance[i][j]);
        }
        printf("\n");
    }
}

void findNeighbor() {
    float range;
    printf("\nEnter the neighbor range: ");
    scanf("%f", &range);

    for (i = 0; i < n; i++) {
        printf("\nNeighbors of %d are:\t", i + 1);
        for (j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (distance[i][j] <= range) {
                printf("%d (%f)\t", j + 1, distance[i][j]);
            }
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    createNetwork();
    computeDistance();
    findNeighbor();
    return EXIT_SUCCESS;
}
