#ifndef Processus_h
#define Processus_h
#include <string>
#include <vector>
using namespace std;
class Processus{
public:
    string name;
    int AT;
    int ET;
    char P;

    Processus(){};
    
    static vector<vector<int> > valeurs(int nbr_proc , string);
    static int get_numb_proc(string file);
    
};


#endif /* Header_h */
