template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to free allocated memory
    ~LinkedList() {
        clear();
    }

    // Copy constructor
    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr) {
        Node* current = other.head;
        while (current) {
            insert(current->data);
            current = current->next;
        }
    }

    // Assignment operator
    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            clear();
            Node* current = other.head;
            while (current) {
                insert(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    // Insert a new value into the list
    void insert(T value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete a value from the list
    void remove(T value) {
        if (!head) return;
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }
        if (current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            if (current->next == nullptr) {
                tail = current;
            }
            delete temp;
        }
    }

    // Traverse the list and print each value
    void traverse() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Concatenate operator +
    LinkedList operator+(const LinkedList& other) const {
        LinkedList result;
        Node* current = head;
        while (current) {
            result.insert(current->data);
            current = current->next;
        }
        current = other.head;
        while (current) {
            result.insert(current->data);
            current = current->next;
        }
        return result;
    }

    // Clear the list
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
};
