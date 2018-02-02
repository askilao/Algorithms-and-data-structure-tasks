#include <iostream>
using namespace std;
//Nodes and lists use public data members for convenience
//This may make some software engineers froth at the mouth

class Node
{
public:
	int value; //This could really be any type
	Node* next;
	Node* prev;
	Node(int val) {
		std::cout << "Node constructor!" << std::endl;
		this->value = val;
		this->next = (Node*)0;
		this->prev = (Node*)0;
	}
	~Node() {
		std::cout << "Node destructor" << std::endl;
		std::cout << "I had the value " << this->value << std::endl;
	}
};
class List
{

public:
	Node* head;
	Node* tail;

	List() {
		std::cout << "List Constructor!" << std::endl;
		this->head = 0;
		this->tail = 0;
	}
	~List() {
		std::cout << "List destructor!" << std::endl;
	}
	void insert(Node* n, Node* x) {
		if (n != 0) {
			x->next = n->next;
			n->next = x;
			x->prev = n;
			if (x->next != 0)
				x->next->prev = x;
		}
		if (this->head == 0) {
			this->head = x;
			this->tail = x;
			x->prev = 0;
			x->next = 0;
		}
		else if (this->tail == n) {
			this->tail = x;
		}
	}

	void delete_duplicates() {
		Node* i = this->head;
		Node* j;
		Node* k;
		//if the list isnt empty or has only one value
		while (i != NULL && i->next != NULL) {

			j = i;
			//takes out first value and goes through the list to look for duplicated
			while (j->next !=NULL) {
				//if it finds a duplicate it saves it to k, moves the  to its place and deletes k
				if (i->value == j->next->value) {
					k = j->next;
					j->next = j->next->next;
					delete(k);
				}// if not a duplicate go to the next
				else
					j = j->next;
			}
			i = i->next;
		}
	}

	void display() {
		Node* i = this->head;
		std::cout << "List: ";
		while (i != 0) {
			std::cout << i->value << ",";
			i = i->next;
		}
		std::cout << std::endl;
	}
};

int main(int argc, char *argv[])
{
	List* l = new List();
	l->insert(0, new Node(4));
	l->insert(l->head, new Node(6));
	l->insert(l->head, new Node(10));
	l->insert(l->head, new Node(10));
	l->insert(l->head, new Node(12));
	l->display();
	l->delete_duplicates();
	l->display();
	delete l;

	system("PAUSE");
	return 0;
}