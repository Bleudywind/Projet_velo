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
#include "svgfile.h"

void affichage_graph (graph Graph, int decalage, Svgfile& svgdiagrame);
graph creation_graph (std::string nom_graph, int  &ouverture, int choix_poids);
graph recuperation_poids (graph Graph, std::string nom_graph);
void compteur_binaire();
int menu();
void Partie_3(graph Graph);


#endif /* Header_h */
