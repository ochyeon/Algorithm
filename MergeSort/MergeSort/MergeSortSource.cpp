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

void merge(int left, int mid, int right){
	int leftSize = mid - left + 1;
	int rightSize = right - mid;
	// �ӽ� �迭
	int* leftArr = new int[leftSize];
	int* rightArr = new int[rightSize];

	for (int i = 0; i < leftSize; i++) {
		leftArr[i] = L[left + i];
	}
	for (int i = 0; i < rightSize; i++) {
		rightArr[i] = L[mid + 1 + i];
	}

	// ����
	int i = 0, j = 0, k = left;
	while (i < leftSize && j < rightSize) {
		if (leftArr[i] <= rightArr[j]) {
			L[k] = leftArr[i];
			i++;
		}
		else {
			L[k] = rightArr[j];
			j++;
		}
		k++;
	}
	// ���� ��� ����
	while (i < leftSize) {
		L[k] = leftArr[i];
		i++;
		k++;
	}
	while (j < rightSize) {
		L[k] = rightArr[j];
		j++;
		k++;
	}

	delete[] leftArr;
	delete[] rightArr;
}

void merge_sort(int left, int right)
{
	/* �� ���� �˸��� ������ �߰��Ͻÿ�. */
	/* �Է� ����Ÿ�� L[]�� ��� ������, ��ü ���� ������ SIZE�̴�. */
	if (right > left) {
		int mid = (right + left) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
}

int main()
{
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	merge_sort(0, SIZE - 1);

	cout << "\n\nSorted Data : ";
	print_data();

	return 0;
}
