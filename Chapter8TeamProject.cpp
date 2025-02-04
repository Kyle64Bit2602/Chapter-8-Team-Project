//Chapter 8 Team Project
//Kyle, Kade, Cole, Jullian

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

//Function Prototypes (arguments, type of functions to be updated)
void input_grades();
void student_data();
void quickSort(int arr[], int lowIndex, int highIndex)
void view_grades(int grades[], string students[])
void merge_sort(int arr[], int left, int right);
void load_file();
void save_to_file(array[]);
int menu();
int partition(int arr[], int lowIndex, int highIndex)
void data_analysis(string students[], int* grades[], int student_count, int grade_counts[]);
int binary_search(string students[], int student_count, string target);
double calculate_average(int grades[], int grade_count);
void parseStringArray(const string& line, vector<string>& stringArray);
void parseIntArray(const string& line, vector<int>& intArray)
void merge(int arr[], int left, int mid, int right);

/*
################
######Main######
################
*/
int main()
{
	char cont;
	bool check = True;
	while (check == True)
	{
		choice = menu();
		if (choice == 1)
		{
			pair<int[], string[]> gradesStudents = input_grades();
			int grades[] = gradesStudents.first;
			string students[] = gradesStudents.second;
		}
		else if (choice == 2)
		{
			view_grades(int grades[], string students[])
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
	return choice
}
int load_file()
{
	int grades[];
	string students[];
	string filename;
	cout << "Please enter the file location you wish to load into the program.\n";
	cout << "(Add another \ to each location.\n)";
	cout << "(Ex: C:\\Users\\BillyBob\\Desktop\\Chapter-8-Team-Project)\n";
	cout << ">>: ";
	cin >> filename;

	ifstream file(filename);
	
	string line;
	vector<int> intArray;
	vector<string> stringArray;
	if (!file)
	{
		cout << "Error: File was not found.\n";
		return 1;
	}
	else
	{
		if (getline(filename, line))
			parseIntArray(line, intArray);
			for (size_t i = 0; i < intArray.size(); i++) 
				grades[i] = intArray[i]
		if (getline(filename, line))
			parseStringArray(line, stringArray);
			for (size_t i = 0; i < stringArray.size(); i++)
				students[i] = stringArray[i]
	}
}

void save_to_file(int grades[], string students[])
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
		filename << grades[];
		filename << students[];
	}

}

pair <int[], string[]> input_grades()
{
	//initiates variables
	bool check = True;
	char cont;
	string student;
	string students[];
	int grade;
	int grades[];
	while (check == True)
	{
		cout << "Enter a student's name: ";
		getline(cin, student);
		int num;
		cout << "How many grades do you want to input?\n";
		cin >> num;
		for (int n = 0; n = num; n++)
		{
			cout << "Grade " << n << ":";
			cin >> n;
			cout << grades[n];
		}
		cout << "Grades successfully added.\n";
		cout << "Would you like to add another student to the registry? (y/n)";
		cin >> cont;
		if (cont != 'y' || cont != 'Y')
		{
			check = False;
		}
	}
	return {grades[], students[])
}

void view_grades(int grades[], string students[])
{
	for (int index = 0; index < size; index++)
	{
		cout << students[index] << \t\t\t << grades[index] << endl;
	}
}

void student_data()
{

}

void quickSort(int arr[], int lowIndex, int highIndex)
{
	if (lowIndex < highIndex)
	{
		// Find the partition index
		int partitionIndex = partition(arr, lowIndex, highIndex);

		// Recursively sort elements before and after the partition
		quickSort(arr, lowIndex, partitionIndex - 1);
		quickSort(arr, partitionIndex + 1, highIndex);
	}
}

void merge_sort(int arr[], int left, int right) 
{
	if (left < right) {
		int mid = left + (right - left) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
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

void parseIntArray(const string& line, vector<int>& intArray)
{
	istringstream iss(line);
	int num;
	while (iss >> num) {
		intArray.push_back(num);
	}
}

void parseStringArray(const string& line, vector<string>& stringArray)
{
	istringstream iss(line);
	string word;
	while (iss >> word) {
		intArray.push_back(word);
	}
}

// Function to merge two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
	int leftSize = mid - left + 1;  // Size of left subarray
	int rightSize = right - mid;    // Size of right subarray

	int leftArray[leftSize], rightArray[rightSize];

	// Copy elements into left and right temporary subarrays
	for (int index = 0; index < leftSize; index++)
		leftArray[index] = arr[left + index];
	for (int index = 0; index < rightSize; index++)
		rightArray[index] = arr[mid + 1 + index];

	// Merging the two sorted subarrays back into the main array
	int leftIndex = 0, rightIndex = 0, mergeIndex = left;

	while (leftIndex < leftSize && rightIndex < rightSize) {
		if (leftArray[leftIndex] <= rightArray[rightIndex]) {
			arr[mergeIndex] = leftArray[leftIndex];
			leftIndex++;
		}
		else {
			arr[mergeIndex] = rightArray[rightIndex];
			rightIndex++;
		}
		mergeIndex++;
	}

	// Copy remaining elements of leftArray, if any
	while (leftIndex < leftSize) {
		arr[mergeIndex] = leftArray[leftIndex];
		leftIndex++;
		mergeIndex++;
	}

	// Copy remaining elements of rightArray, if any
	while (rightIndex < rightSize) {
		arr[mergeIndex] = rightArray[rightIndex];
		rightIndex++;
		mergeIndex++;
	}
}