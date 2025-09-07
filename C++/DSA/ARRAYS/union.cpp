#include <bits/stdc++.h>
using namespace std;
vector<int> findUnion(vector<int>& v1,vector<int>& v2) {
    set<int> unionSet;
    for (int num : v1) {
        unionSet.insert(num);
    }
    for (int num : v2) {
        unionSet.insert(num);
    }
    vector<int> unionVec(unionSet.begin(), unionSet.end());
    return unionVec;
}

int main() {
    vector<int> vec1 = {1, 2, 3, 4, 5};
    vector<int> vec2 = {4, 5, 6, 7, 8};
    vector<int> unionResult = findUnion(vec1, vec2);
    cout << "Union of the two vectors: ";
    for (int num : unionResult) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
