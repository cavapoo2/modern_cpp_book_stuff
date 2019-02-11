#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<limits>
#include<cassert>
#include<string>
#include<memory>
using std::default_random_engine;
using std::numeric_limits;
using std::random_device;
using std::uniform_int_distribution;


using namespace std;

template<typename T>
struct Node {
  T data;
  Node<T> *next;
};

template<typename T>
struct List {
  List() = delete;
  List(Node<T>* n):root(n)
  {
    cout <<"List(Node)" << endl;
   // copy(n);
    cout <<"List(Node) done!" << endl;
  }
  List<T>& operator=(const List<T>& other){
    if(this == &other) return *this;
    cout << "using op = " << endl;
    removeElements();
    cout << "using op = remove old" << endl;
    copy(other.get());
    cout << "using op = copied new" << endl;
    //delete old element
    return *this;
  }
  List<T>(const List<T>& other) {
    cout << "using copy constr" << endl;
    copy(other.get());
  }
  Node<T>* get()const {
    return root;
  }
  int len() const {
    int count=0;
    Node<T>* cur = root;
    while(cur != nullptr){
      count++;
      cur = cur->next;
    }
    return count;
  }

  ~List(){
    cout << "in ~List" << endl;
    while(root != nullptr){
      Node<T>* nxt = root->next;
      delete root;
      root = nxt;
    }
  }
  private:
  void removeElements() {
    cout << "remove Elements" << endl;
    show(root);
    while(root != nullptr){
      Node<T>* nxt = root->next;
      delete root;
      root = nxt;
    }
    cout << "remove Elements done!" << endl;
  }
  void copy(Node<T>* in) {
    cout << "deep copy Elements" << endl;
    Node<T>* start = nullptr;
    Node<T>* cur = nullptr;
   // show(in);
    while(in != nullptr)
    {
      Node<T>* n = new Node<T>;
      n->data = in->data;
    //  cout << n->data << ",.";
      n->next = nullptr;
      if(start == nullptr){
        start = cur =  n;
      }else {
        cur->next = n;
        cur =  n;
      }
      in = in->next;
    }
    cout << endl;
    root = start;
 //   show(root);
    cout << "deep copy Elements done!" << endl;
  }
  Node<T>* root;
};
template<typename T>
void show(const List<T> &in){
  Node<T>* n =in.get(); 
  while(n != nullptr){
    cout << n->data << ",";
    n = n->next;
  }
  cout << endl;
}
template<typename T>
void show(Node<T>* n){
  while(n != nullptr){
    cout << n->data << ",";
    n = n->next;
  }
  cout << endl;
}


template< typename T>
List<T> reverse(const List<T> & lst){

  Node<T>* res = nullptr;
  Node<T>* cur = lst.get();
  while(cur != nullptr) {
    if(res == nullptr){
      //      cout << "start" << endl;
      res = new Node<T>;
      res->data = cur->data;
      res->next = nullptr;
      //    cout << "starte" << endl;
    }else {
      //  cout << "next" << endl;
      Node<T>* temp = new Node<T>;
      temp->data = cur->data;
      temp->next = res;
      res = temp;
      //cout << "nexte" << endl;

    }
    //cout << "cur=" << cur->data << endl;
    cur = cur->next;

  }
  return List<T>(res);

}
/*
 *
 */
/*note this assumes the digits are ordered with smallest first, e.g
 * the number 123 with be ordered 3->2->1 in the list*/ 

Node<int>* sumIntsHelper(Node<int>*n1, Node<int>*n2,int carry){
  //cout << "in SumIntsHelper" << endl;
  if(n1 == nullptr && n2 == nullptr && carry == 0) return nullptr;

  Node<int> *res = new Node<int>;
  //cout << "alloc" << endl;
  res->next = nullptr;
  int val = carry;
  if(n1 != nullptr) val+= n1->data;
  if(n2 != nullptr) val+= n2->data;

  res->data = val % 10;
  int nc = val >= 10 ? 1 : 0;

  //cout << "if test" << endl;
  if(n1 != nullptr || n2 != nullptr || nc != 0){
    Node<int>*n1x = (n1 != nullptr) ? n1->next : nullptr;
    Node<int>*n2x = (n2 != nullptr) ? n2->next : nullptr;
    //cout << "recur" << endl;
    Node<int>* ret = sumIntsHelper(n1x,n2x,nc);
    res->next = ret;

  }
  return res;

}

List<int> sumIntsRecur(const List<int>&a, const List<int>&b) {

  Node<int>* an = a.get();
  Node<int>* bn = b.get();
  //  cout << "call sumIntsHelper" << endl;
  Node<int> *rn = sumIntsHelper(an,bn,0);

  return List<int>(rn);
}
/*note this assumes the digits are ordered with smallest first, e.g
 * the number 123 with be ordered 3->2->1 in the list*/ 
List<int> sumInts(const List<int> &a, const List<int>& b){
  Node<int>* n1 = a.get();
  Node<int>* n2 = b.get();
  Node<int>* res = nullptr;
  Node<int>* prev = nullptr;
  int carry = 0;
  while(n1 != nullptr || n2 != nullptr || carry > 0) {
    //  cout << "begin" << endl;
    int sum = carry;
    if(n1 != nullptr){
      sum += n1->data;
    }
    if(n2 != nullptr) {
      sum += n2->data;
    }
    int low = sum % 10;
    if(sum >= 10) carry =1;
    else carry = 0;
    if(res == nullptr){
      //  cout << "start" << endl;
      res = new Node<int>;
      res->data = low;
      res->next = nullptr;
      prev = res;
      //cout << "starte" << endl;

    }
    else {
      // cout << "nxt" << endl;
      Node<int> *n  = new Node<int>;
      n->data = low;
      n->next = nullptr;
      prev->next = n;
      prev = n;
      // cout << "nxte" << endl;
    }

    n1 = n1 != nullptr ? n1->next : n1;
    n2 = n2 != nullptr ? n2->next : n2;
    //cout << "loop" << endl;
  }
  return List<int>(res);

}
struct Sum {
  int data;
  int carry;

};
template<typename T>
int getLength(const Node<T>* n){
  int count=0;
  while(n != nullptr) {
    count++;
    n = n->next;
  }
  return count;
}
/*pad to front of list n zeros*/
Node<int>* padZeros(Node<int>* in, int n){

  Node<int>* head  = nullptr;
  Node<int>* cur = nullptr;
  for(int i=0; i < n; ++i) {
    Node<int>* n = new Node<int>;
    n->next = nullptr;
    n->data = 0;
    if(i ==0) {
      head = cur = n;
    }
    cur->next = n;
    cur = n;

  }
  //now join intput list with zeros
  cur->next = in;
  return head;
}

List<int> padListZeros(const List<int>& in, int n){
  cout << "in padListZeros" << endl;
  if (n == 0) return in;
  Node<int>* res = padZeros(in.get(),n);
  cout<<"pad"<<endl;
  show(in);
  show(res);
  return List<int>(res);

}

/*sum Ints, this assumes that they ordered with msb first. eg the number
 * 123 is ordered 1->2->3 in the list */

List<int> sumIntsRev(const List<int>& la, const List<int>& lb) {
  if(la.len() == 0 && lb.len() == 0) return List<int>(la.get());
  int lena = la.len();
  int lenb = lb.len();
  List<int> temp(nullptr);
  if(lena != lenb){
    if(lena > lenb){
      int diff = lena - lenb;
      cout << "len a > lenb " << diff << endl;
      show(lb);
      //List<int> ab = padListZeros(lb,diff);
      temp = padListZeros(lb,diff);
      cout << "ret padListZeros" << endl;
      //show(ab);
      show(temp);
    }
    else
    {
      int diff =  lenb - lena;
      cout << "lenb  > lena " << diff << endl;
      show(la);
      //List<int> ba = padListZeros(la,diff);
      temp = padListZeros(la,diff);
      show(temp);
    }
  }
  cout<< "ret from sumIntsrev" << endl;
  //show(temp);
  return temp;

}


List<int> genIntList(int length){
  Node<int> *head = nullptr;
  Node<int>* prev = nullptr;

  default_random_engine gen((random_device())());
  uniform_int_distribution<int> dis(0,9 );
  for(int i =0; i < length; i++) {
    int x = dis(gen);
    Node<int>* n = new Node<int>;
    n->data = x;
    n->next = nullptr;
    if(head == nullptr) {
      head = prev = n;
    }
    else 
    {
      prev->next = n;
      prev = n;
    }

  }
  return List<int>(head);

}

int main(int arg, char* argv[])
{
  /*
  List<int> lst = genIntList(3);
  List<int> lst2 = genIntList(3);
  List<int> res = sumInts(lst,lst2);
  show(lst);
  show(lst2);
  show(res);

  List<int> rev = reverse(res);
  show(rev);

  List<int> resr = sumIntsRecur(lst,lst2);
  show(resr);
  //pad list
  List<int> pad = genIntList(5);
  List<int> padr = padListZeros(pad,5);
  cout<<"pad"<<endl;
  show(pad);
  cout<<"padr"<<endl;
  show(padr);
  */
  /*
  List<int> rtest1 = genIntList(6);
  List<int> rtest2 = genIntList(4);
  show(rtest1);
  show(rtest2);
  cout << "sumIntsRev test " << endl;
  List<int> rrtest = sumIntsRev(rtest1,rtest2);
  */
 List<int> rtest1 = genIntList(6);
  show(rtest1);
  List<int> res(nullptr);
  res=  padListZeros(rtest1,5);
  cout << "showing res" << endl;
  show(res);

  




  return 0;
}


