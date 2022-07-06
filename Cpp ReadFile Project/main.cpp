#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class studentInformation{
    string id; 
    string firstName;
    string lastName; 
    string major; 
    double gpa; 
    string enrolled;
    double tuition;
public: 
    static vector <studentInformation> ClassData; 
    studentInformation(
    string Id, 
    string FirstName,
    string LastName,
    string Major,
    double Gpa,
    string Enrolled,
    double Tuition
    ) {
        id = Id;
        firstName = FirstName; 
        lastName = LastName;
        major = Major; 
        gpa = Gpa; 
        enrolled = Enrolled; 
        tuition = Tuition;
    }
    void displayInformation(){
        cout<<"Student ID: "<< id<<endl;
        cout<<"Full Name: "<< firstName<<" "<< lastName<<endl;
        cout<<"Major: "<< major<<endl;
        cout<<"GPA: "<< gpa<<endl;
        cout<<"Currently Enrolled: "<< enrolled<<endl;
        cout<<"Tuition Due: "<< tuition<<endl;
    }
    void static displayDirectory(){
        for (auto student : studentInformation:: ClassData){
        
        student.displayInformation();
        cout<<"-------------------------------------------------"<<endl;
    }
    }
    void addStudent(string num, string fname, string lname, string mjor, double pa, string enrollment, double fees){
        studentInformation student(num, fname, lname, mjor, pa,enrollment, fees );
        ClassData.push_back(student);
    }
};
vector <studentInformation> studentInformation:: ClassData;
int main(){
    ifstream allStudents;

    allStudents.open("StudentUniversityData.csv");
    if (allStudents.fail()){
        cerr << "Unable to open file"<< " StudentUniversityData.csv" <<endl;
        return 1;
    }
 
    vector <studentInformation> studentsData; 
    string line = ""; 
    //skip first line
    getline(allStudents, line);
    while(getline(allStudents, line)){
    string id; 
    string firstName;
    string lastName; 
    string major; 
    double gpa; 
    string enrolled;
    double tuition;
    string temporary = ""; 

    stringstream inputString(line);
    getline(inputString, id, ',');
    getline(inputString, firstName, ',');
    getline(inputString, lastName, ',');
    getline(inputString, major, ',');
    //get gpa as string line and then convert it to double
    getline(inputString, temporary, ',');
    gpa = atof(temporary.c_str());
    getline(inputString, enrolled, ',');
    temporary = "";
    getline(inputString, temporary, ',');
    tuition = atof(temporary.c_str());
    line ="";

    studentInformation student(id, firstName, lastName, major, gpa, enrolled, tuition);
    studentsData.push_back(student);
    studentInformation::ClassData.push_back(student);
    }
    for (auto student : studentsData){
        cout<<"-------------------------------------------------"<<endl;
        student.displayInformation();
        cout<<"-------------------------------------------------"<<endl;

    }
    string id; 
    string firstname;
    string lastname; 
    string stuMajor; 
    double gradePointAverage; 
    string enrolledconfirm;
    double tuitionFees;

    cout<< "Add a student:"<<endl;
    cout<< "ID:";
    cin>> id; 
    cout<< "First Name:";
    cin>>firstname; 
    cout<< "Last Name:";
    cin>>lastname;
    cout<< "Major:";
    cin>> stuMajor;
    cout<< "GPA:";
    cin>> gradePointAverage;
    cout<< "Enrolled for next quarter?";
    cin>> enrolledconfirm;
    cout<< "Tuition fees:";
    cin>> tuitionFees;
    studentInformation somerandomstudent(id,firstname,lastname,stuMajor, gradePointAverage, enrolledconfirm, tuitionFees);
    somerandomstudent.addStudent(id,firstname,lastname,stuMajor, gradePointAverage, enrolledconfirm, tuitionFees);
    cout<<"-------------------Directory---------------------"<<endl;
    studentInformation::displayDirectory();
    return 0;
}