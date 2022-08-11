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



class SampleClass {
    private:
        int val;
    public:
        void set(int a) {
            val = a;
        }
        int get() {
            return val;
        }
};

struct typ{
    string text="hello";
    int value;
};

const int L = 18;
ll n,m,k,a,b,c,l,r,nb,q;
double tot;
ll cnt;
int ans[M];
ll vis[M];
vector<ii> v[M];
bool test;

void dfs(int a,int p=-1,int ind=0){

    cout<<a<<'\n';
    if(((v[a].size()>1)&&(p!=-1))||(v[a].size()>2))
        {test=false;
        return;}
    if(v[a].size()>1)
    {
        ans[v[a][0].y]=2;
        dfs(v[a][0].x,a,0);
        ans[v[a][1].y]=3;
        dfs(v[a][1].x,a,1);
        return;
    }
    if(ind)
    {ans[v[a][0].y]=2;
    dfs(v[a][0].x,a,0);}
    else
    {
        ans[v[a][0].y]=3;
        dfs(v[a][0].x,a,1);
    }

}

void solve()
{
    cin>>n;
    for (int i=0;i<=n;i++)
        v[i].clear();
    for (int i=0;i<(n-1);i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].pb(mp(b,i));
        v[b].pb(mp(a,i));
    }
    test=true;
    dfs(1);
    if(!test)
    {
        cout<<-1<<'\n';
        return ;
    }
    for(int i=0;i<(n-1);i++)
        cout<<ans[i]<<" ";
    cout<<'\n';


}


int main()
{
    //ios_base::sync_with_stdio(0);
    //freopen("out.txt","w",stdout);
    //cin>>nb;
    cin>>nb;

    while(nb--)
        solve();

    return 0;
}
