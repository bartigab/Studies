#include <iostream>
#include <string>
#include <cmath>
using namespace std;

float PI = 3.14;

class Circle 
{
private:
    string name;
    float radius;

public:
    Circle() : name(""), radius(0.0) 
    {}
    
    Circle(string n, float r) : name(n), radius(r) 
    {}

    float circumference() {
        return 2 * PI * radius;
    }

    void display() {
        cout << name << " " << circumference() << " ";
    }
};

class Shape {
public:
    virtual float circumference() = 0;
    virtual float area() = 0;
    virtual void display() = 0;
};

class CircleShape : public Shape 
{
private:
    string name;
    float radius;

public:
    CircleShape() : name(""), radius(0.0) 
    {}
    CircleShape(string n, float r) : name(n), radius(r) 
    {}

     float circumference() override {
        return 2 * PI * radius;
    }

    float area()override {
        return PI*radius*radius;
    }

     void display() override {
        cout << name<<" "<<radius<< " " <<circumference()<< " "<< area() <<" "; 
    }
};

class Rectangle : public Shape {
private:
    string name;
    float side1, side2;

public:
    Rectangle() : name(""), side1(0.0), side2(0.0) 
    {}
    Rectangle(string n, float s1, float s2) : name(n), side1(s1), side2(s2) 
    {}

    float circumference() override {
        return 2*(side1+side2);
    }

        float area() override {
            return side1*side2;
        }
    
    void display() override {
        cout <<name<< " "<<side1<< " "<<side2<< " "<<circumference()<< " "<< area() <<" ";
    }
};

int main() {
    short int task;
    cin >> task;
    switch(task)
    {
        case(1):
        {
            int size;
            cin >> size; 

            Circle* circles= new Circle[size];

            for (int i = 0; i < size; i++) {
                
                string name;
                float radius;
                
                cin>>name>>radius;
                
                circles[i] = Circle(name, radius);
            }


            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - i - 1; j++) {
                    if (circles[j].circumference() < circles[j + 1].circumference()) {
                        Circle temp = circles[j];
                        circles[j] = circles[j + 1];
                        circles[j + 1] = temp;
                    }
                }
            }


            for (int i = 0; i < size; i++) {
                circles[i].display();
            }

            delete[] circles;

            break;
        }   
        case(2):
        {
            int rows,cols;
            cin >> rows >> cols;

            Shape*** shapes = new Shape**[rows];
            for (int i = 0; i < rows; i++) {
                shapes[i] = new Shape*[cols];
                for (int j = 0; j < cols; j++) {
                    string name;
                    float dim1, dim2;
                    cin >> name >> dim1;
                    if (i % 2 == 0) {
                        shapes[i][j] = new CircleShape(name, dim1);
                    } else {
                        cin >> dim2;
                        shapes[i][j] = new Rectangle(name, dim1, dim2);
                    }
                }
            }

            int row, col;
            cin >> row >> col;
            shapes[row][col]->display();

            for (int i = 0; i < rows; i++) 
            {
                for (int j = 0; j < cols; j++) {
                    delete shapes[i][j];
                }
                delete[] shapes[i];
            }
            delete[] shapes;

            break;
        }
    }
        
    return 1;
}