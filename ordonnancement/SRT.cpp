//
//  SRT.cpp
//  ordonnancement
//
//  Created by t on 08/06/2022.
//  Copyright © 2022 tax. All rights reserved.
//

#include "SRT.hpp"
#include"SRT.h"
#include <vector>
using namespace std;
Processus SRT::p_SRT(vector<Processus> proc, int n){
    
        int i = 0;
        int lent = (int)proc.size();
        int min = proc[0].ET;
        int the_min = 0;
        for (i=0; i<lent; i++) {
            if(proc[i].ET<min){
                min = proc[i].ET;
                the_min = i;
            }
        }
        return proc[the_min];
        
        

}
