#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        if (index && heap[parent(index)] > heap[index]) {
            swap(heap[index], heap[parent(index)]);
            heapifyUp(parent(index));
        }
    }

    void heapifyDown(int index) {
        int left = leftChild(index);
        int right = rightChild(index);
        int smallest = index;

        if (left < size() && heap[left] < heap[index])
            smallest = left;

        if (right < size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    unsigned int size() { return heap.size(); }
    bool empty() { return size() == 0; }
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i + 1); }
    int rightChild(int i) { return (2 * i + 2); }

    void insert(int key) {
        heap.push_back(key);
        int index = size() - 1;
        heapifyUp(index);
    }

    void insertMultiple(const vector<int>& values) {
        for (int value : values) {
            insert(value);
        }
    }

    void deleteMin() {
        if (size() == 0) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int getMin() { return size() == 0 ? -1 : heap.front(); }

    void printHeap() {
        for (int i : heap)
            cout << i << " ";
        cout << endl;
    }

    void visualizeHeap(int index = 0, int depth = 0) {
        if (index >= size()) return;

        visualizeHeap(rightChild(index), depth + 1);

        for (int i = 0; i < depth; ++i) cout << "    ";
        cout << heap[index] << endl;

        visualizeHeap(leftChild(index), depth + 1);
    }
};

class MaxHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        if (index && heap[parent(index)] < heap[index]) {
            swap(heap[index], heap[parent(index)]);
            heapifyUp(parent(index));
        }
    }

    void heapifyDown(int index) {
        int left = leftChild(index);
        int right = rightChild(index);
        int largest = index;

        if (left < size() && heap[left] > heap[index])
            largest = left;

        if (right < size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    unsigned int size() { return heap.size(); }
    bool empty() { return size() == 0; }
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i + 1); }
    int rightChild(int i) { return (2 * i + 2); }

    void insert(int key) {
        heap.push_back(key);
        int index = size() - 1;
        heapifyUp(index);
    }

    void insertMultiple(const vector<int>& values) {
        for (int value : values) {
            insert(value);
        }
    }

    void deleteMax() {
        if (size() == 0) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int getMax() { return size() == 0 ? -1 : heap.front(); }

    void printHeap() {
        for (int i : heap)
            cout << i << " ";
        cout << endl;
    }

    void visualizeHeap(int index = 0, int depth = 0) {
        if (index >= size()) return;

        visualizeHeap(rightChild(index), depth + 1);

        for (int i = 0; i < depth; ++i) cout << "    ";
        cout << heap[index] << endl;

        visualizeHeap(leftChild(index), depth + 1);
    }
};

void minHeapUserInteraction() {
    MinHeap heap;
    vector<int> defaultValues = {23, 45, 56, 78, 65, 98};
    heap.insertMultiple(defaultValues);
    cout << "Default values added to the Min-Heap: 23, 45, 56, 78, 65, 98\n";

    int choice;
    string input;
    while (true) {
        cout << "\n--- Min-Heap Arena ---\n"
             << "1. Add Elements to Your Heap\n"
             << "2. Destroy the Smallest Priority\n"
             << "3. Reveal the Smallest Priority\n"
             << "4. Visualize the Heap\n"
             << "5. Exit the Arena\n"
             << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter values to insert (separated by spaces): ";
                getline(cin, input);
                {
                    stringstream ss(input);
                    vector<int> values;
                    int value;
                    while (ss >> value) {
                        values.push_back(value);
                    }
                    heap.insertMultiple(values);
                }
                cout << "Values inserted successfully.\n";
                break;
            case 2:
                heap.deleteMin();
                cout << "Smallest priority destroyed.\n";
                break;
            case 3:
                cout << "The smallest priority is: " << heap.getMin() << "\n";
                break;
            case 4:
                cout << "Heap Visualization:\n";
                heap.visualizeHeap();
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice!\n";
        }
    }
}

void maxHeapUserInteraction() {
    MaxHeap heap;
    vector<int> defaultValues = {23, 45, 56, 78, 65, 98};
    heap.insertMultiple(defaultValues);
    cout << "Default values added to the Max-Heap: 23, 45, 56, 78, 65, 98\n";

    int choice;
    string input;
    while (true) {
        cout << "\n--- Max-Heap Arena ---\n"
             << "1. Add Elements to Your Heap\n"
             << "2. Destroy the Largest Priority\n"
             << "3. Reveal the Largest Priority\n"
             << "4. Visualize the Heap\n"
             << "5. Exit the Arena\n"
             << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter values to insert (separated by spaces): ";
                getline(cin, input);
                {
                    stringstream ss(input);
                    vector<int> values;
                    int value;
                    while (ss >> value) {
                        values.push_back(value);
                    }
                    heap.insertMultiple(values);
                }
                cout << "Values inserted successfully.\n";
                break;
            case 2:
                heap.deleteMax();
                cout << "Largest priority destroyed.\n";
                break;
            case 3:
                cout << "The largest priority is: " << heap.getMax() << "\n";
                break;
            case 4:
                cout << "Heap Visualization:\n";
                heap.visualizeHeap();
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice!\n";
        }
    }
}

int main() {
    cout << "Welcome to HeapMaster: Prioritize Your Data!\n";
    cout << "Choose Your Heap Kingdom:\n"
         << "1. Min-Heap (Minimizing Your Chaos)\n"
         << "2. Max-Heap (Maximizing Your Gains)\n"
         << "Enter your choice: ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        minHeapUserInteraction();
    } else if (choice == 2) {
        maxHeapUserInteraction();
    } else {
        cout << "Invalid choice!\n";
    }

    return 0;
}
