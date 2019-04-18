//
//  Arretes.hpp
//  Projet velo
//
//  Created by Thomas FLG on 16/04/2019.
//  Copyright © 2019 Thomas FLG. All rights reserved.
//

#ifndef Arretes_hpp
#define Arretes_hpp
#include<vector>
#include <stdio.h>
#include "Sommet.h"

class arrete
{
    public:

    arrete (sommet S_1, sommet S_2, int nb);
    arrete ();
    sommet Get_S1();
    sommet Get_S2();
    float Get_Poids_1();
    float Get_Poids_2();

    int Get_nb();
    void changement_S_1( sommet S_1);
    void changement_S_2( sommet S_2);
    void changement_poids_1(float poids_1);
    void changement_poids_2(float poids_2);

    void changement_nb (int nb);


    private:


    sommet m_S_1;
    sommet m_S_2;
    float m_poids_1, m_poids_2;
    int m_nb;

};


#endif /* Arretes_hpp */
