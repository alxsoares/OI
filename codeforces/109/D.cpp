#include <cstdio>
#include <algorithm>
using namespace std;
int x1, x2, a, b;
int main() {
	scanf("%d%d%d%d", &x1, &x2, &a, &b);
	if ( x1 + a <= x2 && x2 <= x1 + b )
		printf("FIRST\n%d\n", x2);
	else if ( a <= 0 && 0 <= b )
		printf("DRAW\n");
	else {
		bool flag = false;
		if ( b < 0 ) {
			swap(x1, x2);
			a *= -1, b *= -1;
			swap(a, b);
			flag = true;
		}
		if ( x1 > x2 ) 
			printf("DRAW\n");
		else {
			int d = x2 - x1;
			if ( d % (a + b) == 0 )
				printf("SECOND\n");
			else if ( a <= d % (a + b) && d % (a + b) <= b ) {
				printf("FIRST\n");
				if ( !flag )
					printf("%d\n", x1 + d % (a + b));
				else
					printf("%d\n", x2 - d % (a + b));
			} else
				printf("DRAW\n");
		}
	}
}
