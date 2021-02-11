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
    int id = promptInt("\nPlease enter the student's id number: ", 0, 999999999);
    student.id = id;

    string firstname;
    cout << "Please enter the student's first name: ";
    cin.ignore();
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
    calculateStudentAverage(grades, student.grades);

    // Output `average`
    cout << "\nStudent: " << student.f_name << " " << student.l_name << " [" << student.id << "]" << endl;
    cout << "  Average grade: " << student.grades << "\n" << endl;

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
    int input;

    // Loop to gather user input until a valid integer is read
    while(1) {
        cout << message;
        cin >> input;

        // Error-checking triggers if there is a type mismatch, or the input is out of bounds
        if(cin.fail() || input < min || input > max) {
            // Clear the error flag on cin, then skip all the characters until the newline '\n' before reprompting
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Sorry, I cannot understand your answer \n" << endl;
        } else {
            break;
        }
    }

    return input;
}

/* 
    Prompts the user to enter a double between two defined values.
        message: text to output as the prompt
        min: minimum value to accept as a valid double
        max: maximum value to accept as a valid double
*/
double promptDouble(string message, double min, double max) {
    // The double entered by the user
    double input;

    // Loop to gather user input until a valid double is read
    while(1) {
        cout << message;
        cin >> input;

        // Error-checking triggers if there is a type mismatch, or the input is out of bounds
        if(cin.fail() || input < min || input > max) {
            // Clear the error flag on cin, then skip all the characters until the newline '\n' before reprompting
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Sorry, I cannot understand your answer" << endl;
        } else {
            break;
        }

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
    cout << result;

    // Dereference avg
    *avg = result;
    cout << "got here";
}
