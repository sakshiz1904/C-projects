#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Define the task structure
struct Task {
    string title;
    string description;
    string due_date; // Consider using a more appropriate date format if needed
    bool completed = false;
};

// Function to find a task by title
int findTask(const std::vector<Task>& tasks, const std::string& title) {
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].title == title) {
            return i;
        }
    }
    return -1;
}

// Function to add a new task
void addTask(std::vector<Task>& tasks) {
    Task new_task;
    std::cout << "Enter task title: ";
    std::getline(std::cin, new_task.title);
    std::cout << "Enter task description (optional): ";
    std::getline(std::cin, new_task.description);
    std::cout << "Enter task due date: ";
    std::getline(std::cin, new_task.due_date);

    tasks.push_back(new_task);

    int index = findTask(tasks, new_task.title);
    if (index != -1) {
        std::cout << "New task added at index: " << (index + 1) << std::endl;
    }
    std::cout << "Task added successfully!" << std::endl;

    // User choice to mark completed on adding
    int choice;
    std::cout << "Mark task as completed now? (1 - Yes, 0 - No): ";
    std::cin >> choice;
    if (choice == 1) {
        new_task.completed = true;
    }
    std::cin.ignore(); // Clear input buffer
}

// Function to mark a task as completed
void markTaskCompleted(std::vector<Task>& tasks, const std::string& title) {
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].title == title) {
            tasks[i].completed = true;
            std::cout << "Task marked as completed successfully!" << std::endl;
            return; // Exit after finding and marking the task
        }
    }
    std::cout << "Task not found." << std::endl;
}

// Function to display a single task
void displayTask(const Task& task) {
    std::cout << "Title: " << task.title << std::endl;
    if (!task.description.empty()) {
        std::cout << "Description: " << task.description << std::endl;
    }
    std::cout << "Due Date: " << task.due_date << std::endl;
    if (task.completed) {
        std::cout << "Status: Completed" << std::endl;
    } else {
        std::cout << "Status: Pending" << std::endl;
    }
    std::cout << std::endl;
}

// Function to display all tasks
// function to display all tasks
void displayTasks(const std::vector<Task>& tasks) {
  if (tasks.empty()) {
    cout << "No tasks found." << endl;
    return;
  }
  else{
    std::string title;
    cout << "Enter the title of the task to display (case-insensitive): ";
    std::getline(std::cin, title);

    // Convert user input to lowercase
    std::transform(title.begin(), title.end(), title.begin(), ::tolower);

    bool found = false;
    for (const Task& task : tasks)
    {
        // Convert task title to lowercase for comparison
        std::string lower_task_title = task.title;
        std::transform(lower_task_title.begin(), lower_task_title.end(), lower_task_title.begin(), ::tolower);

        if (lower_task_title == title) 
            {
                displayTask(task);
                found = true;
                break; // Exit the loop after finding the task
             }
    }

    if (!found) {
        cout << "Task not found." << endl;
         }
    }
}

// Function to edit an existing task
void editTask(std::vector<Task>& tasks) {
    string title;
    std::cout << "Enter the title of the task to edit: ";
    std::getline(std::cin, title);

    int index = findTask(tasks, title);
    if (index == -1) {
        std::cout << "Task not found." << std::endl;
        return;
    }

    std::cout << "Edit task (leave blank to keep unchanged):" << std::endl;
    std::string new_title, new_description, new_due_date;

    std::cout << "New Title: ";
    std::getline(std::cin, new_title);
    if (!new_title.empty()) {
        tasks[index].title = new_title;
 }
  std::cout << "New Description: ";
  std::getline(std::cin, new_description);
  if (!new_description.empty()) {
    tasks[index].description = new_description;
  }
  cout << "New Due Date: ";
  getline(std::cin, new_due_date);
  if (!new_due_date.empty()) {
    tasks[index].due_date = new_due_date;
  }
  std::cout << "Task edited successfully!" << std::endl;
}

// Function to delete a task
void deleteTask(std::vector<Task>& tasks) {
  std::string title;
  std::cout << "Enter the title of the task to delete: ";
  std::getline(std::cin, title);
  int index = findTask(tasks, title);
  if (index == -1) {
    std::cout << "Task not found." << std::endl;
    return;
  }

  tasks.erase(tasks.begin() + index);
  std::cout << "Task deleted successfully!" << std::endl;
}

int main() {
  // Declare a vector to store tasks
  std::vector<Task> tasks;

  int choice;
    string title;
  do {
    std::cout << "\nTask Manager\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Edit Task\n";
    std::cout << "4. Delete Task\n";
    std::cout<< "5 Mark Task Completed" << std::endl;
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore(); // Clear input buffer

    switch (choice) {
      case 1:
        addTask(tasks);
        break;
      case 2:
        displayTasks(tasks);
        break;
      case 3:
        editTask(tasks);
        break;
      case 4:
        deleteTask(tasks);
        break;
      case 5:
            
            std::cout << "Enter title of the task to mark complete: ";
            std::getline(std::cin, title);
            markTaskCompleted(tasks, title);
            break;
      case 6:
        std::cout << "Exiting...\n";
        break;
      default:
            std::cout << "Invalid choice.\n";
    }
  } while (choice != 6);

  return 0;
}



