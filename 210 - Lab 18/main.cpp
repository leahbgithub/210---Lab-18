// 210 - Lab 18 - Leah Balakrishnan
#include <iostream>
#include <string>
using namespace std;

// Node structure for linked list must be defined
struct Review {
    float rating;
    string comments;
    Review* next;
};

// New node to head function
void addAtHead(Review*& head, float rating, const string& comments) {
    Review* newNode = new Review;
    newNode->rating = rating;
    newNode->comments = comments;
    newNode->next = head;
    head = newNode;
}

// New node to tail function
void addAtTail(Review*& head, float rating, const string& comments) {
    Review* newNode = new Review;
    newNode->rating = rating;
    newNode->comments = comments;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Review* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Traverses linked list and will output the reviews, this is a function
void outputReviews(Review* head) {
    if (head == nullptr) {
        cout << "No reviews available." << endl;
        return;
    }
    
    int count = 0;
    float totalRating = 0;
    Review* temp = head;

    while (temp != nullptr) {
        count++;
        cout << "> Review #" << count << ": " << temp->rating << ": " << temp->comments << endl;
        totalRating += temp->rating;
        temp = temp->next;
    }

    cout << "> Average: " << totalRating / count << endl;
}

// main program
int main() {
    Review* head = nullptr;
    int choice;
    char anotherReview = 'y';

    cout << "Which linked list method should we use?\n";
    cout << "    [1] New nodes are added at the head of the linked list\n";
    cout << "    [2] New nodes are added at the tail of the linked list\n";
    cout << "Choice: ";
    cin >> choice;

    while (anotherReview == 'y' || anotherReview == 'Y') {
        float rating;
        string comments;

        cout << "Enter review rating 0-5: ";
        cin >> rating;
        cin.ignore();  // ignores newline when getting response
        cout << "Enter review comments: ";
        getline(cin, comments);

        if (choice == 1) {
            addAtHead(head, rating, comments);
        } else if (choice == 2) {
            addAtTail(head, rating, comments);
        }

        cout << "Enter another review? Y/N: ";
        cin >> anotherReview;
    }

    cout << "Outputting all reviews:" << endl;
    outputReviews(head);

    // free the memory
    while (head != nullptr) {
        Review* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

