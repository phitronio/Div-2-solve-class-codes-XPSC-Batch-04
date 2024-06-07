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
    int x,y;
    cin>>x>>y;
    int z = x^y;

    // To print the seq
//    debug(z);
//    for(int i=0;i<100;i++)
//    {
//        cout<<(i^z)<<" ";
//    }
//    cout<<"\n";

    int zero = 0;
    for(int i=0;i<31;i++)
    {
        if(z&(1<<i))
            break;
        zero++;
    }
    cout<<(1<<zero)<<"\n";
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
