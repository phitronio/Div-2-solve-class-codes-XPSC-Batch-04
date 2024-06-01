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

const int K=25;
const int MAXN = 2e5+5;
int st[MAXN][K + 1];
int logg[MAXN+1];
void initLog()
{
    logg[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        logg[i] = logg[i/2] + 1;
}

void build(vector<int>&a) //O(nlogn)
{
    int N = a.size();
    for (int i = 0; i < N; i++)
        st[i][0] = a[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}

int query(int L, int R) //O(1)
{
    int j = logg[R - L + 1];
    int maxi = max(st[L][j], st[R - (1 << j) + 1][j]);
    return maxi;
}

void TEST_CASES()
{
    string s;
    cin>>s;
    int n = s.size();
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)
    {
        a[i] = a[i-1] + (s[i-1]=='('? 1: -1);
    }
    build(a);
    ll ans = 0;
    map<int,deque<int>>mp;
    for(int i=0;i<=n;i++)
    {
        deque<int>&now = mp[a[i]];
        while(now.size())
        {
            int pos = now[0];
            int maxi = query(pos, i);
            if(a[i] - (maxi - a[i]) < 0)
                now.pop_front();
            else
                break;
        }
        ans += now.size();
        mp[a[i]].push_back(i);
    }
    cout<<ans<<"\n";
}

int32_t main()
{
#ifndef APURBA
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    initLog();
    int t=1;
    cin>>t;
    while(t--)
    {
        TEST_CASES();
    }
    return 0;
}
