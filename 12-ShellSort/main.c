#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 100

//���� ��ҵ��� ���
void print_list(int list[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%02d ", list[i]);
	}
	printf("\n");
}

//���� ��ҵ��� 20���� ���
void print_partial_list(int list[], int n) {
	for (int i = 0; i < n && i < 20; i++) {
		printf("%02d ", list[i]);
	}
	printf(". . . \n");
}

//�迭�� ���� ���ڵ��� ����
void generateRandomNumbers(int data[]) {
	srand(time(0));
	for (int i = 0; i < ARRAY_SIZE; i++) {
		data[i] = rand() % 1000;
	}
}

//�� ���� ���� �Լ�
int doShellSort(int list[], int first, int last, int gap, int* moveCount) {
	int i, j, key, count = 0;
	for (i = first; i < last; i += gap) {
		key = list[i];
		for (j = i - gap; j >= first && list[j] > key; j -= gap) {
			count++;
			list[j + gap] = list[j];
			(*moveCount)++;
		}
		list[j + gap] = key;
		(*moveCount)++;
	}
	return count;
}

//�� ���� �Լ� ����
void ShellSort(int list[], int n, int* comparisonCount, int* moveCount) {
	int gap, i;
	*comparisonCount = 0;
	*moveCount = 0;
	for (gap = ARRAY_SIZE / n; gap > 0; gap /= n) {
		printf("Sorting with gap: %d\n", gap);
		print_partial_list(list, ARRAY_SIZE);
		printf("\n");
		for (i = 0; i < gap; i++) {
			*comparisonCount += doShellSort(list, i, ARRAY_SIZE, gap, moveCount);
		}
	}
	printf("Sorted shellArray (gap = %d):\n", n);
	print_list(list, ARRAY_SIZE);
	printf("\n");
}

//(���ʽ�) ���� ���� ���� �Լ�
void insertSort(int list[], int* comparisonCount, int* moveCount) {
	int i, j, key;
	*comparisonCount = 0;
	*moveCount = 0;
	for (i = 1; i < ARRAY_SIZE; i++) {
		key = list[i];
		j = i - 1;
		while (j >= 0 && list[j] > key) {
			list[j + 1] = list[j];
			j = j - 1;
			(*comparisonCount)++;
			(*moveCount)++;
		}
		list[j + 1] = key;
		(*moveCount)++;
	}
	printf("Sorted insertArray:\n");
	print_list(list, ARRAY_SIZE);
	printf("\n");
}

int main() {
	int array[ARRAY_SIZE];
	int comparisonCount, moveCount;

	generateRandomNumbers(array); // �迭�� �ٽ� �ʱ�ȭ�մϴ�.

	printf("Shell Sort (n/2)\n");
	ShellSort(array, 2, &comparisonCount, &moveCount);
	printf("Shell Sort (n/2) - Comparisons: %d, Moves: %d\n\n", comparisonCount, moveCount);

	generateRandomNumbers(array); // �迭�� �ٽ� �ʱ�ȭ�մϴ�.

	printf("Shell Sort (n/3)\n");
	ShellSort(array, 3, &comparisonCount, &moveCount);
	printf("Shell Sort (n/3) - Comparisons: %d, Moves: %d\n\n", comparisonCount, moveCount);

	generateRandomNumbers(array); // �迭�� �ٽ� �ʱ�ȭ�մϴ�.

	printf("Insert Sort\n");
	insertSort(array, &comparisonCount, &moveCount);
	printf("Insert Sort - Comparisons: %d, Moves: %d\n\n", comparisonCount, moveCount);

	return 0;
}
