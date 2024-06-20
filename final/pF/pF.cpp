#include <iostream>
#include <vector>
using namespace std;

int main() {
    int totalHotel, totalCustomer;
    cin >> totalHotel >> totalCustomer;

    vector<int> hotels(totalHotel);
    for (int i = 0; i < totalHotel; ++i) {
        cin >> hotels[i];
    }

    vector<int> customers(totalCustomer);
    for (int i = 0; i < totalCustomer; ++i) {
        cin >> customers[i];
    }

    for (int i = 0; i < totalCustomer; ++i) {
        int assignedHotel = 0;
        for (int j = 0; j < totalHotel; ++j) {
            if (hotels[j] >= customers[i]) {
                assignedHotel = j + 1; // Hotel indices are 1-based
                hotels[j] -= customers[i];
                break;
            }
        }
        cout << assignedHotel << " ";
    }

    return 0;
}
