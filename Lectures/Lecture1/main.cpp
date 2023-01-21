/************************************************
 *      Linked List
 * 
 *      Review of building a single linked list
 * 
**************************************************/

#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int x) {
    data = x;
    next = nullptr;
  }
};

class Linked {
  Node *front;
  Node *tail;

  void FrontSert(Node *node) {
      node->next = front;
      front = node;
  }

  void TailSert(Node *node) {
      tail->next = node;
      tail = node;
  }

public:
  Linked() { front = tail = nullptr; }

  int Find() { return 0; }

  // will add value to end of list
  void Push(int x) {
    Node *temp = new Node(x);
    if (tail == nullptr) {
      front = tail = temp;
    } else {
      TailSert(temp);
    }
  }

  void OrderedInsert(int x) {
    Node *temp = new Node(x);
    // logic to find spot
    if (!front) {
      front = tail = temp;
    } else if (temp->data < front->data){
      FrontSert(temp);
    } else if(temp->data > tail->data){
      TailSert(temp);
    }else{
      // Node *prev = front;
      // Node *curr = front;
      // while(curr->data < temp->data){
      //   prev = curr;
      //   curr = curr->next;
        
      // }

      Node *travel = front;

      while(travel->next->data < temp->data){
        travel = travel->next;
      }

      temp->next = travel->next;
      travel->next = temp;
        
    }
  }

  bool Remove() { return 0; }

  void Print() {
    Node *travel = front;
    while (travel) {
      cout << travel->data;
      if (travel->next) {
        cout << "->";
      }
      travel = travel->next;
    }
  }
};

int main() {
  Linked L;
  L.OrderedInsert(10);
  L.OrderedInsert(7);
  L.OrderedInsert(4);
  L.OrderedInsert(5);
  L.OrderedInsert(16);
  for(int i=0;i<1000;i++){
    L.OrderedInsert(rand()%1000);
  }
  L.Print();
}