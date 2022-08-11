#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define MOD 998244353
#define INF 3*1e16
#define N 200000
#define M 1000000
#define MIN 1e-11
#define ll long long
#define pb push_back
#define DIM 2
#define forn(i,a,b) for(int i = a; i < n;  i++)
//#define for(i,j,k) for(int i=j;i<k;i++)
using namespace std;
typedef pair<ll, ll> ii;
typedef pair<ii, int> iii;


const int L = 18;
ll n,m,k,a,b,c,l,r,nb,q;
double tot;
ll cnt;
int dp[M];
ll vis[M];
vector<int> v[M];
bool test;



void solve()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {

        int a;
        dp[i]=INF;
        // adding edges bewtween i <--> i+1
        if(i<n)
        {
            v[i].pb(i+1);
            v[i+1].pb(i);
        }
        cin>>a;
        // adding edges between i and a[i]  i ---> a[i]
        v[i].pb(a);

    }
    //dijkstra
    set<ii> s;
    dp[1]=0;
    s.insert(mp(0,1));
    while(!s.empty()){
        ii top = *(s.begin());
        s.erase(s.begin());
        /*cout<<"TOP \n";
        cout<<top.x<<" "<<top.y<<'\n';
        cout<<"---------------\n";*/
        for (int i=0;i<v[top.y].size();i++)
        {

            int neighbor=v[top.y][i];
            //cout<<top.y<<" "<<neighbor<<'\n';
            if(dp[top.y]+1 < dp[neighbor])
            {
                dp[neighbor]=dp[top.y]+1 ;
                s.insert(mp(dp[neighbor],neighbor));
            }
        }
        //cout<<"---------------\n";
    }
    for (int i=1;i<=n;i++)
        cout<<dp[i]<<" ";



}


int main()
{
    //ios_base::sync_with_stdio(0);
    //freopen("out.txt","w",stdout);
    //cin>>nb;
    //cin>>nb;
    nb=1;
    while(nb--)
        solve();

    return 0;
}
