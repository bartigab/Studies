#include <iostream>
#include <string>
#include <cmath>
using namespace std;


template <class T> class List;

// ======================================================================
//                          Class Template Link
// ======================================================================

template <class T>
class Link {
	private:
		T value;
		Link* next;
		Link* previous;

	public:
		Link(T val, Link* nextPtr = nullptr, Link* previousPtr = nullptr)
			:value(val), next(nextPtr), previous(previousPtr) {}

		~Link() {}

		Link* getNext() {
			return next;
		}

		Link* getPrevious() {
			return previous;
		}

		T getValue() {
			return value;
		}

		friend class List <T>;
};

// ======================================================================
//                          Class Template List
// ======================================================================

template <class T>
class List {
	private:
		Link<T>* first;
		Link<T>* last;

	public:
		List()
			:first(nullptr), last(nullptr) {}

		~List() {}

        Link<T>* getFirst() {
			return first;
		}

        Link<T>* getLast() {
			return last;
		}

        void addElement(T val) {
            if (first == nullptr) {
				first = new Link<T>(val, nullptr, nullptr);
				last = first;
            } else {
				Link<T>* tmp = first;

                while (tmp) {
                    if (tmp->getValue() > val) {
                        if (tmp->getPrevious()) {
							tmp->getPrevious()->next = new Link<T>(val, tmp, tmp->getPrevious());
							tmp->previous = tmp->getPrevious()->next;
                        } else {
							first = new Link<T>(val, tmp, nullptr);
							tmp->previous = first;
						}
						return;
					}
					tmp = tmp->getNext();
				}
				last->next = new Link<T>(val, nullptr, last);
				last = last->next;
			}
		}

		void removeElement(T value) {
			Link<T>* tmp = last;

			while (tmp) {
				if (tmp->getValue() == value) {
					if (tmp->getPrevious())
						tmp->getPrevious()->next = tmp->getNext();
					else
						first = tmp->getNext();

					if (tmp->getNext())
						tmp->getNext()->previous = tmp->getPrevious();
					else
						last = tmp->getPrevious();

					delete tmp;
				}
				tmp = tmp->getPrevious();
			}
		}
};

template <typename T>
ostream& operator<<(ostream& os, List<T>& list) {
	Link<T>* tmp = list.getLast();

	while (tmp) {
		os << tmp->getValue() << " ";
		tmp = tmp->getPrevious();
	}
	return os;
}

// ======================================================================
//							Class Complex
// ======================================================================

class Complex {
	private:
		float real{};
		float imaginary{};

	public:
		Complex(float r, float i)
			:real(r), imaginary(i) {}

		~Complex() {}

		float getReal() const {
			return real;
		}

		float getImaginary() const {
			return imaginary;
		}

		float getModule() {
			return sqrt(real * real + imaginary * imaginary);
		}

		bool operator==(Complex& complex_) {
			return (real == complex_.getReal() && imaginary == complex_.getImaginary());
		}

		bool operator<(Complex& complex_) {
			if (getModule() < complex_.getModule())
				return true;
			else if (getModule() == complex_.getModule()) {
				if (real < complex_.getReal())
					return true;
				else if (real == complex_.getReal()) {
					if (imaginary < complex_.getImaginary())
						return true;
				}
			}
			return false;
		}

		bool operator>(Complex& complex_) {
			if (getModule() > complex_.getModule())
				return true;
			else if (getModule() == complex_.getModule()) {
				if (real > complex_.getReal())
					return true;
				else if (real == complex_.getReal()) {
					if (imaginary > complex_.getImaginary())
						return true;
				}
			}
			return false;
		}

		friend ostream& operator<<(ostream& os, const Complex& complex_) {
			if (complex_.getImaginary() == 0)
				os << complex_.getReal();
			else if (complex_.getImaginary() > 0)
				os << complex_.getReal() << "+" << complex_.getImaginary() << "i";
			else
				os << complex_.getReal() << complex_.getImaginary() << "i";
			return os;
		}
};
int main() {
    
    List<Complex> list_obj;
    int x,y;
    float real, imaginary;
    cin>> x;
    for(int i=0; i<x; ++i){
        cin>> real >> imaginary;
        Complex complex_(real, imaginary);
        list_obj.addElement(complex_);
        
    }
    
    cout<< list_obj;
    
    cin>> y;
        for(int i=0; i<y; ++i){
        cin>> real >> imaginary;
        Complex complex_(real, imaginary);
        list_obj.removeElement(complex_);
        
    }
    
    cout << list_obj;
    
    return 1;
}