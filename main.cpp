#include <iostream>
#include <vector>

void enterData(int & var, std::string name, int low, int high){
    do{
        std::cout << "\nEnter " << name << ": ";
        std::cin >> var;
    } while(var > high || var < low);
}

void printVector(std::vector<int> & vec){
    for (int el : vec) std::cout << el << " ";
}

std::vector<int> removeValue(std::vector<int> & vec, int value){
    int shift = 0;
    std::vector<int> newVec;
    for(int elem : vec){
        if(elem != value) newVec.push_back(elem);
    }
    vec.resize(vec.size() - shift);
    return newVec;
}

void task1(){
    /*
     * Задача 1.
    Пользователь вводит с клавиатуры число n, далее -- n целых чисел, которые нужно записать в вектор.
    Потом пользователь вводит ещё одно значение. Нужно удалить из вектора все элементы, которые равны данному значению,
    и вывести итоговое состояние вектора
    Пример:
    Пользователь ввёл 5, потом числа 1, 3, 3, 5, 1. И потом -- число 3. Необходимо, чтобы в векторе остались числа
    1, 5, 1, которые надо вывести их на экран.
     * */
    int n, element;
    std::vector<int> numbers;
    enterData(n, "n", 1, 1e9);
    for (int i = 0; i < n; i++){
        std::cout << "Enter element " << i << std::endl;
        std::cin >> element;
        numbers.push_back(element);
    }
    enterData(element, "value to remove", -1e9, 1e9);
    numbers = removeValue(numbers, element);
    printVector(numbers);
}

void task2(){
    /*
     * Задача 2.
     С помощью списка инициализации задаётся вектор цен на продукты (дробными числами). Так же, с помощью списка
     инициализации, задаётся вектор покупок (в виде индексов), которые совершает человек. Необходимо вывести на экран
     итоговую стоимость покупок
     Пример:
     Вектор цен выглядит так:  {2.5, 4.25, 3.0, 10.0}
     Вектор покупок: {1, 1, 0, 3}, то есть два товара по индексу 1, и по одному — индексов 0 и 3.
     Суммарная стоимость будет равна 21.0
     * */
    std::vector<float> prices = {2.5, 4.25, 3.0, 10.0};
    std::vector<int> items = {1, 1, 0, 3};
    float totalPrice = 0.0;
    for (int item : items){
        totalPrice += prices[item];
    }
    std::cout << "Total price: "<< totalPrice << std::endl;
}

void task3(){
    /*
     * Задача 3.
     В базу данных, являющуюся вектором, с клавиатуры приходят целочисленные значения, и помещаются в конец. Однако,
     эта база может хранить только 20 элементов, а дальше необходимо будет удалять элементы, которые лежат в базе дольше
     всех.
     При вводе -1 с клавиатуры необходимо вывести всё содержимое базы данных (то есть 20 или менее элементов).
     При выводе элементы должны быть в том порядке, в котором они добавлялись в базу данных.
     Попробуйте написать максимально оптимизированное решение данной задачи, чтобы совершалось как можно меньше
     расширений и перемещений элементов внутри вектора.
     * */
    const int MAX_SIZE = 20;
    int element=0;
    std::vector<int> vec;
    while(element != -1){
        std::cout << "Enter new element" << std::endl;
        std::cin >> element;
        if(vec.size() > MAX_SIZE){
            for(int i = 0; i < vec.size() - MAX_SIZE; i++) vec = removeValue(vec, vec.front());
        }
        vec.push_back(element);
    }
    printVector(vec);
}

int main() {
//    task1();
//    task2();
    task3();
    return 0;
}
