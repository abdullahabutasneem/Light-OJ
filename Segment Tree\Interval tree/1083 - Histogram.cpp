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
#define pii pair<int, int>
#define pf printf
#define sf(t) scanf("%d",&t)
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
#define Inf 1e9
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
#define N 100005
int a[N],n;
pii seg[3*N];

void build(int node, int beg, int en)
{
	if(beg==en){
		seg[node] = {a[beg], beg};
		return;
	}
	int left = 2*node;
	int right = left+1;
	int mid = beg+(en-beg)/2;
	build(left,beg,mid);
	build(right,mid+1,en);
	seg[node] = min(seg[left],seg[right]);
}

pii query(int node,int beg,int en,int i,int j)
{
    //cout<<"ggg"<<endl;
    if(beg>j || en<i) return pii(Inf,Inf);
    else if(beg>=i && en<=j) return seg[node];
    int left=2*node;
    int right=left+1;
    int mid = beg+(en-beg)/2;
    pii l=query(left,beg,mid,i,j);
    pii r=query(right,mid+1,en,i,j);
    return min(l,r);
}

ll max_area(int i,int j)
{
    if(j<i) return 0;
    pii min_height=query(1,1,n,i,j);
    ll area1=(j-i+1)*min_height.first;
    ll area2=max_area(i,min_height.second-1);
    ll area3 = max_area(min_height.second+1,j);
    return max(area1, max(area2,area3));
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
    	fof(i,1,n)sf(a[i]);
    	//cout<<"build"<<endl;
    	build(1,1,n);
    	//cout<<"build"<<endl;
    	ll area = max_area(1,n);
    	pf("Case %d: %lld\n",tc,area);
    }
    return 0;
}

///Alhamdulillah
