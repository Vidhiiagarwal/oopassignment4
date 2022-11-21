#include <iostream>
#include <string.h>
using namespace std;

class Student
{
    public:
    string name;
    int roll;
    string branch;
    string sec;
    void getdata()
    {
        cout<<"\nEnter the name of the student:";
        cin>>name;
        cout<<"\nEnter the roll number:";
        cin>>roll;
        cout<<"\nEnter the branch of the student:";
        cin>>branch;
        cout<<"\nEnter section:";
        cin>>sec;
    }
    void display()
    {
        cout<<"\nName: "<<name;
        cout<<"\nRoll number: "<<roll;
        cout<<"\nBranch: "<<branch;
        cout<<"\nSection:"<<sec;
    }
};

class InternalExam:virtual public Student
{
    public:
    int internal_marks=0;
    void imarks()
    {
        int arr[5];
        cout<<"\nEnter the internal marks of 5 subjects(out of 30):";
        for(int i=0;i<5;i++)
        {
            cin>>arr[i];
            internal_marks+=arr[i];
        }
    }    
};

class Midexam:virtual public Student
{
    public:
    int mid_marks=0;
    void mmarks()
    {
        int arr[5];
        cout<<"\nEnter the mid semester marks of 5 subjects(out of 20):";
        for (int i=0;i<5; i++)
        {
            cin>>arr[i];
            mid_marks+=arr[i];
        }
    }
};

class Endexam:virtual public Student,virtual public InternalExam,virtual public Midexam
{
    public:
    int end_marks=0;
    void emarks()
    {
        int arr[5];
        cout<<"\nEnter the end semester marks of 5 subjects(out of 50):";
        for (int i=0;i<5;i++)
        {
            cin>>arr[i];
            end_marks+=arr[i];
        }
    }
};

class Result
{
    public:
    void calculate()
    {
        Endexam s1;
        s1.Student::getdata();
        s1.InternalExam::imarks();
        s1.Midexam::mmarks();
        s1.Endexam::emarks();
        s1.Student::display();
        int sum=0;
        sum = s1.InternalExam::internal_marks + s1.Midexam::mid_marks + s1.Endexam::end_marks;
        cout<<"\nTotal marks:"<<sum;
        int per;
        per = sum/5;
        cout<<"\nPercentage:"<<per<<"%";   
    }
};

int main()
{
    Result std1;
    std1.calculate();
    return 0;
}
