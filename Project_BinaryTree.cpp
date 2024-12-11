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

    // Public function to insert a value into the tree
    void insert(int data) {
        root = insertRec(root, data);  // Recursive insert function
        cout << "The Tree of Wisdom grows with new knowledge: " << data << endl;
        this_thread::sleep_for(chrono::milliseconds(500));  // Adding delay for animation
    }

    // Public function to insert multiple values at once
    void insertMultiple(const vector<int>& values) {
        for (int value : values) {
            insert(value);  // Insert each value individually
        }
    }

    // Public function for inorder traversal
    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    // Public function for preorder traversal
    void preorder() {
        preorderRec(root);
        cout << endl;
    }

    // Public function for postorder traversal
    void postorder() {
        postorderRec(root);
        cout << endl;
    }

    // Public function to search for a value in the tree
    Node* search(int data) {
        return searchRec(root, data);
    }

    // Public function to delete a value from the tree
    void deleteNode(int data) {
        root = deleteRec(root, data);
    }

private:
    // Recursive function to insert a value into the tree
    Node* insertRec(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);  // Create a new node if position is empty
        }

        // Recursively insert the value in the correct subtree
        if (data < node->data) {
            node->left = insertRec(node->left, data);
        } else {
            node->right = insertRec(node->right, data);
        }
        return node;  // Return the updated node
    }

    // Private recursive function for inorder traversal (left, root, right)
    void inorderRec(Node* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            cout << node->data << " -> ";
            inorderRec(node->right);
        }
    }

    // Private recursive function for preorder traversal (root, left, right)
    void preorderRec(Node* node) {
        if (node != nullptr) {
            cout << node->data << " -> ";
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }

    // Private recursive function for postorder traversal (left, right, root)
    void postorderRec(Node* node) {
        if (node != nullptr) {
            postorderRec(node->left);
            postorderRec(node->right);
            cout << node->data << " -> ";
        }
    }

    // Private recursive function to search for a value in the tree
    Node* searchRec(Node* node, int data) {
        // Base case: value is found or node is null
        if (node == nullptr || node->data == data) {
            return node;
        }

        // Recursively search in the left or right subtree
        if (data < node->data) {
            return searchRec(node->left, data);
        }
        return searchRec(node->right, data);
    }

    // Private recursive function to delete a value from the tree
    Node* deleteRec(Node* root, int key) {
        if (root == nullptr) return root;
        if (key < root->data) {
            root->left = deleteRec(root->left, key);
        } else if (key > root->data) {
            root->right = deleteRec(root->right, key);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteRec(root->right, temp->data);
        }
        return root;
    }

    // Function to find the node with the minimum value in a subtree
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }
};

void binaryTreeUserInteraction() {
    BinaryTree tree; //declare object tree
    vector<int> defaultValues = {23, 45, 56, 78, 65, 98};
    tree.insertMultiple(defaultValues);
    cout << "Default values inserted: 23, 45, 56, 78, 65, 98" << endl;

    int choice;
    string input;
    int value; // Declare the value variable here
    while (true) {
        cout << "1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Search\n6. Delete\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter values to insert (separated by spaces): ";
            getline(cin, input);
            {
                stringstream ss(input);
                vector<int> values;
                while (ss >> value) {
                    values.push_back(value);
                }
                tree.insertMultiple(values);  // No longer checks for a minimum number of values
            }
            break;

            case 2:
                cout << "Inorder traversal: ";
                tree.inorder();
                break;
            case 3:
                cout << "Preorder traversal: ";
                tree.preorder();
                break;
            case 4:
                cout << "Postorder traversal: ";
                tree.postorder();
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                cout << (tree.search(value) != nullptr ? "Found" : "Not Found") << endl;
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                tree.deleteNode(value);
                break;
            case 7:
                return;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}

int main() {
    binaryTreeUserInteraction();  // Begin user interaction with the tree
    return 0;
}
