#include <iostream>
using namespace std;

void selection_sort(int *a, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < len; j++)
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        int t = a[i];
        a[i] = a[min_index];
        a[min_index] = t;
    }
}

int main()
{
    int a[9] = {1, -1, 3, 5, 7, 8, 4, 6, 2};
    selection_sort(a, 9);
    for (int i = 0; i < 9; i++)
        cout << a[i] << " ";
    system("pause");
    return 0;
}
