#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define endl "\n";
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
const int N = 1e6;

int main()
{
optimize();
fraction();
 ll t;
 cin >> t;
   while(t--)
//for(int i = 1; i <= t; i++)
    {
         //cout << "Case " << i <<  ": " ;
         ll n , x; cin >> n >> x;
         vector<ll>a(n);
         for(int i = 0; i <n; i++){cin >> a[i];}
         sort(a.begin() , a.end());//sort the array
         vector<ll>pre(n); // prefix sum for cost of sugar 
         vector<ll>pos(n , 0);//the total possible days to pick the i_th element
         pre[0]=a[0];
         for(int i = 1 ;i<n;i++){
            pre[i] = pre[i-1]+a[i];
         }
         for(int i = 0 ;i<n;i++){
            if(pre[i]>x)continue; //skipping the i elements that cannot took togather
            pos[i]=((x-pre[i])/(i+1))+1; // calculating the possible days for each element
         }
         ll ans = 0 ;
         ll subtract = 0 ;
         for(int i = n-1 ;i>=0;i--){
            ans+=((pos[i]-subtract)*(i+1));//contributing the elements that and subtracting the elements that are already been picked
            subtract+=(pos[i]-subtract);//counting the total picked for the next i_th element
         }
         cout<< ans << endl;
    }
}