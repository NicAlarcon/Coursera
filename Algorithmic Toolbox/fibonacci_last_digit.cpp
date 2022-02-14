#include <iostream>

int get_fibonacci_last_digit_fast(int n) {
int *arr = new int[n+2];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i<=n; i++){
        arr[i] = (arr[i-1] + arr[i-2]) % 10;
    }
    int ans = arr[n];
    delete[] arr;
    return ans;
}

int main() {
    int n;
    std::cin >> n;
    int d = get_fibonacci_last_digit_fast(n);
    std::cout << d << '\n';
    }
