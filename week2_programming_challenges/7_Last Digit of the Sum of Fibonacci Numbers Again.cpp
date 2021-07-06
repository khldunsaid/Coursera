#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

long long Periodic(long long m) {
	long long a = 0, b = 1, c = a + b;
	for (int i = 0; i < m*m; i++) {
		c = (a + b) % m;
		a = b;
		b = c;
		if (a == 0 && b == 1)
			return i + 1;
	}
}
int get_fibonacci_huge_fast(long long n, long long m) {
	long long remainder = n % Periodic(m);

	long long first = 0;
	long long second = 1;

	long long res = remainder;

	for (int i = 1; i < remainder; i++) {
		res = (first + second) % m;
		first = second;
		second = res;
	}

	return res % m;
}

// Sum Of (Fib[0]+Fib[1]+.....+Fib[n])= Fib[n+2]-Fib[2]
//Sum of (Fib[0]+Fib[1]+.....+Fib[m])= Fib[m+2]-Fib[2]
//Sum of (Fib[m]+Fib[1]+.....)
long long fibonacci_sum_fast_to(long long n) {
	int Last_Digit_Of_nPlus2 = get_fibonacci_huge_fast(n + 2, 10);
	int Last_Digit_Of_2 = get_fibonacci_huge_fast(2, 10);

	if (Last_Digit_Of_nPlus2 >= Last_Digit_Of_2)
		return (Last_Digit_Of_nPlus2 - Last_Digit_Of_2);
	else
		return ((10 + Last_Digit_Of_nPlus2) - Last_Digit_Of_2);
}

long long fibonacci_sum_fast_from(long long m) {
	int Last_Digit_Of_nPlus2 = get_fibonacci_huge_fast(m + 1, 10);
	int Last_Digit_Of_2 = get_fibonacci_huge_fast(2, 10);

	if (Last_Digit_Of_nPlus2 >= Last_Digit_Of_2)
		return (Last_Digit_Of_nPlus2 - Last_Digit_Of_2);
	else
		return ((10 + Last_Digit_Of_nPlus2) - Last_Digit_Of_2);
}

int fibonacci_partial_sum_fast(long long m, long long n){
    int fib_from = fibonacci_sum_fast_from(m);
    int fib_to = fibonacci_sum_fast_to(n);
    
    if (fib_to > fib_from)
		return (fib_to - fib_from)%10;
	else
		return ((10 + fib_to) - fib_from)%10;
    
    
    
}
    


int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << fibonacci_partial_sum_fast(from, to) << '\n';
}

