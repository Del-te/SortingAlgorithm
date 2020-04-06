#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 5;

int a[maxn], t[maxn];

void merge_sort(int l, int r)
{
    if (l >= r)  return;

    int m = (l + r) / 2;

    merge_sort(l, m);
    merge_sort(m + 1, r);

    int i = l, j = m + 1, p = 0;
    while (i <= m && j <= r)
    {
        if (a[i] < a[j])
            t[p++] = a[i++];
        else
            t[p++] = a[j++];
    }

    while (i <= m)  t[p++] = a[i++];
    while (j <= r)  t[p++] = a[j++];
    
    p = 0;
    for (int i = l; i <= r; i++)
        a[i] = t[p++];
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    merge_sort(0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}