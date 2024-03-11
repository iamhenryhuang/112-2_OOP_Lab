#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Alternative string multiplication function
string multiplyStr(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0"; // If either number is 0, the result is 0.

    int length1 = num1.size(), length2 = num2.size();
    vector<int> result(length1 + length2, 0); // Result can have at most len1 + len2 digits.

    // Reverse both strings to simplify the multiplication and carry handling.
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    // Perform multiplication
    for (int i = 0; i < length1; i++) {
        for (int j = 0; j < length2; j++) {
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';
            result[i + j] += digit1 * digit2; // Add current product to the result.
            result[i + j + 1] += result[i + j] / 10; // Handle carry
            result[i + j] %= 10; // Keep only the last digit at the current position.
        }
    }

    // Remove leading zeros and reverse back to the correct order.
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    string resultString;
    for (auto it = result.rbegin(); it != result.rend(); it++) { // Convert result to string in correct order.
        resultString += to_string(*it);
    }

    return resultString;
}

// String subtraction function, ensuring non-negative results
string subtract(const string& num1, const string& num2) {
    // Determine which string represents the larger number
    string larger, smaller;
    if (num1.length() > num2.length() || (num1.length() == num2.length() && num1 >= num2)) {
        larger = num1;
        smaller = num2;
    } else {
        larger = num2;
        smaller = num1;
    }

    // Pad the smaller number with leading zeros
    string padSmall = string(larger.length() - smaller.length(), '0') + smaller;
    
    // Perform subtraction
    string result = "";
    int borrow = 0;
    for (int i = larger.length() - 1; i >= 0; --i) {
        int diff = (larger[i] - '0') - (padSmall[i] - '0') - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result = to_string(diff) + result;
    }

    // Remove leading zeros from the result
    result.erase(0, result.find_first_not_of('0'));
    if (result.empty()) {
        result = "0";
    }
    
    return result;
}

// String comparison function
int compare(const string& num1, const string& num2) {
    // First, compare based on the length of the strings
    if (num1.size() > num2.size()) {
        // If num1 is longer than num2, then num1 is larger
        return 1;
    } else if (num1.size() < num2.size()) {
        // If num1 is shorter than num2, then num2 is larger
        return -1;
    } else {
        // If the lengths are equal, compare lexicographically
        for (int i = 0; i < num1.size(); i++) {
            if (num1[i] > num2[i]) {
                // The first non-equal digit from the left in num1 is greater than in num2
                return 1;
            } else if (num1[i] < num2[i]) {
                // The first non-equal digit from the left in num1 is less than in num2
                return -1;
            }
        }
    }
    // If none of the above conditions are met, the numbers are equal
    return 0;
}

// Calculates twice the area of the triangle formed by two points and the origin
string calculateArea(const string& x1, const string& y1, const string& x2, const string& y2) {
    string area = subtract(multiplyStr(x1, y2), multiplyStr(x2, y1));
    return area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int total;
    cin >> total;
    vector<pair<string, string>> points(total);

    for (int i = 0; i < total; i++) {
        cin >> points[i].first >> points[i].second;
    }

    string biggest = "0";
    string smallest = "";

    for (int i = 0; i < total; i++) {
        for (int j = i + 1; j < total; j++) {
            string area = calculateArea(points[i].first, points[i].second, points[j].first, points[j].second);
            if (smallest.empty() || compare(smallest, area) > 0) {
                smallest = area;
            }
            if (compare(biggest, area) < 0) {
                biggest = area;
            }
        }
    }

    if (smallest.empty()) smallest = "0";

    cout << biggest << " " << smallest << endl;
    return 0;
}
