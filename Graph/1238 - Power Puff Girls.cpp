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
#define mp make_pair
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

int n,m;
string city[30];
bool vis[30][30];
int dis[30][30];

int bfs(int sx, int sy, int hx, int hy)
{
	fil(dis);
	fillb(vis);
	vis[sx][sy]=1;
	dis[sx][sy]=0;
	queue<pii>q;
	q.push({sx,sy});
	while(!q.empty())
	{
		pii u = q.front();
		q.pop();
		int ux = u.first;
		int uy = u.second;
		fo(k,4)
		{
			int dx = u.first + dx4[k];
			int dy = u.second + dy4[k];
			if(dx>=0 and dx<n and dy>=0 and dy<m and city[dx][dy]!='#' and city[dx][dy]!='m' and !vis[dx][dy])
			{
				vis[dx][dy]=1;
				dis[dx][dy]=dis[ux][uy]+1;
				q.push({dx,dy});
				if(dx==hx and dy==hy)return dis[hx][hy];
			}
		}
	}
	return dis[hx][hy];
}


int main()
{
    file();
    int t;cin>>t;
    fof(tc,1,t)
    {
    	pii a,b,c,h;
    	cin>>n>>m;
    	fo(i,n){
    		cin>>city[i];
    	}
    	fo(i,n)
    	{
    		fo(j,m)
    		{
    			if(city[i][j]=='a')a = {i,j};
    			if(city[i][j]=='b')b = {i,j};
    			if(city[i][j]=='c')c = {i,j};
    			if(city[i][j]=='h')h = {i,j};
    		}
    	}
    	int path=0;
    	path = max(path, bfs(a.first, a.second, h.first, h.second));
    	path = max(path, bfs(b.first, b.second, h.first, h.second));
    	path = max(path, bfs(c.first, c.second, h.first, h.second));
    	cout<<"Case "<<tc<<": "<<path<<"\n";
    }
    return 0;
}

///Alhamdulillah
