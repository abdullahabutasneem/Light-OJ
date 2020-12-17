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
#define sfff(x,y,z) scanf("%d%d%d",&x,&y,&z)
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

void file()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

struct edge
{
	int a,b,w;
};

//this fuction sorts vector pair according to first element in descending order.
bool comp1(edge a, edge b)
{
    return a.w<b.w;
}
bool comp2(edge a, edge b)
{
    return a.w>b.w;
}

#define N 105
edge edge_min[12010],edge_max[12010];
int par_min[N],par_max[N];

int find(int x, bool step)
{
	if(step){
		if(par_min[x]==-1)return x;
		return par_min[x] = find(par_min[x],true);
	}
	else{
		if(par_max[x]==-1)return x;
		return par_max[x] = find(par_max[x],false);
	}
}


void merge(int a, int b, bool step)
{
	if(step)par_min[a] = b;
	else par_max[a] = b;
}

int main()
{
    file();
    IOS;
    int t;sf(t);
    fof(tc,1,t)
    {
        int n;
        sf(n);
        int u,v,w;
        int idx=0;
        while(sfff(u,v,w))
        {
        	if(u==0 and v==0 and w==0)break;
        	edge_min[idx].a = u;
        	edge_min[idx].b = v;
        	edge_min[idx].w = w;

        	edge_max[idx].a = u;
        	edge_max[idx].b = v;
        	edge_max[idx].w = w;

        	idx++;
        }
        fof(i,0,n){
        	par_min[i]=-1;
        	par_max[i]=-1;
        }
        sort(edge_min,edge_min+idx,comp1);
        sort(edge_max,edge_max+idx,comp2);

        ll sum1=0,sum2=0;
        fo(i,idx){
        	int x_min = find(edge_min[i].a,true);
        	int y_min = find(edge_min[i].b,true);
        	if(x_min!=y_min){
        		sum1+=edge_min[i].w;
        		merge(x_min,y_min,true);
        	}
        	//cout<<"Sum1 = "<<sum1<<endl;
        	int x_max = find(edge_max[i].a,false);
        	int y_max = find(edge_max[i].b,false);
        	//cout<<"x_max = "<<x_max<<"  y_max = "<<y_max<<endl;
        	if(x_max!=y_max){
        		sum2+=edge_max[i].w;
        		merge(x_max,y_max,false);
        	}
        	//cout<<"Sum2 = "<<sum2<<endl;
        }
        ll sum = sum1+sum2;
        if(sum%2!=0)pf("Case %d: %lld/2\n",tc,sum);
        else pf("Case %d: %lld\n",tc,sum/2);
        fil(edge_max);
        fil(edge_min);
    }
    return 0;
}

///Alhamdulillah
