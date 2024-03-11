#include <iostream>
#include <cmath> // For the pow function

using namespace std;

int main() {
    int times;
    cin >> times;

    for(int i = 0; i < times; i++) {
        int totalCard, needCard;
        int flag = 0, answer = 0;

        cin >> totalCard >> needCard;

        while(needCard > (totalCard + 1) / 2) {
            needCard = needCard - ((totalCard + 1) / 2);
            totalCard = totalCard - ((totalCard + 1) / 2);
            flag++;
        }

        // 2*(n-1)+1 -> calculate odd number
        answer = pow(2, flag) * (2 * (needCard - 1) + 1);

        cout << answer << endl;
    }

    return 0;
}
