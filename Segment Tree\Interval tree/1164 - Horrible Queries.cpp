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

#define pf printf
#define sf(x) scanf("%d",&x);
#define sfl(x) scanf("%lld",&x);
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
#define cases(t) printf("Case %d:",t)
#define PI acos(-1)


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
#define pii pair<ll, ll>
#define N 100005
#define prop first
#define sum second 
pii seg[3*N];
int n;

void build(int node, int beg, int en)
{
	if(beg==en){
		seg[node]= {0,0};
		return;
	}
	int left = 2*node+1;
	int right = 2*node+2;
	int mid = beg+(en-beg)/2;
	build(left,beg,mid);
	build(right,mid+1,en);
	seg[node].sum = 0;
	seg[node].prop = 0;
}

void update(int node, int b, int e, int i, int j, ll val)
{
	if(i>e or j<b)return;
	if(b>=i and e<=j){
		seg[node].sum += (e-b+1)*val;
		seg[node].prop += val;
		return;
	}
	int left = 2*node+1;
	int right = 2*node+2;
	int mid = b+(e-b)/2;
	update(left,b,mid,i,j,val);
	update(right,mid+1,e,i,j,val);
	seg[node].sum = seg[left].sum + seg[right].sum + (e-b+1)*seg[node].prop;
}

ll query(int node,int b,int e,int i,int j, ll carry=0)
{
	if(i>e or j<b)return 0;
	if(b>=i and e<=j){
		return seg[node].sum + carry*(e-b+1);
	}
	int left = 2*node+1;
	int right = 2*node+2;
	int mid = b+(e-b)/2;
	ll x = query(left,b,mid,i,j,carry+seg[node].prop);
	ll y = query(right,mid+1,e,i,j,carry+seg[node].prop);
	return x+y;
}

int main()
{
    file();
    int t; sf(t);
    fof(tc,1,t)
    {
    	fil(seg);
    	ll ans;
    	int q;
    	sf(n); sf(q);
    	pf("Case %d:\n",tc);
    	//build(0,0,n-1);
    	while(q--)
    	{
    		int op;sf(op);
    		if(op==0)
    		{
    			int i,j; ll v;
    			sf(i);sf(j);sfl(v);
    			update(0,0,n-1,i,j,v);
    		}
    		else
    		{
    			int i,j;
    			sf(i);sf(j);
    			ans = query(0,0,n-1,i,j,0);
    			pf("%lld\n",ans);
    			ans=0;
    		}
    	}
    }
    return 0;
}

///Alhamdulillah
