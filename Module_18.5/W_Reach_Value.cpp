#include <bits/stdc++.h>
using namespace std;

bool fun(long long N, long long val)
{
    if (val == N)
        return true;
    if (val > N)
        return false;
  
    return fun(N, val * 10) or fun(N, val * 20);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long N;
        cin >> N;

        fun(N, 1) ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}