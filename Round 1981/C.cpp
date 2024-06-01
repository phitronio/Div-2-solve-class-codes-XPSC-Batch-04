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

vector<int> go_up(int x)
{
    int tmp_x = x;
    vector<int>par;
    while(tmp_x != 0)
    {
        par.push_back(tmp_x);
        tmp_x/=2;
    }
    return par;
}

vector<int> get_path(int x, int y) // O(log(max(x,y)))
{
    vector<int>a = go_up(x);
    vector<int>b = go_up(y);
    int lca = -1;
    while(a.size() && b.size() && a.back() == b.back())
    {
        lca = a.back();
        a.pop_back();
        b.pop_back();
    }
    vector<int>path;
    for(int i:a)
        path.push_back(i);
    path.push_back(lca);

    reverse(b.begin(),b.end());
    for(int i:b)
        path.push_back(i);
    return path;
}

void TEST_CASES()
{
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>idx;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]!=-1)
            idx.push_back(i);
    }

    vector<int>ans = a;

    if(idx.empty())
    {
        for(int i=0; i<n; i++)
        {
            ans[i] = i%2+1;
        }
    }
    else
    {
        for(int i=1; i<idx.size(); i++)
        {
            int l = idx[i-1];
            int r = idx[i];
            int x = a[l];
            int y = a[r];

            vector<int>path = get_path(x,y);
            int sz = path.size();
            if(sz > r-l+1 || sz%2 != (r-l+1)%2)
            {
                cout<<"-1\n";
                return;
            }

            for(int j=l;j<=r;j++)
            {
                if(j-l < path.size()){
                    ans[j] = path[j-l];
                }
                else{
                    if(ans[j-1] == y*2)
                        ans[j] = y;
                    else
                        ans[j] = y*2;
                }
            }
        }
        for(int i=idx[0]-1;i>=0;i--)
        {
            if(ans[i+1] == a[idx[0]] * 2)
                ans[i] = a[idx[0]];
            else
                ans[i] = a[idx[0]] * 2;
        }
        for(int i=idx.back()+1;i<n;i++)
        {
            if(ans[i-1]==a[idx.back()] * 2)
                ans[i] = a[idx.back()];
            else
                ans[i] = a[idx.back()] * 2;
        }
    }
    for(int i:ans)
        cout<<i<<" ";
    cout<<"\n";
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
