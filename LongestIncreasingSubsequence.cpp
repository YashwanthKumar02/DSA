#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int a[N];
int dp[N];

int func(int i)
{
    // int ans = 1;
    // for (int j = 0; j < i; j++)
    // {
    //     if (a[j] < a[i])
    //     {
    //         ans = max(ans, func(j) + 1);
    //     }
    // }
    // return ans; // time complexity is O(2^i) because of recursion and it occurs for another i times because of for loop so effective T.C is O(2^i*i)
    int ans = 1;
    if(dp[i]!=-1) return dp[i];
    for (int j = 0; j < i; j++)
    {
        if (a[j] < a[i])
        {
            ans = max(ans, func(j) + 1);
        }
    }
    return dp[i]=ans;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max_len = 1;
    for (int i = 0; i < n; i++)
    {
        max_len = max(max_len, func(i));
    }
    cout << max_len;
}