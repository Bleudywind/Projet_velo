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
: m_sommets(sommets), m_arretes(arretes), m_poids_totale(0)
{
    for (int i = 0; i < arretes.size() ; i++)
    {
        m_marquage.push_back(0);
    }
}

graph::graph ()
: m_poids_totale(0)
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
    
    m_marquage.clear();
    
    for (int i = 0; i < arretes.size() ; i++)
    {
       m_marquage.push_back(0);
    }
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

void graph::marquage(int indice_sommets, std::vector<int> &arete_poids, std::vector<int> &fil_attente)
{
    
    std::vector<int> arete =m_sommets[indice_sommets].Get_aretes();
    
    for (int i =0; i < arete.size() ; ++i)
    {
        if (m_marquage[arete[i]] == 0)
        {
            m_marquage[arete[i]] = 1;
            if (m_arretes[arete[i]].Get_nb_S1() == indice_sommets)
            {
                fil_attente.push_back(m_arretes[arete[i]].Get_nb_S2());
                
                if (arete_poids[m_arretes[arete[i]].Get_nb_S2()] == 0 || arete_poids[m_arretes[arete[i]].Get_nb_S2()] > (m_arretes[arete[i]].Get_Poids_2() + arete_poids[indice_sommets]))
                {
                        arete_poids[m_arretes[arete[i]].Get_nb_S2()] = m_arretes[arete[i]].Get_Poids_2() + arete_poids[indice_sommets];
                }
                
            }
            
            else
            {
                fil_attente.push_back(m_arretes[arete[i]].Get_nb_S1());
                
                if (arete_poids[m_arretes[arete[i]].Get_nb_S1()] == 0 || (arete_poids[m_arretes[arete[i]].Get_nb_S1()] > m_arretes[arete[i]].Get_Poids_2() + arete_poids[indice_sommets]))
                    {
                            arete_poids[m_arretes[arete[i]].Get_nb_S1()] = m_arretes[arete[i]].Get_Poids_2() + arete_poids[indice_sommets];
                    }
                    
            }
            
            
        }
    }
    fil_attente.erase(fil_attente.begin());
}


int graph::dijkstra()
{
    std::vector<int> sommet_poids, file_attente;
    
    
    for (int i = 0; i < m_sommets.size(); ++i)
    {
        sommet_poids.push_back(0);
    }
    
    for (int i = 0; i < m_sommets.size(); ++i)
    {
        file_attente.push_back(i);
    
    while (file_attente.size() != 0)
    {
        marquage(file_attente[0], sommet_poids, file_attente);
    }
    for (int j = 0; j < sommet_poids.size(); ++j)
    {
           m_poids_totale = m_poids_totale + sommet_poids[j];
           sommet_poids[j] = 0;
    }
        for (int j = 0; j < m_arretes.size(); ++j)
            m_marquage[j] = 0;
        
        
       
    }
    return m_poids_totale;
}

void graph::changement_sommets(std::vector <sommet> Sommets)
{
    m_sommets = Sommets;
}
