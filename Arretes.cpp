//
//  Arretes.cpp
//  Projet velo
//
//  Created by Thomas FLG on 16/04/2019.
//  Copyright © 2019 Thomas FLG. All rights reserved.
//

#include "Arretes.hpp"

    arrete::arrete (sommet S_1, sommet S_2, int nb)
: m_S_1 (S_1), m_S_2 (S_2), m_nb(nb)
{}

arrete::arrete ()
: m_S_1(0,0,0), m_S_2(0,0,0)
{}

sommet arrete::Get_S1()
{
    return m_S_1;
}

sommet arrete::Get_S2()
{
    return m_S_2;
}

float arrete::Get_Poids_1()
{
    return m_poids_1;
}

float arrete::Get_Poids_2()
{
    return m_poids_2;
}

int arrete::Get_nb()
{
    return m_nb;
}

void arrete::changement_S_1(sommet S_1)
{
    m_S_1=S_1;
}
void arrete::changement_S_2(sommet S_2)
{
    m_S_2=S_2;
}

void arrete::changement_poids_1(float poids)
{
    m_poids_1 = poids;
}
void arrete::changement_poids_2(float poids)
{
    m_poids_2 = poids;
}

void arrete::changement_nb(int nb)
{
    m_nb = nb;
}


