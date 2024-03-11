#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE 10

int grid[MAX_SIZE][MAX_SIZE];
int NUM;

bool isSquare() {
    int minRow = NUM, maxRow = -1, minCol = NUM, maxCol = -1;

    for (int i = 0; i < NUM; i++) {
        for (int j = 0; j < NUM; j++) {
            if (grid[i][j] == 1) {
                if (i < minRow) minRow = i;
                if (i > maxRow) maxRow = i;
                if (j < minCol) minCol = j;
                if (j > maxCol) maxCol = j;
            }
        }
    }

    int sideLength = maxRow - minRow + 1;
    return (maxCol - minCol + 1 == sideLength);
}

int main() {
    int totalnum;
    cin >> totalnum;

    for (int i = 0; i < totalnum; i++) {
        int num;
        cin >> num;
        NUM = num;

        for (int j = 0; j < num; j++) {
            for (int k = 0; k < num; k++) {
                cin >> grid[j][k];
            }
        }

        if (isSquare()) {
            cout << "SQUARE\n";
        } else {
            cout << "TRIANGLE\n";
        }
    }

    return 0;
}
