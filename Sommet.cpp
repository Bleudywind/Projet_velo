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
: m_x(x), m_y(y), m_nb(nb)
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

