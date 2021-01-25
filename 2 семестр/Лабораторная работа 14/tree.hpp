#include <fstream>
#include "node.hpp"
using namespace std;

#pragma once

class Tree
{
private:
    Node* root;
public:
    Tree() { root = NULL; };
    Tree(const Tree &);
    ~Tree();
    Node* & GetRoot(){ return root; };
    Tree& operator = (const Tree&);
    
    bool Insert(const int&, Node* &);
    bool Find(int, Node* &, Node* &, int &);
    bool Delete(Node*, int);
    
    void ForEach(void(Node*, ostream&), ostream&);
    void Erase(Node*);
    Node* Clone(Node*);
};
