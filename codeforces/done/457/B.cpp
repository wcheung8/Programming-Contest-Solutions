#include <stdio.h>

int main() {
	static long long N, K, b[1000000] = {}, n, i, t;
	for (scanf("%lld%lld", &N, &K), n = N, i = 900000; n; n /= 2, i++) {
        n&1 && (b[i]++, K--);
        printf("%lld\n", n);
	}

	if (K < 0)
		puts("No");
	else {
		for (i = 999999; K >= b[i]; i--)
			if (b[i])
				while (b[i])
					b[i-1] += 2, b[i]--, K--;
		for (i = 0; !b[i]; i++) ;
		for (; K; )
			b[i] ? (b[i]--, b[i-1] += 2, K--, i--) : i--;
		for (puts("Yes"), t = 0, i = 999999; i >= 0; i--)
			while (b[i])
				printf("%lld ", i-900000), b[i]--, t++;
	}
}
