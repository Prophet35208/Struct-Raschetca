#include "Header.h"
#include <iostream>;
using namespace std;
// Конструктор
BST::BST()
{
	root = nullptr;
}
// Нахождение минимума в дереве. 
// Проводится обход по левой части дерева. 
// Функция рекурсивна. Кол-во вызовов определяется глубиной дерева(G). Отсюда сложность O(G).
// В худшем случае G=N, отсюда сложность O(N)
Node* BST::FindMin(Node* node)
{
	if (node == nullptr)
		// Возврат при пустом указателе узла
		return nullptr;
	else
		if (node->left == nullptr)
			// Возвращение минимумального узла
			return node;
		else
			// Переход к следующему узлу, если он существует.
			// После раскрутки ф-ий ,первая вызванная возвратит адрес минимального узла
			return FindMin(node->left);
}
// Вставка числа в дерево.
// Функция рекурсивна. Кол-во вызовов определяется глубиной дерева(G). Отсюда сложность O(G).
// В худшем случае G=N, отсюда сложность O(N)
Node* BST::InsertNode(int value, Node* node)
{
	if (node == nullptr)
	{
		// Создание узла. Здесь же возможно создание корня, если вызов первой ф-ии приведёт сюда
		node = new Node(value);
		node->left = node->right = nullptr;
	}
	else
		if (value < node->value)
			// Если число меньше числа текущего узла, то переход по левой ветви
			node->left = InsertNode(value, node->left);
		else
			if (value > node->value)
				// Если число больше числа текущего узла, то переход по правой ветви
				node->right = InsertNode(value, node->right);
	// Возврат текущего обрабатываемоего узла. Первая вызванная ф-ия возвратит корень при раскрутки рекурсии
	return node;
}
// Удаление узла из дерева.
// Функция рекурсивна. Кол-во вызовов определяется N. Отсюда сложность O(N).
Node* BST::DeleteNode(int value, Node* node)
{
	// Вспомогательный буффер при удалении
	Node* temp;
	if (node == nullptr)
		return nullptr;
	else
		// Если искомое значение меньше текущего значения узла, то переход по левой ветви
		if (value < node->value)
			node->left = DeleteNode(value, node->left);
		else
			// Если искомое значение больше текущего значения узла, то переход по правой ветви
			if (value > node->value)
				node->right = DeleteNode(value, node->right);
			else
				if (node->left && node->right)
				{
				// Если у удаляемого узла есть 2 дочерних, тогда нужно вместо удаляемого узла вставить
				// минимальный узел правого поддрева, где корень поддрева-удаляемый узел 
					temp = FindMin(node->right);
					node->value = temp->value;
					// Удаление минимума поддрева
					node->right = DeleteNode(node->value, node->right);
				}
				else
				{
					// Переход при одном потомке или же при их отсутствии
					temp = node;
					// Если есть только правый потомок, то родитель заменяется им
					if (node->left == nullptr)
						node = node->right;
					else 
					// Если есть только левый потомок, то родитель заменяется им
						if (node->right == nullptr)
						node = node->left;
					delete temp;
				}
	return node;
}
// Получение значений в список. При этом в память загружается N значений
void BST::GetValues(Node* node,list<int>* l)
{
	if (node == NULL)
		// Возврат при достижения конца
		return;
	// Переход по левой ветви
	GetValues(node->left, l);
	l->push_back(node->value);
	// Переход по правой ветви
	GetValues(node->right,l);
}

// Ф-ия, предоставленная пользователю. Позволяет создать узел
void BST::InsertNode(int x)
{
	// Создание корня, если его не было. В ином случае значение корня не изменится
	root = InsertNode(x, root);
}
// Ф-ия, предоставленная пользователю. Позволяет создать узел
void BST::DeleteNode(int x)
{
	// Если корень не был удалён, то он не изменится. Если корень удалён, определяется новый
	root = DeleteNode(x, root);
}

// Ображение к GetValues
void BST::GetValues(list<int>* l)
{
	GetValues(root, l);
}

// Вывод дерева в поток
void BST::PrintTree(Node* t, int l, ofstream& ofc)
{
	if (t == NULL)
		return;
	PrintTree(t->right, l + 1, ofc);
	for (int i = 0; i < l; ++i)
		// Отступ исходя из текущего уровня дерева
		ofc << "\t";
	ofc << t->value << endl;
	PrintTree(t->left, l + 1, ofc);
}
// Ображение к PrintTree со стороны пользователя
void BST::DisplayTree(ofstream& ofc)
{
	PrintTree(root, 0, ofc);
}
// Вывод дерева в cout
void BST::PrintTreeCout(Node* t, int l)
{
	if (t == NULL)
		return;
	PrintTreeCout(t->right, l + 1);
	for (int i = 0; i < l; ++i)
		// Отступ исходя из текущего уровня дерева
		cout << "\t";
	cout << t->value << endl;
	PrintTreeCout(t->left, l + 1);
}
// Ображение к PrintTreeCout со стороны пользователя
void BST::DisplayTreeCout()
{
	PrintTreeCout(root, 0);
}



