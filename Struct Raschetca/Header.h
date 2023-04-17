#pragma once
#include <list>
#include <fstream>
#include <iostream>
using namespace std;
struct Node { // Структура узла бинарного дерева
	int value; // Поле данных
	Node* left; // Левый дочерний узел
	Node* right; // Правый дочерний узел
	// Конструктор
	Node(int data) : value(data), left(nullptr), right(nullptr) {} 
};
class BST { // Двоичное дерево поиска
private:
	Node* root; // Корень
	Node* FindMin(Node* node); // Нахождение минимума в двоичном дереве. Используется ф-ией DeleteNode
	Node* InsertNode(int value, Node* node); // Вставить узел, рекурсивная ф-ия 
	Node* DeleteNode(int value, Node* node); // Удалить узел, рекурсивная ф-ия
	void GetValues(Node* node, list<int>* l); // Сформировать список из значений дерева
	void PrintTree(Node* t, int l, ofstream& ofc); // Печать структуры дерева 
	void PrintTreeCout(Node* t, int l); // Печать структуры дерева в cout

public:
	BST(); // Констурктор
	void InsertNode(int x); // Ф-ия ссылкается на private InsertNode, вставка в дерево
	void DeleteNode(int x); // Ф-ия ссылкается на private DeleteNode, удаление из дерева
	void GetValues(list<int>* l); // Ф-ия ссылкается на private GetValues, формирование списка из значений
	void DisplayTree(ofstream& ofc);  // Обращение к PrintTree, печать дерева
	void DisplayTreeCout();  // Обращение к PrintTreeCout, печать дерева в cout 

};