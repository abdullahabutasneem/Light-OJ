#include<bits/stdc++.h>
//for pbds
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
//template <typename T>using ordered_set =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
 
const long long MOD = 100000007;
#define fil(x) memset(x, 0, sizeof(x))
#define fillb(x) memset(x,false,sizeof(x))
#define fillm(x) memset(x, -1, sizeof(x))
#define mp make_pair
#define pll pair<int, int>
#define pf printf
#define sf(x) scanf("%lld",&x)
#define all(x) x.begin(),x.end()
#define pb push_back
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define np std::string::npos
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<n;i++)
#define fof(i,a,b) for(int i=a;i<=b;i++)
#define off(i,a,b) for(int i=a;i>=b;i--)
#define of(i,n) for(int i=n-1;i>=0;i--)
#define stl(i,x) for(auto i=x.begin(); i!=x.end();i++)
#define highest(x) numeric_limits<x>::max()
#define lowest(x) numeric_limits<x>::min()
#define Inf INFINITY
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define cases(cs,t) for(int cs=1;cs<=t;cs++)
#define PI acos(-1)
#define nl endl
 
typedef unsigned long long lll;
typedef long long ll;
int knigtx8[] = {2, 2, -2, -2, 1, 1, -1, -1}; ///knight move in chess
int knigty8[] = {1, -1, 1, -1, 2, -2, 2, -2}; ///knight move in chess
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; ///for 8 directions
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1}; ///for 8 directions
int dx4[] = {0, 0, 1, -1}; ///for 4 directions
int dy4[] = {1, -1, 0, 0}; ///for 4 directions
const int maxx=100005;
 
//this fuction sorts vector pair according to first element in descending order.
bool sortinrev(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.first>b.first;
}
ll pw(ll a, ll b)
{
    ll ans = 1;
    for(ll i = 1; i <= b; ++i)
        ans = (ans * a);
    return ans;
}
ll bigmod(ll p, ll q){
    if(q == 1) return p%MOD;
    if(q%2 == 0){
        ll a = bigmod(p, q/2)%MOD;
        return ((a%MOD)*(a%MOD))%MOD;
    }
    else{
        ll a = bigmod(p, q-1);return (a*p)%MOD;
    }
}
 
ll numbers[1000006];
int c=0;
void perfect_power()
{
    for(ll i=2;i<=100000;i++)
    {
        ll num = i*i;
        while(num<=10000000000)
        {
            numbers[c++]=num;
            num*=i;
        }
    }
    sort(numbers,numbers+c);
    c = unique(numbers,numbers+c)-numbers;
    numbers[c++] = 1000000000000000;
}
 
ll fact[1000006];
 
void factorial()
{
    fact[0]=1;
    fof(i,1,1000005)
    {
        fact[i] = (fact[i-1]*i)%MOD;
    }
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    perfect_power();
    factorial();
    ll t;sf(t);
    fof(tt,1,t)
    {
       ll a,b;
       sf(a);
       sf(b);
 
       ll r=upper_bound(numbers,numbers+c,b)-numbers;
       ll l=lower_bound(numbers,numbers+c,a)-numbers;
       ll n=(r-l);
       
        if(n==0)
            printf("Case %d: 0\n",tt);
        else
        {
            ll ans=(fact[n+1]*fact[n])%MOD;
            ans=bigmod(ans,MOD-2);
            ans=(fact[2*n]*ans)%MOD;
            printf("Case %d: %lld\n",tt,ans);
        }
    }
    return 0;
}
 
///Alhamdulillah
