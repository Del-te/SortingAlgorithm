#include <iostream>
using namespace std;

void quick_sort(int *a, int l, int r)
{
    if (l >= r)
        return;
    int i = l;
    int j = r + 1;
    //开头的数为基准数
    int key = a[l];
    while (true)
    {
        // 从左向右找比key大的值
        while (a[++i] < key) 
            if (i == r)
                break;
        // 从右向左找比key小的值
        while (a[--j] > key)
            if (j == l)
                break;
        if (i >= j)
            break;
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    // 基准数与j对应值交换
    int t = a[l];
    a[l] = a[j];
    a[j] = t;
    quick_sort(a, l, j - 1);
    quick_sort(a, j + 1, r);
}
int main()
{
    int a[9] = {1, -1, 3, 5, 7, 8, 4, 6, 2};
    quick_sort(a, 0, 8);
    for (int i = 0; i < 9; i++)
        cout << a[i] << " ";
    system("pause");
    return 0;
}
