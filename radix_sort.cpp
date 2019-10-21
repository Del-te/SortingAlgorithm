#include <iostream>
using namespace std;
int maxbit(int* a, int len) //辅助函数，求数据的最大位数
{
    int d = 1; //保存最大的位数
    int p = 10;
    for(int i = 0; i < len; ++i)
    {
        while(a[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;
}
void radix_sort(int* a, int len) //基数排序
{
    int d = maxbit(a, len);
    // 用于收集的数组
    int *tmp = new int[len];
    int count[10]; 
    int radix = 1;
    // 进行d次排序
    for(int i = 0; i < d; i++) 
    {
        // 每次分配前清空计数器
        for(int j = 0; j < 10; j++)
            count[j] = 0; 
        // 统计每个数对应的位置的记录数
        for(int j = 0; j < len; j++)
            count[(a[j] / radix) % 10]++;
        // 将tmp中的位置依次分配给每个桶
        for(int j = 1; j < 10; j++)
            count[j] += count[j - 1]; 
        // 将所有桶中记录依次收集到tmp中
        for(int j = len - 1; j >= 0; j--) 
        {
            count[(a[j] / radix) % 10]--;
            tmp[count[(a[j] / radix) % 10]] = a[j];
        }
        // 将临时数组的内容复制到待排序数组中中
        for(int j = 0; j < len; j++) 
            a[j] = tmp[j];
        // 准备进行下一个数位的排序
        radix = radix * 10;
    }
    delete[] tmp;
}
int main()
{
    int a[9] = {1, 11, 30, 500, 701, 81, 4, 6, 2};
    radix_sort(a, 9);
    for (int i = 0; i < 9; i++)
        cout << a[i] << " ";
    system("pause");
    return 0;
}
