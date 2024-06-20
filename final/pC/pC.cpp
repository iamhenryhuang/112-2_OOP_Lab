#include <iostream>
#include <string>
template <typename T>
class DinamicArray {
private:
    T *_arr;
    int _size;
    int capacity;

    void reCreate(int temp_capacity) {
        T *temp_arr = new T[temp_capacity];
      
        for (int i = 0; i < _size; ++i) {
            temp_arr[i] = _arr[i];
        }
      
        delete[] _arr;
        _arr = temp_arr;
        capacity = temp_capacity;
    }
    
public:
    DinamicArray() : _arr(nullptr), _size(0), capacity(0) {}

    DinamicArray(const DinamicArray &other) {
      _arr = new T[capacity];
      for (int i = 0; i < _size; ++i) {
          _arr[i] = other._arr[i];
      }
      _size = other._size;
      capacity = other.capacity;
    }

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
                reCreate(1);
            } 
          	else {
                reCreate(2 * capacity);
            }
        }
        _arr[_size++] = value;
    }

    T pop() {
        return _arr[--_size];
    }

    void clear() {
      _size = 0;
      capacity = 0;
    }

    DinamicArray slice(int startIndex, int endIndex) const {
        DinamicArray dump;
        for (int i = startIndex; i < endIndex; ++i) {
            dump.push(_arr[i]);
        }
        return dump;
    }

    DinamicArray& operator=(const DinamicArray &other) {
        //return *this;
        return other._arr;
    }

    DinamicArray operator+(const DinamicArray &other) const {
        DinamicArray dump;
      
        for (int i = 0; i < _size; ++i) {
            dump.push(_arr[i]);
        }
      
        for (int j = 0; j < other._size; ++j) {
            dump.push(other._arr[j]);
        }
      
        return dump;
    }

    DinamicArray& operator+=(const DinamicArray &other) {
        for (int i = 0; i < other._size; ++i) {
            this->push(other._arr[i]);
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
      if(*this == other) return false;
      else return true;
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
    for(int i = 0; i < datasize; ++i) {
        int temp;
        std::cin >> temp;
        arr.push(temp);
    }

    DinamicArray<int> arr2;
    std::cin >> datasize;
    for(int i = 0; i < datasize; ++i) {
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
    for(int i = 0; i < strdatasize; ++i) {
        std::string temp;
        std::cin >> temp;
        strarr.push(temp);
    }

    DinamicArray<std::string> strarr2;
    std::cin >> strdatasize;
    for(int i = 0; i < strdatasize; ++i) {
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
