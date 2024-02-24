#include "datdat.h"

using namespace std;
vector <int > st(10,0);
void update( int id ,int l ,int r, int i ,int v){
    if ( i < l || i > r){
        return ;
    }
    if ( l == r){
        st[id] = v;
        return ;
    }
    int mid = (l + r) / 2;
    update( id * 2 , l , mid, i , v);
    update( id * 2 + 1, mid + 1, r , i , v);
}
int get (int id , int l , int r , int u ,int v){
    if ( v < l || u > r ){
        return -INF;
    }
    if ( u <= l && r <= v){
        return st[id];
    }
    int mid = (l+r)/2;
    return max(get ( id * 2 , l,mid ,u ,v) , get ((id * 2 + 1) , mid + 1, r,u,v));
}
int main(){

    debugMode();
    int n , x;
    n = 10;
    
    rep (i,0,n) {
        cin >> x;
        update ( 0 , 0 , n - 1, i , x);
    }
    fora (x , st) cout << x <<el;
    int max = get (0 , 0 , n - 1 , 2 , 5);
    cout << max << el;

    return 0;
}