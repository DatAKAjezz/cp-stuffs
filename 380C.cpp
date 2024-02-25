#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair< int, int>
#define pll pair < ll , ll>
#define el endl
#define cel cout << endl
#define rep(i , u , v) for (int i = u ; i < v; i++)
#define per(i , u ,     v) for (int i = v; i > u ;i--)
#define fora(x, a) for (auto & x : a)
#define MOD 1000000007
#define pi = 3.1415926535897932384626433832795
#define pb push_back
#define eb emplace_back
#define pf push_front 
#define all(a) (a).begin() , (a).end()
#define lb lower_bound
#define up upper_bound 

ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }

const int  INF = INT_MAX;

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
template<class T> bool ckmin(T&a, T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, T&b) { bool B = a < b; a = max(a,b); return B; }
void yes(){ cout << "YES\n" ;}
void no(){cout << "NO\n";}
void debugMode(){
	#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" ,stdin);
	freopen ("output.txt" , "w" , stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int MAXN = 1e6 + 1;
string s;

struct node {
	int optimal;
	int open;
	int close;
	node(){};
	node( int opt , int o ,int c){
        optimal = opt;
        open = o;
        close = c;
	}
};

node st[MAXN * 4];

node operator + (const node & left , const node & right ) {
	node res;
	int tmp = min (left.open, right.close);
	res.optimal = left.optimal + right.optimal + tmp * 2;

	res.open = left.open + right.open - tmp;
	res.close = left.close + right.close - tmp;
	return res;
}

void build (int id , int l , int r){
	if ( l == r){
		if (s[l] == '(')
			st[id] = node ( 0 ,1 ,0);
		else st[id] = node ( 0 , 0 , 1);
		return;
	}
	int mid = ( l + r ) / 2;
	build ( id * 2 , l , mid );
	build ( id * 2 + 1 , mid + 1 , r);

	st[id] = st[id * 2] + st[id*2 + 1];

}

node query (int id , int l , int r ,int u ,int v){
	if ( v < l || r < u){
		return node( 0 , 0 , 0);
	}
	if ( u <= l && r <= v){
		return st[id];
	}
	int mid = (l + r) / 2;
	return query(id * 2 , l , mid , u  , v) + query (id*2+1 , mid+1,r,u,v);
}

int main(){

	debugMode();
	int t , x , y; 	
	cin >> s;
	int n; n = s.size();

	cin >> t;
	build ( 1 , 0 , n - 1);
	while ( t --){

		//rep ( i , 0, n) cout << s[i] <<
		
		cin >> x >>y; --x;--y;
		node res = query ( 1 , 0 , n - 1 , x , y);
		cout << res.optimal <<el;
	}

	return 0 ;
}