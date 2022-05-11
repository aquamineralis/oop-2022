#include <iostream>

template <class A, class B>
struct pair {
    A key;
    B value;
};

template <class A, class B>
class Iterator {
  private:
    struct tuple {
        A key;
        B value;
        int index;
    };
    pair<A, B>* ptr;
    int index;

  public:
    Iterator(pair<A, B>* ptr, int index) : ptr(ptr), index(index){};
    bool operator!=(const Iterator& other) {
        return ptr != other.ptr;
    }
    Iterator& operator++() {
        ptr++;
        index++;
        return *this;
    }
    tuple operator*() {
        // tuple T = { ptr->key, ptr->value, index };
        return { ptr->key, ptr->value, index };
    }
};

template <class A, class B>
class Map {
  private:
    pair<A, B> vector[30];
    int size;

  public:
    Map() : size(0){};
    B& operator[](A key) {
        for (int i = 0; i < size; i++) {
            if (vector[i].key == key)
                return vector[i].value;
        }
        vector[size].key   = key;
        vector[size].value = {};
        size++;
        // sort
        return vector[size - 1].value;
    }
    Iterator<A, B> begin() {
        return { vector, 0 };
    }
    Iterator<A, B> end() {
        return { vector + size, size };
    }
};

int main() {
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}
