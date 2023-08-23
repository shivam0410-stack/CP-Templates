#include <bits/stdc++.h>
#define int long long
#define ff first
#define ss second
using namespace std;

const int mod=1e9+7;

int squareRoot(int x){
    if(x<0) return -1;
    if(x==0) return 0;
    int l=1,r=1e9;
    while(l<=r){
        int m=l+(r-l)/2;
        int a=x/m,b=(x-1)/m;
        if(a>=m && b<m+2) return m;
        if(a>=m+2) l=m+1;
        else r=m-1;
    }
    return 0;
}

int binexp(int x, int y){
    int z = 1;
    while(y)
    {
        if(y & 1) z = (z*x)%mod;
        x = (x*x)%mod;
        y >>= 1;
    }
    return z;
}

const int N=1e6+1;

vector<bool> isprime(N+1, true);
vector<int> p;

void sieve(){
    isprime[0] = isprime[1] = false;

    for(int i=2;i*i<=N;i++){
        if(!isprime[i]) continue;
        for(int j=i*i;j<=N;j+=i){
            isprime[j]=false;
        }
    }
    for(int i=1;i<=N;i++) if(isprime[i]) p.push_back(i);
}

int fenwick[100001];

void update(int i,int x) {
  while(i<=N)
  {
      fenwick[i]+=x;
      i+=(i&(-i));
  }
}

int query(int x)
{
  int ans=0;
  while(x>0)
  {
       ans+=fenwick[x];
       x-=(x & (-x));
  }

  return ans;
}

vector<int> ans;

void dfs(vector<vector<int>> &adj, int u, int p){
    if(adj[u].size()==1 && u!=1){
        ans[u]=1;
        return ;
    }
    for(auto v : adj[u]){
        if(v!=p){
            dfs(adj,v,u);
            ans[u]+=ans[v];
        }
    }
}

void solve(){
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        // cout<<"Case #"<<i<<": ";
        solve();
        // cout<<'\n';
    }
    return 0;
}
