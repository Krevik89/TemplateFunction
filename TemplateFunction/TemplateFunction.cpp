#include <iostream>
#include <algorithm>
using namespace std;


template<typename T>
T Min(T arr[],const int n);
template<typename T>
T Max(T arr[],const int n);
template<typename T>
void sort(T arr[], const int n);
template<typename T>
void biFind(T arr[],const int n,T c);
template<typename T>
void replace(T arr[],const int n, T c);


int main()
{
	setlocale(0, "");
	const int n =10;
	int c = 3;
	int intarr[n]{9,2,3,4,5,6,7,8,1,10};
	double darr[n]{9.21,2.09,3.43,4.0,5.12,6.432,7.31,85.12,1.01,10.12};
	auto armin=Min(darr, n);
	//cout << armin<<endl;
	auto armax=Max(intarr, n);
	//cout << armax<<endl;
	//sort(darr, n);
	//replace(darr, n, 2.4);
	biFind(intarr, n, c);

}

template<typename T>
T Min(T arr[],const int n) {
    T min = arr[0];
	for (int i{0}; i < n; i++)
	{
		if (min > arr[i]) min = arr[i];
	}
	return min;
}

template<typename T>
T Max(T arr[],const int n) {
	T max = arr[0];
	for (int i{0}; i < n; i++)
	{
		if (max < arr[i]) max = arr[i];
	}
	return max;
}

template<typename T>
void sort(T arr[],const int n) {
	for (int i{ 0 }; i < n; i++) {
		for (int j{ 0 }; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	
}

template<typename T>
void biFind(T arr[],const int n,T c) {
	sort(arr, arr + 10);
	bool flag = false;
	int l = 0; // левая граница
	int r = 9; // правая граница
	int mid;

	while ((l <= r) && (flag != true)) {
		mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

		if (arr[mid] == c) flag = true; //проверяем ключ со серединным элементом
		if (arr[mid] > c) r = mid - 1; // проверяем, какую часть нужно отбросить
		else l = mid + 1;
	}

	if (flag) cout << "Индекс элемента " << c << " в массиве равен: " << mid;
	else cout << "Извините, но такого элемента в массиве нет";
}

template<typename T>
void replace(T arr[],const int n,T c) {
	for (int i = 0; i < n; i++)
	{
		arr[i] = c;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

}
