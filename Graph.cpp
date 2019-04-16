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
