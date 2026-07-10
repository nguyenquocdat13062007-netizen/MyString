#pragma once
#include <iostream>
using namespace std;
class SortAlg
{
private:
	SortAlg() {};
	static void (*currentAlg)(float[], int);
public:
	static void SetAlg(void (*alg)(float[], int))
	{
		if (alg != NULL)
		{
			currentAlg = alg;
		}
	};
	static void BubbleSort(float[], int);
	static void SelectionSort(float[], int);
	static void InsertionSort(float[], int);
	static void InterchangeSort(float[], int);
	static void Sort(float[], int);
	void (*menuAlg[])(float[], int);
};
void SortAlg::InsertionSort(float arr[], int n) {
	int j;
	float pos;
	for (int i = 1; i < n; i++) {
		pos = arr[i];
		j = i - 1;

		while (j >= 0) {
			if (arr[j] > pos) {
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			else {
				break;
			}
		}
		arr[j + 1] = pos;
	}
}

void SortAlg::BubbleSort(float a[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    // Đổi chỗ
                    float temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }
