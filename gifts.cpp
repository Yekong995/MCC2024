#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int ll;

#define magic ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {

    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    magic;

    ll num, gift;
    cin >> num >> gift;

    vector<ll> v;
    map<ll, ll> m;
    for (ll i = 0; i < num; ++i) {
        ll x;
        cin >> x;
        v.emplace_back(x);
        m[x] += 1;
    }

    vector<ll> record_pos;
    while (gift > 0) {
        for (auto j = m.begin(); j != m.end(); j++) {
            ll tier = j->first;
            for (ll i = 0; i < num; i++) {
                if (v[i] == tier) {
                    gift -= 1;
                    record_pos.emplace_back(i);
                }
                if (gift <= 0) {
                    break;
                }
            }
            if (gift <= 0) {
                break;
            }
        }
    }

    // Output map
    // for (auto i = m.begin(); i != m.end(); i++) {
    //     cout << i->first << " " << i->second << endl;
    // }

    ll recorded_pos = 0;
    sort(record_pos.begin(), record_pos.end());
    for (ll i = 0; i < num; i++) {
        if (i == record_pos[recorded_pos]) {
            cout << 1 << " ";
            recorded_pos += 1;
        } else {
            cout << 0 << " ";
        }
    }

    return 0;
}

