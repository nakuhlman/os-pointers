// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
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
    int id = promptInt("\nPlease enter the student's id number: ", 0, 999999999);
    student.id = id;

    string firstname;
    cout << "Please enter the student's first name: ";
    getline(cin,firstname);
    // Convert the string to a const char *, then to a char * and assign to student's f_name field
    char * temp1 = const_cast<char*>(firstname.c_str());
    student.f_name = temp1;

    // Prompt for the student's last name, then set the char pointer to the string's address
    string lastname;
    cout << "Please enter the student's last name: ";
    getline(cin,lastname);
    
     // Convert the string to a const char *, then to a char * and assign to student's l_name field
    char * temp2 = const_cast<char*>(lastname.c_str());
    student.l_name = temp2;

    // Prompt for the number of assignments
    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 1, 134217728);
    cout << '\n';

    // Array of doubles to store the assignment grades, one extra spot for terminating character
    double grades[student.n_assignments + 1];

    // Get the grades of all the assignments one by one
    for(int i = 0; i < student.n_assignments; i++) {
        string msg = "Please enter the grade for assignment " + to_string(i) + ": ";
        grades[i] = promptDouble(msg, 0, 1000.0);
    }

    // Add the null terminator to indicate the end of the array
    grades[student.n_assignments] = '\0';
    
    // Call calculateStudentAverage, passing in the grades array and the student "grades" field that holds the average
    student.grades = new double[1];
    calculateStudentAverage(grades, student.grades);

    // Output `average`
    cout << "\nStudent: " << student.f_name << " " << student.l_name << " [" << student.id << "]" << endl;
    cout << "  Average grade: " << setprecision(1) << fixed << *student.grades << "\n" << endl;

    return 0;
}

/*
    Prompts the user to enter an int between two defined values.
        message: text to output as the prompt
        min: minimum value to accept as a valid int
        max: maximum value to accept as a valid int
*/
int promptInt(string message, int min, int max) {
    // The int entered by the user
    string input;
    int input_val;
    bool charFound;
    bool intFound;

    // Loop to gather user input until a valid integer is read
    while(cout << message && getline(cin, input)) {

        // Check for characters
        for(int i = 0; i < input.size(); i++) {
            if(!isdigit(input[i])) {
                charFound = true;
            } else {
                intFound = true;
            }
        }

        if(intFound) {
            try {
                input_val = stoi(input);
            } catch (const invalid_argument & e) {
                intFound = false;
            }
        }

        // Error-checking triggers if there is a type mismatch, or the input is out of bounds
        if(cin.fail() || input_val < min || input_val > max || charFound || !intFound) {
            // Clear the error flag on cin
            cin.clear();
            cout << "Sorry, I cannot understand your answer" << endl;
            charFound = false;
            intFound = false;
        } else {
            break;
        }
    }

    return input_val;
}

/* 
    Prompts the user to enter a double between two defined values.
        message: text to output as the prompt
        min: minimum value to accept as a valid double
        max: maximum value to accept as a valid double
*/
double promptDouble(string message, double min, double max) {

    // The int entered by the user
    string input;
    double input_val;
    bool charFound;
    bool doubleFound;

    // Loop to gather user input until a valid integer is read
    while(cout << message && getline(cin, input)) {

        // Check for characters
        for(int i = 0; i < input.size(); i++) {
            if(!isdigit(input[i]) && input[i] != '.') {
                charFound = true;
            } else if (input[i] == '.') {
                if(!isdigit(input[i + 1])){
                    charFound = true;
                }
            } else{
                doubleFound = true;
            }
        }

        if(doubleFound) {
            try {
                input_val = stod(input);
            } catch (const invalid_argument & e) {
                doubleFound = false;
            }
        }

        // Error-checking triggers if there is a type mismatch, or the input is out of bounds
        if(cin.fail() || input_val < min || input_val > max || charFound || !doubleFound) {
            // Clear the error flag on cin
            cin.clear();
            cout << "Sorry, I cannot understand your answer" << endl;
            charFound = false;
            doubleFound = false;
        } else {
            break;
        }
    }

    return input_val;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg) {
    // Cast the void pointer to grades
    double * grades = (double *)(object);

    // Calculate the size of the passed-in array, indicated by the null terminating character '\0'
    int size = 0;
    for(int i = 0; grades[i] != '\0'; i++){
        size++;
    }

    // Sum the elements in the array
    double sum = 0;
    for(int i = 0; i < size; i++) {
        sum = sum + grades[i];
    }

    // Calculate the average by dividing sum by size
    double result = sum/size;

    // Dereference avg
    *avg = result;
}
