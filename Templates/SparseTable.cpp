//buid
const int K=25
int st[MAXN][K + 1];
void build(vector<int>&a)
{
    for (int i = 0; i < N; i++)
        st[i][0] = a[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = st[i][j-1] + st[i + (1 << (j - 1))][j - 1];
}

//query O(logn)
int query(int L, int R)
{
    int sum = 0;
    for (int j = K; j >= 0; j--)
    {
        if ((1 << j) <= R - L + 1)
        {
            sum += st[L][j];
            L += 1 << j;
        }
    }
    return sum;
}

//RMQ O(1) query
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


void build(vector<int>&a)
{
    int N = a.size();
    for (int i = 0; i < N; i++)
        st[i][0] = a[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}

int query(int L, int R)
{

    int j = logg[R - L + 1];
    int maxi = max(st[L][j], st[R - (1 << j) + 1][j]);
    return maxi;
}

