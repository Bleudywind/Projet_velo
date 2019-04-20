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

void graph::kruskal() 
{
    int sortie = 0, j =0, styo;
    arrete Arrete_tampon, Arrete_tampon_2;
    sommet S1{0,0,0}, S2{0,0,0}, SI{0,0,0};
    std::vector<arrete> V_Arrete_tampon;
    float P1,P2;
    std::vector<int> arete, Tri;
    
    
    while (!sortie)
    {
        sortie = 1;
        
        for (int i = 0; i < m_arretes.size() - 1; ++i )
        {
            
            P1 = m_arretes[i].Get_Poids_1();
            P2 = m_arretes[i+1].Get_Poids_1();
            
            
            if (P1 > P2)
            {
                
                Arrete_tampon = m_arretes[i];
                m_arretes[i] = m_arretes[i+1];
                m_arretes[i+1] = Arrete_tampon;
                sortie = 0;
            
            }
                
        }
    }
    
    for (int i = 0; i < m_sommets.size(); ++i)
        Tri.push_back(i);
    S1 = m_arretes[0].Get_S1();
   
    
   while (V_Arrete_tampon.size() != m_sommets.size() - 1)
    {
        
        S1 = m_arretes[j].Get_S1();
        S2 = m_arretes[j].Get_S2();
       if (Tri[S1.Get_nb()] == Tri[S2.Get_nb()])
       {}
        
        else
        {
            
            styo = Tri[S2.Get_nb()];
            for (int i = 0; i < Tri.size(); ++i)
            {
               
                if (Tri[i] == styo)
                {
                    
                    Tri[i] = Tri[S1.Get_nb()];
                }
                
                    
            }
           
            V_Arrete_tampon.push_back(m_arretes[j]);
         
        }
        
        ++j;
    }
    

    
  
    
    
  
        m_arretes.clear();
        m_arretes = V_Arrete_tampon;
    
   
    
    
}
void graph::kruskal_2()
{
    int sortie = 0, j =0, styo;
    arrete Arrete_tampon, Arrete_tampon_2;
    sommet S1{0,0,0}, S2{0,0,0}, SI{0,0,0};
    std::vector<arrete> V_Arrete_tampon;
    float P1,P2;
    std::vector<int> arete, Tri;
    
    
    while (!sortie)
    {
        sortie = 1;
        
        for (int i = 0; i < m_arretes.size() - 1; ++i )
        {
            
            P1 = m_arretes[i].Get_Poids_2();
            P2 = m_arretes[i+1].Get_Poids_2();
            
            
            if (P1 > P2)
            {
                
                Arrete_tampon = m_arretes[i];
                m_arretes[i] = m_arretes[i+1];
                m_arretes[i+1] = Arrete_tampon;
                sortie = 0;
                
            }
            
        }
    }
    
    for (int i = 0; i < m_sommets.size(); ++i)
        Tri.push_back(i);
    S1 = m_arretes[0].Get_S1();
    styo = S1.Get_nb();
    
    while (V_Arrete_tampon.size() != m_sommets.size() - 1)
    {
        
        S1 = m_arretes[j].Get_S1();
        S2 = m_arretes[j].Get_S2();
        if (Tri[S1.Get_nb()] == Tri[S2.Get_nb()])
        {}
        
        else
        {
            
            styo = Tri[S2.Get_nb()];
            for (int i = 0; i < Tri.size(); ++i)
            {
                
                if (Tri[i] == styo)
                {
                    
                    Tri[i] = Tri[S1.Get_nb()];
                }
                
                
            }
            
            V_Arrete_tampon.push_back(m_arretes[j]);
            
        }
        
        ++j;
    }
    
    
    
    
    
    
    
    m_arretes.clear();
    m_arretes = V_Arrete_tampon;
    
    
    
    
}

int graph::cout_totale_1()
{
    arrete Arrete;
    int cout_totale = 0;
    
    for (int i = 0; i < m_arretes.size(); ++i)
    {
        Arrete = m_arretes[i];
        cout_totale = Arrete.Get_Poids_1() + cout_totale;
    }
    
    return cout_totale;
}

int graph::cout_totale_2()
{
    arrete Arrete;
    int cout_totale = 0;
    
    for (int i = 0; i < m_arretes.size(); ++i)
    {
        Arrete = m_arretes[i];
        cout_totale = Arrete.Get_Poids_2() + cout_totale;
    }
    
    return cout_totale;
}
