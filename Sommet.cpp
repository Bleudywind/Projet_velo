//
//  Sommet.cpp
//  Projet velo
//
//  Created by Thomas FLG on 16/04/2019.
//  Copyright © 2019 Thomas FLG. All rights reserved.
//

#include <stdio.h>
#include "Sommet.h"

sommet::sommet(int x, int y, int nb)
: m_x(x), m_y(y), m_nb(nb), m_arretes(NULL)
{}

int sommet::Get_x()
{
    return m_x;
}

int sommet::Get_y()
{
    return m_y;
}

int sommet::Get_nb()
{
    return m_nb;
}

void sommet::changement_x(int x)
{
    m_x = x;
}

void sommet::changement_y(int y)
{
    m_y = y;
}
void sommet::changement_nb(int nb)
{
    m_nb = nb;
}

void sommet::changement_arrete(arrete Arrete)
{
    m_arretes.push_back(Arrete);
}
