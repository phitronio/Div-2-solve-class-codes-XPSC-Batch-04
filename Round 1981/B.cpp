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

int get_or(int l, int r)
{
    int ans = 0;
    for(int i=31; i>=0; i--)
    {
        int b1 = ((l&(1<<i))? 1:0);
        int b2 = ((r&(1<<i))? 1:0);
        if(!b1 && !b2)
            continue;
        if(b1 && b2)
            ans += (1<<i);
        else
        {
            for(int j=0; j<=i; j++)
                ans += (1<<j);
            break;
        }
    }
    return ans;
}

void TEST_CASES()
{
    int n,m;
    cin>>n>>m;
    int l = max(0, n-m);
    int r = n+m;
    cout<<get_or(l,r)<<"\n";
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
