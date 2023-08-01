#include<bits/stdc++.h>
using namespace std;
//Creation of Class Student.
class Student{
    public:
    string roll;
    float cgpa;
    string name;
    Student(){
        roll="";
        cgpa = 0;
        name = "";
    }
    Student(string r, float c, string n){
        this->cgpa = c;
        this->name = n;
        this->roll = r;
    }
};
bool condition(Student s1,Student s2){
    return (s1.name<s2.name || 
    (s1.name == s2.name && s1.cgpa>s2.cgpa) || 
    (s1.name==s2.name && s1.cgpa == s2.cgpa && s1.roll<s2.roll));
}
int main()
{
    //To fetch the data from file input.txt
    ifstream inpt;
    inpt.open("input.txt");
    //To write the data into output.txt after sorting.
    ofstream outpt;
    outpt.open("output.txt");
    int n;
    inpt>>n;
    Student data[n];
    for(int i=0;i<n;i++){
        string roll_number;
        float cgpa;
        string name;
        inpt>>roll_number;
        inpt>>cgpa;
        getline(inpt,name);
        Student s(roll_number, cgpa,name);
        data[i] = s;
    }
    //Sorting the records of file input.txt based on Student Name to file output.txt
    sort(data,data + n,condition);
    for(int i=0;i<n;i++){
        outpt<<data[i].name<<" "<<data[i].cgpa<<" "<<data[i].roll<<endl;
    }
}