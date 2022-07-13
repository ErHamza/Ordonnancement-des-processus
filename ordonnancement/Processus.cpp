#include "Processus.h"
#include <vector>
#include <iostream>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<string>
    vector<vector<int>>Processus::valeurs(int nbr_proc ,string file){
     
        // define variables
        string a;        //variables from file are here
        
       vector <int> V[nbr_proc];
        
        
                
    ifstream coeff(file); //opening the file.
    
    if (coeff.is_open()) //if the file is open
    {
        string line;
        getline(coeff, line); // ingorer la première ligne
        


            
            
        while (!coeff.eof()) //while the end of file is NOT reached
        {
               
                for (int i=0 ; i<nbr_proc;i++)
                {
                            if (i<nbr_proc-1)
                            {
                                
                                
                                getline(coeff, a, ',');
                                V[i].push_back(stoi(a));
                            }
                        else
                        {
                            
                                getline(coeff, a, '\n');
                            
                                V[i].push_back(stoi(a));

                        
                         }

                    
                }
                

            }
            coeff.close(); //closing the file
        }
        else cout << "Unable open file"; //if the file is not open output
        
        vector<vector<int>>d;
        for (int i=0 ; i<nbr_proc; i++)
            d.push_back(V[i]);
        
        return d;
        
    };
    

int Processus::get_numb_proc(string file){
    
    char c ='h';
    int j=0  ;
    
    ifstream coeff(file);
    if (coeff)
    {
                    while(!coeff.eof())
                    {
                        coeff.get(c);
                        if (c=='/')
                            j++ ;
                    }
    }
    return j+1;

};

