#include <cstdio>
#include <iostream>

using namespace std;
typedef long long int ll;

#define magic ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {

    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    magic;

    ll num;
    cin >> num;

    for (ll i = 0; i < num; i++) {
        ll x, y, sx, sy;
        cin >> x >> y >> sx >> sy;

        ll grida_x = sx, grida_y = sy;
        ll gridb_x = sy, gridb_y = sx;

        if ((gridb_x > x || gridb_y > y) && (grida_x > x || grida_y > y)) {
            cout << "NO\n";
        } else if (grida_x == x || grida_y == y || gridb_x == x || gridb_y == y) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

