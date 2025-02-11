#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::sort
#include <numeric>   // For std::accumulate
#include <fstream>
#include <sstream>
using namespace std;

// Function Prototypes
void input_grades(vector<string>& students, vector<vector<int>>& grades);
void view_grades(const vector<string>& students, const vector<vector<int>>& grades);
void student_data(vector<string>& students, vector<vector<int>>& grades);
void data_analysis(const vector<string>& students, const vector<vector<int>>& grades);
void save_to_file(const vector<string>& students, const vector<vector<int>>& grades);
void load_file(vector<string>& students, vector<vector<int>>& grades);
int menu();

// Helper functions
double calculate_average(const vector<int>& grades);
void quickSort(vector<pair<double, string>>& arr, int low, int high);
int partition(vector<pair<double, string>>& arr, int low, int high);
void mergeSort(vector<string>& students, vector<vector<int>>& grades, int left, int right);
void merge(vector<string>& students, vector<vector<int>>& grades, int left, int mid, int right);

/*
################
######Main######
################
*/
int main()
{
    vector<string> students;
    vector<vector<int>> grades;
    bool running = true;

    while (running)
    {
        int choice = menu();
        switch (choice)
        {
        case 1:
            input_grades(students, grades);
            break;
        case 2:
            view_grades(students, grades);
            break;
        case 3:
            save_to_file(students, grades);
            break;
        case 4:
            load_file(students, grades);
            break;
        case 5:
            data_analysis(students, grades);
            break;
        case 6:
            student_data(students, grades);
            break;
        case 7:
            running = false;
            cout << "Thank you for using the Student Grades Management System.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
    return 0;
}

// Menu function
int menu()
{
    int choice;
    cout << "\nStudent Grades Management System\n";
    cout << "1. Input Grades\n";
    cout << "2. View Grades\n";
    cout << "3. Save Grades to File\n";
    cout << "4. Load Grades from File\n";
    cout << "5. Analyze Grades\n";
    cout << "6. Sort Data\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Input grades function
void input_grades(vector<string>& students, vector<vector<int>>& grades)
{
    string student;
    char cont;

    do
    {
        cout << "Enter a student's name: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, student);
        students.push_back(student);

        vector<int> studentGrades;
        int grade;
        int numGrades;
        cout << "How many grades do you want to input for " << student << "? ";
        cin >> numGrades;

        for (int i = 0; i < numGrades; i++)
        {
            cout << "Enter grade " << i + 1 << ": ";
            cin >> grade;
            studentGrades.push_back(grade);
        }
        grades.push_back(studentGrades);

        cout << "Would you like to add another student? (y/n): ";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');
}

// View grades function
void view_grades(const vector<string>& students, const vector<vector<int>>& grades)
{
    if (students.empty())
    {
        cout << "No student data available.\n";
        return;
    }

    for (size_t i = 0; i < students.size(); i++)
    {
        cout << "Student: " << students[i] << "\tGrades: ";
        for (int grade : grades[i])
        {
            cout << grade << " ";
        }
        cout << endl;
    }
}

// Student data function (sort by name or average grade)
void student_data(vector<string>& students, vector<vector<int>>& grades)
{
    int choice;
    cout << "Sort students by:\n";
    cout << "1. Name\n";
    cout << "2. Average Grade\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        // Sort by name using Merge Sort
        mergeSort(students, grades, 0, students.size() - 1);
        cout << "Students sorted by name:\n";
        view_grades(students, grades);
    }
    else if (choice == 2)
    {
        // Sort by average grade using QuickSort
        vector<pair<double, string>> avgGrades;
        for (size_t i = 0; i < students.size(); i++)
        {
            double avg = calculate_average(grades[i]);
            avgGrades.push_back({ avg, students[i] });
        }

        quickSort(avgGrades, 0, avgGrades.size() - 1);

        cout << "Students sorted by average grade:\n";
        for (const auto& entry : avgGrades)
        {
            cout << "Student: " << entry.second << "\tAverage Grade: " << entry.first << endl;
        }
    }
    else
    {
        cout << "Invalid choice.\n";
    }
}

// Data analysis function
void data_analysis(const vector<string>& students, const vector<vector<int>>& grades)
{
    if (students.empty())
    {
        cout << "No data available for analysis.\n";
        return;
    }

    double highestAvg = 0, lowestAvg = 100;
    string topStudent, bottomStudent;

    for (size_t i = 0; i < students.size(); i++)
    {
        double avg = calculate_average(grades[i]);
        if (avg > highestAvg)
        {
            highestAvg = avg;
            topStudent = students[i];
        }
        if (avg < lowestAvg)
        {
            lowestAvg = avg;
            bottomStudent = students[i];
        }
    }

    cout << "Top Student: " << topStudent << " (Average: " << highestAvg << ")\n";
    cout << "Lowest Student: " << bottomStudent << " (Average: " << lowestAvg << ")\n";
}

// Calculate average grade
double calculate_average(const vector<int>& grades)
{
    if (grades.empty()) return 0.0;
    int sum = accumulate(grades.begin(), grades.end(), 0);
    return static_cast<double>(sum) / grades.size();
}

// QuickSort for sorting by average grade
void quickSort(vector<pair<double, string>>& arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(vector<pair<double, string>>& arr, int low, int high)
{
    double pivot = arr[high].first;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j].first < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Merge Sort for sorting by name
void mergeSort(vector<string>& students, vector<vector<int>>& grades, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(students, grades, left, mid);
        mergeSort(students, grades, mid + 1, right);
        merge(students, grades, left, mid, right);
    }
}

void merge(vector<string>& students, vector<vector<int>>& grades, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> leftStudents(n1), rightStudents(n2);
    vector<vector<int>> leftGrades(n1), rightGrades(n2);

    for (int i = 0; i < n1; i++)
    {
        leftStudents[i] = students[left + i];
        leftGrades[i] = grades[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        rightStudents[i] = students[mid + 1 + i];
        rightGrades[i] = grades[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftStudents[i] <= rightStudents[j])
        {
            students[k] = leftStudents[i];
            grades[k] = leftGrades[i];
            i++;
        }
        else
        {
            students[k] = rightStudents[j];
            grades[k] = rightGrades[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        students[k] = leftStudents[i];
        grades[k] = leftGrades[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        students[k] = rightStudents[j];
        grades[k] = rightGrades[j];
        j++;
        k++;
    }
}

// Save to file function
void save_to_file(const vector<string>& students, const vector<vector<int>>& grades)
{
    string filename;
    cout << "Enter the file name to save: ";
    cin >> filename;

    ofstream file(filename);
    if (!file)
    {
        cout << "Error opening file.\n";
        return;
    }

    for (size_t i = 0; i < students.size(); i++)
    {
        file << students[i] << " ";
        for (int grade : grades[i])
        {
            file << grade << " ";
        }
        file << "\n";
    }
    cout << "Data saved to file.\n";
}

// Load from file function
void load_file(vector<string>& students, vector<vector<int>>& grades)
{
    string filename;
    cout << "Enter the file name to load: ";
    cin >> filename;

    ifstream file(filename);
    if (!file)
    {
        cout << "Error opening file.\n";
        return;
    }

    students.clear();
    grades.clear();
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string name;
        ss >> name;
        students.push_back(name);

        vector<int> studentGrades;
        int grade;
        while (ss >> grade)
        {
            studentGrades.push_back(grade);
        }
        grades.push_back(studentGrades);
    }
    cout << "Data loaded from file.\n";
}