#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        this->head = NULL;
    }

    void addNode(int data) {
        Node* newNode = new Node(data);
        if (this->head == NULL) {
            this->head = newNode;
            return;
        }
        Node* currentNode = this->head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }

    void printList() {
        Node* currentNode = this->head;
        while (currentNode != NULL) {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }
    
    void deleteNode(int targetValue) {
	// check case 1
	if (head != NULL) {
		// list is not empty
		// need to traverse list, stopping at the last node
		Node * currNode = head;
		// check case 2... the node to delete is the first node
		if (head->data == targetValue)  {
			head = head->next;
			delete currNode;
		}
		else { // case 3... the node to delete is not the first node, but might not even be in the list
			Node * prevNode = NULL;
			while (currNode != NULL && currNode->data != targetValue) {
				prevNode = currNode;
				currNode = currNode->next;
			}
			// check if we found targetValue
			if (currNode != NULL) {
				// did find it
				prevNode->next = currNode->next;
				delete currNode;
			}
		}
	}
}
};

int main() {
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);
    list.deleteNode(2);
    list.printList();
    return 0;
}