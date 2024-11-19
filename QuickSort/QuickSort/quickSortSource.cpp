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
	int pivot = L[right]; // ����Ʈ�� ������ �� = pivot
	int i = left - 1;

	// ���ʺ��� Ž��
	for (int j = left; j < right; j++) {
		if (L[j] < pivot) {
			i++;
			swap(L[i], L[j]); // �ǹ����� ���� ���� ��������
		}
	}
	swap(L[i + 1], L[right]); // Left - pivot - Right ���·�
	return i + 1; // pivot�� ���� ��ġ �ε��� ��ȯ
}

void quick_sort(int left, int right)
{
	/* �� ���� �˸��� ������ �߰��Ͻÿ�. partition ����� ���⿡ �ڵ带 ���� �ְų�, ���� �Լ��� ���� ���� */
	/* �Է� ����Ÿ�� L[]�� ��� ������, ��ü ���� ������ SIZE�̴�. */
	if (left < right) {
		int targetIndex = partition(left, right); // Left - pivot - Right ����
		quick_sort(left, targetIndex - 1); // ���� ����
		quick_sort(targetIndex + 1, right); // ���� ����
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
