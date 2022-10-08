#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mod 100000007
#define sz(a) (int)a.size()

template <typename V, typename T>
struct sparseTable
{
    static int highest_bit(unsigned x) { return x == 0 ? -1 : 31 - __builtin_clz(x); }
    int n, level;
    vector<vector<T>> st;
    T f(T a, T b)
    {
        // change here as required
        return min(a, b);
    }

    void build(const vector<V> &v = {})
    {
        for (int i = 0; i < sz(v); i++)
            st[0][i] = v[i];
        for (int p = 1; p <= level; p++)
        {
            for (int i = 0; i + (1 << p) <= n; i++)
            {
                st[p][i] = f(st[p - 1][i], st[p - 1][i + (1 << (p - 1))]);
            }
        }
    }
    sparseTable(const vector<V> &v) : n((int)v.size()), level(highest_bit(n))
    {
        st.resize(level + 1, vector<T>(n));
        build(v);
    }
    T qryN(int l, int r)
    {
        T ans = INT_MAX;
        for (int i = level; i >= 0; i--)
        {
            if ((1 << i) <= r - l + 1)
            {
                ans = f(ans, st[i][l]);
                l += (1 << i);
            }
        }
        return ans;
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    sparseTable<int, int> st(ar);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << st.qryN(l, r) << endl;
    }
}
