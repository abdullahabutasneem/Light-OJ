//Bismillahir Rahmanir Rahim
/*
    Abdullah Abu Tasneem
    Dept of CSTE, NSTU
*/

#include<bits/stdc++.h>
//for pbds
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
//template <typename T>using ordered_set =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
typedef unsigned long long lll;
typedef long long ll;
#define all(x) x.begin(),x.end()
const long long MOD = 1000000007;
#define fil(x) memset(x, 0, sizeof(x))
#define fillb(x) memset(x,false,sizeof(x))
#define fillm(x) memset(x, -1, sizeof(x))
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int,int>>
#define vpl vector<pair<ll,ll>>
#define pf printf
#define sf(x) scanf("%d",&x);
#define sff(x,y) scanf("%d%d",&x,&y);
#define sfff(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define sfl(x) scanf("%lld",&x);
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
#define cases(t) printf("Case %d:",t)
#define PI acos(-1)
#define uniq(vec) vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))

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
void file()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
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

#define N 10005
vector<pii>forwrd[N],backwrd[N];
bool vis[N];
int dis_src[N],dis_des[N];

void clr(int n)
{
	fo(i,n){
		forwrd[i].clear();
		backwrd[i].clear();
		dis_src[i]=1e9;
		dis_des[i]=1e9;
	}
}

void dijkstra1(int s)
{
	dis_src[s]=0;
	multiset<pii>mul;
	mul.insert({0,s});
	while(!mul.empty())
	{
		pii frnt = *mul.begin();
		mul.erase(mul.begin());
		int x = frnt.second;
		//cout<<"distance = "<<dis_src[x]<<endl;
		//cout<<forwrd[x].size()<<endl;
		fo(i,forwrd[x].size()){
			int nd = forwrd[x][i].first;
			int cost = forwrd[x][i].second;
			if(dis_src[x]+cost < dis_src[nd]){
				dis_src[nd] = dis_src[x]+cost;
				//cout<<"dis = "<<dis_src[nd]<<endl;
				mul.insert({dis_src[nd],nd});
			}
		}
	}
}

void dijkstra2(int s)
{
	dis_des[s]=0;
	multiset<pii>mul;
	mul.insert({0,s});
	while(!mul.empty())
	{
		pii frnt = *mul.begin();
		mul.erase(mul.begin());
		int x = frnt.second;
		int w = frnt.first;
		fo(i,backwrd[x].size()){
			int nd = backwrd[x][i].first;
			int cost = backwrd[x][i].second;
			if(dis_des[x]+cost < dis_des[nd]){
				dis_des[nd] = dis_des[x]+cost;
				mul.insert({dis_des[nd],nd});
			}
		}
	}
}

int main()
{
    file();
    IOS;
    int t;sf(t);
    fof(tc,1,t)
    {
        int n,m,src,des,p;
        sff(n,m);
        sfff(src,des,p);
        clr(n+5);
        while(m--)
        {
        	int u,v,w;
        	sfff(u,v,w);
        	forwrd[u].pb({v,w});
        	backwrd[v].pb({u,w});
        }
        
        dijkstra1(src);
        dijkstra2(des);
        int ans=-1;
        fof(node,1,n)
        {
        	fo(j,forwrd[node].size())
        	{
        		int v = forwrd[node][j].first;
        		int cost = forwrd[node][j].second;
        		int a = dis_src[node];
        		int b = dis_des[v];
        		int tot_cost = a+b+cost;
        		if(tot_cost<=p){
        			ans = max(ans,cost);
        		}
        	}
        }
        if(ans==1e9)ans=-1;
        pf("Case %d: %d\n",tc,ans);
    }
    return 0;
}

///Alhamdulillah
