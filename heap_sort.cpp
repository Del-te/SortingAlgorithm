#include <iostream>
#include <algorithm>
using namespace std;

void max_heapify(int arr[], int start, int end) {
    // 建立父节点和左子节点指针(左子节点加一就是右子节点)
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { 
        // 越界判断 && 选择最大的子节点与父节点比较
        if (son + 1 <= end && arr[son] < arr[son + 1])
            son++;
        // 如果父节点大于子节点则代表调整完毕
        if (arr[dad] > arr[son])
            return;
        else { 
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
void heap_sort(int arr[], int len) {
    // 初始化，i从最后一个父节点开始调整
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    // 此时堆顶是最大元素，将堆顶与最后一个元素交换，重复进行
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

int main() {
    int a[9] = {3, 4, 2, 1, -1, 8, 9, 5, 7};
    heap_sort(a, 9);
    for (int i = 0; i < 9; i++)
        cout << a[i] << " ";
    system("pause");
    return 0;
}