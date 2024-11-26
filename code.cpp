#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* current_node = nullptr;

void insert() {
    cout << "Enter Music Name:\n";
    string temp;
    cin.ignore();
    getline(cin, temp);

    Node* new_node = new Node();
    new_node->data = temp;

    if (head == nullptr) {
        new_node->next = new_node->prev = new_node;
        head = current_node = new_node;
        return;
    }

    Node* last = head->prev;
    new_node->prev = last;
    last->next = new_node;
    new_node->next = head;
    head->prev = new_node;
}

void Delete_element() {
    if (head == nullptr) {
        cout << "No Music is there to delete!\n";
        return;
    }

    cout << "Enter Music Name to delete:\n";
    string temp;
    cin.ignore();
    getline(cin, temp);

    Node* ptr = head;
    do {
        if (ptr->next == ptr && ptr->data == temp) {
            cout << "One file deleted! Playlist is Empty Now!\n";
            head = nullptr;
            delete ptr;
            return;
        } else if (ptr->data == temp) {
            Node* prev = ptr->prev;
            Node* next = ptr->next;
            prev->next = next;
            next->prev = prev;
            if (ptr == head) head = next;
            delete ptr;
            cout << "Music deleted!\n";
            return;
        }
        ptr = ptr->next;
    } while (ptr != head);

    cout << "No Music file is there!\n";
}

void show() {
    if (head == nullptr) {
        cout << "Playlist is Empty!\n";
        return;
    }

    Node* show_ptr = head;
    cout << "\nDisplaying Playlist:\n";
    int i = 1;
    do {
        cout << "Song " << i << " : " << show_ptr->data << "\n";
        i++;
        show_ptr = show_ptr->next;
    } while (show_ptr != head);
}

void next_node() {
    if (current_node == nullptr) {
        cout << "No songs in Playlist!\n";
    } else {
        current_node = current_node->next;
        cout << "Playing Next Song: " << current_node->data << "\n";
    }
}

void prev_node() {
    if (current_node == nullptr) {
        cout << "No songs in Playlist!\n";
    } else {
        current_node = current_node->prev;
        cout << "Playing Previous Song: " << current_node->data << "\n";
    }
}

void first_node() {
    if (head == nullptr) {
        cout << "Playlist is Empty!\n";
    } else {
        cout << "Playing First Music: " << head->data << "\n";
    }
}

void last_node() {
    if (head == nullptr) {
        cout << "Playlist is Empty!\n";
    } else {
        cout << "Playing Last Music: " << head->prev->data << "\n";
    }
}

void specific_data() {
    if (head == nullptr) {
        cout << "No music is there to be searched!\n";
        return;
    }

    show();
    cout << "Enter Music to play:\n";
    string temp;
    cin.ignore();
    getline(cin, temp);

    Node* ptr = head;
    do {
        if (ptr->data == temp) {
            cout << "Music Found!\n";
            cout << "Playing Music: " << ptr->data << "\n";
            return;
        }
        ptr = ptr->next;
    } while (ptr != head);

    cout << "There is no Music file with this name!\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n-----Song Playlist Application-----\n";
        cout << "1. Add Music\n";
        cout << "2. Remove Music\n";
        cout << "3. Show Playlist\n";
        cout << "4. Play next music\n";
        cout << "5. Play previous music\n";
        cout << "6. Play first music\n";
        cout << "7. Play last music\n";
        cout << "8. Play specific music\n";
        cout << "9. Exit\n\n";
        cin >> choice;

        switch (choice) {
            case 1: insert(); break;
            case 2: Delete_element(); break;
            case 3: show(); break;
            case 4: next_node(); break;
            case 5: prev_node(); break;
            case 6: first_node(); break;
            case 7: last_node(); break;
            case 8: specific_data(); break;
            case 9: exit(0);
            default: cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
