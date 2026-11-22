#include<iostream>
#include<fstream>
using namespace std;
class Student
{
    int rollno;
    char name[20];
    int age;
public:
    void accept()
    {
        cout<<"Enter Roll number: ";
        cin>>rollno;
        cout<<"Enter Name: ";
        cin.ignore();
        cin.getline(name, 20);
        cout<<"Enter Age: ";
        cin>>age;
    }
    void display()
    {
        cout<<"Roll number: "<<rollno<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};
int main()
{
    Student s;
    ofstream fout;
    fout.open("student.txt", ios::binary|ios::app);
    s.accept();
    fout.write((char*)&s,sizeof(s));
    fout.close();
    ifstream fin;
    fin.open("student.txt",ios::binary);
    cout<<"\n---- Displaying Details ----" << endl;
    while(fin.read((char*)&s,sizeof(s)))
    {
        s.display();
    }
    fin.close();
    return 0;
}
