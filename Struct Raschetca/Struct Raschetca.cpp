#include <iostream>
#include "Header.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    ifstream fin("In.txt", ios_base::in);  // Поток на ввод
    ofstream fout("Out.txt", ios_base::out);  // Поток на вывод
    string str_cur;   // Текущая обрабатываемая строка (буфер)
    int buf; // Буфер
    BST tree1, tree2;  // Деревья                     
    list <int> values_tree1; // Список под первое дерево

    // Обработка первого входного дерева (в виде потока чисел)
    getline(fin, str_cur);
    std::stringstream ss1(str_cur);
    while (ss1.eof() == false) {               // Цикл обработки подстрок текущей строки документа
        getline(ss1, str_cur, ' ');
        if (str_cur.size() == 0)            // Пропуск пробелов
            ss1.peek();
        else {
            buf = stoi(str_cur);
            tree1.InsertNode(buf); // Вставка в дерево
        }
    }
    // Обработка второго входного дерева (в виде потока чисел)
    getline(fin, str_cur);
    std::stringstream ss2(str_cur);
    while (ss2.eof() == false) {               // Цикл обработки подстрок текущей строки документа
        getline(ss2, str_cur, ' ');
        if (str_cur.size() == 0)            // Пропуск пробелов
            ss2.peek();
        else {
            buf = stoi(str_cur);
            tree2.InsertNode(buf);
        }
    }
    fin.close();

    // Получение значений первого дерева в список
    cout << "Начальное дерево 1:" << endl;
    fout << "Начальное дерево 1:" << endl;
    tree1.DisplayTree(fout);
    tree1.DisplayTreeCout();
    tree1.GetValues(&values_tree1);
    // Вывод начального дерева (перед изменением)
    cout << "Начальное дерево 2:" << endl;
    fout << "Начальное дерево 2:" << endl;
    tree2.DisplayTree(fout);
    tree2.DisplayTreeCout();
    // Отступ
    fout << endl;
    cout << endl;
    cout << "Конечное дерево 2:" << endl;
    fout << "Конечное дерево 2:" << endl;
    // Итерация по списку, попытка удаления текущего значения из дерева. Сложность O(N*Z), N и Z - кол-во звеньев в первом и втором деревьях.
    // При Z~N O(N^2)
    std::list<int>::iterator it;
    for (it= values_tree1.begin(); it != values_tree1.end(); it++)
    {
        tree2.DeleteNode(*it);
    }
    // Вывод конечного дерева
    tree2.DisplayTree(fout);
    tree2.DisplayTreeCout();
    system("pause");
}

