// method 1
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

int grid[MAX_SIZE][MAX_SIZE];
int NUM;

bool isSquare() {
    int minRow = NUM, maxRow = -1, minCol = NUM, maxCol = -1;

    for (int i = 0; i < NUM; i++) {
        for (int j = 0; j < NUM; j++) {
            if (grid[i][j] == 1) {
                if (i < minRow) {
                    minRow = i;
                }
                if (i > maxRow) {
                    maxRow = i;
                }
                if (j < minCol) {
                    minCol = j;
                }
                if (j > maxCol) {
                    maxCol = j;
                }
            }
        }
    }

    int sideLength = maxRow - minRow + 1;
    
    if (maxCol - minCol + 1 == sideLength) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int totalnum;
    scanf("%d", &totalnum);

    for (int i = 0; i < totalnum; i++) {
        int num;
        scanf("%d", &num);
        NUM = num;

        for (int j = 0; j < num; j++) {
            for (int k = 0; k < num; k++) {
                scanf("%1d", &grid[j][k]);
            }
        }

        if (isSquare() == true) {
            printf("SQUARE\n");
        } else {
            printf("TRIANGLE\n");
        }
    }

    return 0;
}

// method B
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

int grid[MAX_SIZE][MAX_SIZE];
int N;

bool Square() {
    int minRow = -1, minCol = -1, maxRow = -1, maxCol = -1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                if (minRow == -1 || i < minRow) minRow = i;
                if (minCol == -1 || j < minCol) minCol = j;
                if (i > maxRow) maxRow = i;
                if (j > maxCol) maxCol = j;
            }
        }
    }

    for (int i = minRow; i <= maxRow; i++) {
        for (int j = minCol; j <= maxCol; j++) {
            if (grid[i][j] != 1) return false;
        }
    }

    if(maxRow - minRow == maxCol - minCol){
        return true;
    }
}

int main() {
    int totalnum;
    scanf("%d", &totalnum);

    int num;

    for (int i = 0; i < totalnum; i++) {
        scanf("%d", &num);
        N = num;

        for (int j = 0; j < num; j++) {
            for (int k = 0; k < num; k++) {
                scanf("%1d", &grid[j][k]);
            }
        }

        if (Square() == true) {
            printf("SQUARE\n");
        } else {
            printf("TRIANGLE\n");
        }
    }

    return 0;
}
