#include <stdio.h>
#include <math.h>

int main() {
	int T;
	scanf("%d\n", &T);
	while(T--) {
	    long long a, b;
	    scanf("%lld %lld\n", &a, &b);
	    long long ans = b - a;
        if(ans < 0) {
            printf("%lld\n", -ans);
            continue;
        }
	    long long bits = a & ~b;
	    long long cnt = 1;
	    while(cnt <= bits) {
	        cnt *= 2;
	    }
        long long cnt2 = 1;
        for(long long i = 0; i < bits; i++) {
            cnt2 *= 2;
            if(cnt2 > bits) break;
        }
	    long long ans2 =  -(b & (cnt - 1)) + 1 + (a & (cnt - 1));

        if(ans2 < ans) {
            ans = ans2;
        }
        long long ans4 = b - a + 6;
		while ((ans > ans4) || ((b & cnt) == 0) || ((a & cnt) > 0))
		{
			cnt = cnt << 1;
		}
        long long ans3 = b - a + 9;
 		long long ans5 = cnt - (a & (cnt - 1)) + 1;
        if(ans5 < ans) {
            ans = ans5;
        }
        printf("%lld\n", ans);
	}
	return 0;
}