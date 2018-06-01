//
//
//
//
//
//
//

#define PROBLEM_NO 4

#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

void main()
{
	std::chrono::steady_clock::time_point start_time, end_time;
	
	int problem_no;
	cout << "Enter the problem number : ";
	cin >> problem_no;

	start_time = std::chrono::steady_clock::now();
	switch (problem_no)
	{
	case(1):// 25 May 2018
	{
		cout << "1. Problem 1 : Find the sum of all the multiples of 3 or 5 below 1000" << endl;
		long int sum = 0;

		for (int i = 0; i < 1000; i++)
		{
			if (i % 3 == 0 || i % 5 == 0)
			{
				sum = sum + i;
			}
		}
		cout << "Solution to Problem 1 : " << sum << endl;
		break;
	}
	case(2)://25 May 2018
		{
			cout << "2 .By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms" << endl;
			unsigned long int sum = 0, first = 0, second = 1, third = 1, temp = 0;
			while (third < 4000000)
			{
				if (third % 2 == 0)
				{
					sum = sum + third;
				}
				temp = third + second;
				first = second;
				second = third;
				third = temp;
			}
			cout << "Solution to Problem 2 : " << sum << endl;
			break;
		}
	case(3):// 29 May 2018
	{
		cout << "3. What is the largest prime factor of the number 600851475143 ?" << endl;
		unsigned long long int num = 600851475143, divisor = 2;
		vector<long int> prime_factors;
		vector<long int>::iterator iter;
		prime_factors.reserve(10);

		for (divisor = 2; divisor < num / 2; divisor++)
		{
			if (num%divisor == 0)
			{
				prime_factors.push_back(divisor);
				//cout << "divisor : " << divisor << endl;
				num = num / divisor;
				//cout << "num " << num << endl;
				divisor = 2;
			}
		}
		iter = prime_factors.end() - 1;
		cout << "Solution to Problem 3 : " << num << endl;
		break;
	}
	case(4):// 29May 2018
	{
		int largest_num = 0;
		cout << "4. Find the largest palindrome made from the product of two 3 - digit numbers." << endl;
		for (int i = 999; i > 100; i--)
			for (int j = 999; j > 100; j--)
			{
				string s = to_string(i*j);
				if ((s[0] == s[5]) && (s[1] == s[4]) && (s[2] == s[3]))
				{
					if ((largest_num == 0) || (largest_num < i*j))
					{
						largest_num = i*j;
					}
				}
			}
		cout << "Solution to Problem 4 : " << largest_num << endl;
		break;
	}
	case(5):// 30 May 2018
	{
		cout << "5. What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?" << endl;
		int MAX_NUM = 20;
		vector<int> num_vec;
		num_vec.reserve(MAX_NUM);
		for (int i = 1; i <= MAX_NUM; i++)
			num_vec.push_back(i);

		int result = 1, divisor = 2;
		bool factor_found = false;

		while (divisor <= MAX_NUM)
		{
			for (int i = 0; i < MAX_NUM; i++)
			{
				if (num_vec.at(i) % divisor == 0)
				{
					num_vec.at(i) = num_vec.at(i) / divisor;
					factor_found = true;
				}
			}
			if (factor_found)
				result = result * divisor;
			else
				divisor++;
			factor_found = false;
		}
		cout << "Solution to Problem 5 : " << result << endl;
		break;
	}
	case(6): // 30 May 2018
	{
		cout << "6. Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum." << endl;
		int n = 100, result;
		result = n*n*(n + 1)*(n + 1) / 4 - (n * (n + 1)*(2 * n + 1)) / 6;
		cout << "Solution to Problem 6 : " << result << endl;
		break;
	}
	case(7): // 31 May 2018
	{
		cout << "7. What is the 10001st prime number?" << endl;
		const int NUM = 10001;
		long int prime_array[NUM] = { 2, 3, 5, 7, 11, 13, 17, 19 };
		int current_loc = 8; // 7 locations initialized
		long int current_num = prime_array[current_loc - 1] + 2;
		while (prime_array[NUM - 1] == 0)
		{
			for (int i = 1; i < current_loc; i++)
			{
				if (current_num%prime_array[i] == 0)
				{
					current_num = current_num + 2;
					break;
				}
				if ((i == current_loc - 1) && (current_num%prime_array[i] != 0))
				{
					prime_array[current_loc] = current_num;
					current_loc = current_loc + 1;
				}
			}
		}
		cout << "Solution to Problem 7 : " << prime_array[NUM-1] << endl;
		break;
	}
	case(8):// 31 May 2018
	{
		cout << "8. Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product? " << endl;
		char input_list[1001] = 
"73167176531330624919225119674426574742355349194934\
96983520312774506326239578318016984801869478851843\
85861560789112949495459501737958331952853208805511\
12540698747158523863050715693290963295227443043557\
66896648950445244523161731856403098711121722383113\
62229893423380308135336276614282806444486645238749\
30358907296290491560440772390713810515859307960866\
70172427121883998797908792274921901699720888093776\
65727333001053367881220235421809751254540594752243\
52584907711670556013604839586446706324415722155397\
53697817977846174064955149290862569321978468622482\
83972241375657056057490261407972968652414535100474\
82166370484403199890008895243450658541227588666881\
16427171479924442928230863465674813919123162824586\
17866458359124566529476545682848912883142607690042\
24219022671055626321111109370544217506941658960408\
07198403850962455444362981230987879927244284909188\
84580156166097919133875499200524063689912560717606\
05886116467109405077541002256983155200055935729725\
71636269561882670428252483600823257530420752963450";
		unsigned long long int result= 1;
		for (int i = 0; i <= 1000-13; i++)
		{
			unsigned long long int temp_result = 1;

			for (int j = 0; j < 13; j++)
				temp_result = temp_result * (unsigned long long int)(input_list[i + j] - 48);
			
			if (temp_result > result)
				result = temp_result;
		}
		cout << "Solution to Problem 8 : " << result << endl;
		break;
	}
	case(9):// 31 May 2018
	{
		cout << "9. There exists exactly one Pythagorean triplet for which a + b + c = 1000. \n   Find the product abc." << endl;
		int result = 1;
		bool found = false;
		for(int a=1; a < 997; a++)
			for(int b=1;b < 997; b++)
				for (int c = 997; c >= 1 ; c--)
				{
					if ((a + b + c == 1000) && (c*c == a*a + b*b))
					{
						//cout << a << "\t" << b << "\t" << c << endl;
						result = a*b*c;
						found = true;
						break;
					}
					if (found)
						break;
				}
		cout << "Solution to Problem 9 : " << result << endl;
		break;
	}
	case(10):// 31 May 2018
	{
		cout << "10. Find the sum of all the primes below two million." << endl;
		const unsigned int NUM = 200000;
		long int prime_array[NUM] = { 2, 3, 5, 7, 11, 13, 17, 19 };
		int current_loc = 8; // 7 locations initialized
		long int current_num = prime_array[current_loc - 1] + 2;
		bool num_exceeded = false;
		unsigned long long result=0;
		while (prime_array[NUM - 1] == 0)
		{
			for (int i = 1; i < current_loc; i++)
			{
				if (current_num%prime_array[i] == 0)
				{
					current_num = current_num + 2;
					break;
				}
				if ((i == current_loc - 1) && (current_num%prime_array[i] != 0))
				{
					prime_array[current_loc] = current_num;
					current_loc = current_loc + 1;
				}
				if (current_num > 2000000)
				{
					num_exceeded = true;
					break;
				}
			}
			if (num_exceeded)
				break;
		}
		for (int i = 0; i < current_loc; i++)
			result = result + prime_array[i];

		cout << "Solution to Problem 10 : " << result << endl;
		break;
	}
	case(11): // 01 June 2018
	{
		cout << "11. What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20x20 grid?" << endl;
		int input_array[20][20] = { 
		{  8, 2,22,97,38,15, 0,40, 0,75, 4, 5, 7,78,52,12,50,77,91, 8 },
		{ 49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48, 4,56,62, 0 },
		{ 81,49,31,73,55,79,14,29,93,71,40,67,53,88,30, 3,49,13,36,65 },
		{ 52,70,95,23, 4,60,11,42,69,24,68,56, 1,32,56,71,37, 2,36,91 },
		{ 22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80 },
		{ 24,47,32,60,99, 3,45, 2,44,75,33,53,78,36,84,20,35,17,12,50 },
		{ 32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70 },
		{ 67,26,20,68, 2,62,12,20,95,63,94,39,63, 8,40,91,66,49,94,21 },
		{ 24,55,58, 5,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72 },
		{ 21,36,23, 9,75, 0,76,44,20,45,35,14, 0,61,33,97,34,31,33,95 },
		{ 78,17,53,28,22,75,31,67,15,94, 3,80, 4,62,16,14, 9,53,56,92 },
		{ 16,39, 5,42,96,35,31,47,55,58,88,24, 0,17,54,24,36,29,85,57 },
		{ 86,56, 0,48,35,71,89, 7, 5,44,44,37,44,60,21,58,51,54,17,58 },
		{ 19,80,81,68, 5,94,47,69,28,73,92,13,86,52,17,77, 4,89,55,40 },
		{ 04,52, 8,83,97,35,99,16, 7,97,57,32,16,26,26,79,33,27,98,66 },
		{ 88,36,68,87,57,62,20,72, 3,46,33,67,46,55,12,32,63,93,53,69 },
		{ 04,42,16,73,38,25,39,11,24,94,72,18, 8,46,29,32,40,62,76,36 },
		{ 20,69,36,41,72,30,23,88,34,62,99,69,82,67,59,85,74, 4,36,16 },
		{ 20,73,35,29,78,31,90, 1,74,31,49,71,48,86,81,16,23,57, 5,54 },
		{ 01,70,54,71,83,51,54,69,16,92,33,48,61,43,52, 1,89,19,67,48 } };
		long int result = 0;
		for(int row = 0 ; row < 20-4; row++)
			for (int col = 0; col < 20; col++)
			{
				long int temp_result = 0;
				if (col < 17)
				{
					//-45 deg
					temp_result = input_array[row][col] * input_array[row+1][col+1] * input_array[row+2][col+2] * input_array[row+3][col+3];
					if (temp_result > result)
						result = temp_result;
					// 0 deg
					temp_result = input_array[row][col] * input_array[row][col + 1] * input_array[row][col + 2] * input_array[row][col + 3];
					if (temp_result > result)
						result = temp_result;
				}
				if (col > 2)
				{
					//-180 deg
					temp_result = input_array[row][col] * input_array[row][col - 1] * input_array[row][col - 2] * input_array[row][col - 3];
					if (temp_result > result)
						result = temp_result;
					// -135 deg
					temp_result = input_array[row][col] * input_array[row+1][col - 1] * input_array[row+2][col - 2] * input_array[row+3][col - 3];
					if (temp_result > result)
						result = temp_result;
				}
				// -90 deg
				temp_result = input_array[row][col] * input_array[row+1][col] * input_array[row+2][col] * input_array[row + 3][col];
				if (temp_result > result)
					result = temp_result;
			}
		cout << "Solution to Problem 11 : " << result << endl;
		break;
	}
	case(12):
	{
		cout << "12. What is the value of the first triangle number to have over five hundred divisors ? " << endl;
		bool num_found = false;
		long int i = 10;
		long int j;
		int count = 0;
		while (!num_found)
		{
			j = int(i*(i + 1) / 2);
			for (int k = 1; k <= j; k++)
			{
				if (j%k == 0)
				{
					count++;
					if (count > 500)
					{
						num_found = true;
						break;
					}
				}
			}
			//cout << i << "\t" << count << endl;
			count = 0;
			i++;
		}
		cout << "Solution to Problem 12 : " <<  i-1 << "\t" << j << endl;
		break;
	}
	default:
		cout << "Yet to be written " << endl;
	}
	end_time = std::chrono::steady_clock::now();
	int64_t elapsed_time;
	elapsed_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
	if (elapsed_time < 1000)
		cout << "Elapsed time : " << elapsed_time << " micro Seconds." << endl;
	else if (elapsed_time >= 1000 && elapsed_time < 1000000)
		cout << "Elapsed time : " << elapsed_time/1000 << " milli Seconds and " << elapsed_time%1000 << " micro Seconds" << endl;
	else if(elapsed_time >= 1000000)
		cout << "Elapsed time : " << elapsed_time / 1000000 << " Seconds and " << (elapsed_time % 1000000)/1000 << " milli Seconds " << (elapsed_time % 1000000) % 1000  << " micro Seconds"<< endl;
}