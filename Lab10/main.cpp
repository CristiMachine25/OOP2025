#include <iostream>
#include <exception>
using namespace std;

class Compare {
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T> class Array; // Forward declaration

template<class T>
class ArrayIterator
{
private:
    Array<T>* arr;
    int Current;
public:
    ArrayIterator() : arr(nullptr), Current(0) {}
    ArrayIterator(Array<T>* array, int index) : arr(array), Current(index) {}

    ArrayIterator& operator++() {
        Current++;
        return *this;
    }

    ArrayIterator& operator--() {
        Current--;
        return *this;
    }

    ArrayIterator& operator=(const ArrayIterator<T>& other) {
        this->arr = other.arr;
        this->Current = other.Current;
        return *this;
    }

    bool operator==(const ArrayIterator<T>& other) const {
        return this->arr == other.arr && this->Current == other.Current;
    }

    bool operator!=(const ArrayIterator<T>& other) const {
        return !(*this == other);
    }

    T* GetElement() {
        if (!arr || Current < 0 || Current >= arr->GetSize()) {
            return nullptr;
        }
        return &(*arr)[Current];
    }
};

class IndexOutOfRange : public exception {
public:
    const char* what() const throw() {
        return "Index out of range";
    }
};

class ArrayFullException : public exception {
public:
    const char* what() const throw() {
        return "Array is full";
    }
};

template<class T>
class Array
{
private:
    T** List;
    int Capacity;
    int Size;
public:
    Array() : List(nullptr), Capacity(0), Size(0) {}

    Array(int capacity) {
        Capacity = capacity;
        Size = 0;
        List = new T * [Capacity];
        for (int i = 0; i < Capacity; i++)
            List[i] = nullptr;
    }

    ~Array() {
        for (int i = 0; i < Size; i++)
            delete List[i];
        delete[] List;
    }

    Array(const Array<T>& otherArray) {
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++) {
            List[i] = new T(*otherArray.List[i]);
        }
    }

    T& operator[] (int index) {
        if (index < 0 || index >= Size)
            throw IndexOutOfRange();
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem) {
        if (Size >= Capacity) {
            throw ArrayFullException();
        }
        List[Size] = new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem) {
        if (index < 0 || index > Size)
            throw IndexOutOfRange();
        if (Size >= Capacity)
            throw ArrayFullException();
        for (int i = Size - 1; i >= index; i--)
            List[i + 1] = List[i];
        List[index] = new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray) {
        if (index < 0 || index > Size)
            throw IndexOutOfRange();
        if (Size + otherArray.Size > Capacity)
            throw ArrayFullException();
        for (int i = Size - 1; i >= index; i--)
            List[i + otherArray.Size] = List[i];
        for (int i = 0; i < otherArray.Size; i++)
            List[index + i] = new T(*otherArray.List[i]);
        Size += otherArray.Size;
        return *this;
    }

    const Array<T>& Delete(int index) {
        if (index < 0 || index >= Size)
            throw IndexOutOfRange();
        delete List[index];
        for (int i = index; i < Size - 1; i++)
            List[i] = List[i + 1];
        List[Size - 1] = nullptr;
        Size--;
        return *this;
    }

    bool operator=(const Array<T>& otherArray) {
        if (this == &otherArray)
            return true;
        for (int i = 0; i < Size; i++)
            delete List[i];
        delete[] List;
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++)
            List[i] = new T(*otherArray.List[i]);
        return true;
    }

    void Sort() {
        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (*List[i] > *List[j]) {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    void Sort(int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (compare(*List[i], *List[j]) > 0) {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    void Sort(Compare* comparator) {
        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (comparator->CompareElements(List[i], List[j]) > 0) {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    int BinarySearch(const T& elem) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (*List[mid] == elem)
                return mid;
            if (*List[mid] < elem)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (compare(*List[mid], elem) == 0)
                return mid;
            if (compare(*List[mid], elem) < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (comparator->CompareElements(List[mid], &elem) == 0)
                return mid;
            if (comparator->CompareElements(List[mid], &elem) < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int Find(const T& elem) {
        for (int i = 0; i < Size; i++) {
            if (*List[i] == elem)
                return i;
        }
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size; i++) {
            if (compare(*List[i], elem) == 0)
                return i;
        }
        return -1;
    }

    int Find(const T& elem, Compare* comparator) {
        for (int i = 0; i < Size; i++) {
            if (comparator->CompareElements(List[i], &elem) == 0)
                return i;
        }
        return -1;
    }

    int GetSize() {
        return Size;
    }

    int GetCapacity() {
        return Capacity;
    }

    ArrayIterator<T> GetBeginIterator();
    ArrayIterator<T> GetEndIterator();
};

template<class T>
ArrayIterator<T> Array<T>::GetBeginIterator() {
    return ArrayIterator<T>(this, 0);
}

template<class T>
ArrayIterator<T> Array<T>::GetEndIterator() {
    return ArrayIterator<T>(this, Size);
}

int main() {
    Array<int> a(3);
    try {
        a += 10;
        a += 20;
        a += 30;
    }
    catch (ArrayFullException& e) {
        cout << "Eroare la adaugare (+): " << e.what() << endl;
    }

    cout << "Elementele din array sunt: ";
    for (int i = 0; i < a.GetSize(); i++)
        cout << a[i] << " ";
    cout << endl;

    cout << "Adaugam 40 la indexul 1" << endl;
    try {
        a.Delete(2); // eliberăm un slot înainte de a insera
        a.Insert(1, 40);
        cout << "Elementele din array dupa inserarea lui 40: ";
        for (int i = 0; i < a.GetSize(); i++)
            cout << a[i] << " ";
        cout << endl;
    }
    catch (exception& e) {
        cout << "Eroare la inserare: " << e.what() << endl;
    }

    cout << "Stergem elementul de la indexul 2" << endl;
    try {
        a.Delete(2);
        cout << "Elementele dupa stergere: ";
        for (int i = 0; i < a.GetSize(); i++)
            cout << a[i] << " ";
        cout << endl;
    }
    catch (IndexOutOfRange& e) {
        cout << "Eroare la stergere: " << e.what() << endl;
    }

    cout << "Incercam sa inseram 50 la indexul 5 (invalid)" << endl;
    try {
        a.Insert(5, 50);
    }
    catch (exception& e) {
        cout << "Eroare la inserare: " << e.what() << endl;
    }

    return 0;
}