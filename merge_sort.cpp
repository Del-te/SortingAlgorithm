#include <iostream>
using namespace std;
void merge(int *a, int l, int mid, int r)
{
    int t[r], i = l, j = mid + 1;
    for (int k = l; k <= r; k++)
        t[k] = a[k];
    for (int k = l; k <= r; k++)
    {
        if (i > mid)
            a[k] = t[j++];
        else if (j > r)
            a[k] = t[i++];
        else if (a[i] < a[j])
            a[k] = t[i++];
        else
            a[k] = t[j++];
    }
}
void merge_sort(int *a, int l, int r)
{
    if (r <= l)
        return;
    int mid = l + (r - l) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    merge(a, l, mid, r);
}
int main()
{
    int a[9] = {1, -1, 6, 2, 8, 9, 9, 7, 4};
    merge_sort(a, 0, 8);
    for (int i = 0; i < 9; i++)
        cout << a[i] << " ";
    system("pause");
    return 0;
}
