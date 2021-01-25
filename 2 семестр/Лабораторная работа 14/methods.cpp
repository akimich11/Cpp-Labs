#include "tree.hpp"
#include <iostream>

Node* Tree::Clone(Node* T)
{
    if(T == NULL)
        return NULL;
    Node* N = new Node;
    N -> Info = T -> Info;
    N -> Left = Clone(T -> Left);
    N -> Right = Clone(T -> Right);
    return N;
}
void Tree::Erase(Node* T)
{
    if(T != NULL)
    {
        Erase(T -> Left);
        Erase(T -> Right);
        delete T;
    }
}
Tree::Tree(const Tree &T)
{
    root = Clone(T.root);
}
Tree::~Tree()
{
    Erase(root);
    root = NULL;
}

Tree& Tree:: operator = (const Tree& T)
{
    if (&T == this)
		return *this;
    Erase(root);
    root = Clone(T.root);
    return *this;
}

bool Tree:: Insert(const int& c, Node* &T)
{
    if(!T)
    {
        T = new Node;
        T -> Info = c;
        T -> Left = T -> Right = NULL;
        return true;
    }
    else if(c < T -> Info)
    {
        if(T -> Left)
        {
            T -> Left -> Father = T;
            if(Insert(c, T -> Left))
                return true;
            else
                return false;
        }
        else
        {
            T -> Left = new Node;
            T -> Left -> Father = T;
            T -> Left -> Info = c;
            T -> Left -> Left = T -> Left -> Right = NULL;
            return true;
        }
    }
    else if (c > T -> Info)
    {
        if (T -> Right)
        {
            T -> Right -> Father = T;
            if(Insert(c, T -> Right))
                return true;
            else
                return false;
        }
        else
        {
            T -> Right = new Node;
            T -> Right -> Father = T;
            T -> Right -> Info = c;
            T -> Right -> Left = T -> Right -> Right = NULL;
            return true;
        }
    }
    else
        return false;
}
void inorderPrint(Node *T, ostream& fout)
{
    if (T == NULL)
       return;
    inorderPrint(T -> GetLeft(), fout);
    fout << T -> GetInfo() << endl;
    inorderPrint(T -> GetRight(), fout);
}
void Tree::ForEach(void Fun(Node*, ostream&), ostream& fout)
{
    Node* T = root;
    if(T == NULL)
    {
        fout << "Tree is empty" << endl;
        return;
    }
    else
    {
        fout << "List of elements" << endl;
        Fun(T, fout);
    }
    fout << endl;
}
bool Tree:: Find(int c, Node* & root, Node* & Rezult, int & counter)
{
    Node* T = root;
    while (T)
    {
        counter++;
        if (c < T -> Info)
        {
            T = T -> Left;
            continue;
        }
        else if (c > T -> Info)
        {
            T = T -> Right;
            continue;
        }
        else
        {
            Rezult = T;
            return true;
        }
    }
    return false;
}
Node* Leftmost(Node* node) 
{
    if (node == NULL)
        return NULL;
    if (node -> GetLeft() != NULL)
        return Leftmost(node -> GetLeft());
    return node;
}
Node* Rightmost(Node* node) 
{
    if (node == NULL)
        return NULL;
    if (node -> GetRight() != NULL)
        return Rightmost(node -> GetRight());
    return node;
}
bool Tree::Delete(Node* node, int value)
{
    if (node == NULL)
        return false;

    if (value < node -> Info)
        return Delete(node -> Left, value);
    else if(value > node-> Info)
        return Delete(node -> Right, value);
    else  
    {
        if(node -> Left == NULL && node -> Right == NULL) 
        {
            if (node -> Father -> Left == node) 
                node -> Father -> Left = NULL;
            else      
                node -> Father -> Right = NULL;
            delete node;
            return true;
        } 
        else 
        {
            Node * newnode = NULL;
            if(node -> Right != NULL)              
                newnode = Leftmost(node -> Right); //поиск замены удаляемому
            else
                newnode = Rightmost(node -> Left);

            if(newnode -> Father -> Left == newnode) //удаление ссылки на замену
                newnode -> Father -> Left = NULL;
            else
                newnode -> Father -> Right = NULL; 

            if (node -> Father != NULL && node -> Father -> Left == node) //перестройка ссылки на отца
                node -> Father -> Left = newnode;
            else if (node -> Father != NULL) 
                node -> Father -> Right = newnode;
            
            newnode -> Father = node -> Father;
            if(node -> Right != NULL) //перестройка ссылок на поддеревья
            {
                newnode -> Right = node -> Right;
                node -> Right -> Father = newnode;
            }
            if(node -> Left != NULL)
            {
                newnode -> Left = node -> Left;
                node -> Left -> Father = newnode;
            }
            
            if(node -> Father == NULL) //изменение корня, если удаляли его
                root = newnode;
        }
        delete node;
        return true; 
    }
}