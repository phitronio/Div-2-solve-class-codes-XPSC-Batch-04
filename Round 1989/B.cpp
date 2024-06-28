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
    string a,b;
    cin>>a>>b;
    int ans = a.size() + b.size();

    for(int start=0;start<b.size();start++)
    {
        int p2 = start;
        for(int p1=0;p1<a.size() && p2<b.size();p1++)
        {
            if(a[p1] == b[p2])
            {
                p2++;
            }
        }
        int need =  a.size() + b.size() - (p2 - start);
        ans = min(ans, need);
    }
    cout<<ans<<"\n";
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
