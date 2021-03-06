/*
Problem Name: Box Stacking Problem
Problem Difficulty: 
Problem Constraints: 1 <= T <= 100
1 <= N <= 100
1 <= l,w,h <= 1000000
Problem Description:
Given a set of <b>N</b> types of rectangular 3-D boxes, where the <b>i<sup>th</sup></b> box has height <b>h</b>, width <b>w</b> and length <b>l</b>. Create a stack of boxes which is as tall as possible. However, you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base.It is also allowable to use multiple instances of the same type of box. Your task is to write a program to find the maximum Height by any possible arrangements of the boxes.


Input Format: The first line contains an integer <b>T</b> denoting the no of test cases. <br />
For every test case: <br />
<ul>
<li>First line contains an integer <b>N</b> denoting the total no of boxes available. </li>
<li> Second line contains <b>3*N</b> space separated values denoting the height, width and length of the <b>N</b> boxes.
Sample Input: 2
4
4 6 7 1 2 3 4 5 6 10 12 32
3
1 2 3 4 5 6 3 4 1
Output Format: For every test case, print the maximum height possible with the given boxes.
Sample Output: 60
15



=====Solution=====
*/
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
 #define fio ios_base::sync_with_stdio(false)
 
#define ll long long int

#define s(x) scanf("%lld",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)
 
#define p(x) printf("%lld\n",x)
#define p2(x,y) p(x)+p(y)
#define p3(x,y,z) p(x)+p(y)+p(z)
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
 
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define pb push_back

ll inf = 1e18;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

vector<pair<ll,pll>> dims;
vector<ll> maxHtPossibleWithIthBoxAtTop;
vector<vector<ll>>adj;
vector<bool>vis;

void dfs(ll i){
	vis[i]=true;

	ll ans=dims[i].first;
	for(ll j=0;j<adj[i].size();j++){
		if(!vis[adj[i][j]])dfs(adj[i][j]);
		ans=max(ans,maxHtPossibleWithIthBoxAtTop[adj[i][j]]+dims[i].first);
	}
	maxHtPossibleWithIthBoxAtTop[i]=ans;
}

int main()
{
	// freopen("input.txt","r",stdin);
 	// freopen("output.txt","w",stdout);
	ll t=1;
	s(t);
	while(t--){
		ll n;
		s(n);
		dims.clear();
		maxHtPossibleWithIthBoxAtTop.clear();
		adj.clear();
		vis.clear();

		F(i,0,n-1){
			ll h,w,b;
			vector<ll>temp;
			s3(h,w,b);
			temp.pb(h);temp.pb(w);temp.pb(b);
			sort(temp.begin(), temp.end());
			h=temp[0];
			w=temp[1];
			b=temp[2];
			dims.push_back({h,{w,b}});
			dims.push_back({w,{h,b}});
			dims.push_back({b,{h,w}});
		}

		adj.resize(dims.size());
		vis.resize(dims.size());
		maxHtPossibleWithIthBoxAtTop.resize(dims.size());

		for(ll i=0;i<dims.size();i++){
			for(ll j=0;j<dims.size();j++){
				if(i==j)continue;
				if(dims[i].second.first<dims[j].second.first){
					if(dims[i].second.second<dims[j].second.second)
						adj[i].push_back(j);
				}
			}
		}

		for(ll i=0;i<dims.size();i++){
			if(vis[i])continue;
			dfs(i);
		}

		ll ans=0;
		for(ll i=0;i<maxHtPossibleWithIthBoxAtTop.size();i++)
			ans=max(ans,maxHtPossibleWithIthBoxAtTop[i]);

		p(ans);
	}
}
