#ifndef SJF_h
#define SJF_h
#include<iostream>
#include<vector>
#include"Processus.h"
using namespace std;


class  SJF : public Processus
{
    
public:
    
    SJF();
    static vector<Processus> p_SJF(vector<Processus> P,int n);


};


#endif /* SJF_h */
