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

void quick_sort() {
    // Implementing Quick Sort for sorting students by name
    // Quick Sort logic uses a partitioning method to recursively sort the array

    if (students.empty()) return;

    // Partition function
    auto partition = [](int low, int high) -> int {
        string pivot = students[high].name; // Taking the last element as pivot
        int i = low - 1; // index of smaller element

        for (int j = low; j < high; ++j) {
            if (students[j].name < pivot) {
                ++i;
                swap(students[i], students[j]);
            }
        }
        swap(students[i + 1], students[high]); // Place the pivot element in the correct position
        return i + 1;
        };

    // Helper recursive quick sort function
    function<void(int, int)> quickSortHelper = [&](int low, int high) {
        if (low < high) {
            int pi = partition(low, high); // Partition index
            quickSortHelper(low, pi - 1);  // Recursively sort the left part
            quickSortHelper(pi + 1, high); // Recursively sort the right part
        }
        };

    // Calling quick sort for the entire list
    quickSortHelper(0, students.size() - 1);
}

void merge_sort() {
    // Implementing Merge Sort for sorting students by average grade
    // Merge Sort divides the list into two halves, sorts them, and then merges them

    if (students.empty()) return;

    // Helper function to merge two halves
    auto merge = [](int left, int mid, int right) {
        int n1 = mid - left + 1;  // Length of the left part
        int n2 = right - mid;     // Length of the right part

        vector<Student> leftPart(n1);
        vector<Student> rightPart(n2);

        // Fill left part
        for (int i = 0; i < n1; ++i)
            leftPart[i] = students[left + i];
        // Fill right part
        for (int j = 0; j < n2; ++j)
            rightPart[j] = students[mid + 1 + j];

        // Merge the two parts
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftPart[i].avgGrade <= rightPart[j].avgGrade) {
                students[k++] = leftPart[i++];
            }
            else {
                students[k++] = rightPart[j++];
            }
        }

        // Copy remaining elements
        while (i < n1) students[k++] = leftPart[i++];
        while (j < n2) students[k++] = rightPart[j++];
        };

    // Helper recursive merge sort function
    function<void(int, int)> mergeSortHelper = [&](int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSortHelper(left, mid);  // Sort left half
            mergeSortHelper(mid + 1, right); // Sort right half
            merge(left, mid, right); // Merge the sorted halves
        }
        };

    // Calling merge sort for the en
    mergeSortHelper(0, students.size() - 1);
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
