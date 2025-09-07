#include<stdio.h>
struct Student{
    char id[50];
    char name[50];
    int year;
    float cgpa;
};
void stgrades(struct Student *ptr,int index);


int main(){
    int stnum;
    struct Student student[5]={
        {"24CP035","Uday",1,8.9},
        {"24CP042","Jani",1,9.8},
    };
    printf("Whats student's Grade do you wanna modify?");
    scanf("%d",&stnum);
    struct Student *ptr= student;
    printf("\n%s ID %s from year %d has cgpa:%f ",student[0].name,student[0].id,student[0].year,student[0].cgpa);
    stgrades(ptr,stnum-1);
    printf("\n%s ID %s from year %d has cgpa:%f ",student[stnum-1].name,student[stnum-1].id,student[stnum-1].year,student[stnum-1].cgpa);
}
void stgrades(struct Student *ptr,int index){
    ptr+=index;
    ptr->cgpa=7.9;
    printf("\n%s ID %s from year %d has cgpa:%f ",ptr->name,ptr->id,ptr->year,ptr->cgpa);
}