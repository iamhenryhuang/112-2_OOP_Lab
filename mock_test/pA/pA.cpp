#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> weights(n);
    long long totalWeight = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        totalWeight += weights[i];
    }
    
    long long minDifference = LLONG_MAX;
    
    // There are 2^n possible subsets
    for (int i = 0; i < (1 << n); i++) {
        long long subsetSum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subsetSum += weights[j];
            }
        }
        long long difference = abs(totalWeight - 2 * subsetSum);
        minDifference = min(minDifference, difference);
    }
    
    cout << minDifference << endl;
    
    return 0;
}
