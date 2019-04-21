//
//  Graph.hpp
//  Projet velo
//
//  Created by Thomas FLG on 16/04/2019.
//  Copyright © 2019 Thomas FLG. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include "Sommet.h"
#include "Arretes.hpp"

class graph
{
public:

    graph (std::vector <sommet> sommets, std::vector<arrete> arretes);
    graph ();
    std::vector <sommet> Get_sommets();
    std::vector <arrete> Get_arretes();
    void changement_arretes(std::vector <arrete> arretes);
    void changement_sommets(std::vector <sommet> Sommets);
    void kruskal ();
    void kruskal_2();
    int dijkstra();
    int cout_totale_1();
    int cout_totale_2();
    void marquage(int indice_sommets,std::vector<int> &arete, std::vector<int> &fil_attente);

private:

    std::vector <sommet> m_sommets;
    std::vector<arrete> m_arretes;
    std::vector<int> m_marquage, m_marquage_sommets;
    int m_poids_totale;
};

#endif /* Graph_hpp */
