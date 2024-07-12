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
// for pbds
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int >,rb_tree_tag,tree_order_statistics_node_update>indexed_set;

ll inv_count(vector<int>&a)
{
    indexed_set st;
    ll inv = 0;
    for(int i=0;i<a.size();i++)
    {
        // how many values greater than a[i]
        int id = st.order_of_key(a[i] + 1);
        inv += st.size() - id;

        st.insert(a[i]);
    }
    return inv;
}

void TEST_CASES()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int>b(n);
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    set<int>st1(a.begin(), a.end());
    set<int>st2(b.begin(), b.end());

    if(st1 != st2)
    {
        cout<<"NO\n";
        return;
    }

    if(inv_count(a)%2 != inv_count(b)%2)
    {
        cout<<"NO\n";
        return;
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
