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

const long long MOD = 1000000007;
#define fil(x) memset(x, 0, sizeof(x))
#define fillb(x) memset(x,false,sizeof(x))
#define fillm(x) memset(x, -1, sizeof(x))
#define mp make_pair
#define pll pair<int, int>
#define pf printf
#define sf(t) scanf("%d",&t);
#define all(x) x.begin(),x.end()
#define pb push_back
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<n;i++)
#define fof(i,a,b) for(int i=a;i<=b;i++)

typedef unsigned long long lll;
typedef long long ll;

#define N 30005
const int k = ceil(log2(N))+2;
vector<int>edge[N];
int table[N][k];
int st[N], en[N], heavy_child[N], parent[N],p[N],level[N];
int pos_in_base[N], chain_ind[N], chain_head[N];
ll cost[N],bit[N],base_array[N],ans=0;
int chain_no,ptr,n,timer,logg;
int dfs(int now, int par, int dep)
{
	st[now]=++timer;
	p[now] = par;
	level[now]=dep;
	int sz=1,mxsz=0;
	fo(i,edge[now].size())
	{
		int u = edge[now][i];
		if(u!=par)
		{
			parent[u] = now;
			int child_size = dfs(u,now,dep+1);
			sz += child_size;
			if(child_size>mxsz){
				mxsz = child_size;
				heavy_child[now] = u;
			}
		}
	}
	en[now]=++timer;
	return sz;
}

void lca_preprocess(int n)
{
	fo(i,n)table[i][0]=p[i];
	for(int j=1; (1<<j)<n;j++)
	{
		fo(i,n){
			if(table[i][j-1]!=-1)
			{
				table[i][j] = table[table[i][j-1]][j-1];
			}
		}
	}
}

int lca_query(int u, int v)
{
	if(level[u]<level[v])swap(u,v);
	for(int i=logg;i>=0;i--)
	{
		if(level[u]-(1<<i)>=level[v]){
			u = table[u][i];
		}
	}
	if(u==v)return u;
	for(int i=logg;i>=0;i--)
	{
		if(table[u][i]!=-1 and table[u][i]!=table[v][i]){
			u = table[u][i];
			v = table[v][i];
		}
	}
	return parent[u];
}

void HLD(int cur) //Basically it's kind of a dfs procedure
{
	if(chain_head[chain_no]==-1)chain_head[chain_no] = cur; //"chain_no" chain's head is cur
	chain_ind[cur] = chain_no; //cur is in the "chain_no" chain number

	pos_in_base[cur] = ptr; //position of cur node in base array
	base_array[ptr++] = cost[cur]; //cost of cur node saved in base array

	if(heavy_child[cur]!=-1) HLD(heavy_child[cur]);
	fo(i,edge[cur].size()){
		int u = edge[cur][i];
		if(u!=parent[cur] and u!=heavy_child[cur]){
			chain_no++;
			HLD(u);
		}
	}
}

void update(int pos, ll val){
	while(pos<=ptr){
		bit[pos] += val;
		pos += (pos &- pos);
	}
}

ll query(int pos){
	ll sum=0;
	while(pos>0){
		sum += bit[pos];
		pos -= (pos &- pos);
	}
	return sum;
}

void tree_query(int u, int v)
{
	int uchain, vchain=chain_ind[v];
	while(1)
	{
		uchain = chain_ind[u];
		if(uchain==vchain){
			ans += query(pos_in_base[u]+1) - query(pos_in_base[v]);
			break;
		}
		ans += query(pos_in_base[u]+1) - query(pos_in_base[chain_head[uchain]]);
		u = chain_head[uchain];
		u = parent[u];
	}
}

void mmset() //everything reinitialized
{
	chain_no=0;
	ptr=0;
	fo(i,n+5)edge[i].clear();
	fillm(table);
	fill(base_array,base_array+(n+5),0);
	fill(chain_ind,chain_ind+(n+5),-1);
	fill(chain_head, chain_head+(n+5),-1);
	fill(pos_in_base, pos_in_base+(n+5),-1);
	fill(st,st+(n+5),0);
	fill(en,en+(n+5),0);
	fill(parent,parent+(n+5),0);
	fill(heavy_child,heavy_child+(n+5),-1);
	fill(bit,bit+(n+5),0);
	timer=0;
	logg=ceil(log2(n));
}

int main()
{
    #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
    #endif
    
    int t;
    sf(t);
    fof(tc,1,t)
    {
    	sf(n);
    	mmset();
    	fo(i,n)scanf("%lld",&cost[i]);
    	fo(i,n-1)
    	{
    		int u,v;
    		sf(u); sf(v);
    		edge[u].pb(v);
    		edge[v].pb(u);
    	}
    	dfs(0,0,0);
    	lca_preprocess(n);
    	HLD(0);
    	fo(i,ptr+1){
    		update(i+1, base_array[i]);
    	}
    	int q;
    	sf(q);
    	pf("Case %d:\n",tc);
    	while(q--)
    	{
    		int op;sf(op);
    		if(op==0)
    		{
    			int u,v;
    			sf(u); sf(v);
    			int lc = lca_query(u,v);
    			tree_query(u,lc);
    			tree_query(v,lc);
    			ans -= cost[lc];
    			pf("%lld\n",ans);
    			ans=0;
    		}
    		else{
    			int u;ll val;
    			sf(u);scanf("%lld",&val);
    			update(pos_in_base[u]+1,-cost[u]);
    			cost[u]=val;
    			update(pos_in_base[u]+1,cost[u]);
    		}
    	}
    }
    return 0;
}

///Alhamdulillah
