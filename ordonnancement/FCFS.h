#ifndef FCFS_h
#define FCFS_h
#include<iostream>
#include<vector>
#include "Processus.h"



using namespace std;

class FCFS :public Processus
{
    
public:
    
    FCFS();
    
    static vector<Processus>  p_FCFS(vector<Processus>   , int);

    
};
#endif /* FCFS_h */
