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

#define N 510
#define dist first
#define node second
vector<pii> edge[N];
int dis[N];
bool vis[N];
int cost[N][N];

void dijkstra(int s)
{
	fillb(vis);
	dis[s]=0;
	multiset<pii>mul;
	mul.insert({0,s});//dis-source
	while(!mul.empty())
	{
		pii frnt = *mul.begin();
		mul.erase(mul.begin());
		int x = frnt.node;
		int cst = frnt.dist;
		if(!vis[x])
		{
			vis[x]=1;
			fo(i,edge[x].size()){
				int nd = edge[x][i].first;
				int w = edge[x][i].second;
				int dist = max(cst,w);
				if(dist<dis[nd]){
					dis[nd]=dist;
					mul.insert({dis[nd],nd});
				}
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
        int n,m;
        sff(n,m);
        fof(i,0,n+5){
        	edge[i].clear();
        	dis[i]=1e9;
        	fof(j,0,n+5)cost[i][j]=1e9;
        }
        fo(i,m){
        	int u,v,w;
        	sfff(u,v,w);
        	cost[u][v]=min(w,cost[u][v]);
        	//if(w<cst)cst=w;
        	edge[u].pb({v,cost[u][v]});
        	edge[v].pb({u,cost[u][v]});
        }
        int des;
        sf(des);
        
        dijkstra(des);
        pf("Case %d:\n",tc);
        fo(i,n){
        	if(dis[i]==1e9)pf("Impossible\n");
        	else pf("%d\n",dis[i]);
        }
        //fo(i,n)edge[i].clear();
    }
    return 0;
}

///Alhamdulillah
