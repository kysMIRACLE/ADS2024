#include <iostream>
#include <vector>
using namespace std;

long long MOD = 9007199254740881;
long long X = 31;

long long getHash(string s)
{
    long long hash = 0;
    long long curX = 1;
    for (long long i = 0; i < s.size(); i++)
    {
        long long curHash = (s[i] - 'a' + 1) * curX % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X) % MOD;
    }
    return hash;
}

vector<long long> getPrefixHashes(string s)
{
    vector<long long> hashes(s.size());
    long long curX = 1;
    for (long long i = 0; i < s.size(); i++)
    {
        hashes[i] = (s[i] - 'a' + 1) * curX % MOD;
        if (i != 0)
        {
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        curX = (curX * X) % MOD;
    }
    return hashes;
}
// long long rabinKarp(string s, string t)
// {
//     long long smallHash = getHash(t);
//     long long res = 0;
//     vector<long long> hashes = getPrefixHashes(s);
//     for (long long i = 0; i < s.size() - t.size() + 1; i++)
//     {
//         long long hashDif = hashes[i + t.size() - 1];
//         if (i != 0)
//             hashDif -= hashes[i - 1];
//         if (hashDif < 0)
//             hashDif += MOD;
//         if (i != 0)
//             smallHash = (smallHash * X) % MOD;
//         if (smallHash == hashDif)
//         {
//             res++;
//         };
//     }
//     return res;
// }
long long rabinKarp_vector_new(vector<long long> hashes, string t, string s)
{
    long long smallHash = getHash(t);
    long long res = 0;
    for (long long i = 0; i < s.size() - t.size() + 1; i++)
    {
        long long hashDif = hashes[i + t.size() - 1];
        if (i != 0)
            hashDif -= hashes[i - 1];
        if (hashDif < 0)
            hashDif += MOD;
        if (i != 0)
            smallHash = (smallHash * X) % MOD;
        if (smallHash == hashDif)
        {
            res++;
        };
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    string to_check = "";
    long long n, ans;
    cin >> n;
    vector<long long> hashes = getPrefixHashes(s);
    for (long long i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        for (long long j = x - 1; j <= y - 1; j++)
            to_check += s[j];
        ans = rabinKarp_vector_new(hashes, to_check, s);
        cout << ans << endl;
        to_check.clear();
    }
}