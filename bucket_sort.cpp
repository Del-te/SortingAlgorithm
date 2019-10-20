#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucket_sort(int *a, int len)
{
    int min_item = a[0], max_item = a[0];
    for (int i = 0; i < len; i++)
    {
        if (a[i] > max_item)
            max_item = a[i];
        if (a[i] < min_item)
            min_item = a[i];
    }
    // 计算桶的个数
    int n = (max_item - min_item) / 10 + 1;
    // 为了方便，用二维向量做桶
    vector<vector<int>> bucket(n);
    // 把东西丢进对应的桶中
    for (int i = 0; i < len; i++)
        bucket[(a[i] - min_item) / 10].push_back(a[i]);
    // 桶内排序，可使用任意排序算法
    for (int i = 0; i < n; i++)
        sort(bucket[i].begin(), bucket[i].end());
    // 把桶中元素按顺序取出，拷贝回待排序数组
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; bucket[i].size() > 0; j++)
        {
            a[cnt++] = *bucket[i].begin();
            bucket[i].erase(bucket[i].begin());
        }
}

int main()
{
    int a[9] = {10, -11, 60, 20, 80, -93, 91, 71, 41};
    bucket_sort(a, 9);
    for (int i = 0; i < 9; i++)
        cout << a[i] << " ";
    system("pause");
    return 0;
}
