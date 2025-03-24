#include <cstdlib>
#include <ctime>

class Sort
{
    int* vector;
    int size;
public:
    
    Sort(int nrElemente, int minValue, int maxValue);
	Sort();
    Sort(int* vector, int size);
    Sort(int count, ...);
    Sort(char* string);

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);
	void QuickSort(int left, int right, bool ascendent);
	int  Partition(int left, int right, bool ascendent);
	void Swap(int i, int j);

    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
