/* #include <iostream>
using namespace std;

class Student{
    private:
        int age;
        string name;
        int id;
    
    public:
    
    void setAge(int age){
        this->age = age;
    }

    int getAge(){
        return age;
    }

    void setname(string name){
        this->name = name;
    }
    string getName(){
        return name;
    }

    void setid(int id){
        this->id = id;
    }
    int getid(){
        return id;
    }
    
};

int main(){
    
    Student s1,s2,s3;

    s1.setAge(18);
    s1.setname("Arman singh");
    s1.setid(126);
    s2.setAge(20);
    s2.setname("divyansh");
    s2.setid(102);
    s3.setAge(24);
    s3.setname("manish");
    s3.setid(127);


    cout << s1.getAge() << s1.getName()<< s1.getid() <<endl;
    cout << s1.getAge() << s2.getName()<< s2.getid() <<endl;
    cout << s1.getAge() << s3.getName()<< s3.getid() <<endl;
    

    return 0;
} */

/* #include <iostream>
using namespace std;

class Student{
    public:
        int age;
        string name;
    
        Student(int age, string name){
            this->age = age;
            this->name = name;
        }
};

int main(){

    Student s1(20, "Arman");
    Student s2(22, "Shivani");
   

    cout << s1.age << " " << s1.name << endl;
    cout << s2.age << " " << s2.name << endl;
    

    return 0;
} */

#include <iostream>
using namespace std;

class Student{
    private:
        int rollno;
        string name;
    public:
        Student(int r, string n){
            rollno = r;
            name = n;
        }

        Student(const Student &s){
            rollno = s.rollno;
            name = s.name;
        }
        void display(){
            cout << rollno << name;
        }
};

int main(){

    Student s1(12, "arman");
    s1.display();

    Student s2 = s1;
    s2.display();

    return 0;
}