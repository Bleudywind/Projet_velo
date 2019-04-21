//
//  Pareto.cpp
//  Projet velo
//
//  Created by Thomas FLG on 19/04/2019.
//  Copyright © 2019 Thomas FLG. All rights reserved.
//

#include "Pareto.hpp"
#include "svgfile.h"

Pareto::Pareto(graph Graph)
: m_Graph_original(Graph), m_rayon(0)
{
    for (int i = 0 ; i < 25; ++i)
    {
        m_compteur.push_back(0);
    }
}
void Pareto::changement_graph_original(graph Graph)
{
    m_Graph_original = Graph;
}
void Pareto::ajout_Graph(graph Graph, int poids_1, int Poids_2)
{
    m_Graphs[poids_1][Poids_2].push_back(Graph);
}

graph Pareto::Get_un_graph(int nb_graph, int poids_1, int Poids_2)
{
    return m_Graphs[poids_1][Poids_2][nb_graph];
}

std::vector<std::vector<std::vector<graph>>> Pareto::Get_graphs()
{
    return m_Graphs;
}
void Pareto::compteur()
{
    int j = 0;
    
        if (m_compteur[0] == 0)
            m_compteur[0] = 1;
        else
        {
            while (m_compteur[j] != 0)
            {
                m_compteur[j] = 0;
                ++j;
            }
            m_compteur[j] = 1;
            j = 0;
        }
 
}
void Pareto::creation_liste_graph()
{
    std::vector<sommet> Sommets = m_Graph_original.Get_sommets();
    std::vector<arrete> arretes_test, arretes_original = m_Graph_original.Get_arretes();
    std::vector<bool> Tri;
    graph Graph{Sommets, arretes_test};
    bool non =0;
    sommet S1{0,0,0}, S2{0,0,0};
    int taille = 0, max_P1 = 0, max_P2 = 0, compteur_m =0, count = 0;
    arrete Arrete_test;
    std::vector<graph> P2;
    std::vector<std::vector<graph>> P1;
    bool vert = 1;
    std::cout << "hello";
    
    
    for (int i =0; i < Sommets.size(); ++i)
    {
        Tri.push_back(0);
    }
    
    while (!m_compteur[arretes_original.size()])
    {
        for (int i = 0; i < arretes_original.size(); ++i)
        {
            if (m_compteur[i] == 1)
                compteur_m++;
        }
        
        
        if (compteur_m == Sommets.size() - 1)
        {
            
        
        for (int i = 0; i < arretes_original.size(); i++)
        {
            if (m_compteur[i])
            {
                arretes_test.push_back(arretes_original[i]);
                
            }
            
            
        }
            
            for (double i = 0; i < arretes_test.size(); ++i)
            {
                if( Tri[arretes_test[i].Get_nb_S1()] == 0)
                {
                    Tri[arretes_test[i].Get_nb_S1()] = 1;
                    count++;
                    
                }
                if (Tri[arretes_test[i].Get_nb_S2()] == 0)
                {
                    Tri[arretes_test[i].Get_nb_S2()] = 1;
                    count++;
                }
                
                if (count == Sommets.size())
                {
                    i = arretes_test.size();
                    non = 0;
                }
                
            }
            
            
            if(count < Sommets.size())
                non = 1;
            
            count = 0;
            
            for (int i = 0; i < Tri.size(); ++i)
                Tri [i] = 0;
           
            
            
            if (!non)
            {
                Graph.changement_arretes(arretes_test);
                
                if (Graph.cout_totale_1() > max_P1)
                {
                    for (int i = max_P1; i <= Graph.cout_totale_1(); ++i)
                    {
                        m_Graphs.push_back(P1);
                       
                    }
                }
                if (Graph.cout_totale_2() > max_P2)
                {
                    for (int i = max_P2; i <= Graph.cout_totale_2(); ++i)
                    {
                        m_Graphs[Graph.cout_totale_1()].push_back(P2);
                        
                    }
                }
                
                
                m_Graphs[Graph.cout_totale_1()][Graph.cout_totale_2()].push_back(Graph);
                
                for (int i = 0; i < m_Graphs_verts.size(); ++i)
                {
                    if(m_Graphs_verts[i].cout_totale_1() > Graph.cout_totale_1() && m_Graphs_verts[i].cout_totale_2() > Graph.cout_totale_2())
                    {
                        m_Graphs_verts.erase(m_Graphs_verts.begin() + i);
                        
                    }
                    
                    
                    
                    if (m_Graphs_verts[i].cout_totale_1() >= Graph.cout_totale_1() || m_Graphs_verts[i].cout_totale_2() >= Graph.cout_totale_2())
                    {}
                        
                    else
                        vert = 0;
                    
                    
                    
                    
                       
                }
                
                
                
                if (vert == 1)
                    m_Graphs_verts.push_back(Graph);
                
                
                
                
                
                vert = 1;
                
                
                if (m_Graphs[Graph.cout_totale_1()][Graph.cout_totale_2()].size() > m_rayon)
                    m_rayon = m_Graphs[Graph.cout_totale_1()][Graph.cout_totale_2()].size();
                
                
                taille++;
                
            }
        }
        
        compteur_m =0;
        arretes_test.clear();
        this->compteur();
        non = 0;
        
    }
    
   
}

void Pareto::affichage_pareto()
{
    Svgfile svgout;
    svgout.addGrid();
    std::vector<std::vector<std::vector<graph>>> Graphs = m_Graphs;
    
    
    
    
    for (int i = 0; i < m_Graphs.size(); ++i )
    {
        for (int j = 0; j < m_Graphs[i].size(); ++j)
        {
            
            if ((m_Graphs[i][j].size() * 2) / m_rayon > 0.001)
            {
                
                svgout.addDisk(i*7 +100, j*7 +100, (m_Graphs[i][j].size() * 5) / m_rayon, "red");
                
            }
            
            
        }
    }
    
    svgout.addLine(100, 100, 900, 100);
    svgout.addLine(100, 100, 100, 700);
    svgout.addLine(900, 100, 875, 75);
    svgout.addLine(900, 100, 875, 125);
    svgout.addLine(100, 700, 75, 675);
    svgout.addLine(100, 700, 125, 675);
    svgout.addText(800, 90, "Coût 1");
    svgout.addText(125, 625, "Coût 2");
    
    
    for (int i = 0; i < m_Graphs_verts.size(); ++i)
    {
        
        svgout.addDisk(m_Graphs_verts[i].cout_totale_1()* 7 +100, m_Graphs_verts[i].cout_totale_2()*7 +100, 5, "green");

    }
   
        
        //svgout.addLine(200, 150, 300, 150);
}
