#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printArray(const vector<vector<char>>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int rows, cols, commandLength;
    cin >> rows >> cols >> commandLength;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    string commands;
    cin >> commands;

    vector<vector<char>> output(rows, vector<char>(cols, '.'));
    vector<pair<int, int>> snake;
    snake.push_back({0, 0});

    // initialize @ to the top left
    int x = 0, y = 0;
    output[x][y] = '@';

    for (char command : commands) {
        switch (command) {
            case 'w': x = (x == 0) ? rows - 1 : x - 1; break;
            case 'a': y = (y == 0) ? cols - 1 : y - 1; break;
            case 's': x = (x == rows - 1) ? 0 : x + 1; break;
            case 'd': y = (y == cols - 1) ? 0 : y + 1; break;
        }

        if (matrix[x][y] == 1) {
            matrix[x][y] = 0;
        } else {
            // Move the snake by removing the tail and adding a new head
            snake.erase(snake.begin());
        }
        snake.push_back({x, y}); // Add new head at the end of the vector

        fill(output.begin(), output.end(), vector<char>(cols, '.'));
        for (const auto& position : snake) {
            output[position.first][position.second] = (position == snake.back()) ? '@' : '#';
        }

        // check wasted
        for (size_t i = 0; i < snake.size() - 1; i++) {
            if (snake[i] == make_pair(x, y)) {
                cout << "Wasted" << endl;
                return 0;
            }
        }

        printArray(output);
    }

    return 0;
}
