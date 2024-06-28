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
    vector<int>b(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    int x = 0;
    int y = 0;
    // unequal
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            if(a[i] > b[i])
                x += a[i];
            else
                y += b[i];
        }
    }
    // both 1
    for(int i=0;i<n;i++)
    {
        if(a[i]==1 && b[i]==1)
        {
            if(x<y)
                x++;
            else
                y++;
        }
    }
    // both -1
    for(int i=0;i<n;i++)
    {
        if(a[i]==-1 && b[i]==-1)
        {
            if(x<y)
                y--;
            else
                x--;
        }
    }
    cout<<min(x,y)<<"\n";
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
