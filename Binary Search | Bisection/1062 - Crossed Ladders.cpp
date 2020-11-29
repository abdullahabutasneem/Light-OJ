#include<bits/stdc++.h>
using namespace std;
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
 
double lombo(double base, double oti)
{
    double lom = sqrt((oti*oti) - (base*base));
    return lom;
}
 
double ok(double base, double x, double y, double c)
{
    double rh,lh;
    pair<double, double>A,B,C,D;
    A = {0.0, 0.0};
    lh = lombo(base,x);
    B = {0.0, lh};
    C = {base, 0.0};
    rh = lombo(base,y);
    D = {base,rh};
    //cout<<lh<<" "<<rh<<endl;
    double height = (lh*rh)/(lh+rh);
    //cout<<a1<<" "<<b1<<" "<<c1<<endl;
    //cout<<a2<<" "<<b2<<" "<<c2<<endl;
    return height;
}
 
int main()
{
    IOS;
    int t;scanf("%d",&t);
    fof(tt,1,t)
    {
        double x,y,c;
        sf(x);
        sf(y);
        sf(c);
 
        double mx = max(x,y);
        double lo=0.0, hi=mx,ans=0.0;
        int hh=100;
        while(hh--)
        {
            double mid = (lo+hi)/2;
            //cout<<"mid = "<<mid<<endl;
            double k = ok(mid,x,y,c);
            //cout<<"k= "<<k<<endl;
            if(k>c){
                lo = mid;
            }
            else{
                hi = mid;
            }
        }
        printf("Case %d: %0.10lf\n",tt,lo);
 
    }
    return 0;
}
 
///Alhamdulillah
