//
//  Graph.cpp
//  Projet velo
//
//  Created by Thomas FLG on 16/04/2019.
//  Copyright © 2019 Thomas FLG. All rights reserved.
//

#include "Graph.hpp"

graph::graph (std::vector <sommet> sommets, std::vector<arrete> arretes)
: m_sommets(sommets), m_arretes(arretes)
{}

graph::graph ()
{}

std::vector<sommet> graph::Get_sommets()
{
    return m_sommets;
}

std::vector<arrete> graph::Get_arretes()
{
    return m_arretes;
}

void graph::changement_arretes(std::vector <arrete> arretes)
{
    m_arretes = arretes;
}

void graph::kruskal(int choix_poids)
{
    int sortie = 0;
    arrete Arrete_tampon;
    std::vector<arrete> V_Arrete_tampon;
    
    while (!sortie)
    {
        sortie = 1;
        
        for (int i = 0; i < m_arretes.size() ; ++i )
        {
            if (m_arretes[i].Get_N_poids(choix_poids) > m_arretes[i+1].Get_N_poids(choix_poids))
            {
                Arrete_tampon = m_arretes[i];
                m_arretes[i] = m_arretes[i+1];
                m_arretes[i+1] = Arrete_tampon;
                sortie = 0;
            }
                
        }
    }
    
    for (int i = 0; i < m_sommets.size() - 1; ++i)
    {
        V_Arrete_tampon[i] = m_arretes[i];
    }
    
    m_arretes = V_Arrete_tampon;
    
    
}
