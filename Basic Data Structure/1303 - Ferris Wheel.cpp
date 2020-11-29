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
 
int main()
{
    int t;
    scanf("%d",&t);
    fof(tc,1,t)
    {
        int n,m;
        sf(n);sf(m);
        deque<int>pro,seat;
        stack<int>temp;
        fof(i,1,n)pro.pb(i);
        fof(i,1,m)seat.pb(i);
        vector<int>ride[n+1];
        int time=0;
        int mark[m+1];
        fil(mark);
        int c=0;
        while(c<(m*n))
        {
            int now = seat.front();
            seat.pop_front();
            seat.pb(now);
            time+=5;
            if(mark[now]!=0){
                c++;
                int k = mark[now];
                ride[k].pb(now);
                pro.pb(k);
                mark[now]=0;
            }
            while(mark[now]==0)
            {
                if(pro.size()==0)break;
                int x = pro.front();
                pro.pop_front();
                bool tt=0;
                int cnt=0;
                if(ride[x].size()!=m)
                {
                    fo(i,ride[x].size())
                    {
                        if(ride[x][i]==now)
                        {
                            //temp.push(x);
                            tt=1;
                            break;
                        }
                        else cnt++;
                    }
                    if(cnt<m and !tt){
                        mark[now] = x;
                    }
                    if(tt){
                        temp.push(x);
                        if(pro.size()>0){
                           
                            continue;
                        }
                        else break;
                    }
                }
                else{
                    temp.push(x);
                }
            }
            while(!temp.empty()){
                pro.push_front(temp.top());
                temp.pop();
            }
        }
        printf("Case %d: %d\n",tc,time);
    }
    return 0;
}
 
///Alhamdulillah
