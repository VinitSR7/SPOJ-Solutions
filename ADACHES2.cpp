#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 10000005;
const int mod = 1000000007;

int T, N;
int f[MAX];

void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
void subtract(int &a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

int main() {
    f[0] = f[1] = 1;
    f[2] = f[3] = 0;
    for (int i = 4; i < MAX; i ++) {
        add(f[i], 1LL * (i + 1) * f[i - 1] % mod);
        subtract(f[i], 1LL * (i - 2) * f[i - 2] % mod);
        subtract(f[i], 1LL * (i - 5) * f[i - 3] % mod);
        add(f[i], 1LL * (i - 3) * f[i - 4] % mod);
    }
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &N);
        printf("%d\n", f[N]);
    }
    
    return 0;
}