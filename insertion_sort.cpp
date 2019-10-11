#include <iostream>
using namespace std;
void insertion_sort(int *a, int len)
{
    for (int i = 1; i < len; i++)
        for (int j = i; j > 0 && a[j] < a[j - 1]; j--)
        {
            int t = a[j];
            a[j] = a[j - 1];
            a[j - 1] = t;
        }
}

int main()
{
    int a[9] = {1,-1,6,2,8,9,9,7,4};
    insertion_sort(a, 9);
    for (int i = 0; i < 9; i++)
        cout << a[i] << " ";
    system("pause");
    return 0;
}
