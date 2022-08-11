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


ll n,nb;
int dp[M];
vector<int> v[M];



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
    //dijkstra implementation 
    set<ii> s;
    //initializing :
    //  dp[1]=0 distance to get from 1 to 1 is always 0
    //  s contains the set of pairs (minimum distance of node , node number)
    //  pushing the first pair (0,1) into the set s =====> ( distance of 1 = 0, node number =1 )
    dp[1]=0;
    s.insert(mp(0,1));


    // while set not empty loop : looping through all of the pairs (btw s is an ordered data structure with the 
    // default comparator < of pairs which compares the first index of pair then the seocnd one)

    while(!s.empty()){
        ii top = *(s.begin()); // top is the lowest pair
        s.erase(s.begin()); // erasing the lowest pair
        
        for (int i=0;i<v[top.y].size();i++) // looping through all of the neighbors
        {

            int neighbor=v[top.y][i];
            //cout<<top.y<<" "<<neighbor<<'\n';
            if(dp[top.y]+1 < dp[neighbor]) // if there's a shorter path  update the distance and insert the updated pair into the set
            {
                dp[neighbor]=dp[top.y]+1 ; // updating the distance
                s.insert(mp(dp[neighbor],neighbor)); // inserting the new pair
            }
        }
    }
    for (int i=1;i<=n;i++)
        cout<<dp[i]<<" ";



}


int main()
{
    ios_base::sync_with_stdio(0);
    nb=1;
    while(nb--)
        solve();

    return 0;
}
