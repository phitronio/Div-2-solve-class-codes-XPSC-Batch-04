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

// returns the index r such that sum from index start to index r is >= need
int go(vector<int>&a, int start, ll need)
{
    int r = start;
    ll cur_sum = 0;
    while(r < a.size())
    {
        cur_sum += a[r];
        if(cur_sum >= need)
            break;
        r++;
    }
    return r;
}

void TEST_CASES()
{
    int n;
    cin>>n;
    vector<int>a[3];
    for(int i=0;i<3;i++)
    {
        a[i].resize(n);
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }

    ll tot = accumulate(a[0].begin(), a[0].end(), 0ll);
    ll need = (tot + 2) / 3;

    vector<int>order = {0,1,2};

    do{
        // 0 1 2
        int first = order[0]; // 0
        int second = order[1]; // 1
        int third = order[2]; // 2

        int r1 = go(a[first], 0, need); // 0
        int r2 = go(a[second], r1+1, need); // 2
        int r3 = go(a[third], r2+1, need); // 4

        if(r3 >= n)
            continue;

        // finally sort the ans because we want to output alice at first, then bob, then charlie
        vector<array<int,3>>ans = { {first, 0, r1}, {second, r1+1, r2}, {third, r2+1, r3} };
        sort(ans.begin(),ans.end());

        for(int i=0;i<3;i++)
        {
            cout<<ans[i][1]+1<<" "<<ans[i][2]+1<<" ";
        }
        cout<<"\n";
        return;
    }while(next_permutation(order.begin(),order.end()));

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
