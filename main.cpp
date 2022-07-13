#include <iostream>
#include "Processus.h"
#include <string>
#include<vector>
#include "FCFS.h"
#include "SJF.h"
#include "RR.h"
#include "RR.h"

using namespace std;
int main(int argc, const char * argv[]) {
   string algo;
    cout<< "please select the scheduling algo that you wish to use "<<endl;
    cout<<"FCFS , SJF or RR \n";
    cin>>algo;
    transform(algo.begin(), algo.end(), algo.begin(), ::toupper);
    
    
    vector<vector<int> > info ; // on crée un vecteur pour storer les données <(AT,ET)>
    string file;                 // le chemin du fichier
    cout << "Enter the file name: ";
    cin >> file;
    int  nbr_proc =Processus::get_numb_proc(file); // détermine le nombre des processus
    info=Processus::valeurs(nbr_proc,file );
    Processus* objs = new Processus[nbr_proc]; // création de n objets
    
    for (int i =0 ; i<nbr_proc ; i++)  // une boucle pour affecter les valeurs AT et ET aux objets
    {
        objs[i].AT= info[i][0];
        objs[i].ET= info[i][1];
        if (info[i].size()==3) // affecter la priorité si elle est donnée par l'utilisateur
            objs[i].P= info[i][2];
        string a= to_string(i+1);
        objs[i].name= "p"+a;// on nomme les processus P(i)
    }
    vector<Processus> proc; // on store les objets dans un vecteur
    for(int i =0; i<nbr_proc; i++)
        proc.push_back(objs[i]);
    if (algo=="FCFS")
    {
                            vector<Processus> result;   // pour storer le résultat de la fonction p_FCFS()
                            result=FCFS::p_FCFS(proc,nbr_proc);
                            for (int i=0 ; i<result.size();i++) //boucle pour l'affichage du résultat
                            {   for(int j =0 ;j<result[i].ET;j++)
                                cout<<result[i].name<<" ";
            
            
                            }
    }
    
    
    
    
    if (algo=="SJF")
    {
        
                    vector<Processus> file_attente;
                    vector<Processus> proc_trie_AT;
        

                    proc_trie_AT=FCFS::p_FCFS(proc,nbr_proc  ); // on trie les processus selon le temps d'arrivé
                   int counter = proc_trie_AT[0].AT;

                    for (int i = 0; i<nbr_proc; i++)
                        
                    {
// si la file d'attente contient plus de deux element, on trie les objet selon ET
                                    if (file_attente.size()>=2)
                                    {
                                        size_t size_fille_attente= file_attente.size();
                                        
                                        file_attente= SJF::p_SJF(file_attente,(int)size_fille_attente );
                                    }
                        
                        
                                    if(file_attente.size()==0 )
                                    {
                        
                                                for (int j=0; j<proc_trie_AT[i].ET;j++)
                                                {
                                                                cout<<proc_trie_AT[i].name<<" ";
                                                                counter++;
                                                                for (int s=0; s<nbr_proc;s++)
                                                                {
                                                                    if (proc_trie_AT[s].AT==counter)
                                                                    {//entrée des processus
                                                                        file_attente.push_back(proc_trie_AT[s]);
                                                                        

                                                                    }

                                                                
                                                                 }
                                                    
                                                    
                                                };
                                                proc_trie_AT.erase(proc_trie_AT.begin());
                                        
                                     }
                        
                        
                        if (file_attente.size()>=2)
                        {
                            size_t size_fille_attente= file_attente.size();
                            
                            file_attente= SJF::p_SJF(file_attente,(int)size_fille_attente );
                        }
                        

                        
                        
                        
                        if(file_attente.size()!=0)
                                    {
                                    
                            
                                                for (int j=0; j<file_attente[0].ET;j++)
                                                {
                                                    cout<<file_attente[0].name<<" ";
                                                    counter++;
                                                    for (int s=0; s<nbr_proc;s++)
                                                    {
                                                        if (proc_trie_AT[s].AT==counter)
                                                            // procesuus entrant
                                                            
                                                        {file_attente.push_back(proc_trie_AT[s]);
                                                            

                                                        }
                                                        
                                                    }
                                                    
                                                    
                                                 }
                                        
                                                 file_attente.erase(file_attente.begin());
                                 }
                        }

                }
    
    if (algo=="RR")
        
        
        
    {
        
        vector<string> results; //
        int Q; // le quantum
        cout<<"enter le quantum "<<endl;
        cin>>Q;
        results=RR::p_RR(proc, nbr_proc, Q); // on stock les resultats de la fonction p_RR dans resutlts
        for (int i=0; i<results.size();i++)
            cout<<results[i];
        
    }
    return 0;}
