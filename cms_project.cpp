#include <iostream>
#include <vector>
#include <algorithm>
#include<regex>
using namespace std;

class Task {
public:
    string title, description, duedate;
    bool completed = false;
};

class Task_Manager : public Task {
public:
    vector<Task> tasks;

    void Display(const Task& task);
    void displaytask(const vector<Task>& tasks);
    int findtask(const vector<Task>& tasks, const string& title);
    void addtask();
    void markTaskCompleted(const string& title, bool taskCompleted);
    void edit_task();
    void deleteTask();
    bool isValidDateFormat(const std::string& date);
};

void Task_Manager::Display(const Task& task) {
    cout << "Title: " << task.title << endl;

    if (!task.description.empty()) {
        cout << "Description: " << task.description << endl;
    }
    else {
        cout << "Description: (No description provided)" << endl;
    }
    
    cout << "Due Date: " << task.duedate << endl;
    
    if (task.completed) {
        cout << "Status: Completed" << endl;
    }
    else {
        cout << "Status: Pending" << endl;
    }
    
    cout << endl;
}

void Task_Manager::displaytask(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks found." << endl;
        return;
    }
    else {
        cout << "\n** All Tasks **\n" << endl;

        // Loop through tasks and display them (using a range-based for loop)
        for (const Task& task : tasks) {
            Display(task);
            cout << endl;
        }
    }
}

int Task_Manager::findtask(const vector<Task>& tasks, const string& title) {
    for (size_t i = 0; i < tasks.size(); i++)
        if (tasks[i].title == title) {
            return i;
        }
    return -1;
}



bool Task_Manager::isValidDateFormat(const std::string& date) {
    // Define a regular expression for MM-DD-YY format
    std::regex dateRegex("^\\d{2}-\\d{2}-\\d{2}$");

    // Check if the date matches the pattern
    if (!std::regex_match(date, dateRegex)) {
        return false;
    }

    // Extract month, day, and year from the date string
    int month, day, year;
    sscanf(date.c_str(), "%d-%d-%d", &month, &day, &year);

    // Check for a valid month (1-12)
    if (month < 1 || month > 12) {
        return false;
    }

    // Check for a valid day based on the month
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust days in February for leap years
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[2] = 29; // Leap year
    }

    if (day < 1 || day > daysInMonth[month]) {
        return false;
    }

    // Check for a valid two-digit year
    if (year < 0 || year > 99) {
        return false;
    }

    return true;
}

void Task_Manager::addtask() {
    Task new_task;
    cout << "Enter task title : ";
    getline(cin, new_task.title);
    cout << "Enter the task description ";
    getline(cin, new_task.description);
    string dueDate;
    do {
        cout << "Enter task due date (MM-DD-YY): ";
        getline(cin, dueDate);

        if (!isValidDateFormat(dueDate)) {
            cout << "Invalid date format. Please use MM-DD-YY format." << endl;
        }
    } while (!isValidDateFormat(dueDate));

    new_task.duedate = dueDate;

    tasks.push_back(new_task);

    cout << "Task added successfully!" << endl;

    // User choice to mark completed on adding
    int choice;
    cout << "Mark task as completed now? (1 - Yes, 0 - No): ";
    cin >> choice;
    if (choice == 1) {
        new_task.completed = true;
        markTaskCompleted(new_task.title, true);
    }
    else {
        markTaskCompleted(new_task.title, false);
    }

    cin.ignore(); // Clear input buffer
}

void Task_Manager::markTaskCompleted(const string& title, bool taskCompleted) {
    int index = findtask(tasks, title);
    if (index != -1) {
        tasks[index].completed = taskCompleted;
        cout << "Task marked as completed successfully!" << endl;
    }
    else {
        cout << "Task not found." << endl;
    }
}

void Task_Manager::edit_task() {
    string title;
    cout << "Enter the title of the task to edit: ";
    getline(cin, title);
    int index = findtask(tasks, title);

    if (index == -1) {
        cout << "Task not found." << endl;
        return;
    }

    cout << "Edit task:\n";
    string new_title, new_description, new_due_date;

    cout << "New Title: ";
    getline(cin, new_title);
    if (!new_title.empty()) {
        tasks[index].title = new_title;
    }

    cout << "New Description: ";
    getline(cin, new_description);
    if (!new_description.empty()) {
        tasks[index].description = new_description;
    }

    cout << "New Due Date: ";
    getline(cin, new_due_date);
    if (!new_due_date.empty()) {
        tasks[index].duedate = new_due_date;
    }

    cout << "Task edited successfully!" << endl;

    // Prompt the user for completion status
    int choice;
    cout << "Set task completion status (1 - Completed, 0 - Pending): ";
    cin >> choice;

    // Clear input buffer
    cin.ignore();

    // Update completion status based on user input
    tasks[index].completed = (choice == 1);

    cout << "Task completion status updated!" << endl;
}

void Task_Manager::deleteTask() {
    string title;
    cout << "Enter the title of the task to be delete : ";
    getline(cin, title);
    int index = findtask(tasks, title);
    if (index != -1) {
        tasks.erase(tasks.begin() + index);
        cout << "Task deleted successfully!" << endl;
    }
    else {
        cout << "Task not found." << endl;
    }
}

int main() {
    Task_Manager manager;
    string title;
    int choice;
    do {
        cout << "\n \t\t TASK MANAGER \t\t \n";
        cout << "1. Add Tasks\n";
        cout << "2. View Tasks\n";
        cout << "3. Edit Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
        case 1:
            manager.addtask();
            break;
        case 2:
            manager.displaytask(manager.tasks);
            break;
        case 3:
            manager.edit_task();
            break;
        case 4:
            manager.deleteTask();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}



