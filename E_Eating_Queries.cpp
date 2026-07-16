#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n,q;
        cin >> n >> q;
        vector<long long> a(n);
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        for(int i=1; i<n; i++)
        {
            a[i] += a[i-1];
        }
        while(q--)
        {
            long long x;
            cin >> x;
            if(a[n-1] < x)
            {
                cout << -1 << endl;
                continue;
            }
            int l=0,r = n-1,ans=n;
            while(l <= r)
            {
                int mid = (l+r)/2;
                if(a[mid] >= x)
                {
                    ans = mid;
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
            cout << ans+1 << endl;
        }
    }
    return 0;
}