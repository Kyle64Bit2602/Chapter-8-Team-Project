//Chapter 8 Team Project
//Kyle, Kade, Cole, Jullian

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//Function Prototypes (arguments, type of functions to be updated)
void input_grades();
void view_grades();
void student_data();
void data_analysis();
void quick_sort();
void merge_sort();
void binary_search();
void load_file();
void save_to_file(array[]);
int menu();
void data_analysis(string students[], int* grades[], int student_count, int grade_counts[]);
int binary_search(string students[], int student_count, string target);
double calculate_average(int grades[], int grade_count);

/*
################
######Main######
################
*/
int main()
{
	
}

void binary_search()
{
}

void load_file()
{
	string filename;
	cout << "Please enter the file location you wish to load into the program.\n";
	cout << "(Add another \ to each location.\n)";
	cout << "(Ex: C:\\Users\\BillyBob\\Desktop\\Chapter-8-Team-Project)\n";
	cout << ">>: ";
	cin >> filename;

	ifstream file(filename);
	
	if (!file)
	{
		cout << "Error: File was not found.\n"
	}
	else
	{
		//Placeholder
		//Loads file into data in array format
	}
}

void save_to_file(array[])
{
	string filename;
	cout << "Please enter the file location you wish to save to.\n";
	cout << "(Add another \ to each location.\n)";
	cout << "(Ex: C:\\Users\\BillyBob\\Desktop\\Chapter-8-Team-Project)\n";
	cout << ">>: ";
	cin >> filename;

	ofstream file(filename);

	if (!file)
	{
		cout << "Error: File was not found.\n"
	}
	else
	{
		//Placeholder
		//Will take the array of student grades to save
	}

}

void input_grades()
{
	//initiates variables
	string student;
	int grade;
	int grades[4];
	cout << "Enter a student's name: "; //gets a 
	getline(cin, student);
	for (int n = 0; n > 5, n++)
	{
		cout << "Grade " << n << ":";
		cout << grades[n];
	}
	
}

void view_grades()
{

}

void student_data()
{
}

void data_analysis()
{
}

void quick_sort()
{
}

void merge_sort()
{
}


int menu()
{
	int choice = 0;
	bool check = false;

	cout << "Student Grades Management System\n";
	cout << "1. Input Grades\n";
	cout << "2. View Grades\n";
	cout << "3. Save Grades to File\n";
	cout << "4. Load Grades from File\n";
	cout << "5. Analyze Grades\n";
	cout << "6. Search for a Student by Name\n";
	cout << "7. Sort Data\n";
	cout << "8. Exit\n";

	cout << "\n\nEnter your choice:";
	cin >> choice;
	while (check == false)
	{
		if (choice < 1 || choice > 8)
		{
			cout << "Error: Input does not fall between 1-8.\n";
			cout << "Enter your choice: ";
			cin >> choice;
		}
		else
			check == true
	}
// Function to analyze data: calculate averages, find min and max
void data_analysis(string students[], int* grades[], int student_count, int grade_counts[]) {
    if (student_count == 0) {
        cout << "No data available.\n";
        return;
    }

    double highest_avg = 0, lowest_avg = 100;
    string top_student, bottom_student;
    
    for (int i = 0; i < student_count; i++) {
        double avg = calculate_average(grades[i], grade_counts[i]);
        if (avg > highest_avg) {
            highest_avg = avg;
            top_student = students[i];
        }
        if (avg < lowest_avg) {
            lowest_avg = avg;
            bottom_student = students[i];
        }
    }
    
    cout << "Top: " << top_student << " (" << highest_avg << "%)\n";
    cout << "Lowest: " << bottom_student << " (" << lowest_avg << "%)\n";
}

// Binary search to find a student
int binary_search(string students[], int student_count, string target) {
    int left = 0, right = student_count - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (students[mid] == target) return mid;
        else if (students[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Calculate average grade
double calculate_average(int grades[], int grade_count) {
    if (grade_count == 0) return 0.0;
    int sum = 0;
    for (int i = 0; i < grade_count; i++) sum += grades[i];
    return sum / (double)grade_count;
}
}
