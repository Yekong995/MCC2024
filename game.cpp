#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long int ll;

#define magic ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {

    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    magic;

    ll num;
    cin >> num;

    vector<pair<ll, ll>> arr(num);
    for (ll i = 0; i < num; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), [](pair<ll, ll>& p1, pair<ll, ll>& p2) {
        return p1.first + p1.second > p2.first + p2.second;
    });

    ll E = 0, R = 0;
    for (ll i = 0; i < num; i++) {
        if (i % 2 == 0) {
            // Evirir
            E += arr[i].first;
            // cout << "Evirir: " << arr[i].first << endl;
        } else {
            // Rhae
            R += arr[i].second;
            // cout << "Rhae: " << arr[i].second << endl;
        }
    }

    cout << E - R << endl;

    return 0;
}

