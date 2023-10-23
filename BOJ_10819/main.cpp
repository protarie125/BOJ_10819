#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n;
vl kh;

vb used;
vl now;

ll ans = -1;

ll calc() {
	auto ret = ll{ 0 };

	for (auto i = 0; i < n - 1; ++i) {
		ret += abs(now[i] - now[i + 1]);
	}

	return ret;
}

void solve() {
	if (n == now.size()) {
		ans = max(ans, calc());

		return;
	}

	for (auto i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}

		now.push_back(kh[i]);
		used[i] = true;

		solve();

		now.pop_back();
		used[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;

	kh = vl(n);
	for (auto&& x : kh) {
		cin >> x;
	}

	used = vb(n, false);
	now = vl{};
	now.reserve(n);

	solve();

	cout << ans;

	return 0;
}