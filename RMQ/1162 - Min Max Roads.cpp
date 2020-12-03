//Bismillahir Rahmanir Rahim
/*
    Abdullah Abu Tasneem
    Dept of CSTE, NSTU
*/
//LCA+sparse table
#include<bits/stdc++.h>
//for pbds
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
//template <typename T>using ordered_set =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;

const long long MOD = 1000000007;
#define fil(x) memset(x, -1, sizeof(x))
#define fillb(x) memset(x,false,sizeof(x))
#define fillm(x) memset(x, -1, sizeof(x))
#define mp make_pair
#define pii pair<int, int>
#define pf printf
#define sf(t) scanf("%d",&t);
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

const int N = 100005;
const int LOG = 17;
vector<int>edge[N], cost[N];
int dis[N], par[N], level[N];
int table_par[N][LOG], table_min[N][LOG], table_max[N][LOG];

void dfs(int from, int u, int depth)
{
	par[u] = from;
	level[u] = depth;
	fo(i,edge[u].size()){
		int v = edge[u][i];
		if(v==from)continue;
		dis[v] = cost[u][i];
		dfs(u,v,depth+1);
	}
}

void preprocess(int n)
{
	fil(table_par);
	table_par[1][0] = par[1];
	table_max[1][0] = 0;
	table_min[1][0] = 1e9;

	fof(i,2,n)
	{
		table_par[i][0] = par[i];
		table_max[i][0] = dis[i];
		table_min[i][0] = dis[i];
	}

	for(int j=1; (1<<j)<n; j++)
	{
		for(int i=1; i<=n; i++)
		{
			if(table_par[i][j-1]!=-1)
			{
				table_par[i][j] = table_par[table_par[i][j-1]][j-1];
				table_max[i][j] = max(table_max[table_par[i][j-1]][j-1], table_max[i][j-1]);
				table_min[i][j] = min(table_min[table_par[i][j-1]][j-1], table_min[i][j-1]);
			}
		}
	}
}

pii lca_query(int p, int q)
{
	if(level[p]<level[q])swap(p,q);
	int log = log2(level[p]);
	int mx=0, mn=1e9;
	for(int i=log; i>=0; i--)
	{
		if(level[p]-(1<<i)>=level[q]){
			mx = max(mx, table_max[p][i]);
			mn = min(mn, table_min[p][i]);
			p = table_par[p][i];
		}
	}
	if(p==q){
		return pii(mn,mx);
	}
	for(int i=log; i>=0; i--)
	{
		if(table_par[p][i]!=-1 and table_par[p][i]!=table_par[q][i]){
			mn = min(mn,min(table_min[p][i], table_min[q][i]));
			mx = max(mx,max(table_max[p][i], table_max[q][i]));
			p = table_par[p][i];
			q = table_par[q][i];
		}
	}
	mx = max(mx, max(dis[p],dis[q]));
	mn = min(mn, min(dis[p],dis[q]));

	return pii(mn,mx);
}

int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; sf(t);
    fof(tc,1,t)
    {
    	int n;
    	sf(n);
    	int u,v,w;
    	fo(i,n-1)
    	{
    		sf(u); sf(v); sf(w);
    		edge[u].pb(v);
    		edge[v].pb(u);
    		cost[u].pb(w);
    		cost[v].pb(w);
    	}
    	dfs(1,1,0);
    	//cout<<"akib"<<endl;
    	preprocess(n);
    	//cout<<"fkdib"<<endl;
    	printf("Case %d:\n",tc);
    	int qu;
    	sf(qu);
    	while(qu--)
    	{
    		int p,q;
    		sf(p); sf(q);
    		pii ans = lca_query(p,q);
    		printf("%d %d\n",ans.first, ans.second);
    	}
    	fof(i,0,n){
    		edge[i].clear();
    		cost[i].clear();
    	}
    }
    return 0;
}

///Alhamdulillah
