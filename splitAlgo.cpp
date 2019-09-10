bool checker(int* arr, int n,int sumA, int sumB) 
{ 
    if (n==0) 
        return sumA == sumB;
    if (arr[0] % 5 == 0) 
        sumA += arr[0];  
    else if (arr[0] % 3 == 0) 
        sumB += arr[0];  
    else
        return checker(arr+1, n-1, sumA + arr[0], sumB) || checker(arr+1, n-1, sumA, sumB + arr[0]); 
    return checker(arr+1, n-1, sumA, sumB); 
} 
bool splitArray(int *input, int size) 
{
       checker(input , size , 0 , 0 );
}
