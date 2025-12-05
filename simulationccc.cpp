#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    void enqueue(int id) {
        if (isFull()) {
            cout << "\nQueue Full! No more patients can wait.\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = id;
        count++;
        cout << "Patient with ID " << id << " has arrived.\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "\nQueue Empty! No patients to serve.\n";
            return -1;
        }
        int id = arr[front];
        front = (front + 1) % capacity;
        count--;
        cout << "Doctor served patient with ID " << id << ".\n";
        return id;
    }

    int getFront() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return arr[front];
    }

    int getRear() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return arr[rear];
    }

    int size() const {
        return count;
    }

    void displayQueue() const {
        if (isEmpty()) {
            cout << "\nNo patients waiting.\n";
            return;
        }

        cout << "\nCurrent Patient Queue (front -> rear):\n";
        int i = front;
        for (int c = 0; c < count; c++) {
            cout << arr[i] << "  ";
            i = (i + 1) % capacity;
        }
        cout << "\nFront index: " << front 
             << ", Rear index: " << rear << "\n";
    }
};

int main() {
    int maxSize;
    cout << "====== HOSPITAL PATIENT QUEUE SYSTEM ======\n";
    cout << "Enter maximum number of patients allowed: ";
    cin >> maxSize;

    CircularQueue q(maxSize);
    int choice;
    int nextID = 100;  // automatic patient IDs start from 100

    do {
        cout << "\n------------ MENU ------------\n";
        cout << "1. New patient arrives (Enqueue)\n";
        cout << "2. Doctor serves next patient (Dequeue)\n";
        cout << "3. Show all waiting patients\n";
        cout << "4. Show front & rear patient IDs\n";
        cout << "5. Show queue size\n";
        cout << "6. Exit\n";
        cout << "--------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            q.enqueue(nextID);
            nextID++;
            q.displayQueue();
            break;

        case 2:
            q.dequeue();
            q.displayQueue();
            break;

        case 3:
            q.displayQueue();
            break;

        case 4: {
            int f = q.getFront();
            int r = q.getRear();
            if (!q.isEmpty()) {
                cout << "Front patient ID: " << f << "\n";
                cout << "Rear patient ID: " << r << "\n";
            }
            break;
        }

        case 5:
            cout << "Patients waiting: " << q.size() << "\n";
            break;

        case 6:
            cout << "Exiting system...\n";
            break;

        default:
            cout << "Invalid option! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
