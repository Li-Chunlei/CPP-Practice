/*
你需要编程 求出一个正整数最多能分解成多少个互不相同的素数的和。
例如，21 = 2 + 19是21的合法分解方法。21 = 2 + 3 + 5 + 11则是分解为最多素数的方法。
再比如：128，最多可以分解为9个素数的和。
*/



//以为是一个很不错的方案，结果部分不通过
#include <iostream>
#include <vector>
using namespace std;


// 埃拉托斯特尼筛法，生成所有小于等于n的素数
vector<int> generatePrimes(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

//个数最多的情况一定是从小开始加的情况
// 贪心算法：从小到大选择素数，尽可能多的加到和里
int maxPrimeSumDecomposition(int n) {
    vector<int> primes = generatePrimes(n); // 获取小于等于n的所有素数
    int count = 0;
    int sum = 0;

    for (int prime : primes) {
        if (sum + prime <= n) {
            sum += prime;
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    cout << maxPrimeSumDecomposition(n) << endl;

    return 0;
}
