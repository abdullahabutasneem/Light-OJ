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

#define N 20005
vi ar[N],tr[N];
int scc,scc_no[N];
bool vis[N],out_deg[N],in_deg[N];
stack<int> order;

void dfs(int node)
{
	vis[node]=1;
	for(int child:ar[node]){
		if(!vis[child])dfs(child);
	}
	order.push(node);
}

void dfs1(int node)
{
	scc_no[node]=scc;
	//pf("%d ",node);
	for(int child:tr[node]){
		if(scc_no[child]==0)dfs1(child);
	}
}

void kosaraju(int n)
{
	fof(i,1,n)
	{
		if(!vis[i])dfs(i);
	}
	scc=0;
	while(!order.empty()){
		int v = order.top();
		order.pop();
		if(scc_no[v]==0){
			scc++;
			dfs1(v);
		}
	}
	//pf("scc = %d\n",scc);
}

void clr(int n)
{
	fof(i,0,n){
       ar[i].clear();
       tr[i].clear();
       vis[i]=0;
       scc_no[i]=0;
       in_deg[i]=0;
       out_deg[i]=0;
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
        clr(n+2);
        fof(i,1,m)
        {
        	int u,v;
        	sff(u,v);
        	ar[u].pb(v);
        	tr[v].pb(u);
        }
        kosaraju(n);
        if(scc==1){
        	pf("Case %d: 0\n",tc);
        	continue;
        }

        fof(node,1,n)
        {
        	for(int child:ar[node]){
        		if(scc_no[node] != scc_no[child]){
        			out_deg[scc_no[node]]=1;
        			in_deg[scc_no[child]]=1;
        		}
        	}
        }
        int in=0,out=0;
        fof(i,1,scc){
        	if(!out_deg[i])out++;
        	if(!in_deg[i])in++;
        }
        pf("Case %d: %d\n",tc,max(in,out));
    }
    return 0;
}

///Alhamdulillah
