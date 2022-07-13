#ifndef RR_h
#define RR_h
#include"Processus.h"
#include<string> 
class RR:Processus{
public:
    
   static vector<string> p_RR(vector<Processus> p , int nbr_proc,int Q);
    RR();
    
};

#endif /* RR_h */
