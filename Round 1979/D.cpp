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

const int MAX = 1e5 + 5;
int mods[2] = {1000000007, 1000000009};
int bases[2] = {137, 281};
int pwbase[2][MAX];

void Preprocess()
{
    pwbase[0][0] = pwbase[1][0] = 1;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 1; j < MAX; j++)
        {
            pwbase[i][j] = (pwbase[i][j - 1] * 1ll * bases[i]) % mods[i];
        }
    }
}

struct Hashing
{
    vector<int> hsh[2];
    string str;

    Hashing() {}
    Hashing(string _str)
    {
        hsh[0].resize(_str.size()+1);
        hsh[1].resize(_str.size()+1);
        str = _str;
        hsh[0][str.size()] = 0;
        hsh[1][str.size()] = 0;
        Build();
    }

    void Build()
    {
        for(int i = str.size() - 1; i >= 0; i--)
        {
            for(int j = 0; j < 2; j++)
            {
                hsh[j][i] = ((hsh[j][i + 1] *1ll* bases[j] % mods[j]) + str[i]) % mods[j];
                hsh[j][i] = (hsh[j][i] + mods[j]) % mods[j];
            }
        }
    }

    pair<int,int> GetHash(int i, int j)
    {
        if(i>j)
            return make_pair(0,0);
        int tmp1 = (hsh[0][i] - (hsh[0][j + 1] *1ll* pwbase[0][j - i + 1]) % mods[0]) % mods[0];
        int tmp2 = (hsh[1][i] - (hsh[1][j + 1] *1ll* pwbase[1][j - i + 1]) % mods[1]) % mods[1];
        if(tmp1 < 0)
            tmp1 += mods[0];
        if(tmp2 < 0)
            tmp2 += mods[1];
        return make_pair(tmp1, tmp2);
    }
};
int n,k;

pair<int,int> DoOp(int p, Hashing &h, Hashing &h_rev)
{
    pii x1 = h.GetHash(p, n-1);
    pii x2 = h_rev.GetHash(n-p, n-1); // 0 .. p-1 // n-p .. 0

    x2.first = (x2.first *1ll* pwbase[0][n-p]) % mods[0];
    x2.second = (x2.second *1ll* pwbase[1][n-p]) % mods[1];

    x1.first = (x1.first + x2.first) % mods[0];
    x1.second = (x1.second + x2.second) % mods[1];

    return x1;
}

void TEST_CASES()
{
    cin>>n>>k;
    string s;
    cin>>s;

    string k_proper_starts_with_zero;
    string k_proper_starts_with_one;

    for(int i=0; i<k; i++)
    {
        k_proper_starts_with_zero += "0";
        k_proper_starts_with_one += "1";
    }

    for(int i=k; i<n; i++)
    {
        k_proper_starts_with_zero += ((k_proper_starts_with_zero[i-k] - '0')^1) + '0';
        k_proper_starts_with_one += ((k_proper_starts_with_one[i-k] - '0')^1) + '0';
    }

    string s_rev = s;
    reverse(s_rev.begin(),s_rev.end());

    Hashing h1(s),h2(k_proper_starts_with_zero),h3(k_proper_starts_with_one);

    Hashing h1_rev(s_rev);

    pii hash_k_proper_zero = h2.GetHash(0,n-1);
    pii hash_k_proper_one = h3.GetHash(0,n-1);

    for(int p=1; p<=n; p++)
    {
        pii new_hash = DoOp(p, h1, h1_rev);
        if(new_hash == hash_k_proper_zero || new_hash == hash_k_proper_one)
        {
            cout<<p<<"\n";
            return;
        }
    }
    cout<<"-1\n";
}

int32_t main()
{
#ifndef APURBA
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    Preprocess();
    int t=1;
    cin>>t;
    while(t--)
    {
        TEST_CASES();
    }
    return 0;
}
