#include "tree.hpp"
#include "methods.cpp"

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string c;
    int n, k = 0;
    Tree MyTree;
    Node* Rezult;
    while(getline(fin, c))
    {
        switch(c[0])
        {
            case 'I':
                n = stoi(c.substr(2, c.size() - 2));
                if(MyTree.Insert(n, MyTree.GetRoot()))
                    fout << n <<": inserted" << endl;
                else
                    fout << n <<": not inserted" << endl;
                break;
            case 'D':
                n = stoi(c.substr(2, c.size() - 2));
                if(MyTree.Delete(MyTree.GetRoot(), n))
                    fout << n <<": deleted" << endl;
                else
                    fout << n <<": not deleted" << endl;
                break;
            case 'F':
                n = stoi(c.substr(2, c.size() - 2));
                if(MyTree.Find(n, MyTree.GetRoot(), Rezult, k))
                    fout << n <<": found after " << k << " comparison(s)" << endl;
                else
                    fout << n <<": not found after " << k << " comparison(s)" << endl;
                k = 0;
                break;
            default:
                MyTree.ForEach(inorderPrint, fout);
                break;
        }
    }
    Tree My = MyTree;
    fin.close();
    fout.close();
    return 0;
}