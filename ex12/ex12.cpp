#include <iostream>
#include <string>

template <typename T>
class DinamicArray {
private:
    T *_arr;
    int _size;
    int capacity;

    void resize(int new_capacity) {
        T *new_arr = new T[new_capacity];
        for (int i = 0; i < _size; ++i) {
            new_arr[i] = _arr[i];
        }
        delete[] _arr;
        _arr = new_arr;
        capacity = new_capacity;
    }

public:
    // Default Constructor
    DinamicArray() : _arr(nullptr), _size(0), capacity(0) {}

    // Constructor
    DinamicArray(const DinamicArray &other) : _size(other._size), capacity(other.capacity) {
        _arr = new T[capacity];
        for (int i = 0; i < _size; ++i) {
            _arr[i] = other._arr[i];
        }
    }

    // Destructor
    ~DinamicArray() {
        delete[] _arr;
    }

    int size() const {
        return _size;
    }

    T& get(int index) const {
        return _arr[index];
    }

    T& operator[](int index) const {
        return _arr[index];
    }

    void push(T value) {
        if (_size == capacity) {
            if(capacity == 0) {
                resize(1);
            } else {
                resize(2 * capacity);
            }
        }
        _arr[_size++] = value;
    }

    T pop() {
        if (_size == 0) {
            throw std::out_of_range("Array is empty");
        }
        return _arr[--_size];
    }

    void clear() {
        _size = 0;
    }

    DinamicArray slice(int startIndex, int endIndex) const {
        DinamicArray result;
        for (int i = startIndex; i < endIndex; ++i) {
            result.push(_arr[i]);
        }
        return result;
    }

    DinamicArray& operator=(const DinamicArray &other) {
        if (this != &other) {
            delete[] _arr;
            _size = other._size;
            capacity = other.capacity;
            _arr = new T[capacity];
            for (int i = 0; i < _size; ++i) {
                _arr[i] = other._arr[i];
            }
        }
        return *this;
    }

    DinamicArray operator+(const DinamicArray &other) const {
        DinamicArray result;
        for (int i = 0; i < _size; ++i) {
            result.push(_arr[i]);
        }
        for (int i = 0; i < other._size; ++i) {
            result.push(other._arr[i]);
        }
        return result;
    }

    DinamicArray& operator+=(const DinamicArray &other) {
        for (int i = 0; i < other._size; ++i) {
            push(other._arr[i]);
        }
        return *this;
    }

    bool operator==(const DinamicArray &other) const {
        if (_size != other._size) {
            return false;
        }
        for (int i = 0; i < _size; ++i) {
            if (_arr[i] != other._arr[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const DinamicArray &other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream &out, const DinamicArray &arr) {
        out << "[";
        for (int i = 0; i < arr._size; ++i) {
            out << arr._arr[i];
            if (i != arr._size - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }
};

int main() {
    DinamicArray<int> arr;
    int datasize;
    std::cin >> datasize;
    for (int i = 0; i < datasize; ++i) {
        int temp;
        std::cin >> temp;
        arr.push(temp);
    }

    DinamicArray<int> arr2;
    std::cin >> datasize;
    for (int i = 0; i < datasize; ++i) {
        int temp;
        std::cin >> temp;
        arr2.push(temp);
    }

    std::cout << arr << std::endl;
    std::cout << arr.size() << std::endl;
    std::cout << arr.pop() << std::endl;

    DinamicArray<int> arr3 = arr + arr2;
    std::cout << arr3 << std::endl;

    arr3 += arr2;
    std::cout << arr3 << std::endl;
    std::cout << ((arr3 == arr + arr2 + arr2) ? "true" : "false") << std::endl;

    arr.clear();
    std::cout << arr.size() << std::endl;
    std::cout << arr << std::endl;
    std::cout << ((arr3 != arr + arr2 + arr2) ? "true" : "false") << std::endl;

    int startIndex, endIndex;
    std::cin >> startIndex >> endIndex;
    std::cout << arr3.slice(startIndex, endIndex) << std::endl;

    DinamicArray<std::string> strarr;
    int strdatasize;
    std::cin >> strdatasize;
    for (int i = 0; i < strdatasize; ++i) {
        std::string temp;
        std::cin >> temp;
        strarr.push(temp);
    }

    DinamicArray<std::string> strarr2;
    std::cin >> strdatasize;
    for (int i = 0; i < strdatasize; ++i) {
        std::string temp;
        std::cin >> temp;
        strarr2.push(temp);
    }

    std::cout << strarr << std::endl;
    std::cout << strarr.size() << std::endl;
    std::cout << strarr.pop() << std::endl;

    DinamicArray<std::string> strarr3 = strarr + strarr2;
    std::cout << strarr3 << std::endl;

    strarr3 += strarr2;
    std::cout << strarr3 << std::endl;
    std::cout << ((strarr3 == strarr + strarr2 + strarr2) ? "true" : "false") << std::endl;

    strarr.clear();
    std::cout << strarr.size() << std::endl;
    std::cout << strarr << std::endl;
    std::cout << ((strarr3 != strarr + strarr2 + strarr2) ? "true" : "false") << std::endl;

    int strstartIndex, strendIndex;
    std::cin >> strstartIndex >> strendIndex;
    std::cout << strarr3.slice(strstartIndex, strendIndex) << std::endl;

    return 0;
}
