// Name : zaid , Section SE-A , Roll No : 22i-2513

#include<iostream>
using namespace std;
template<typename T>
class Node {
public:
	T data;
	Node<T>* next;
	Node<T>* LeftY;
	Node<T>* RightY;
	Node(T d):data(d),next(nullptr), LeftY(nullptr), RightY(nullptr){}

};
template<typename T>

class YshapeList {
	Node<T>* head;
public:
	YshapeList():head(nullptr){}
	void Insert(T val) {
		Node<T>* newNode = new Node<T>(val);
		if (!head) {
			head = newNode;
			return;

		}
		if (!head->next) {
			head->next = newNode;

			return;
		}
		int CountL = 0;
		int CountR = 0;

		Node<T>* currentL = head->next;
		Node<T>* currentR = head->next;

		while (currentL->LeftY != nullptr) {

			currentL = currentL->LeftY;

			CountL++;
		}
		while (currentR->RightY != nullptr) {

			currentR = currentR->RightY;

			CountR++;
		}
		if (CountL <= CountR) {
			currentL->LeftY = newNode;
		}
		else {
			currentR->RightY = newNode;
		}
	}
	void displayL() {
        cout << " [L]";
         Node<T>* Current = head->next;
         while (Current) {
             cout << Current->data << " ";
             Current = Current->LeftY;
         }
         cout << "[L] ";
     }
     void displayR() {
         cout << " [R]";
         Node<T>* Curr = head->next;
         while (Curr) {
             cout << Curr->data << " ";
            Curr = Curr->RightY;
        }
        cout << "[R] ";
    }
    void display() {
        Node<T>* CURR = head;
        while (CURR) {
            cout << CURR->data << " ";
            CURR = CURR->next;
        }
        displayL();
        displayR();

        cout << endl;
    }


	

};
int main() {
	YshapeList<int> Y;
	cout << "Displaying Integers : ";

	
	Y.Insert(32);
	Y.Insert(42);
	Y.Insert(52);
	Y.Insert(62);
	Y.Insert(72);
	Y.Insert(82);
	Y.Insert(92);
	Y.Insert(22);
	Y.Insert(12);
	Y.Insert(2);

	Y.display();
	cout << endl;
	cout << endl;
	cout << "Displaying Characters : ";
	YshapeList<char> Y2;


	Y2.Insert('v');
	Y2.Insert('c');
	Y2.Insert('f');
	Y2.Insert('d');
	Y2.Insert('f');
	Y2.Insert('x');
	Y2.Insert('c');
	Y2.Insert('b');
	Y2.Insert('m');
	
	Y2.display();
}
