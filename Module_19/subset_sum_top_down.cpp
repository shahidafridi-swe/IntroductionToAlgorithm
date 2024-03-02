#include <bits/stdc++.h>
using namespace std;

bool subset_sum(int n, int a[], int sum)
{

    if (n == 0)
    {
        if (sum == 0)
            return true;
        else
            return false;
    }
    if (a[n - 1] <= sum)
    {
        bool op1 = subset_sum(n - 1, a, sum - a[n - 1]);
        bool op2 = subset_sum(n - 1, a, sum);
        return op1 || op2;
    }
    else
    {
        bool op2 = subset_sum(n - 1, a, sum);
        return op2;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum;
    cin >> sum;

    subset_sum(n, a, sum) ? cout << "YES" : cout << "NO";
    return 0;
}