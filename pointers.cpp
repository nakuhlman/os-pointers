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

int promptInt(std::string message, int min, int max);
//double promptDouble(std::string message, double min, double max);
//void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv) {
    Student student;
    double average;

    // Prompting for the student's ID number (between 0 and 9 digits long)
    int id = promptInt("Please enter the student's id number: ", 0, 999999999);
    student.id = id;

    // Prompting for the student's first name
    string firstname;
    cout << "Please enter the student's first name: ";
    getline(cin,firstname);
    cin.ignore();
    student.f_name = firstname;

    // Prompting for the student's last name
    string lastname;
    cout << "Please enter the student's last name: ";
    getline(cin,lastname);
    cin.ignore();

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

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
//double promptDouble(std::string message, double min, double max)
//{
    // Code to prompt user for a double
//}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
//void calculateStudentAverage(void *object, double *avg)
//{
    // Code to calculate and store average grade
//}
