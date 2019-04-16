//
//  Arretes.cpp
//  Projet velo
//
//  Created by Thomas FLG on 16/04/2019.
//  Copyright © 2019 Thomas FLG. All rights reserved.
//

#include "Arretes.hpp"

    arrete::arrete (sommet S_1, sommet S_2, double cout_1, double cout_2)
: m_S_1 (S_1), m_S_2 (S_2), m_cout_1(cout_1), m_cout_2(cout_2)
{}

sommet arrete::Get_S1()
{
    return m_S_1;
}

sommet arrete::Get_S2()
{
    return m_S_2;
}

double arrete::Get_cout_1()
{
    return m_cout_1;
}

double arrete::Get_cout_2()
{
    return m_cout_2;
}

