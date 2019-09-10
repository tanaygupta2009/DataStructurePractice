// C++ program to print print all primes smaller than 
// n using segmented sieve 
#include <bits/stdc++.h> 
using namespace std; 

// This functions finds all primes smaller than 'limit' 
// using simple sieve of eratosthenes. It also stores 
// found primes in vector prime[] 
void simpleSieve(long long limit, vector<long long int> &prime) 
{ 
	// Create a boolean array "mark[0..n-1]" and initialize 
	// all entries of it as true. A value in mark[p] will 
	// finally be false if 'p' is Not a prime, else true. 
	bool mark[limit+1]; 
	memset(mark, true, sizeof(mark)); 

	for (long long int p=2; p*p<limit; p++) 
	{ 
		// If p is not changed, then it is a prime 
		if (mark[p] == true) 
		{ 
			// Update all multiples of p 
			for (long long int i=p*2; i<limit; i+=p) 
				mark[i] = false; 
		} 
	} 

	// Print all prime numbers and store them in prime 
	/*
  for (int p=2; p<limit; p++) 
	{ 
		if (mark[p] == true) 
		{ 
			prime.push_back(p); 
			cout << p << " "; 
		} 
	} 
    */
} 

// Prints all prime numbers smaller than 'n' 
void segmentedSieve(long long int n) 
{ 
	// Compute all primes smaller than or equal 
	// to square root of n using simple sieve 
	long long int limit = floor(sqrt(n))+1; 
	vector<long long int> prime; 
	simpleSieve(limit, prime); 

	// Divide the range [0..n-1] in different segments 
	// We have chosen segment size as sqrt(n). 
	long long int low = limit; 
	long long int high = 2*limit; 

	// While all segments of range [0..n-1] are not processed, 
	// process one segment at a time 
	while (low < n) 
	{ 
		if (high >= n) 
		high = n; 
		
		// To mark primes in current range. A value in mark[i] 
		// will finally be false if 'i-low' is Not a prime, 
		// else true. 
		bool mark[limit+1]; 
		memset(mark, true, sizeof(mark)); 

		// Use the found primes by simpleSieve() to find 
		// primes in current range 
		for (long long int i = 0; i < prime.size(); i++) 
		{ 
			// Find the minimum number in [low..high] that is 
			// a multiple of prime[i] (divisible by prime[i]) 
			// For example, if low is 31 and prime[i] is 3, 
			// we start with 33. 
			long long int loLim = floor(low/prime[i]) * prime[i]; 
			if (loLim < low) 
				loLim += prime[i]; 

			/* Mark multiples of prime[i] in [low..high]: 
				We are marking j - low for j, i.e. each number 
				in range [low, high] is mapped to [0, high-low] 
				so if range is [50, 100] marking 50 corresponds 
				to marking 0, marking 51 corresponds to 1 and 
				so on. In this way we need to allocate space only 
				for range */
			for (long long int j=loLim; j<high; j+=prime[i]) 
				mark[j-low] = false; 
		} 

		// Numbers which are not marked as false are prime 
		//for (int i = low; i<high; i++) 
		//	if (mark[i - low] == true) 
		//		cout << i << " "; 

		// Update low and high for next segment 
		low = low + limit; 
		high = high + limit; 
	} 
} 

// Driver program to test above function 
int main() 
{ 
	long long int n = 1000000000; 
	//cout << "Primes smaller than " << n << ": ";
  clock_t start, end;	
  start = clock(); 
	segmentedSieve(n);
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl;
	return 0; 
} 
