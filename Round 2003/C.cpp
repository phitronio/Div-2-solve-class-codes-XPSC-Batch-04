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
    string s;
    cin>>s;
    vector<int>freq(26,0);
    for(int i=0; i<n; i++)
    {
        freq[s[i]-'a']++;
    }

    set<pii>st;
    for(int i=0; i<26; i++)
    {
        if(freq[i])
        {
            st.insert({-freq[i], i});
        }
    }

    string ans;
    while(ans.size() < n)
    {
        pii max_freq_char = {-1,-1};
        for(auto it: st)
        {
            char ch = it.second + 'a';
            if(ans.empty())
            {
                max_freq_char = it;
                break;
            }
            else if(ans.back() != ch)
            {
                max_freq_char = it;
                break;
            }
        }
        if(max_freq_char.second == -1)
        {
            max_freq_char = *st.begin();
        }

        st.erase(max_freq_char);

        ans += max_freq_char.second + 'a';

        max_freq_char.first++;

        if(max_freq_char.first != 0)
            st.insert(max_freq_char);
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
