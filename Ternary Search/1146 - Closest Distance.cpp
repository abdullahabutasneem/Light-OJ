#include<bits/stdc++.h>
//for pbds
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
//template <typename T>using ordered_set =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
 
const long long MOD = 1000000007;
#define fil(x) memset(x, 0, sizeof(x))
#define fillb(x) memset(x,false,sizeof(x))
#define fillm(x) memset(x, -1, sizeof(x))
#define mp make_pair
#define pll pair<int, int>
#define pf printf
#define sf(x) scanf("%lf",&x)
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
#define pi pair<double,double>
 
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
template<typename T>inline T Bigmod(T base, T power, T MOD){
    T ret=1;
    while(power)
    {
        if(power & 1)ret=(ret*base)%MOD;
        base=(base*base)%MOD;
        power>>=1;
    }
    return ret;
}
 
pi v[4];
#define eps 0.000000001
double dis(pi a, pi b)
{
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}
 
int main()
{
    //IOS;
    int t;scanf("%d",&t);
    fof(tt,1,t)
    {
        fo(i,4){
            sf(v[i].first);
            sf(v[i].second);
        }
        double ac = dis(v[0],v[2]);
        double bd = dis(v[1],v[3]);
        while(abs(ac-bd)>eps)
        {
            pi a,b,c,d;
            a.first = (2*v[0].first+v[1].first)/3.0;
            a.second = (2*v[0].second+v[1].second)/3.0;
            b.first = (v[0].first+2*v[1].first)/3.0;
            b.second = (v[0].second+2*v[1].second)/3.0;
 
            c.first=(2*v[2].first+v[3].first)/3.0;
            c.second=(2*v[2].second+v[3].second)/3.0;
            d.first=(v[2].first+2*v[3].first)/3.0;
            d.second=(v[2].second+2*v[3].second)/3.0;
 
            ac = dis(a,c);
            bd = dis(b,d);
 
            if(ac>bd){
                v[0] = a;
                v[2] = c;
            }
            else{
                v[1] = b;
                v[3] = d;
            }
        }
        printf("Case %d: %0.8lf\n",tt,(ac+bd)/2.0);
    }
    return 0;
}
 
///Alhamdulillah
