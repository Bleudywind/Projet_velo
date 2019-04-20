//
//  Pareto.hpp
//  Projet velo
//
//  Created by Thomas FLG on 19/04/2019.
//  Copyright © 2019 Thomas FLG. All rights reserved.
//

#ifndef Pareto_hpp
#define Pareto_hpp

#include <stdio.h>
#include "Header.h"

class Pareto
{
public:
    Pareto (graph Graph);
    void ajout_Graph(graph Graph, int poids_1, int Poids_2);
    graph Get_un_graph(int nb_graph, int poids_1, int Poids_2);
    std::vector<std::vector<std::vector<graph>>> Get_graphs();
    void creation_liste_graph();
    void compteur();
    void affichage_pareto();
    
    
    
private:
    graph m_Graph_original;
    std::vector<std::vector<std::vector<graph>>> m_Graphs;
    std::vector<graph> m_Graphs_verts;
    std::vector<bool> m_compteur;
    double m_min_x, m_min_y;
    double m_rayon;
    
};


#endif /* Pareto_hpp */
