//
//  main.cpp
//  Projet velo
//
//  Created by Thomas FLG on 16/04/2019.
//  Copyright © 2019 Thomas FLG. All rights reserved.
//

#include <iostream>
#include "Header.h"
#include "Graph.hpp"
#include "svgfile.h"
#include "Pareto.hpp"

int main()
{
    graph Graph, Graph_2;
    Svgfile svgout;
    svgout.addGrid();
    Graph = creation_graph("broadway.txt");
    Graph_2 = Graph;
    Graph.kruskal();
    Graph_2.kruskal_2();
    affichage_graph(Graph, 0, svgout);
    affichage_graph(Graph_2, 400, svgout);
   // Pareto pareto{Graph};
    //pareto.creation_liste_graph();
    //pareto.affichage_pareto();
    
    return 0;
}
