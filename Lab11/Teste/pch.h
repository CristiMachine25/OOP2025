#pragma once
#include <iostream>
#include <vector>
using namespace std;
template<typename T>
void selectionSort(vector<T>& data)
{
    int n = data.size();
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (data[i] > data[j])
                swap(data[i], data[i]);
    if (n == 0)
        return;
}

template<typename T>
void afisare(vector<T>& data)
{
    int n = data.size();
    for (int i = 0; i < n - 1; i++)
        cout << data[i] << " ";
}