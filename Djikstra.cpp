//
//  Djikstra.cpp
//  Projet velo
//
//  Created by Thomas FLG on 21/04/2019.
//  Copyright © 2019 Thomas FLG. All rights reserved.
//

#include "Djikstra.hpp"
#include "Graph.hpp"
#include <vector>
#include <iostream>
#include "svgfile.h"

int bfs(graph Graph)
{
    
    std::vector<bool> marquage;
    std::vector<arrete> Arrete = Graph.Get_arretes();
    std::vector<sommet> Sommets = Graph.Get_sommets();
    std::vector<int> file_attente, arete;
    
    
    file_attente.push_back(0);
    
    for (int i = 0; i < Sommets.size(); ++i)
    {
        marquage.push_back(0);
    }
    
    while (file_attente.size() != 0)
    {
        
        if (!marquage[file_attente[0]])
        {
            marquage[file_attente[0]] = 1;
            arete = Sommets[file_attente[0]].Get_aretes();
            for (int i = 0; i < arete.size(); ++i)
            {
                if (!marquage[Arrete[arete[i]].Get_nb_S1()])
                {
                    file_attente.push_back(Arrete[arete[i]].Get_nb_S1());
                }
                if (!marquage[Arrete[arete[i]].Get_nb_S2()])
                {
                    file_attente.push_back(Arrete[arete[i]].Get_nb_S2());
                }
            }
            
        }
        file_attente.erase(file_attente.begin());
        std::cout << file_attente.size() << "\n";
    }
    
    for (int i = 0; i < marquage.size(); ++i)
    {
        
        if (!marquage[i])
            return 1;
    }
    return 0;
}

void Partie_3(graph Graph)
{
    Svgfile svgout;
    svgout.addGrid();
    std::vector<bool> m_compteur;
    std::vector<arrete> arretes_original = Graph.Get_arretes(), arretes_test;
    std::vector<sommet> Sommets = Graph.Get_sommets(), sommet_tampon;
    std::vector<std::vector<std::vector<graph>>> m_Graphs;
    std::vector<std::vector<graph>> P1;
    std::vector<graph> P2, m_Graphs_verts;
    std::vector<std::vector<int>> arete;
    bool non = 0,vert = 1;
    int compteur_m = 0, j =0, max_P1 = 0, max_P2 = 0, cout_2;
    double m_rayon = 0;
    
    for (int i = 0; i < arretes_original.size() + 1; ++i)
    {
        m_compteur.push_back(0);
    }
   
    while (!m_compteur[arretes_original.size()])
    {
        
        
        non = 0;
        
        
        if (m_compteur[0] == 0)
        {
            m_compteur[0] = 1;
            ++compteur_m;
        }
        
        else
        {
            while (m_compteur[j] != 0)
            {
                m_compteur[j] = 0;
                ++j;
                --compteur_m;
            }
            m_compteur[j] = 1;
            j = 0;
            ++compteur_m;
        }
        j =0;
        
        
        if (compteur_m >= Sommets.size() - 1)
        {
            for (int i = 0; i < Sommets.size(); ++i)
                Sommets[i].reset_arete();
            
            for (int i = 0; i < arretes_original.size(); i++)
            {
                if (m_compteur[i])
                {
                    arretes_test.push_back(arretes_original[i]);
                    Sommets[arretes_original[i].Get_nb_S1()].ajout_arete(i);
                    Sommets[arretes_original[i].Get_nb_S2()].ajout_arete(i);
                }
                
                
            }
            
            
            
            Graph.changement_arretes(arretes_test);
            Graph.changement_sommets(Sommets);
            non = bfs(Graph);
            std::cout << "entering";
            
            
            
            if (!non)
            {
                
                cout_2 = Graph.dijkstra();
                
                if (Graph.cout_totale_1() > max_P1)
                {
                    for (int i = max_P1; i <= Graph.cout_totale_1(); ++i)
                    {
                        m_Graphs.push_back(P1);
                        
                    }
                }
                if (cout_2 > max_P2)
                {
                    for (int i = max_P2; i <= cout_2; ++i)
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
                
                
                
                
            }
            
        }
        
        arretes_test.clear();
        
    }
    
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
}
