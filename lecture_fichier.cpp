//
//  lecture_fichier.cpp
//  Projet velo
//
//  Created by Thomas FLG on 16/04/2019.
//  Copyright © 2019 Thomas FLG. All rights reserved.
//

#include <stdio.h>
#include "Graph.hpp"
#include <string>
#include <fstream>
#include "Header.h"

graph creation_graph (std::string nom_graph, std::string nom_graph_poids)
{
    std::ifstream fichier("nom_graph.txt", std::ios::in);
    std::vector<sommet> sommets;
    std::vector<arrete> arretes;
    
    if(fichier)
    {
       
        sommet S1{0,0,0};
        arrete A1;
        int nb;
        int var;
        
        fichier >> nb;
        
        for (int i = 0; i < nb; ++i)
        {
            fichier >> var;
            S1.changement_nb(var);
            fichier >> var;
            S1.changement_x(var);
            fichier >> var;
            S1.changement_y(var);
            sommets.push_back(S1);
        }
        
        fichier >> nb;
        
        for (int i = 0; i < nb; ++i)
        {
            fichier >> var;
            A1.changement_nb(var);
            fichier >> var;
            A1.changement_S_1(sommets[var]);
            fichier >> var;
            A1.changement_S_2(sommets[var]);
            arretes.push_back(A1);
        }
        
        fichier.close();
        
    }
    
        graph Graph{sommets, arretes};
    
    
    
    
    return Graph;
    
}

void affichage_graph (graph Graph)
{
    
}
