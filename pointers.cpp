// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <limits>
using namespace std;

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(string message, int min, int max);

double promptDouble(string message, double min, double max);

void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv) {
    Student student;
    double average;

    // Prompt for the student's ID number (between 0 and 9 digits long)
    int id = promptInt("Please enter the student's id number: ", 0, 999999999);
    student.id = id;

    // Prompt for the student's first name, then set the char pointer to the string's address
    string firstname;
    cout << "Please enter the student's first name: ";
    getline(cin,firstname);
    cin.ignore();
    student.f_name = &firstname[0];

    // Prompt for the student's last name, then set the char pointer to the string's address
    string lastname;
    cout << "Please enter the student's last name: ";
    getline(cin,lastname);
    cin.ignore();
    student.l_name = &lastname[0];

    // Prompt for the number of assignments
    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 0, 134217728);

    // Array of doubles to store the assignment grades
    double grades[student.n_assignments];

    // Get the grades of all the assignments one by one
    for(int i = 1; i < student.n_assignments; i++) {
        string msg = "Please enter the grade for assignment: ";
        grades[i] = promptDouble(msg, 0, 1000.0);
    }

    double finalGrade;

    //calculateStudentAverage(&grades, &finalGrade)

    //cout << "Student " << student.firstname << " " << student.lastname << "[" << student.id << "]" << endl;
    
    //cout <<

    // Sequence of user input -> store in fields of `student`

    // Call `CalculateStudentAverage(???, ???)`
    // Output `average`

    return 0;
}

/*
   Prompts the user to enter an int between two defined values.
    message: text to output as the prompt
    min: minimum value to accept as a valid int
    max: maximum value to accept as a valid int
*/
int promptInt(string message, int min, int max) {
    // The number entered by the user
    int input;

    // Handles inappropriate types by clearing the cin buffer if cin returns false and then reprompting
    while(cout << message && (!(cin >> input) || input < min || input > max)) { 
        cout << "Sorry, I cannot understand your answer \n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return input;
}

/* // Code to prompt user for a double
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(string message, double min, double max) {
    // The number entered by the user
    double input;

    while(cout << message && (!(cin >> input) || input < min || input > max)) { 
        cout << "Sorry, I cannot understand your answer \n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return input;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg) {
    // Code to calculate and store average grade
    for(int i = 0; i < 10; i++) {

    }
}
