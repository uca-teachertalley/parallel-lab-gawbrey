/*-- prime_count_serial.cpp-----------------------------------------------------------
   This file implements a program that fills an arry with numbers and 
   then counts the prime numbers in the array
-------------------------------------------------------------------------*/

#include <iostream>
#include <chrono>
#include <cmath>
#include <omp.h> //add the OpenMP include to the top of your main
using namespace std;

// gen_numbers
// This function adds numbers to an array
void gen_numbers(long int numbers[], long int how_many)
{
	#pragma omp parallel for // PARALLELIZE - for question 5
	for (int i = 0; i < how_many; i++)
	{
		numbers[i] = i;
	}
}

// This function determines if a number is a prime number
bool is_prime(long int n)
{
	if (n < 2)
		return false;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

// This function walks through an array and counts the prime numbers
int count_prime_serial(long int numbers[], long int how_many)
{
	int count = 0;
	for (int i = 0; i < how_many; i++)
	{
		if (is_prime(numbers[i]))
			count++;
	}
	return count;
}

// COPY OF COUNT_PRIME_SERIAL FUNCTION
int count_prime_parallel(long int numbers[], long int how_many)
{
	int count = 0;

#pragma omp parallel
	{
		int thread_id = omp_get_thread_num();
		int total_threads = omp_get_num_threads();

#pragma omp single
		{
			cout << "Number of threads: " << total_threads << endl;
		}

#pragma omp for reduction(+:count)
		for (int i = 0; i < how_many; i++)
		{
			if (is_prime(numbers[i]))
				count++;
		}
	}
	return count;
}

// This is the entrypoint into the program
int main() {
	long int n = 1000000;
	long int* numbers = new long int[n];
	
	cout << "Generating numbers..." << endl;
	// Generate numbers first
	gen_numbers(numbers, n);

	cout << "Counting primes..." << endl;
	// Count primes, use chrono to time the function
	auto start = chrono::steady_clock::now();
	int count = count_prime_serial(numbers, n);
	auto end = chrono::steady_clock::now();

	// Print results
	double compute_time = chrono::duration<double>(end - start).count();
	cout << "Total number of primes = " << count << endl;
	cout << "Total computation time = " << compute_time << endl << endl;
	auto start_gen = chrono::steady_clock::now();
	gen_numbers(numbers, n);
	auto end_gen = chrono::steady_clock::now();
	double gen_time = chrono::duration<double>(end_gen - start_gen).count();
	cout << "Time to generate numbers = " << gen_time << " seconds" << endl;

    return 0;
}





