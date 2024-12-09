#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
int count=0;
int a[205];

//找出范围内的所有素数
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

//搜索
void search(int number,int sum,int step){
    vector<int> primes=generatePrimes(number);
    for(int prime:primes){
        if(prime>a[step-1]){
            a[step]=prime;
            if(sum+prime==number){
                count=max(count,step);
            }else if(sum+prime<number){
                search(number,sum+prime,step+1);

            }
            }
        }
    }

int getMaxPrimeCount(int n) {
        count = 0;  // 重置最大分解数
        search(n, 0, 1);  
        return count;
    }

};

int main(){
    Solution solution;
    int n;
    scanf("%d",&n);
    printf("%d\n",solution.getMaxPrimeCount(n));
    return 0;
}