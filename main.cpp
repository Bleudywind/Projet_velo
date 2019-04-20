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
 
    
    Graph = creation_graph("triville.txt");
    
    Pareto pareto{Graph};
    pareto.creation_liste_graph();
    pareto.affichage_pareto();
    
    return 0;
}
