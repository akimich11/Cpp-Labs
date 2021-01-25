#pragma once

class Node
{
private:
    int Info;
    Node* Left;
    Node* Right;
    Node* Father;
    friend class Tree;
public:
    Node(): Left(NULL), Right(NULL), Father(NULL){};
    Node(const int& c): Info(c), Left(NULL), Right(NULL), Father(NULL){};
    int GetInfo() { return Info; };
    Node* GetRight() { return Right; };
    Node* GetLeft() { return Left; };
    Node* Getfather() { return Father; };
};
