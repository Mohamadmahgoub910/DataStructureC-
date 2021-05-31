#include <iostream>

using namespace std;

void Swap(int &first, int &second)
{
	int temp = first;
	first = second;
	second = temp;
}

void BubbleSort(int *arr, int size)
{
	int sorted = 0, loops = 0;

	for (int counter = 0; counter < size - 1 && sorted == 0; counter++)
	{
		sorted = 1;

		for (int index = 0; index < size - 1 - counter; index++)
		{
			if (arr[index] > arr[index + 1])
			{
				Swap(arr[index], arr[index + 1]);
				sorted = 0;
			}
			loops++;
		}

	}

	cout << "loops = " << loops << endl;
}

void SelectionSort(int *arr, int size)
{
	int minIndex;

	for (int counter = 0; counter < size - 1; counter++)
	{
		minIndex = counter;

		for (int index = minIndex + 1; index < size; index++)
		{
			if (arr[index] < arr[minIndex])
			{
				minIndex = index;
			}
		}
		Swap(arr[counter], arr[minIndex]);
	}

}


void Display(int *arr, int size)
{
	for (int index = 0; index < size; index++)
	{
		cout << arr[index] << "\t";
	}
}

int main()
{
	int arr[] = { 4, 2, 5, 1, 6, 3 };

	BubbleSort(arr, 6);
	Display(arr, 6);

	return 0;
}







//#include<iostream>
//using namespace std;
//
//void bubbleSort(int *arr, int size);
//void display(int * arr, int size);
//void Swap(int &f, int &l);
//void sellectionSort(int *arr, int size);
//int BinarySearch(int *arr , int size, int data);
//
//int main() {
//	/*int *ptr;
//	//4
//	cout << sizeof(ptr) << endl;*/
//	//int arr[] = { 4,2,5,1,6,3 };
//	int arr[] = { 4,6,2,5,1,3 };
//	//Bubble Sort (1)
//	cout << "Bubble sort \n";
//	bubbleSort(arr, 6);
//	display(arr, 6);
//	cout << endl;
//	cout << "Sellection sort \n";
//	sellectionSort(arr, 6);
//	display(arr, 6);
//	cout << endl;
//	cout << "Binary search \n";
//	
//	int res = BinarySearch(arr,6,2);
//	
//		if (res == 1) {
//			cout << "got it \n";
//		}
//		else {
//			cout << "Not found \n";
//		}
//	
//	return 0;
//}
//
//
//void BubbleSort(int *arr, int size)
//{
//	int sorted = 0, loops = 0;
//
//	for (int counter = 0; counter < size - 1 && sorted == 0; counter++)
//	{
//		sorted = 1;
//
//		for (int index = 0; index < size - 1 - counter; index++)
//		{
//			if (arr[index] > arr[index + 1])
//			{
//				Swap(arr[index], arr[index + 1]);
//				sorted = 0;
//			}
//			loops++;
//		}
//
//	}
//
//	cout << "loops = " << loops << endl;
//}
//void display(int * arr, int size)
//{
//	for (int i = 0; i < size; i++) {
//		cout << arr[i] << " ";
//	}
//}
//
//void Swap(int & f, int & l)
//{
//	int temp;
//	temp = f;
//	f = l;
//	l = temp;
//}
//
//void sellectionSort(int * arr, int size)
//{
//	// suppoze that i have minindex =0;
//	int minIndex = 0;
//	for (int j=0; j<size-1; j++){
//	for (int i = minIndex+1; i < size; i++) {
//		if (arr[i] < arr[minIndex]) {
//			minIndex = i;
//		}
//	}
//	Swap(arr[j], arr[minIndex]);
//}
//	
//}
//
//int BinarySearch(int * arr, int size, int data)
//{
//	bubbleSort(arr, size);
//	int min = 0, max = size - 1;
//	int middle = (min + max) / 2;
//	while (min<=max) {
//		 middle = size / 2;
//		if (arr[middle] == data) {
//			//cout << "got it \n";
//			return middle;
//		}
//		if (data < arr[middle]) {
//			max = middle - 1;
//		}
//		else
//		{
//			min = middle + 1;
//		}
//	}
//	return -1;
//	
//}
