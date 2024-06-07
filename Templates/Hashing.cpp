// Double Hashing
const int MAX = 1e6 + 5;
int mods[2] = {1000000007, 1000000009};
int bases[2] = {137, 281};
int pwbase[2][MAX];

void Preprocess() // Call me
{
    pwbase[0][0] = pwbase[1][0] = 1;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 1; j < MAX; j++)
        {
            pwbase[i][j] = (pwbase[i][j - 1] *1ll* bases[i]) % mods[i];
        }
    }
}

struct Hashing
{
    int hsh[2][MAX];
    string str;

    Hashing() {}
    Hashing(string _str)
    {
        str = _str;
        hsh[0][str.size()] = 0;
        hsh[1][str.size()] = 0;
        Build();
    }
    void setstr(string &_str)
    {
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
        assert(i <= j);
        int tmp1 = (hsh[0][i] - (hsh[0][j + 1] *1ll* pwbase[0][j - i + 1]) % mods[0]) % mods[0];
        int tmp2 = (hsh[1][i] - (hsh[1][j + 1] *1ll* pwbase[1][j - i + 1]) % mods[1]) % mods[1];
        if(tmp1 < 0)
            tmp1 += mods[0];
        if(tmp2 < 0)
            tmp2 += mods[1];
        return make_pair(tmp1, tmp2);
    }
};
