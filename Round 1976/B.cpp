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
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n+1);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<=n; i++)
    {
        cin>>b[i];
    }
    ll ans = 0;
    ll mini = 1e18;
    for(int i=0; i<n; i++)
    {
        ans += abs(a[i] - b[i]);
        ll mn = min(a[i], b[i]);
        ll mx = max(a[i], b[i]);
        if(b.back() >= mn && b.back() <= mx)
        {
            mini = 0;
        }
        mini = min(mini, (ll)abs(b.back()- a[i]));
        mini = min(mini, (ll)abs(b.back()- b[i]));
    }
    ans += mini;
    cout<<ans+1<<"\n";
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
