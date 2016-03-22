
/* needs:
 * gcd, <cmath>
 */
ll get_prime_factor(ll n) {
	ll lim = pow(n, 1.0/3.0);
	for (int d = 2; d <= lim; ++d)
		if (n%d == 0)
			return d;

	for (int k = 1; k <= lim; ++k) {
		for (int d = 0; d <= static_cast<ll>(pow(n, 1.0/6.0)/(4*sqrt(k)))+1; ++d) {
			ll a = sqrt(4*k*n) + d;
			ll t = a*a - 4*k*n;

			if (t < 0) continue;

			ll b = sqrt(t);
			if (b*b == t) {
				ll dd = gcd(a-b, n);

				if (1 < dd && dd < n)
					return dd;
			}
		}
	}
	return -1;
}

