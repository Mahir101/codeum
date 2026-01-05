#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int mod;

int power(int n, ll k) {
  int ans = 1 % mod;
  while (k) {
    if (k & 1) ans = (ll) ans * n % mod;
    n = (ll) n * n % mod;
    k >>= 1;
  }
  return ans;
}

// returns pair {b^n % mod, (1 + b + ... + b^{n-1}) % mod}
pair<int, int> pow_sum(int b, ll n) {
  if (n == 0) return {1, 0};
  auto [p, s] = pow_sum(b, n / 2);
  int p2 = (ll)p * p % mod;
  if (n & 1) {
    int pn = (ll)p2 * b % mod;
    int sn = (1 + (ll)b * (p + 1) % mod * s) % mod;
    return {pn, sn};
  } else {
    int sn = (ll)(p + 1) * s % mod;
    return {p2, sn};
  }
}

// Computes x^s + x^{s+d} + x^{s+2d} + ... + x^{s+(n-1)d}
int progression_sum(ll x, ll s, ll d, ll n) {
  x %= mod;
  int base = power(x, s);
  auto [_, sum] = pow_sum(power(x, d), n);
  return (ll)base * sum % mod;
}

struct Progression {
  ll start; // First element (mod m)
  ll diff;  // Step difference (mod m)
  ll len;   // Number of terms in this progression (no wrap)
};

// Decomposes sequence S = { (a*k + b) % m | 0 <= k < n }
// into O(sqrt(m)) disjoint arithmetic progressions (non-wrapping).
//
// Preconditions: gcd(a, m) = 1 and n < m
//
// Returns a sequence of progressions
// Each progression p = {start, diff, len} satisfies: start + (len - 1) * diff < m
// and the union of all such progressions covers {0 <= k < n}.
//
// Note that as gcd = 1, all elements % m are distinct in the given arithmetic progression
vector<Progression> decompose_mod_linear(ll a, ll b, ll m, ll n) {
  vector<Progression> res;
  ll w = sqrtl(m) + 1;

  // If n is small, directly enumerate every element
  // Each element forms a single-length progression.
  if (n <= w) {
    for (ll i = 0; i < n; i++)
      res.push_back({(a * i + b) % m, 0, 1});
    return res;
  }

  // Idea: by pigeonhole principle, among w+1 residues in [0, m),
  //       there exist two with difference <= m/w.
  vector<pair<ll, ll>> vals(w + 1);
  for (ll i = 0; i <= w; i++)
    vals[i] = {a * i % m, i};   // store (residue, index)
  sort(vals.begin(), vals.end());

  // h = smallest difference between two residues
  // d = difference of their indices
  ll d = 1, h = m;
  for (ll i = 0; i < w; i++) {
    ll diff = vals[i + 1].first - vals[i].first;
    if (diff < h) {
      h = diff;
      d = vals[i + 1].second - vals[i].second;
    }
  }
  // After this:
  //  - h <= m / w  (small difference in values)
  //  - d <= w      (small difference in indices)
  //  - Also: a * d = ±h (mod m)

  // Now partition indices by (k mod d)
  //
  // For each residue class r (0 <= r < d):
  //    k = r, r + d, r + 2*d, ...
  // Then (a*k + b) % m evolves as:
  //    v, (v + h) % m, (v + 2*h) % m, ...
  //
  // This forms an arithmetic progression (possibly decreasing if a*d = -h mod m).
  // We iterate along it, cutting when value would exceed m.
  if (d > 0) {
    // Increasing pattern (a*d = +h mod m)
    for (ll r = 0; r < d; r++) {
      ll j = r; // start index
      while (j < n) {
        ll v = (a * j + b) % m;
        // We can move at most until (v + step*h) < m
        // => step_max = floor((m - v - 1) / h) + 1
        // We also cannot exceed n
        // => step_limit = floor((n - j - 1) / d) + 1
        ll step = min((m - v - 1) / h + 1,
                (n - j - 1) / d + 1);

        // Push one progression: {v, v+h, v+2h, ..., v+(step-1)*h}
        res.push_back({v, h, step});
                
        // Jump to the next unprocessed k in this residue class
        j += step * d;
      }
    }
  } else {
    // Descending pattern (a*d = -h mod m)
    // Values decrease instead of increase
    // Handled symmetrically by iterating backwards.
    for (ll r = n - 1; r >= n + d; --r) {
      ll j = r;
      while (j >= 0) {
        ll v = (a * j + b) % m;
        ll step = min((m - v - 1) / h + 1,
                j / -d + 1);
        res.push_back({v, h, step});
        j += step * d;
      }
    }
  }

  return res;
}

// Computes sum_{k=0}^{n-1} x^{(a*k + b) % m} % mod
int solve(ll a, ll b, ll m, ll n, ll x) {
  ll g = gcd(a, m);

  // Case 1: reduce by gcd(a, m)
  if (g != 1) {
    // let a = a' * g, m = m' * g, b = b1 * g + b2 (notice b2 is < g)
    // (a * k + b) % m = (a' * g * k + b1 * g + b2) % (m' * g) = b2 + g * ((a' * k + b1) % m')
    return (ll) power(x, b % g) *
         solve(a / g, b / g, m / g, n, power(x, g)) % mod;
  }

  // Case 2: handle full cycles when n >= m
  if (n >= m) {
    // as g = 1, all elements % m are distinct, so there will be n / m full cycles containing each element [0, m)
    auto [_, total] = pow_sum(x, m); // total = 1 + x + x^2 + ... + x^(m-1)
    return ((ll)(n / m % mod) * total % mod +
        solve(a, b, m, n % m, x)) % mod;
  }

  // Case 3: gcd = 1 and n<m, use sqrt decomposition
  auto progressions = decompose_mod_linear(a, b, m, n);
  int ans = 0;
  for (auto &p : progressions)
    ans = (ans + progression_sum(x, p.start, p.diff, p.len)) % mod;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    ll n, m, a, b, x;
    cin >> n >> m >> a >> b >> x >> mod;
    cout << solve(a, b, m, n, x % mod) % mod << '\n';
  }
}
// https://atcoder.jp/contests/abc429/editorial/14242
