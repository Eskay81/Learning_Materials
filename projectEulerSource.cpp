//
//
//
//
//
//
//

#define PROBLEM_NO 3

#include <iostream>

using namespace std;

void main()
{
	if (PROBLEM_NO == 1) // 25 May 2018
	{
		cout << "Problem 1 : Find the sum of all the multiples of 3 or 5 below 1000" << endl;
		long int sum = 0;
		for (int i = 0; i < 1000; i++)
		{
			if (i % 3 == 0 || i % 5 == 0)
			{
				sum = sum + i;
			}
		}
		cout << "Solution to Problem 1 : " << sum << endl;
	}
	else if (PROBLEM_NO == 2) // 25 May 2018
	{
		cout << "By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms" << endl;
		unsigned long int sum = 0, first=0, second=1, third=1, temp=0;
		while (third < 4000000)
		{
			if (third%2 == 0)
			{
				sum = sum + third;
			}
			temp = third + second;
			first = second;
			second = third;
			third = temp;
		}
		cout << "Solution to Problem 2 : " << sum << endl;
	}
	else if (PROBLEM_NO == 3) // 25 May 2018
	{
		cout << "What is the largest prime factor of the number 600851475143 ?" << endl;
		unsigned long long int num = 600851475143 , divisor = 600851475143/2;
		while (num%divisor != 0)
		{
			divisor--;
			cout << divisor<< endl;
		}
		cout << "Solution to Problem 3 : " << divisor << endl;
	}

}