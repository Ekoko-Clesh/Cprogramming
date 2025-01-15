# Student Data Management Program

A simple C program for managing student records. This program allows you to add, display, and search for student information, including their grades and average score.

## Features

- **Add Student Data**: Input a student's name, grades, and automatically calculate the average.
- **Display Data**: View all stored student records in a formatted table.
- **Search Student**: Look up a specific student by name.
- **Dynamic Memory Allocation**: Efficient memory management using `calloc`.

## How It Works

The program provides a menu-driven interface with the following options:

1. **Enter New Student Data**  
   Allows the user to input a student's name and grades. The program calculates the average and stores the data.

2. **Show Entered Student Data**  
   Displays all stored student information, including name, grades, and average score.

3. **Search for Student in the List**  
   Searches for a specific student by name and displays their record.

4. **Exit**  
   Exits the program.

## Code Overview

### Data Structure

The program uses a `struct` to store student information:
```c
typedef struct Data {
    char name[50];
    float grade1;
    float grade2;
    float average;
} Data;

Function Descriptions

void InsertData(Data p[], int *iteratorPtr)
Handles adding student data to the list.

void ReadData(Data *ptr, Data p[], int *iteratorPtr)
Reads student data from the user and calculates the average.

void ShowData(Data *ptr, Data p[], int *iteratorPtr)
Displays all stored student records.

void SearchStudent(Data *ptr, Data p[], int *iteratorPtr)
Searches for a specific student by name and displays their record.


Main Function

The main function provides a loop-based menu to navigate through the program's features.

Requirements

GCC Compiler or any C compiler.

Basic understanding of C programming.


How to Run

1. Clone the repository:

git clone <repository_url>


2. Compile the program:

gcc -o student_data student_data.c


3. Run the executable:

./student_data



Example Menu

[ 1 ] - Enter New Student data
[ 2 ] - Show entered student data
[ 3 ] - Search for student in the list
[ 0 ] - Exit
Choose an option:

Follow the prompts to manage student records.

Future Enhancements

Add file handling to save and load student records.

Improve the search feature to allow partial name matching.

Support multiple students dynamically without reallocation issues.


License

This project is licensed under the MIT License.
