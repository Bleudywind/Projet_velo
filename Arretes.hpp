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
    std::vector<float> Get_poids();
    float Get_N_poids (int choix_poids);

    int Get_nb();
    void changement_S_1( sommet S_1);
    void changement_S_2( sommet S_2);
    void changement_poids(std::vector<float> poids);

    void changement_nb (int nb);


    private:


    sommet m_S_1;
    sommet m_S_2;
    std::vector<float> m_poids;
    int m_nb;

};


#endif /* Arretes_hpp */
