#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

string decodeString(const string &s) {
    stack<int> counts;
    stack<string> result;
    int index = 0;
    string res = "";
    
    while (index < s.size()) {
        if (isdigit(s[index]) == true) {
            int count = 0;
            while (isdigit(s[index]) == true) {
                count = count * 10 + (s[index] - '0');
                index++;
            }
            counts.push(count);
        } else if (s[index] == '[') {
            result.push(res);
            res = "";
            index++;
        } else if (s[index] == ']') {
            string temp = result.top();
            result.pop();
            int count = counts.top();
            counts.pop();
            for (int j = 0; j < count; j++) {
                temp += res;
            }
            res = temp;
            index++;
        } else {
            res += s[index];
            index++;
        }
    }
    
    return res;
}

int main() {
    string encodedString;
    getline(cin, encodedString);
    
    string decodedString = decodeString(encodedString);
    cout << decodedString << endl;
    
    return 0;
}
