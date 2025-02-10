#include <stdio.h>
#include <stdlib.h>

void StopAndWait();
void GoBackN();
void SelectiveRepeat();

int main(int argc, char** argv) {
    int val;
    while (1) {
        printf("\nEnter:\n1. Stop And Wait protocol\n2. Go back N protocol\n3. Selective Repeat protocol\n");
        scanf("%d", &val);
        switch (val) {
            case 1: StopAndWait(); break;
            case 2: GoBackN(); break;
            case 3: SelectiveRepeat(); break;
            default: return 0;
        }
    }
    return EXIT_SUCCESS;
}

// Function to implement Stop and Wait ARQ algorithm
void StopAndWait() {
    int n, i = 0, frame;
    printf("Enter the total number of frames: ");
    scanf("%d", &n);
    while (i != n) {
        printf("\nEnter received frame: ");
        scanf("%d", &frame);
        if (frame == i + 1) {
            printf("Transmitting..... ACK to frame %d\n", frame);
            i++;
        } else {
            printf("Negative ACK.... to frame %d\n", i + 1);
        }
    }
}

// Function to implement Go back N algorithm
void GoBackN() {
    int n, i = 0, frame, size, t;
    printf("Enter the total number of frames: ");
    scanf("%d", &n);
    printf("Enter window size of frames: ");
    scanf("%d", &size);
    printf("Sending frames: ");
    for (int j = 0; j < size; j++) {
        printf("%d, ", j + 1);
    }
    for (int j = 0; j < n; j++) {
        printf("\nIs frame %d received (1 or 0): ", j + 1);
        scanf("%d", &t);
        if (t == 1) {
            printf("Sending ACK to frame %d\n", j + 1);
            printf("Sliding window: ");
            for (int k = j + 1; k < j + 1 + size; k++) {
                if (k < n)
                    printf("%d, ", k + 1);
            }
        } else {
            printf("\nRetransmitting frames: ");
            for (int m = j; m < j + size; m++) {
                if (m < n)
                    printf("%d, ", m + 1);
            }
        }
    }
}

// Function to implement Selective Repeat algorithm
void SelectiveRepeat() {
    int n, m, size;
    printf("Enter the total number of frames: ");
    scanf("%d", &n);
    printf("Sending frames: ");
    for (int j = 0; j < n; j++) {
        printf("%d, ", j + 1);
    }
    printf("\nEnter the number of frames received: ");
    scanf("%d", &m);
    int a[n];
    printf("\nEnter received frames: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        int trigger = 0;
        for (int j = 0; j < m; j++) {
            if (i + 1 == a[j]) {
                trigger = 1;
                break;
            }
        }
        if (!trigger) {
            printf("Retransmitting frame %d\n", i + 1);
            a[m++] = i + 1;
        }
    }
    // Sorting the received frames
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("\nSorted frames: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}