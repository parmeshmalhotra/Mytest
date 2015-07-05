#include<iostream>
using namespace std;

class LList;
class Node {
 friend class LList;
 int data;
 Node* next;
};


class LList {
   Node *head;
   public:
//   friend class Node;
   void insertNode(int value);
   void display();
     LList()
      {
        head=NULL;
      }
     ~LList()
      { 
        head=NULL;
      }
};

void LList::insertNode(int value)
{

 if (head == NULL)
    {
       head = new Node;
       head->data = value;
       head->next= NULL;
 //      cout<<"head.data ="<<head->data;
     }
 else 
    { 
      Node *ptr = head;
      while (ptr->next!=NULL)
      { 
       ptr=ptr->next;
      }
      ptr->next = new Node;
      ptr->next->data = value;
    }

}

void LList::display()
{
 Node *ptr = head;
 while (ptr!=NULL)
 {
  cout<<ptr->data<<"\n";
  ptr=ptr->next;
 }
}
int main()
{
 LList l;
 for (int i=1;i<5;i++)
 {
 l.insertNode(i);
 }
 l.display();
}

 
