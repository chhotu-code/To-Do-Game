#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struct to represent a task
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// Function to display tasks
void displayTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\n empty task. \n";
    } else {
        cout << "\nTo-Do List:\n";
        cout<<"-------------------------------"<<endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description
                 << (tasks[i].completed ? " [Completed]" : "") << endl;
        }
        cout<<"-------------------------------"<<endl;
    }
}

// Function to add a task
void addTask(vector<Task>& tasks) {
    cin.ignore(); // Clear the buffer
    cout << "Enter task description: ";
    string desc;
    getline(cin, desc);
    tasks.push_back(Task(desc));
    cout << "Task added.\n";
}

// Function to mark or delete a task
void modifyTask(vector<Task>& tasks, bool markAsCompleted) {
    if (tasks.empty()) {
        cout << "No tasks to modify.\n";
        cout<<"-------------------------------"<<endl;
        return;
    }

    displayTasks(tasks);
    cout << "Enter the task number: ";
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number.\n";
        cout<<"-------------------------------"<<endl;
        return;
    }

    if (markAsCompleted) {
        tasks[taskNumber - 1].completed = true;
         cout<<"-------------------------------"<<endl;
        cout << "Task marked as completed.\n";
         cout<<"-------------------------------"<<endl;
    } else {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task deleted.\n";
        cout<<"-------------------------------"<<endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        cout << "\nTo-Do List Application\n";
        cout << "1. View Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Complete Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) displayTasks(tasks);
        else if (choice == 2) addTask(tasks);
        else if (choice == 3) modifyTask(tasks, true);
        else if (choice == 4) modifyTask(tasks, false);
        else if (choice == 5) {
            cout << "Goodbye!\n";
            break;
        } else {
            cout<<"-------------------------------"<<endl;
            cout << "Invalid choice. Try again.\n";
            cout<<"-------------------------------"<<endl;
        }
    }

    return 0;
}
