#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool possibleAllocation(vector<int>& books,int num_students,int pages) {
        int count_students=1;
        int sum=0;
        for (int i=0;i<books.size();i++) {
            if (books[i] > pages) return false;
            if (sum+books[i]>pages) {
                count_students++;
                sum=books[i];
            } else {
                sum+=books[i];
            }
        }
        return count_students<=num_students;
    }
public:
    int findPages(vector<int>& books,int num_students) {
        if (books.size()<num_students) return -1;
        int low= *max_element(books.begin(),books.end());
        int high=accumulate(books.begin(),books.end(), 0);
        int result=-1;
        while (low<=high) {
            int mid=low + (high - low)/2;
            if(possibleAllocation(books,num_students,mid)){
                result=mid;
                high=mid - 1;
            } 
            else low=mid + 1;
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<int> books = {12, 34, 67, 90};
    cout << "Min pages allocated= " << sol.findPages(books, 2);
    return 0;
}
