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

int main()
{
    graph Graph;

    Graph = creation_graph("manhattan.txt", "bite");
    affichage_graph(Graph);

    return 0;
}
