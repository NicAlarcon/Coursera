#include <iostream>

int fLast(int n, int m) {
int *arr = new int[n+2];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i<=n; i++){
        arr[i] = (arr[i-1] + arr[i-2]) % m;
    }
    int ans = arr[n];
    delete[] arr;
    return ans;
}

int pisano(long long m)
{
    int ret = 3;
    
    if (m == 2)
        return ret;

    for(int i = 2; i <= m*m; i++){
        //std::cout << fLast(i-1,m) << ":" << fLast(i,m) << '\n';
        if (fLast(i-1,m) == 0 && fLast(i,m) == 1){
            ret = i-1;
            break;
        }
    }
    return ret;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    
    int pd = pisano(m);

    int rem = n % pd;

    return (long long) fLast(rem,m);

}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
