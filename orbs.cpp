#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef unsigned long long ll;

#define magic ios_base::sync_with_stdio(false); cin.tie(NULL);
ll modulo = 1e9 + 7;

int main() {

    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    magic;

    ll num;
    cin >> num;

    for (ll t = 0; t < num; t++) {
        ll n;
        cin >> n;
        vector<ll> v(n);

        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            v[i] = x;
        }
        sort(v.begin(), v.end(), greater<ll>());

        if (n == 1) {
            cout << v[0] % modulo << "\n";
            continue;
        }

        // a + 2b
        ll ans = (((2 * (v[0] % modulo)) % modulo) + (v[1] % modulo)) % modulo;
        for (ll i = 2; i < n; i++) {
            ans = (((2 * (ans % modulo)) % modulo) + (v[i] % modulo)) % modulo;
        }
        cout << ans << "\n";
    }

    return 0;
}
