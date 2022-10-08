#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define mod 100000007

#define  vi         vector<int>
#define  vll        vector<ll>
#define  pb         push_back
#define  pf         push_front
#define  sz(a)      (int)a.size()
#define  pi         acos(-1.0)
#define  cos(a)     cos(a*pi/180)
#define  sin(a)     sin(a*pi/180)
#define  tan(a)     tan(a*pi/180)
#define  cosi(a)    acos(a)/(pi/180)
#define  sini(a)    asin(a)/(pi/180)
#define  tani(a)    atan(a)/(pi/180)
#define  rev(v)     reverse(v.begin(),v.end())
#define  srt(v)     sort(v.begin(),v.end())
#define  pit(x)    fixed<<setprecision(x)
#define  all(v)     v.begin(),v.end()
#define  mem(a,x)   memset(a,x,sizeof(a))

ll Pow(ll c,ll d){return d==0?1:c*pow(c,d-1); }
ll gcd(ll a,ll b) {return b==0? a:gcd(b,a%b);}
ll lcm(ll a,ll b) {return ((a*b)/gcd(a,b));}
ll egcd(ll a,ll b,ll &x,ll &y){if(b==0){x=1;y=0;return a;}ll x1,y1;ll gcd=egcd(b,a%b,x1,y1);x=y1;y=x1-y1*(a/b);return gcd;}
ll bigMod(ll a,ll b){a%=mod;ll res=1;while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
bool isPowerOfTwo(ll n) { return n > 0 && !(n&(n-1)); }
 
inline ll MOD(ll a){ return (a%mod + mod) %mod ; }
inline ll modAdd(ll a,ll b){ return MOD( MOD(a) + MOD(b) ) ; }
inline ll modSub(ll a,ll b){ return MOD( MOD(a) - MOD(b) ) ; }
inline ll modMul(ll a,ll b){ return MOD( MOD(a) * MOD(b) ) ; }
inline ll modInv(ll a){ return bigMod(a,mod-2) ; }
inline ll modDiv(ll a,ll b){ return modMul( a, modInv(b) ); }



template<typename V, typename T>
struct sparseTable {
    static int highest_bit(unsigned x) {return x == 0 ? -1 : 31 - __builtin_clz(x);}
    int n, level;
    vector<vector<T>> st;
    T f(T a, T b) {
       // change here as required
        return min(a,b);
    }

    void build(const vector<V> &v = {}) {
        for (int i = 0; i < sz(v); i++) st[0][i]=v[i];
        for (int p = 1; p <= level; p++) {
            for (int i = 0; i + (1 << p) <= n; i++) {
                st[p][i] = f(st[p - 1][i], st[p - 1][i + (1 << (p - 1))]);
            }
        }
    }
    sparseTable(const vector<V> &v): n((int)v.size()), level(highest_bit(n)) {
        st.resize(level + 1, vector<T> (n));
        build(v);
    }
    T qryN(int l, int r) {
        T ans=INT_MAX;
        for (int i = level; i >= 0; i--) {
            if ((1 << i) <= r - l + 1) {
                ans = f(ans, st[i][l]);
                l += (1 << i);
            }
        }
        return ans;
    }
};
 


int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> ar(n);
    for (int  i = 0; i <n; i++)
    {
        cin>>ar[i];
    }
    sparseTable <int,int>st(ar);
    while (q--)
    {
        int l,r;
        cin>>l>>r;
        l--,r--;
        cout<<st.qryN(l,r)<<endl;
    }
    

    
    
  
}
