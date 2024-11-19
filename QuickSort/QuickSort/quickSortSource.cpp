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

int partition(int left, int right) {
	int pivot = L[right]; // 리스트의 마지막 값 = pivot
	int i = left - 1;

	// 왼쪽부터 탐색
	for (int j = left; j < right; j++) {
		if (L[j] < pivot) {
			i++;
			swap(L[i], L[j]); // 피벗보다 작은 값을 왼쪽으로
		}
	}
	swap(L[i + 1], L[right]); // Left - pivot - Right 형태로
	return i + 1; // pivot의 최종 위치 인덱스 반환
}

void quick_sort(int left, int right)
{
	/* 이 곳에 알맞은 내용을 추가하시오. partition 기능은 여기에 코드를 직접 넣거나, 별도 함수로 구현 가능 */
	/* 입력 데이타는 L[]에 들어 있으며, 전체 원소 개수는 SIZE이다. */
	if (left < right) {
		int targetIndex = partition(left, right); // Left - pivot - Right 형태
		quick_sort(left, targetIndex - 1); // 좌측 정렬
		quick_sort(targetIndex + 1, right); // 우측 정렬
	}
}

void main()
{
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	quick_sort(0, SIZE - 1);

	cout << "\n\nSorted Data : ";
	print_data();

}
