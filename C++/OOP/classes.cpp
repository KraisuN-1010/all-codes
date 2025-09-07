#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    int id;
    float gpa;

    Student(){}

    Student(string name1, int id1, float gpa1) {
        name = name1;
        id = id1;
        gpa = gpa1;
    }
};

int main(){
    Student s1 = Student("uday", 35, 5);
    string a = "hello";
    string b = "world";
    cout << a + b;

    
}