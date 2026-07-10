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
