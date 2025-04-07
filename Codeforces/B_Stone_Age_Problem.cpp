#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define endl "\n"
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
const int M =  1e9+7;
using namespace std;
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
//memset(array, (0,false,-1,1) , sizeof(array));
//fill(array ,array+n,value);

int main()
{
    optimize();
    fraction();
    ll n , q; cin >> n >> q;
    vector<ll>a(n);
    ll sum =0 ;
    for(int i = 0; i <n; i++)
    {
          cin >> a[i];
          sum+=a[i];
    }
    ll lastall = -1 , lastval = 0 ;
    vector<ll>lastIndex(n , 0);

    for(int i =0;i<q;i++){
        ll x;cin >> x;
        if(x==1){
            ll pos , val ;cin >> pos >> val;
            pos--;
            if(lastIndex[pos]>lastall){
                sum+=val-a[pos];
            }
            else {
                sum += val-lastval;
            }
            lastIndex[pos]=i;
            a[pos]=val;
            cout << sum << endl;
        }
        else{
            ll val ;cin >> val;
            lastall = i ;lastval = val;
            sum = val*n;
            cout << sum << endl;
        }
    }

}