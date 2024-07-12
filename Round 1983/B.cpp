#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#ifdef APURBA
#include "DEBUG_TEMPLATE.h"
#else
#define HERE
#define debug(args...)
#endif
typedef pair<int,int> pii;

void TEST_CASES()
{
    int n,m;
    cin>>n>>m;
    vector<string>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<string>b(n);
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    vector<vector<int>>c(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            c[i][j] = (a[i][j] - b[i][j] + 3) % 3;
        }
    }

    // sum % 3 for each row must be 0
    for(int i=0;i<n;i++)
    {
        if(accumulate(c[i].begin(),c[i].end(),0) % 3 != 0)
        {
            cout<<"NO\n";
            return;
        }
    }

    // sum % 3 for each column must be 0
    for(int i=0;i<m;i++)
    {
        int sum = 0;
        for(int j=0;j<n;j++)
        {
            sum += c[j][i];
        }
        sum %= 3;
        if(sum != 0)
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int32_t main()
{
#ifndef APURBA
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int t=1;
    cin>>t;
    while(t--)
    {
        TEST_CASES();
    }
    return 0;
}
