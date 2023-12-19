#include <math.h>
#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int find_pow_two(int);


int find_amount_zero(int number)
{
	int counter = 0;
	int pow_two = find_pow_two(number);

	while (number > 0)
	{
		if (number >= pow_two)
		{
			number -= pow_two;
		}
		else
		{
			++counter;
		}

		pow_two = pow_two >> 1;
	}

	return counter;
}

int find_pow_two(int number)
{
	int pow_two = 1;

	while (pow_two < number)
	{
		pow_two = pow_two << 1;
	}

	return (pow_two >> 1);
}


int main()
{
	cout << "Write number:" << endl;
	int number; cin >> number;

	int pow_two = find_pow_two(number);
	int prime_number;

	const int SIZE = 2000;
	int prime_numbers[SIZE];

	for (int i = 0; i < number; ++i)
	{
		prime_numbers[i] = i + 1;
	}

	for (int i = 2; i < number; ++i)
	{
		for (int n = i * i - 1; n < number; ++n)
		{
			if (prime_numbers[n] % i == 0)
			{
				prime_numbers[n] = 0;
			}
		}
	}

	int max_am_zero = find_amount_zero(prime_numbers[pow_two]);
	prime_number = prime_numbers[pow_two];

	for (int i = pow_two + 1; i < number; ++i)
	{
		int am_zero = find_amount_zero(prime_numbers[i]);
		
		if (max_am_zero < am_zero)
		{
			max_am_zero = am_zero;
			prime_number = prime_numbers[i];
		}
	}

	cout << "Number whith max 0:" << endl;
	cout << prime_number << endl;
}
