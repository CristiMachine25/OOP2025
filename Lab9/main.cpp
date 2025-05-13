#include <stdio.h>
using namespace std;

template <typename K, typename V>
class Map {
private:
    struct Entry{
        K key;
        V value;
    };
    Entry data[100];
    int size = 0;
public:
    V& operator[](const K& key) {
        for (int i = 0; i < size; i++) {
            if (data[i].key == key)
                return data[i].value;
        }
        data[size].key = key;
        size++;
		return data[size - 1].value;
    }
    struct Item {
        K& key;
        V& value;
        int index;
    };

    void Set(const K& key, const V& value) { ///adauga o cheie si o valoare, iar daca avem deja o cheie, modifica valoarea
        for (int i = 0; i < size; i++) {
            if (data[i].key == key)
                data[i].value = value;
        }
        data[size].key = key;
        data[size].value = value;
        ++size;
    }
    bool Get(const K& key, V& value) { //cauta o cheie si o copiaza in value, returneaza true sau false
        for (int i = 0; i < size; i++) {
            if (data[i].key == key) {
                value = data[i].value;
                return true;
            }
        }
        return false;
    }
    int Count() { //numarul de elemente
        return size;
    }   
    void Clear() {
        size = 0;
    }
    bool Delete(const K& key) {
        for (int i = 0; i < size; i++) {
            if (data[i].key == key) {
                for (int j = i; j < size - 1; j++) {
                    data[j] = data[j + 1];
                }
                --size;
                return true;
            }
        }
        return false;
    }
	bool Includes(const Map<K, V>& map) {
		for (int i = 0; i < map.size; i++) {
			bool found = false;
			for (int j = 0; j < size; j++) {
				if (data[j].key == map.data[i].key) {
					found = true;
					break;
				}
			}
			if (!found)
				return false;
		}
		return true;

    }
    class Iterator {
    private:
        Entry* ptr;
        int index;
    public:
        Iterator(Entry* p, int idx) : ptr(p), index(idx) {}

        Iterator& operator++() {
            ++ptr;
            ++index;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }

        Item operator*() const {
            return { ptr->key, ptr->value, index };
        }
    };

    Iterator begin() {
        return Iterator(data, 0);
    }

    Iterator end() {
        return Iterator(data + size, size);
    }
};

int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}
