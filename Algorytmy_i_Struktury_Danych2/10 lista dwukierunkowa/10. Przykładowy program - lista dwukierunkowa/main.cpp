#include <iostream>
#include <cassert>
using namespace std;


class Link {
            private:
                double value_;
                Link* next_;
                Link* prev_;
               
                Link(double inValue, Link* ptrNext = nullptr, Link* ptrPrev = nullptr);
               
            public:
                Link* getNext();
                double getValue();
               
            friend class List;
        }; 
        
        
         
        Link::Link(double inValue, Link* ptrNext, Link* ptrPrev):
        value_(inValue), next_(ptrNext), prev_(ptrPrev) {
         
        }
         
        Link* Link::getNext() {
          return next_;
        }
        double Link::getValue() {
          return value_;
        }
    

        class List {
            private:
                Link* first_;
                Link* last_;
               
            public:
                List();
               
                void add(double toAdd);
               
                Link* getFirst();
               
                bool rem(double toRemove);
               
        };
         
         
         
          List::List() {
            first_ = nullptr;
            last_ = nullptr;
          }
         
        void List::add(double toAdd) {
          if(first_ == nullptr) {
            first_ = new Link(toAdd);
            last_ = first_;
          }
          else {
            first_ = new Link(toAdd, first_);
            first_->next_->prev_ = first_;
          }
        }
         
        Link* List::getFirst() {
          return first_;
        }
         
        bool List::rem(double toRemove) {
          Link* tmp = last_;
         
          while(tmp) {
            if(tmp->value_ == toRemove) {
              if(tmp->prev_) {
                tmp->prev_->next_ = tmp->next_;
              }
              else {
                first_ = tmp->next_;
              }
              if(tmp->next_){
                tmp->next_->prev_ = tmp->prev_;
              }
              else {
                last_ = tmp->prev_;
              }
              delete tmp;
              return true;
            }
            tmp = tmp->prev_;
          }
          return false;
        }


         


        ostream& operator<<(ostream &s, List toDisplay) {
           
            Link* tmp = toDisplay.getFirst();
           
            while(tmp) {
                s << tmp->getValue() << " ";
                tmp = tmp->getNext();
            }
            return s;
        }
         
         
        int main() {
            List myList;
           
            int M;
            double userValue;
            cin >> M;
           
            for(int i = 0; i < M; i++) {
                cin >> userValue;
                myList.add(userValue);
            }
           
            cout << myList;
         
            cin >> M;
            for(int i = 0; i < M; i++) {
                cin >> userValue;
                myList.rem(userValue);
            }
           
            cout << myList;
           
            return 0;
        }

