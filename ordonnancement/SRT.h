//
//  SRT.h
//  ordonnancement
//
//  Created by t on 05/06/2022.
//  Copyright © 2022 tax. All rights reserved.
//

#ifndef SRT_h
#define SRT_h
#include"Processus.h"
#include<vector>
using namespace std;
class SRT:public Processus
{
    public :
    SRT(){};
  Processus p_SRT(vector<Processus> p, int n);
    
    
    
};


#endif /* SRT_h */

