#include <iostream>

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

long long fHuge(long long n) {
    long long m = 10;
    int pd = pisano(m);

    int rem = n % pd;

    return (long long) fLast(rem,m);

}

int fibonacci_sum_squares(int n){
    int ret = fHuge(n)*(fHuge(n)+fHuge(n-1));
    return ret % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n);
}
