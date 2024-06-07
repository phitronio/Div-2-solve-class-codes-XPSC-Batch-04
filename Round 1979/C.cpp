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
const int LCM = 232792560;

void TEST_CASES()
{
    int n;
    cin>>n;
    vector<int>k(n);
    vector<int>x(n);
    for(int i=0; i<n; i++)
    {
        cin>>k[i];
        x[i] = LCM/k[i];
    }

    ll sum = accumulate(x.begin(),x.end(),0ll);
    if((ll)LCM > sum)
    {
        for(int i=0; i<n; i++)
        {
            cout<<x[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    cout<<"-1\n";
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
