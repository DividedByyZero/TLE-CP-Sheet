// problem link : https://codeforces.com/problemset/problem/1704/B

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin >> t;
	while(t--){
		int n,x; cin >> n >> x;
		vector<int>v(n);
		for(auto &x : v) cin >> x;
		
		int ans = 0;
		int high = v[0]+x;
		int low = v[0]-x;
		for(auto element : v){
			int h = element+x;
			int l = element-x;
			if(!(h<=high && h>=low ) && !(l<=high && l>=low) && !(l<=low && h>=high)){
				// cout << low << " " << high << endl;
				high = h;
				low = l;
				ans++;
				// cout << low << " " << high << endl;
			}
			else{
				high = min(h,high);
				low = max(l,low);
			}
		}
		cout << ans << endl;

	} 
}
