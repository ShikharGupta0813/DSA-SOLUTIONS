//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

//Back-end complete function template for C++

class Solution {

  public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* current = head;
        Node* next;

        while (current != NULL) {
            next = current->next; // storing next node
            current->next = prev; // linking current node to previous
            prev = current;       // updating prev
            current = next;       // updating current
        }

        return prev;
    }

  public:
    Node* addOne(Node* head) {
        head = reverse(head); // reversing list to make addition easy

        Node* current = head;
        int carry = 1;

        while (carry) {
            current->data += 1; // adding one to current node

            if (current->data < 10)
                return reverse(head);
            // if no carry we can reverse back list and return it
            else
                current->data = 0;
            // else we continue with taking carry forward

            if (current->next == NULL)
                break;
            // if, end of list, we break from loop
            else
                current = current->next;
            // else we move to next node
        }

        current->next = new Node(1); // adding new node for the carried 1
        return reverse(head);
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends