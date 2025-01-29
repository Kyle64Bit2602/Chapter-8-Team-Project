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
void quickSort(int arr[], int lowIndex, int highIndex)
void merge_sort();
void binary_search();
void load_file();
void save_to_file(array[]);
int menu();
int partition(int arr[], int lowIndex, int highIndex)

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
	string student;
	int grade;
	int grades[5];
	cout << "Enter a student's name: ";
	getline(cin, student);
	for (int n = 0; n > 5; n++)
	{

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

void quickSort(int arr[], int lowIndex, int highIndex)
{
	if (lowIndex < highIndex) {
		// Find the partition index
		int partitionIndex = partition(arr, lowIndex, highIndex);

		// Recursively sort elements before and after the partition
		quickSort(arr, lowIndex, partitionIndex - 1);
		quickSort(arr, partitionIndex + 1, highIndex);
}

void merge_sort()
{

}

int partition(int arr[], int lowIndex, int highIndex) //Splits data into two for quicksort
{
	int pivotElement = arr[highIndex]; // Choosing the last element as the pivot
	int smallerElementIndex = lowIndex - 1; // Keeps track of the correct position for the pivot

	for (int currentIndex = lowIndex; currentIndex < highIndex; currentIndex++) {
		// If the current element is smaller than the pivot, swap it to the left partition
		if (arr[currentIndex] < pivotElement) {
			smallerElementIndex++;
			swap(arr[smallerElementIndex], arr[currentIndex]);
		}
	}
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
}
