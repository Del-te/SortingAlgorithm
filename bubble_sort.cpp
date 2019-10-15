#include <iostream>
using namespace std;
void bubble_sort(int *a, int len)
{
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - 1 - i; j++)
            if (a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;               
            }
}
int main()
{
    int a[9] = {3, 4, 2, 1, -1, 8, 9, 5, 7};
    bubble_sort(a, 9);
    for (int i = 0; i < 9; i++)
        cout << a[i] << " ";
    system("pause");
    return 0;
}
