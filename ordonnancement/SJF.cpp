#include "SJF.hpp"
#include"SJF.h"
#include<vector>
#include <iostream>
using namespace std;
vector<Processus> SJF::p_SJF(vector<Processus> p , int n){
    
        vector<Processus> PcSJF=p;
    
    
    for(int i=0;i<n;i++)
    {
        
            for(int j=i+1;j<n;j++)
            {
                
                Processus c;
                if ( PcSJF[i].ET > PcSJF[j].ET )
                {
                        c = PcSJF[i];
                        PcSJF[i] = PcSJF[j];
                        PcSJF[j] = c;
               }
            }
        
        
    }
    
    return PcSJF;
    
    
    
};


    


    
    

