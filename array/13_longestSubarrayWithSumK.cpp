#include <iostream>
#include <unordered_map>

using namespace std;

int longestSubarrayWithSumKBrute(int a[], int n, int K)
{
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if(sum == K) len = (j-i+1)>len?(j-i+1):len;
        }
        
    }
    return len;
}

int longestSubarrayWithSumK(int a[], int n, int K)
{
    int left = 0;
    int right = 0;
    int maxLen = 0;
    int sum = a[0];
    while (right < n)
    {
        while (left <= right && sum > K)
        {
            sum-=a[left];
            left++;
        }

        if(sum == K)
        {
            maxLen = max(maxLen, right-left+1);
        }
        right++;
        if(right<n) sum += a[right];
        
    }

    return maxLen;
    
}

int longestSubarrayWithSumKNegatives(int a[], int n, int k)
{

    unordered_map<int, int> mp;

    int longestLen = 0;
    int prefixSum  = 0;


    for (int i = 0; i < n; i++)
    {

        prefixSum += a[i];

        if(prefixSum == k)
        {
            longestLen = i+1;
   

        }

        if(mp.find(prefixSum - k) != mp.end())
        {
            if(i - mp[prefixSum - k] > longestLen)
            {
                longestLen = i - mp[prefixSum-k];
            }
     
        }

        if(mp.find(prefixSum) == mp.end())
        {
            mp[prefixSum] = i;
        }
            
        
    }
    
    return longestLen;

}


int TotalSubarraySumEqualsK(int a[], int n, int k)
{

    unordered_map<int, int> mp;

    int longestLen = 0;
    int prefixSum  = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {

        prefixSum += a[i];

        if(prefixSum == k)
        {
            count++;
        }

        if(mp.find(prefixSum - k) != mp.end())
        {
            count += mp[prefixSum - k];
        }

        mp[prefixSum]++;
    }
    return count;
}
int TotalSubarraySumEqualsK2(int a[], int n, int k)
{

    unordered_map<int, int> mp;


    int prefixSum  = 0;
    int count = 0;
    mp[0] = 1;

    for (int i = 0; i < n; i++)
    {

        prefixSum += a[i];

        count += mp[prefixSum - k];

        mp[prefixSum]++;
    }
    return count;
}



int main()
{
    int a[10] = {10, 5, 2, 7, 1, 10};
    int b[10] = {10, 5, 2, 7, 1, -10};
    cout << longestSubarrayWithSumKBrute(a, 6, 15) << '\n';
    cout << longestSubarrayWithSumK(a, 6, 15) << '\n';
    cout << longestSubarrayWithSumKNegatives(b, 6, 15) << '\n';

    int c[10] = {1,2,3,-3,1,1,1};
    cout << TotalSubarraySumEqualsK2(c, 7, 3) << '\n';
    return 0;
}