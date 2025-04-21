Prime number count parallelism exercise - GABE AWBREY 4/21/2025

- This code counts the number of primes in an array without parallelism
- Your goal is to add parallelism with OpenMP!
- The project should be configured properly, but you can add OpenMP to 
  Visual Studio project by going to Project Properties-C/C++-Language.
  Set the Open MP Support option to "Yes"


SERIAL COUNT RESULT
Generating numbers...
Counting primes...
Total number of primes = 78498
Total computation time = 0.802318


PARALLEL COUNT RESULT (BEFORE REDUCTION(+:COUNT))
Generating numbers...
Counting primes...
Total number of primes = 78357
Total computation time = 0.237227


PARALLEL COUNT RESULT (AFTER REDUCTION(+:COUNT))
Generating numbers...
Counting primes...
Total number of primes = 78498
Total computation time = 0.227299


1. Average of 10 runs of serial version: 0.7660244


2. Average of 10 runs of parallel version: 0.2094459


3. (using 0.802318 & 0.227299) 71.67% increase


4. Number of threads: 16 (coded it inside of the program to find the exact #)


5. It was not faster. To be honest, it went even slower. I think it's because the workload is too light and the loop iteration was too trivial.				
	Time to generate numbers (serial count):   0.0010434
	Time to generate numbers (parallel count): 0.0012743