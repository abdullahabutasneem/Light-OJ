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
#define sf(x) scanf("%d",&x)
#define all(x) x.begin(),x.end()
#define pb push_back
#define IOS ios::sync_with_stdio(false);
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
#define N 1005
int bit[N][N];
bool vis[N][N];
void update(int a, int b)
{
	for(;a<=N; a+=(a & -a))
	{
		int bb = b;
		for(;bb<=N; bb+=(bb & -bb))
		{
			bit[a][bb]+=1;
		}
	}
}
int query(int c, int d){
	int res=0;
	for(;c>0; c-=(c & -c))
	{
		int dd=d;
		for(;dd>0; dd-=(dd & -dd))
		{
			res += bit[c][dd];
		}
	}
	return res;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    IOS;
    int t;sf(t);
    fof(tc,1,t)
    {
    	fil(bit);
    	fillb(vis);
    	pf("Case %d:\n",tc);
        int q;sf(q);
        while(q--)
        {
        	int op;sf(op);
        	if(op==0)
        	{
        		int a,b;
        		sf(a);sf(b);
        		a++;b++;
        		if(!vis[a][b]){
        			vis[a][b]=1;
        			update(a,b);
        		}
        	}
        	else{
        		int a,b,c,d;
        		sf(a);sf(b);sf(c);sf(d);
        		a++;b++;c++;d++;
        		int ans;
        		ans=query(c,d);
            		ans-=query(c,b-1);
            		ans-=query(a-1,d);
            		ans+=query(a-1,b-1);
        		pf("%d\n",ans);
        	}
        }
    }
    return 0;
}

///Alhamdulillah
