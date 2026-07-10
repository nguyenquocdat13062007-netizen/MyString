#pragma once
class SortAlg
{
private:
	SortAlg() {};
	void (*currentAlg)(float[], int);
public:
	static void Menu(void (*alg)(float[], int));
	static void BubbleSort(float[], int n);
	static void SelectionSort(float[], int n);
	static void InsertionSort(float[], int n);
};
