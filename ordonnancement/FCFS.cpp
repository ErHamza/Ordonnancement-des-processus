#include<iostream>
#include<vector>
#include "FCFS.hpp"
#include "FCFS.h"
using namespace std;

vector<Processus> FCFS::p_FCFS(vector<Processus> proc,int n ){
    
    vector<Processus>PcFIFO=proc;
    
    
    
    for(int i=0;i<n;i++){
        
        for(int j=i+1;j<n;j++)
        {
         Processus c;
         if ( PcFIFO[i].AT > PcFIFO[j].AT ) {
                c = PcFIFO[i];
                PcFIFO[i] = PcFIFO[j];
                PcFIFO[j] = c;
            }
        }
        
        
    }
    
    return PcFIFO;

}
