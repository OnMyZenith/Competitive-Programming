// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int a[2];
    int *findTwoElement(int *arr, int n) {
        vector<bool> v(n+1); 
        
        for(int i=0;i<n;i++)
            if(v[arr[i]]) a[0] = arr[i];
            else v[arr[i]] = 1;
            
        for(int i=1;i<=n;i++) 
            if(!v[i]) a[1] = i;
        // cout<<a[0]<<a[1];
        return a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[10];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        int *ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends