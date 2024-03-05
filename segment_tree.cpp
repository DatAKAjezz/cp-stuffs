#include "datdat.h"

using namespace std;

const int inf = 1e9 + 7;
const int maxN = 1e5 + 7;

int n,q;
int a[maxN];
int st[maxN * 4];

void build (int id , int l , int r){
    if ( l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build( id * 2 , l , mid);
    build( id * 2 + 1 , mid + 1, r);
    st[id] = min(st[id* 2] , st[id* 2 + 1]);
}

void update ( int id ,int l , int r , int i ,int val){
    if (l > i || r < i) return;

    if ( l == r){
        st[id] = val;
        return;
    }
    int mid  = ( l+ r) / 2;
    update ( id * 2 , l , mid , i , val);
    update ( id * 2 + 1,    mid + 1 , r ,i ,val);

    st[id] = min ( st[id*2] , st[id* 2 + 1]);
}

int get ( int id ,int l ,int r ,int u ,int v){
    if ( l > v || r < u ) return inf;
    if ( l >= u && r <= v) return st[id];
    int mid = l + r >> 1;
    int get1 = get (id * 2  , l ,mid , u ,v);
    int get2 = get (id * 2 + 1, mid + 1 , r , u ,v);
    return min(get1, get2);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //__________________________________-
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    build ( 1, 1, n);


    cin >> q;
    while ( q-- ){
        int type, u , v;
        cin >> type >> u >>v; 
        if (type == 1) update ( 1 , 1 , n , u ,v);
        else
        cout << get (1 , 1 , n , u , v) << '\n';
    }

    return 0;
}