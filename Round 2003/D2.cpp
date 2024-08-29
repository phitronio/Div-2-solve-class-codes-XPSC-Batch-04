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
    for(int i=0;; i++)
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

vector<int>adj[N];
int out[N];
int to_go[N];
bool vis[N];

void dfs(int s, set<int>&visited_numbers, bool &two_or_greater_out_degree)
{
    if(out[s] >= 2)
    {
        two_or_greater_out_degree = true;
    }
    visited_numbers.insert(s);
    vis[s] = 1;
    for(auto it:adj[s])
    {
        if(!vis[it])
        {
            dfs(it, visited_numbers, two_or_greater_out_degree);
        }
    }
}

void TEST_CASES()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        a[i].clear();
        missing_numbers[i].clear();
    }

    int maxi = 0;
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
        maxi = max(maxi, missing_numbers[i].back());
    }

    for(int i=0;i<=maxi;i++)
    {
        adj[i].clear();
        to_go[i] = -1;
        vis[i] = 0;
        out[i] = 0;
    }

    for(int i=0;i<n;i++)
    {
        adj[missing_numbers[i][0]].push_back(missing_numbers[i][1]);
        adj[missing_numbers[i][1]].push_back(missing_numbers[i][0]);
        out[missing_numbers[i][0]]++;
    }

    ll ans = get_sum(maxi + 1, m);

    int baki_ans = -1;

    for(int i=0;i<=maxi;i++)
    {
        if(vis[i] || adj[i].empty())
            continue;

        set<int>visited_numbers;
        bool two_or_greater_out_degree = false;

        dfs(i, visited_numbers, two_or_greater_out_degree);

        if(two_or_greater_out_degree)
        {
            int last = *(--visited_numbers.end());
            baki_ans = max(baki_ans, last);
        }
        else{
            int second_last = *(--(--visited_numbers.end()));
            baki_ans = max(baki_ans, second_last);
        }

        for(auto it:visited_numbers)
        {
            int last = *(--visited_numbers.end());
            to_go[it] = last;
        }
    }

    for(int i=0;i<=min(maxi,m);i++)
    {
        ans += max({to_go[i], baki_ans, i});
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
