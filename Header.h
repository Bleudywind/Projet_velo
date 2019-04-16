//
//  Header.h
//  Projet velo
//
//  Created by Thomas FLG on 16/04/2019.
//  Copyright © 2019 Thomas FLG. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include "Graph.hpp"
#include <iostream>
#include <string>


void affichage_graph (graph Graph);
graph creation_graph (std::string nom_graph);
graph recuperation_poids (graph Graph, std::string nom_graph);


#endif /* Header_h */
