#include <iostream>
using namespace std;

void shell_sort(int* a, int len)
{
    int h = 1;
    while (h < (len / 3))
        h = 3 * h + 1;
    while (h >= 1)
    {
        // 第h个元素之前都是每小组的第一个元素，只能被插
        for (int i = h; i < len; i++)
            // 每次j -= h使每小组之间进行插排 
            for (int j = i; j >= h && a[j] < a[j - h]; j -= h)
            {
                int t = a[j];
                a[j] = a[j - h];
                a[j - h] = t;
            }       
        h = h / 3;
    }
}
int main()
{
    int a[9] = {1,-1,6,2,8,9,9,7,4};
    shell_sort(a, 9);
    for (int i = 0; i < 9; i++)
        cout << a[i] << " ";
    system("pause");
    return 0;
}
