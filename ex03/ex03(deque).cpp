#include <iostream>
#include <vector>
#include <string>
#include <deque>

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
    deque<pair<int, int>> snake;
    snake.push_back({0, 0});

    // initialize @ to the top left
    int x = 0, y = 0;
    output[x][y] = '@';

    for (char command : commands) {
        switch (command) {
            case 'w': x = (x == 0) ? rows - 1 : x - 1; break;  // upward
            case 'a': y = (y == 0) ? cols - 1 : y - 1; break;  // left
            case 's': x = (x == rows - 1) ? 0 : x + 1; break;  // downward
            case 'd': y = (y == cols - 1) ? 0 : y + 1; break;  // right
        }

        if (matrix[x][y] == 1) {
            matrix[x][y] = 0;
            snake.push_front({x, y});
        } else {
            snake.push_front({x, y});
            auto tail = snake.back(); snake.pop_back();
            output[tail.first][tail.second] = '.';
        }

        for (auto& position : snake) {
            output[position.first][position.second] = (position == snake.front()) ? '@' : '#';
        }

        // check wasted
        for (size_t i = 1; i < snake.size(); i++) {
            if (snake[i] == make_pair(x, y)) {
                cout << "Wasted" << endl;
                return 0;
            }
        }

        printArray(output);
    }

    return 0;
}
