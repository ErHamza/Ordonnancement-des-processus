//
//  methods.hpp
//  ordonnancement
//
//  Created by t on 23/05/2022.
//  Copyright © 2022 tax. All rights reserved.
//

#ifndef methods_hpp
#define methods_hpp

#include <stdio.h>


processus processus::min(processus p1 , processus p2 , processus p3);
{
    int m = p1.AT;
    if (p2.AT> m)
        return p2;
    if(p3.AT>m)
        return p3;
    
    
    return p1;
};
#endif /* methods_hpp */
