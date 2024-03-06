//VNOI ITEZ2

#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 7;
int n ,q;
int a[maxN];
int st[maxN * 4];

void build( int id , int l ,int r){

	if (l == r) {
		st[id] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build ( id * 2 , l,mid);
	build ( id * 2 + 1, mid + 1, r);
	st[id] = (st[id * 2] + st[id * 2 + 1]);

}

void update (int id ,int l ,int r , int i ,int val){

	if ( i > r || i < l) return;
	if ( l == r ) {
		st[id] = val;
		return;
	}
	int mid = l + r >> 1;
	update (id * 2 , l ,mid , i , val);
	update (id * 2 + 1, mid + 1 , r , i ,val);
	st[id] = st[id * 2] + st[id * 2 + 1];

}

long long get ( int id , int l , int r , int u  , int v){

	if ( u > r || v < l) return 0;
	if ( l >= u && r <= v){
		return st[id];
	}
	int mid = l + r >> 1;
	int get1 = get ( id * 2, l ,mid , u , v);
	int get2 = get ( id * 2 + 1 ,mid + 1 , r , u ,v);
	return get1 + get2;

}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i < n + 1; ++i){
		cin >> a[i];
		update (1 , 1 , n , i , a[i]);
	}
	build( 1 , 1 , n);

	//for (int i = 1 ; i < n * 2 + 1; ++i) cout << st[i] << " ";cout <<'\n';
	cin >> q;
	while (q--){

		int type , x , y;
		cin >> type >> x >> y;
		if ( type == 1 ) update (1 , 1 , n , x , y);
		else cout << get(1 , 1 , n , x , y) <<'\n';

	}

	return 0;
}