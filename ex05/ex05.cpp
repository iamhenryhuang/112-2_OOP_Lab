#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
    private:
        string name;
        int age;
        int numHobbies;
        string* hobbies;
    
    public:
        // Default Constructor
        Person() : name(""), age(0), numHobbies(0), hobbies(nullptr) {}

        // Parameterized Constructor
        Person(string name, int age, int numHobbies, string* hobbiesInput) : name(name), age(age), numHobbies(numHobbies) {
            hobbies = new string[numHobbies];
            for(int i = 0; i < numHobbies; ++i) {
                hobbies[i] = hobbiesInput[i];
            }
        }

        // Copy Constructor
        Person(const Person& other) : name(other.name), age(other.age), numHobbies(other.numHobbies) {
            hobbies = new string[numHobbies];
            for(int i = 0; i < numHobbies; ++i) {
                hobbies[i] = other.hobbies[i];
            }
        }

        // Copy Assignment Operator
        Person& operator=(const Person& other) {
            if(this != &other) {
                name = other.name;
                age = other.age;
                numHobbies = other.numHobbies;

                delete[] hobbies; // free existing memory
                hobbies = new string[numHobbies];
                for(int i = 0; i < numHobbies; ++i) {
                    hobbies[i] = other.hobbies[i];
                }
            }
            return *this;
        }

        // Destructor
        ~Person() {
            delete[] hobbies;
        }

        void displayInfo() {
            cout << "Name: " << name << ", Age: " << age << ", Number of Hobbies: " << numHobbies << endl;
            cout << "Hobbies: ";
            for(int i = 0; i < numHobbies; ++i) {
                cout << hobbies[i];
                if(i < numHobbies - 1) {
                    cout << ", ";
                }
            }
            cout << endl;
        }

        // Friend function to compare Persons (for sorting)
        friend bool cmp1(const Person& a, const Person& b);
};

bool cmp1(const Person& a, const Person& b) {
    if(a.numHobbies != b.numHobbies) return a.numHobbies > b.numHobbies;
    if(a.age != b.age) return a.age > b.age;
    return a.name < b.name;
}

int main() {
    int total;
    cin >> total;
    vector<Person> person(total);

    for(int i = 0; i < total; ++i) {
        string name;
        int age, numHobbies;
        cin >> name >> age >> numHobbies;
        string *hobbies = new string[numHobbies];

        for (int j = 0; j < numHobbies; ++j) {
            cin >> hobbies[j];
        }

        Person temp(name, age, numHobbies, hobbies);
        person[i] = temp;
        delete[] hobbies; // release memory to save other temporary data
    }

    sort(person.begin(), person.end(), cmp1);

    for(int i = 0; i < total; ++i) {
        cout << "Person " << i + 1 << " info:" << endl;
        person[i].displayInfo();
    }

    return 0;
}
