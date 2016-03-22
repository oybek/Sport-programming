
template <class T>
T gcd(T a, T b) {
	T c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

