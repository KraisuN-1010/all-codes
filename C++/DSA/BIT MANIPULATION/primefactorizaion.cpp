#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<int>> primeFactors(vector<int>& queries){
            // Find maximum number to determine sieve size
            int maxNum = *max_element(queries.begin(), queries.end());
            
            // Precompute smallest prime factor for each number using sieve
            vector<int> smallestPrimeFactor(maxNum + 1);
            
            // Initialize: each number's smallest prime factor is itself
            for(int i = 0; i <= maxNum; i++) {
                smallestPrimeFactor[i] = i;
            }
            
            // Modified Sieve of Eratosthenes to find smallest prime factors
            for(int i = 2; i * i <= maxNum; i++) {
                if(smallestPrimeFactor[i] == i) { // i is prime
                    // Mark all multiples of i with i as their smallest prime factor
                    for(int j = i * i; j <= maxNum; j += i) {
                        if(smallestPrimeFactor[j] == j) {
                            smallestPrimeFactor[j] = i;
                        }
                    }
                }
            }
            
            vector<vector<int>> result;
            
            // Process each query
            for(int num : queries) {
                vector<int> factors;
                
                // Extract prime factors using precomputed smallest prime factors
                while(num > 1) {
                    int primeFactor = smallestPrimeFactor[num];
                    factors.push_back(primeFactor);
                    num /= primeFactor;
                }
                
                result.push_back(factors);
            }
            
            return result;
        }
};

int main(){
    vector<int> queries = {2,3,4,5,6};
    Solution sol;
    vector<vector<int>> answer = sol.primeFactors(queries);
    cout << "{";
    for (auto it : answer) {
        cout << "{ ";
        for (auto nums : it) {
            cout << nums << " ";
        }
        cout << "}";
    }
    cout << "}";

}