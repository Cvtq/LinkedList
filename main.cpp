#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <random>       // std::default_random_engine
#include "LinkedList.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    {      
        LinkedList<int> ll;

        std::vector<int> numbers;

        for (int i = 0; i < 25; i++)
            numbers.push_back(i);

        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));

        srand(std::chrono::system_clock::now().time_since_epoch().count());
        for (size_t i = 0; i < numbers.size(); i++) {
            ll.insert(numbers[i]);
        }

        cout << "Список до сортировки: " << endl;
        std::cout << ll << std::endl;

        cout << "Список после сортировки: " << endl;
        ll.insertionSort();
        std::cout << ll << std::endl;
    }

    {
        cout << endl;
        // Вставка 50 000 раз
        LinkedList<int> ll;

        ll.insert(0);
        auto t_start = std::chrono::high_resolution_clock::now();               
        for (int i = 0; i < 50000; i++) {
            ll.insert(i);
            ll.deleteNodeNumber(0);
        }
        auto t_end = std::chrono::high_resolution_clock::now();        
        double time = std::chrono::duration<double, std::milli>(t_end - t_start).count();
        cout << "Время, затраченное на вставку 50000 раз: " << time << " миллисекунд" << endl;
    }
    
}