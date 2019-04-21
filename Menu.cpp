//
//  Menu.cpp
//  Projet velo
//
//  Created by Thomas FLG on 21/04/2019.
//  Copyright © 2019 Thomas FLG. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include "Graph.hpp"
#include "Header.h"
#include <string>
#include "Pareto.hpp"
void menu_svg (graph Graph, graph Graph_2)
{
    Svgfile svgout;
    affichage_graph(Graph, 0, svgout);
    affichage_graph(Graph_2, 400, svgout);
    
}
void menu_pareto(graph Graph)
{
    Pareto pareto{Graph};
    
    pareto.creation_liste_graph();
    pareto.affichage_pareto();
}
graph ouverture_fichier (graph Graph)
{
    int ouverture = 1, numero_poids;
    std::string nom_fichier;
    
    while (ouverture)
    {
        std::cout << "\n*** Charger un fichier ***\n" << "Rentrer le nom du fichier :";
        std::cin >> nom_fichier;
        std::cout << "\nRentrer le numéro du fichier poids :";
        std::cin >> numero_poids;
        Graph = creation_graph(nom_fichier, ouverture, numero_poids);
        
    }
    
    return Graph;
}
int menu()
{
    
    graph Graph, Graph_2;
    int  choix, quitter = 0;
    
    Graph = ouverture_fichier(Graph);
    
    
    
    while (!quitter)
    {
        std::cout << "\n1. Arbre couvrant de poids minimal";
        std::cout << "\n2. Frontière de Pareto";
        std::cout << "\n3. ";
        std::cout << "\n4. Charger Fichier";
        std::cout << "\n5. Quitter";
        std::cout << "\nQue voullez vous faire ?\n";
        std::cout << "choix :";
        std::cin >> choix;
        
        switch (choix)
        {
            case 1:
                Graph_2 = Graph;
                Graph.kruskal();
                Graph_2.kruskal_2();
                menu_svg(Graph, Graph_2);
                break;
                
            case 2:
                menu_pareto(Graph);
                break;
                
            case 3:
                Partie_3(Graph);
                break;
            case 4:
                Graph = ouverture_fichier(Graph);
                break;
            default:
                quitter = 1;
                break;
        }
        
        
    }
    
    
    
    return 0;
}
