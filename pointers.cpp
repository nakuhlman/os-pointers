// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

// Student structure that will hold a student's info
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
    
    // Get the student's first name as a string
    string firstname;
    cout << "Please enter the student's first name: ";
    getline(cin,firstname);
    // Convert the string to a const char *, then cast it to a char * and assign to student's f_name field
    char * temp1 = const_cast<char*>(firstname.c_str());
    student.f_name = temp1;

    // Get the student's last name
    string lastname;
    cout << "Please enter the student's last name: ";
    getline(cin,lastname);
    
     // Convert the string to a const char *, then cast it to a char * and assign to student's l_name field
    char * temp2 = const_cast<char*>(lastname.c_str());
    student.l_name = temp2;

    // Prompt for the number of assignments
    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 1, 134217728);
    cout << '\n';

    // Array of doubles to store the assignment grades, one extra spot for terminating character
    double grades[student.n_assignments + 1];

    // Get the grades of all the assignments one by one
    for(int i = 0; i < student.n_assignments; i++) {
        string msg = "Please enter grade for assignment " + to_string(i) + ": ";
        grades[i] = promptDouble(msg, 0, 1000.0);
    }

    // Add the null terminator to indicate the end of the grades 
    grades[student.n_assignments] = '\0';
    
    // Call calculateStudentAverage, passing in the grades array and the student "grades" field that holds the average
    student.grades = new double[1];
    calculateStudentAverage(grades, student.grades);

    // Output `average' to 1 decimal place, as well as information about the student
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
    // The string entered by the user
    string input;
    // The integer parsed from the input string
    int input_val;
    // Boolean to indicate if invalid characters are present in the user's input string
    bool bad_char = false;

    // Loop to gather user input until a valid input is received
    while(cout << message && getline(cin, input)) {

        // Check each index in the string for letters or symbols, which are an invalid input
        for(int i = 0; i < input.size(); i++) {
            if(!isdigit(input[i])) {
                bad_char = true;
            }
        }

        // Parse the string to an integer, catching failures if the process fails due to invalid chars
        try {
            input_val = stoi(input);
        } catch (const invalid_argument & e) {
            bad_char = true;
        }

        // Error-checking triggers if there is a type mismatch, the input is out of bounds, or bad_char is true
        if(cin.fail() || input_val < min || input_val > max || bad_char) {
            // Clear the error flag on cin
            cin.clear();
            cout << "Sorry, I cannot understand your answer" << endl;
            // Reset bad_char for the new input
            bad_char = false;
        // If there were no errors, exit the loop
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
    bool bad_char = false;

    // Loop to gather user input until valid is received
    while(cout << message && getline(cin, input)) {
        // Check for invalid characters
        for(int i = 0; i < input.size(); i++) {
            if(!isdigit(input[i]) && input[i] != '.') {
                bad_char = true;
            // With doubles, a '.' should always be followed by a digit; if not, set the bad_char flag
            } else if (input[i] == '.') {
                if(!isdigit(input[i + 1])){
                    bad_char = true;
                }
            }
        }

        // Use stod to parse a double from the string, catching exceptions
        try {
            input_val = stod(input);
        } catch (const invalid_argument & e) {
            bad_char = true;
        }

        // Error-checking triggers if there is a type mismatch, the input is out of bounds, or bad_char is set
        if(cin.fail() || input_val < min || input_val > max || bad_char) {
            // Clear the error flag on cin
            cin.clear();
            cout << "Sorry, I cannot understand your answer" << endl;
            // Reset bad_char
            bad_char = false;
        // If there were no errors, exit the loop
        } else {
            break;
        }
    }

    return input_val;
}

/*  
    Calculates the average of an array of doubles, representing grades by default, and calculates the average
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
