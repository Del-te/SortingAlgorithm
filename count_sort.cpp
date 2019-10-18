#include <iostream>
#include <cstring>
using namespace std;
void count_sort(int *arr, int len) {
	if (arr == NULL)	return;
	int max = arr[0], min = arr[0];
	for (int i = 1; i < len; i++) {
		if (arr[i] > max)	max = arr[i];
		if (arr[i] < min)	min = arr[i];
	}
	int size = max - min + 1;
	int* count = (int*)malloc(sizeof(int)*size);
	memset(count, 0, sizeof(int)*size);
	for (int i = 0; i < len; i++) count[arr[i] - min]++;//包含了自己！
	for (int i = 1; i < size; i++)	count[i] += count[i - 1];
	int* psort = (int*)malloc(sizeof(int)*len);
	memset(psort, 0, sizeof(int)*len);
	for (int i = len - 1; i >= 0; i--) { 
		count[arr[i] - min]--;//要先把自己减去
		psort[count[arr[i] - min]] = arr[i];
	}
	for (int i = 0; i < len; i++) {
		arr[i] = psort[i];
	}
	free(count);
	free(psort);
	count = NULL;
	psort = NULL;
}
int main()
{
    int a[9] = {1, -1, 6, 2, 8, 9, 9, 7, 4};
    count_sort(a, 9);
    for (int i = 0; i < 9; i++)
        cout << a[i] << " ";
    system("pause");
    return 0;
}
