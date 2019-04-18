//
//  Graph.cpp
//  Projet velo
//
//  Created by Thomas FLG on 16/04/2019.
//  Copyright © 2019 Thomas FLG. All rights reserved.
//

#include "Graph.hpp"
#include "iostream"

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
    float P1,P2;
    
    
    while (!sortie)
    {
        sortie = 1;
        
        for (int i = 0; i < m_arretes.size() - 1; ++i )
        {
            
            P1 = m_arretes[i].Get_Poids_1();
            P2 = m_arretes[i+1].Get_Poids_1();
            std::cout << m_arretes[i].Get_Poids_1();
            
            if (P1 > P2)
            {
                
                Arrete_tampon = m_arretes[i];
                m_arretes[i] = m_arretes[i+1];
                m_arretes[i+1] = Arrete_tampon;
                sortie = 0;
            
            }
                
        }
    }

    
    for (int i = 0; i < m_arretes.size() - m_sommets.size() +2; ++i)
        m_arretes.pop_back();
    
   
    
    
}
