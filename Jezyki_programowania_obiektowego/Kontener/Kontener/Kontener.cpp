#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

//zadanie 1
int randomInt(int min, int max) {
    static std::default_random_engine e{};
    std::uniform_int_distribution<int> d(min, max);
    return d(e);
}

vector<int> generateNumbers(int n)
{
    vector<int> numbers;
    for (int i = 0; i < n; ++i)
    {
        numbers.push_back(randomInt(-20, 20));
    }
    return numbers;
}

   vector<int> removeLargest(vector<int>* wylosowane)
   {
    auto largest = max_element(wylosowane->begin(), wylosowane->end());

        wylosowane->erase(largest);
   
        return *wylosowane;
   }

//zadanie 2

   list<int> generateNumbersList(int n)
   {
       list<int> numbers;
       for (int i = 0; i < n; ++i)
       {
           numbers.push_back(randomInt(-20, 20));
       }
       return numbers;
   }

   list<int> removeLargestList(list<int>& wylosowane) {

       auto largest = max_element(wylosowane.begin(), wylosowane.end());

       wylosowane.erase(largest);

       return wylosowane;
   }







   void countAndPrintOccurrences(const vector<int>& numbersVector, const list<int>& numbersList) {
       // Wyświetlamy wyniki dla wektora
       cout << "Wektora:" << endl;
       for (int num = -20; num <= 20; ++num) {
           int count = std::count(numbersVector.begin(), numbersVector.end(), num);
           if (count > 0) {
               cout << "Liczba " << num << " wystepuje " << count << " razy" << endl;
           }
       }

       // Wyświetlamy wyniki dla listy
       cout << "Listy:" << endl;
       for (int num = -20; num <= 20; ++num) {
           int count = std::count(numbersList.begin(), numbersList.end(), num);
           if (count > 0) {
               cout << "Liczba " << num << " wystepuje " << count << " razy" << endl;
           }
       }
   }

int main()
{
    //zadanie 1
    cout << "Podaj ilosć wylosowanych cyfr: " << endl;
    int n;
    cin >> n;

    vector<int> wylosowane = generateNumbers(n);
    cout << "Wylosowane liczby z zakresu (-20;20) (vector): ";


    for (auto it = wylosowane.begin(); it != wylosowane.end(); ++it) {
        cout << *it << " ";
    }

    vector<int> MaxRemoved = removeLargest(&wylosowane);

    cout << endl;
    cout << endl << "Po usunieciu najwiekszego: ";
    for (int num : MaxRemoved) {
        std::cout << num << " ";
    } 
    cout << endl;

    //zadanie 2
    cout << "Podaj ilosć wylsoowanych cyfr: " << endl;
    int x;
    cin >> x;

    list<int> wylosowaneList = generateNumbersList(x);
    cout << "Wylosowane liczby z zakresu (-20;20) (list): ";


    for (auto it = wylosowaneList.begin(); it != wylosowaneList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    removeLargestList(wylosowaneList);


    cout << endl << "Po usunieciu najwiekszego: ";
    for (int num : wylosowaneList) {
        std::cout << num << " ";
    }
    cout << endl;
    //zadanie3
        
    // Najmniejsza wartość dla wektora
    auto minVector = min_element(wylosowane.begin(), wylosowane.end());
    // Największa wartość dla wektora
    auto maxVector = max_element(wylosowane.begin(), wylosowane.end());

    // Najmniejsza wartość dla listy
    auto minList = min_element(wylosowaneList.begin(), wylosowaneList.end());
    // Największa wartość dla listy
    auto maxList = max_element(wylosowaneList.begin(), wylosowaneList.end());

    cout << "Najmniejsza wartosc z wektora: " << *minVector << endl;
    cout << "Najwieksza wartosc z wektora: " << *maxVector << endl;

    cout << "Najmniejsza wartosc z listy: " << *minList << endl;
    cout << "Najwieksza wartosc z listy: " << *maxList << endl;

    //zadanie 5


    countAndPrintOccurrences(wylosowane, wylosowaneList);

    return 1;
}

            