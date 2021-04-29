#ifndef LIST_H
#define LIST_H
/* List.h
 *
 * doubly-linked, double-ended list with Iterator interface
 * Project UID c1f28c309e55405daf00c565d57ff9ad
 * EECS 280 Project 4
 */
#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL


template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:
    int matches(const List<T> &list2) const{
        for (Node* i = first; i != nullptr; i = i->next){
            for (Node* j; j != nullptr; j = j->next){
                
            }
        }
    }
    void remove_middle(){
        Node *left = first;
        Node *right = last;
        while (left != right){
            left = left->next;
            right = right->prev;
        }
        Node* middle = left;
        if (middle == first && middle == last){
            delete middle;
            first = nullptr;
            last = nullptr;
        }
        else {
            middle->prev->next = middle->next;
            middle->next->prev = middle->prev;
            delete middle;
        }
    }
  //EFFECTS:  returns true if the list is empty
    bool empty() const{
        if(first == nullptr){
            return true;
        }
        else {return false;}
    }

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //         with a private member variable.  That's how std::list does it.
    int size() const{
        int tempSize = 0;
        for (Node *i = first; i != nullptr; i = i->next){
              tempSize+=1;
        }
        return tempSize;
    }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
    T & front(){
        assert(first != nullptr);
        assert(last != nullptr);
        return first->datum;
    }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
    T & back(){
        assert(first);
        assert(last);
        return last->datum;
    }

  //EFFECTS:  inserts datum into the front of the list
    void push_front(const T &datum){
        if (first == nullptr && last == nullptr){
            Node *prochaine = new Node;
            prochaine->prev = nullptr;
            prochaine->next = nullptr;
            prochaine->datum = datum;
            first = prochaine;
            last = prochaine;
            return;
        }
        else if (first == nullptr){
            Node *prochaine = new Node;
            prochaine->prev = nullptr;
            prochaine->next = nullptr;
            prochaine->datum = datum;
            first = prochaine;
            last = prochaine;
            return;
        }
        if (size() == 1){
            Node *prochaine = new Node;
            prochaine->prev = nullptr;
            prochaine->next = nullptr;
            prochaine->datum = datum;
            last->prev = prochaine;
            first = prochaine;
            first->next = last;
            return;
        }
        Node *prochaine = new Node;
        prochaine->datum = datum;
        prochaine->next = first;
        prochaine->prev = nullptr;
        first = prochaine;
    }

  //EFFECTS:  inserts datum into the back of the list
    void push_back(const T &datum){
        if (last == nullptr && first == nullptr){
            Node *fresh = new Node{nullptr, nullptr, datum};
            last = fresh;
            first = fresh;
            return;
        }
        if (last == nullptr){
            Node *fresh = new Node{nullptr, last, datum};
            last = fresh;
            return;
        }
        else if (last->prev == nullptr && last->next == nullptr){
            Node *fresh = new Node{nullptr, first, datum};
            last = fresh;
            first->next = last;
            return;
        }
        Node *fresh = new Node;
        fresh->datum = datum;
        fresh->next = nullptr;
        fresh->prev = nullptr;
        if (empty()) {
            first = last = fresh;
        } else {
            last->next = fresh;
            fresh->prev = last;
            last = fresh;
        }
    }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
    void pop_front(){
        assert(first != nullptr);
        if (first->next == nullptr){
            delete first;
            first = nullptr;
            last = nullptr;
            return;
        }
        else if (first->next == last){
            delete first;
            first = last;
            last->prev = nullptr;
            return;
        }
        Node *new_first = first->next;  // temporary keeps track of new first
        delete first;
        first = new_first;
        first->prev = nullptr;
    }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
    void pop_back(){
        assert(first != nullptr);
        if (last->prev == nullptr){
            delete last;
            last = nullptr;
            first = nullptr;
            return;
        }
        else if (size() == 2){
            delete last;
            last = first;
            first->next = nullptr;
            first->prev = nullptr;
            return;
        }
        Node *new_last = last->prev;  // temporary keeps track of new first
        delete last;
        last = new_last;
        last->next = nullptr;
    }

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
    void clear(){
        while (!empty()) {
            pop_front();
        }
    }

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you can omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists

    //overloaded assignment operator
    List & operator=(const List &rhs) {
        if (this != &rhs) {
            clear();
            copy_all(rhs);
        }
        return *this;
    }
    
    List() : first(nullptr), last(nullptr), listSize(0) {};
    ~List(){
        clear();
    };
    List(const List &other){
        copy_all(other);
        listSize = other.listSize;
       
    }
   // ~List();
private:
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
    void copy_all(const List<T> &other){
        for (Node *i = other.first; i != nullptr; i = i->next){
            this->push_back(i->datum);
        }
    }

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty
  int listSize;
    

public:
  ////////////////////////////////////////
  class Iterator {
    //OVERVIEW: Iterator interface to List

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.

    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.

  public:
    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.
    Iterator& operator--() {
      assert(node_ptr);
      node_ptr = node_ptr->prev;
      return *this;
    }
      
      Iterator& operator++(){
          assert(node_ptr);
          node_ptr = node_ptr->next;
          return *this;
      }
      const T& operator*() const{
          assert(node_ptr);
          return node_ptr->datum;
      }
      bool operator!= (Iterator rhs) const {
          return node_ptr != rhs.node_ptr;
      }
      bool operator== (Iterator rhs) const {
          return node_ptr == rhs.node_ptr;
      }

  private:
    Node *node_ptr;//current Iterator position is a List node
    // add any additional necessary member variables here

    // add any friend declarations here
      friend class List;
    // construct an Iterator at a specific position
      Iterator(Node *p) : node_ptr(p){};
      Iterator() : node_ptr(nullptr) {};

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(first);
  }

  // return an Iterator pointing to "past the end"
    Iterator end() const{
        if (last == nullptr){
            return Iterator(nullptr);
        }
        return Iterator(last->next);
    }

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
    void erase(Iterator i){
        assert(i.node_ptr);
        if (i.node_ptr->prev == nullptr){
            pop_front();
            return;
        }
        else if (i.node_ptr->next == nullptr){
            pop_back();
            return;
        }
        Node* curr = i.node_ptr;
        Node* next = curr->next;
        Node* prev = curr->prev;
        prev->next = next;
        next->prev = prev;
        delete curr;
    }

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
    void insert(Iterator i, const T &datum){
        if (i.node_ptr == nullptr){
            push_back(datum);
            
            return;
        }
        else if (i.node_ptr->prev == nullptr){
            push_front(datum);
            return;
        }
        Node* curr = i.node_ptr;
        Node* prev = curr->prev;
        Node* newDatum = new Node{curr, prev, datum};
        prev->next = newDatum;
        curr->prev = newDatum;
    }

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.


#endif // Do not remove this. Write all your code above this line.
