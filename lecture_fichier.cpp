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

graph creation_graph (std::string nom_graph)
{
    std::ifstream fichier("nom_graph.txt", std::ios::in);
    
    if(fichier)
    {
        std::vector<sommet> sommets;
        sommet S1{0,0,0};
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
        }
        
        fichier >> nb;
        
        for (int i = 0; i < nb; ++i)
        {
            <#statements#>
        }
        
        fichier.close();
    }
    
        
    
    
    graph Graph;
    
    return Graph;
    
}
