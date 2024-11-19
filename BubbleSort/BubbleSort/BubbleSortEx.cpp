#include <iostream>
using namespace std;

const int SIZE = 15;
int L[SIZE] = { 10, 4, 7, 1, -2, 12, 28, 66, 9, 3, 5, 7, 6, 21, 11 };


void print_data()
{
	for (int i = 0; i < SIZE; i++)
		cout << " " << L[i] << " ";
	cout << endl;
}

void sort(int L[])
{
	/* 이 곳에 알맞은 내용을 추가하시오. */
	/* 입력 데이타는 L[]에 들어 있으면, 전체 원소 개수는 SIZE이다. */
	int flag;
	for (int i = 0; i < SIZE; i++) {
		flag = 0;
		for (int j = 1; j < SIZE; j++) {
			if (L[j - 1] > L[j]) {
				int temp = L[j - 1];
				L[j - 1] = L[j];
				L[j] = temp;
				flag++;
			}
		}
		if (flag == 0)
			break;
	}


}

void main()
{
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	sort(L);

	cout << "\n\nSorted Data : ";
	print_data();

}
