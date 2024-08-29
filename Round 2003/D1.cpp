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
const int N = 2e5 +5;
typedef pair<int,int> pii;

int n,m;
vector<int>a[N];
vector<int>missing_numbers[N];

vector<int> find_missing_numbers(vector<int>&a)
{
    vector<int>ans;
    set<int>st(a.begin(),a.end());
    for(int i=0 ;; i++)
    {
        if(st.find(i) == st.end())
        {
            ans.push_back(i);
            if(ans.size()==2)
                break;
        }
    }
    return ans;
}

ll sum_from_one_to_n(ll n)
{
    if(n<=0)
        return 0;
    ll sum = (n * (n + 1)) / 2;
    return sum;
}

ll get_sum(ll l, ll r)
{
    if(l > r)
        return 0;
    return sum_from_one_to_n(r) - sum_from_one_to_n(l - 1);
}

void TEST_CASES()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        a[i].clear();
        missing_numbers[i].clear();
    }
    ll maxi = 0;
    for(int i=0; i<n; i++)
    {
        int sz;
        cin>>sz;
        a[i].resize(sz);
        for(int j=0; j<sz; j++)
        {
            cin>>a[i][j];
        }
        missing_numbers[i] = find_missing_numbers(a[i]);
        maxi = max(maxi, (ll)missing_numbers[i].back());
    }
    ll ans = maxi * min((maxi + 1), (ll)m+1) + get_sum(maxi + 1, m);
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
