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


    Graph = creation_graph("manhattan.txt");
    Graph.kruskal(1);
    affichage_graph(Graph);

    return 0;
}
