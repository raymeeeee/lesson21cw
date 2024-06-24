#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
void addItemBack(T*& arr, int& size, T value)
{
	//1
	T* tmp = new T[size + 1];
	//2
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	//3
	tmp[size] = value;
	//4
	if(arr != nullptr) delete[] arr;
	//5
	arr = tmp;
	//6
	size++;
}
template <typename T>
void addItemFront(T*& arr, int& size, T value)
{	

	T* tmp = new T[size + 1];
	//2
	for (int i = 0; i < size; i++)
	{
		tmp[i + 1] = arr[i];
	}
	//3
	tmp[0] = value;
	//4
	if (arr != nullptr) delete[] arr;
	//5
	arr = tmp;
	//6
	size++;
}

template <typename T>
int myCountIf(T* arr, int size, bool (*func)(T value))
{
	int amount = 0;
	for (int i = 0; i < size; i++)
	{
		if (func(arr[i]) == true)
		{
			amount++;

		}
	}
	return amount;
}


template <typename T>
int myFindIf(T* arr, int size, bool (*func)(T value))
{
	int index_first = 0;
	for (int i = 0; i < size; i++)
	{
		if (func(arr[i]) == true)
		{
			index_first = i;
			break;
		}
	}
	return index_first;
}

template <typename T>
void myReplaceIf(T* arr, int size, bool (*func)(T), T value)
{
	for (int i = 0; i < size; i++)
	{
		if (func(arr[i]) == true)
		{
			arr[i] = value;
			
		}
	}
}

template <typename T>
void myRemoveIf(T*& arr, int& size, bool (*func)(T))
{
	int count = myCountIf(arr, size, func);
	if (count == 0)return;
	
	T* tmp = new T[size - count];
	
	for (int i = 0, j = 0; i < size; i++)
	{
		if (func(arr[i]) == false)
		{
			tmp[j] = arr[i];
			j++;
		}
		
	}
	
	if (arr != nullptr) delete[] arr;
	
	arr = tmp;
	size -= count;
}

template <typename T>
void myCopyIf(T* arr, int size, T*& arr_copy, int& size_copy, bool (*func)(T)){
	size_copy = myCountIf(arr, size, func);
	if (size_copy == 0) return;
	if (arr_copy != nullptr) delete[] arr_copy;

	arr_copy = new T[size_copy];

	for (int i = 0, j = 0; i < size; i++)
	{
		if (func(arr[i]) == true)
		{
			arr_copy[j] = arr[i];
			j++;
		}

	}

}
template <typename T>
int findLast_if(T* arr, int size, bool (*func)(T value))
{
	int index_last = 0;
	for (int i = 0; i < size; i++)
	{
		if (func(arr[i]) == true)
		{
			index_last = i;
			
		}
	}
	return index_last;
}

template <typename T>
void sort_if(T* arr, int size, bool (*cmp)(T, T)) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (cmp(arr[j], arr[j + 1])) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


template <typename T>
void addItemPos(T*& arr, int& size, int pos, T value)
{
	T* tmp = new T[++size];
	//2
	for (int i = 0; i < size; i++)
	{
		if (i < pos)tmp[i] = arr[i];
		else if (i == pos) tmp[i] = value;
		else tmp[i] = arr[i - 1];
	}

	//4
	if (arr != nullptr) delete[] arr;
	//5
	arr = tmp;
}