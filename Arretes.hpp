//
//  Arretes.hpp
//  Projet velo
//
//  Created by Thomas FLG on 16/04/2019.
//  Copyright © 2019 Thomas FLG. All rights reserved.
//

#ifndef Arretes_hpp
#define Arretes_hpp

#include <stdio.h>
#include "Sommet.h"

class arrete
{
    public:
    
    arrete (sommet S_1, sommet S_2, double cout_1, double cout_2);
    
    sommet Get_S1();
    sommet Get_S2();
    double Get_cout_1();
    double Get_cout_2();
    
    
    private:
    
    sommet m_S_1;
    sommet m_S_2;
    double m_cout_1;
    double m_cout_2;
    
};


#endif /* Arretes_hpp */
