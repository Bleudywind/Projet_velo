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

int main()
{
    graph Graph;
    std::vector<arrete> arrete;


    Graph = creation_graph("manhattan.txt");
    arrete = Graph.Get_arretes();
    std::cout << arrete[0].Get_Poids_1();
    Graph.kruskal(0);
    affichage_graph(Graph);

    return 0;
}
