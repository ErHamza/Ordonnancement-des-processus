#include "RR.hpp"
#include<vector>
#include<queue>
#include "RR.h"
#include <iostream>
#include <string>
#include "FCFS.h"
#include <iostream>
using namespace std;
vector<string> RR::p_RR(vector<Processus> p , int nbr_proc, int Q){
    // La methode qui return le tableau (PcRR) triee selon l'algo RR .
    
        vector<Processus> proc_tries;
    proc_tries =FCFS::p_FCFS(p, nbr_proc);
    vector<string> results;
    
    queue<Processus> file_attente;
    
    // test : si tous les proc entre au proc à l'insatant t=0 (ligne 40 jusqu'à 49)
    
    for (Processus proc : proc_tries)
    {
        if (proc.AT==0)
        {
            file_attente.push(proc);
        }
    }
    int temps=proc_tries[0].AT;
    while(!file_attente.empty())
    {
                Processus P = file_attente.front();
        
        
        

                            for (int i=0; i<Q;i++)
                            {
                                
                                            string out;
                                            if (P.ET!=0)
                                            {
                                            out=" "+P.name+" ";
                                            results.push_back(out);
                                                P.ET--;
                                            }
                                            temps++;
                                // cas exp : si tous les proc entre a l'instatnt t=0 ????
                                            for (Processus proc : proc_tries)
                                            {
                                                            if (proc.AT==temps)
                                                            {
                                                                file_attente.push(proc);
                                                                
                                                            } 
                                            }
                             }
                             if (P.ET>0)
                             {
                                 file_attente.pop();
                                 file_attente.push(P);
                             }
                             else
                             {
                                 file_attente.pop();
                             }
    }
    return results;
};
