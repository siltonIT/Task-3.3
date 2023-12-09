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
int find_prime_num_eratosth_sieve(int number)
{
	const int SIZE = 10000;
	int prime_number[SIZE];

	for (int i = 1; i < number; ++i)
	{
		prime_number[i] = i;
	}

	for (int i = 0; i < SIZE; ++i)
	{
		for (int n = 2; n < number; ++n)
		{
			if (prime_number[i] == n)
			{
				continue;
			}

			if (prime_number[i] % n == 0)
			{
				prime_number[i] = 0;
			}
		}
	}

	for (int i = 1; true; ++i)
	{
		if (prime_number[SIZE - i] != 0)
		{
			return prime_number[SIZE - i];
		}
	}
}

//Функция находит число с наибольшим количеством нулей в двоичной записи
int find_prime_number(int pow_two, int number, int prime_number)
{
	if (prime_number - pow_two <= number - pow_two)
	{
		return prime_number;
	}
	else
	{
		return number;
	}
}

int main()
{
	cout << "Write number:" << endl;
	int number; cin >> number;

	int simpleNumber = find_prime_num_eratosth_sieve(number);
	int powTwo = find_pow_two(number);

	cout << "Number whith max 0:" << endl;
	cout << find_prime_number(powTwo, number, simpleNumber) << endl;
}
