//
//  Sommet.h
//  Projet velo
//
//  Created by Thomas FLG on 16/04/2019.
//  Copyright © 2019 Thomas FLG. All rights reserved.
//

#ifndef Sommet_h
#define Sommet_h
#include <vector>


class sommet
{
    public :

    sommet(int x, int y, int nb);

    int Get_x();
    int Get_y();
    int Get_nb();
    std::vector<int> Get_aretes();
    void changement_x(int x);
    void changement_y(int y);
    void changement_nb(int nb);
    void changement_aretes(std::vector<int> aretes);
    void ajout_arete(int nb_aretes);
    void reset_arete();





    private :


    int m_x;
    int m_y;
    int m_nb;
    std::vector<int> m_aretes;
};

#endif /* Sommet_h */
