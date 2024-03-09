/* Dat 2005
When i wrote this code , only god and i knew how it worked.
Now , only god knows it!*/
#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int inf = 1e9 + 7;
const int maxN = 1e5 + 7;

int n , q;
int a[maxN];
ll st[maxN * 4] , lazy[maxN * 4];

void build ( int id , int l , int r){
	if ( l == r){
		st[id] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build (id * 2, l , mid);
	build (id * 2 + 1 , mid + 1 , r);
	st[id] = max(st[id * 2] , st[id * 2 + 1]);
}

void fix (int id  , int l , int r){
	if ( !lazy[id]) return;
	st[id] +=lazy[id];

	if ( l!= r){
		lazy[id * 2] += lazy[id];
		lazy[id * 2 + 1] += lazy[id];

	}
	lazy[id] = 0;
}

void update ( int id , int l ,int r , int u , int v ,int val){
	fix( id ,l ,r);
	if ( l > v || r < u){
		return;
	}
	if ( l >= u && r <= v){
		lazy[id] += val;
		fix ( id , l  , r);
		return;
	}
	int mid = l + r >> 1;
	update ( id * 2 ,l , mid ,u , v , val);
	update ( id * 2 + 1,mid + 1, r , u , v, val);
	st[id] = max( st[id * 2] , st[id * 2 + 1]);
}

ll get (int id , int  l ,int r , int u , int v){
	fix (id , l , r);
	if( l > v || r < u) return -inf;
	if (l >= u && r <= v) return st[id];
	int mid = l + r >> 1;
	ll get1 = get (id*2  , l , mid , u , v);
	ll get2 = get (id * 2 + 1 , mid + 1, r , u ,v);
	return max(get1 , get2);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i < n + 1; ++i) cin >> a[i];
	build(1 , 1, n);	

	cin >> q;
	while ( q--){
		int type , l ,r ,val;
		cin >> type >> l >> r;
		if ( type == 1) {
			cin >> val;
			update ( 1, 1 ,n , l ,r ,val);
		}
		else cout << get ( 1 , 1 , n , l, r) <<'\n';
	}


	return 0;
}