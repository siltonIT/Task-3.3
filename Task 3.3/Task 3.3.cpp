#include <math.h>
#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//Функция находит максимальную степень двойки 
int find_pow_two(int number)
{
	int pow_two = 1;

	while (pow_two < number)
	{
		pow_two = pow_two << 1;
	}

	return (pow_two >> 1);
}

//Функция находит простое число меньшее нашего с помощью решета Эратосфена
bool is_prime_number(int number, int prime_number)
{
	const int SIZE = 10000;
	int prime_numbers[SIZE];

	for (int i = 0; i < number; ++i)
	{
		prime_numbers[i] = i + 1;
	}

	for (int i = 2; i < number; ++i)
	{
		for (int n = i*i - 1; n < number; ++n)
		{
			if (prime_numbers[n] % i == 0)
			{
				prime_numbers[n] = 0;
			}
		}
	}

	for (int i = 0; i < number; ++i)
	{
		if (prime_numbers[i] == 0)
		{
			continue;
		}

		if (prime_number == prime_numbers[i])
		{
			return true;
		}
	}

	return false;
}

int main()
{
	cout << "Write number:" << endl;
	int number; cin >> number;

	int pow_two = find_pow_two(number);
	int prime_number;

	for (int i = pow_two + 1; i <= number; ++i)
	{
		if (is_prime_number(number, i))
		{
			prime_number = i;
			break;
		}
	}

	cout << "Number whith max 0:" << endl;
	cout << prime_number << endl;
}
