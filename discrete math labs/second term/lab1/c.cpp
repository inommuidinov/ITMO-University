#include <bits/stdc++.h>

using namespace std;

struct Node { // структура вершины дерева
    string x; // значение в вершине
    int y; // приоритет в вершине
    int sz; // размер дерева/поддерева
    Node* left; Node* right; // ссылка на левого и правого сынов соответственно
    Node(string xx) { // конструктор для создания нового дерева, состоящего из одного элемента
        x = xx; y = rand(); left = right = NULL; sz = 1;
    };
};

Node* T = NULL; // тот самый "массив строк", изначально пустой

int get_sz(Node* T) { // возвращает размер дерева
    return T ? T->sz : 0;
}

void update(Node* T) { // обновляет размер дерева, понадобится после удаления или добавления элементов
    if (T) {
        T->sz = get_sz(T->left) + 1 + get_sz(T->right);
    }
}

Node* merge(Node* A, Node* B) { // функция слияния двух деревьев
    if (!A) {
        update(B); return B;
    }
    if (!B) {
        update(A); return A;
    }
    if (A->y > B->y) {
        A->right = merge(A->right, B);
        update(A); update(B);
        return A;
    }
    else {
        B->left = merge(A, B->left);
        update(A); update(B);
        return B;
    }
}

pair<Node*, Node*> split(Node* T, int size) { // функция разбиения двух деревьев
    if (!T) {
        return {NULL, NULL};
    }
    int sz_l = get_sz(T->left);
    if (sz_l < size) {
        auto A = split(T->right, size - sz_l - 1);
        T->right = A.fi;
        update(A.fi); update(A.se); update(T);
        return {T, A.se};
    }
    else {
        auto A = split(T->left, size);
        T->left = A.se;
        update(A.fi); update(A.se); update(T);
        return {A.fi, T};
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        if (c == '+') {
            int pos; cin >> pos;
            string val; cin >> val;
            auto A = split(T, pos); // разбиваем дерево на две части, в первой все элементы до pos, во второй - начиная с pos и до конца
            Node* k = new Node(val); // создаем новое дерево состоящее из одной вершины, ключ которой текущая строка
            T = merge(merge(A.fi, k), A.se); // сливаем деревья в одно, сливая сначала первую часть (до pos) и новосозданное дерево, затем результат со второй частью 
        }
        else if (c == '-') {
            int l, r; cin >> l >> r;
            auto A = split(T, l); // разбиваем дерево на две части, в первой все элементы до l, во второй - начиная с l и до конца
            auto B = split(A.se, r - l + 1); // разбиваем вторую часть, в результате в первой получившейся части r - l + 1 элемент (которые собственно и нужно удалить), во второй все остальные
            T = merge(A.fi, B.se); // сливаем нужные части обратно в одно дерево, то есть первое дерево из первого разбиения и второе из второго (первое из второго не нужно, так как содержит удаляемые элементы)
        } else {
            int pos; cin >> pos;
            auto A = split(T, pos); // разбиваем дерево на две части, в первой все элементы до pos, во второй - начиная с pos и до конца
            auto B = split(A.se, 1); // разбиваем вторую часть на две части, в первой будет элемент под индексом pos, во втором все остальные элементы
            cout << B.fi->x << "\n"; // выводим элемент с номером pos
            T = merge(merge(A.fi, B.fi), B.se); // сливаем все части обратно
        }
    }
    return 0;
}

