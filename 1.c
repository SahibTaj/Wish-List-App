#include <stdio.h>
#include <stdbool.h>

bool isDivisible(int A[][2], int A_rows, int B[][1], int B_rows, int x) {
    for (int i = 0; i < B_rows; i++) {
        bool found = false;
        for (int j = 0; j < A_rows; j++) {
            if (A[j][0] == x && A[j][1] == B[i][0]) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

void performDivision(int A[][2], int A_rows, int B[][1], int B_rows) {
    printf("Result of A ÷ B:\n");
    for (int i = 0; i < A_rows; i++) {
        int x = A[i][0];
        bool alreadyChecked = false;
        for (int k = 0; k < i; k++) {
            if (A[k][0] == x) {
                alreadyChecked = true;
                break;
            }
        }
        if (alreadyChecked) continue;

        if (isDivisible(A, A_rows, B, B_rows, x)) {
            printf("%d\n", x);
        }
    }
}

int main() {
    int A[100][2], B[100][1];
    int A_rows, B_rows;

    printf("Enter the number of rows in relation A: ");
    scanf("%d", &A_rows);
    printf("Enter the rows for A (X Y pairs):\n");
    for (int i = 0; i < A_rows; i++) {
        scanf("%d %d", &A[i][0], &A[i][1]);
    }

    printf("Enter the number of rows in relation B: ");
    scanf("%d", &B_rows);
    printf("Enter the rows for B (Y values):\n");
    for (int i = 0; i < B_rows; i++) {
        scanf("%d", &B[i][0]);
    }

    performDivision(A, A_rows, B, B_rows);

    return 0;
}
