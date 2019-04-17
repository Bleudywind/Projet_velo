//
//  lecture_fichier.cpp
//  Projet velo
//
//  Created by Thomas FLG on 16/04/2019.
//  Copyright © 2019 Thomas FLG. All rights reserved.
//

#include <stdio.h>
#include "Graph.hpp"
#include <string>
#include <fstream>
#include "Header.h"
#include "svgfile.h"

graph creation_graph (std::string nom_graph)
{
    std::ifstream fichier(nom_graph, std::ios::in);
    std::vector<sommet> sommets;
    std::vector<arrete> arretes;
    std::string nom_fichier_poids;

    if(fichier)
    {
        sommet S1{0,0,0};
        arrete A1;
        int nb;
        int var;

        fichier >> nb;

        for (int i = 0; i < nb; ++i)
        {
            fichier >> var;
            S1.changement_nb(var);
            fichier >> var;
            S1.changement_x(var);
            fichier >> var;
            S1.changement_y(var);
            sommets.push_back(S1);
        }

        fichier >> nb;

        for (int i = 0; i < nb; ++i)
        {
            fichier >> var;
            A1.changement_nb(var);
            fichier >> var;
            A1.changement_S_1(sommets[var]);
            fichier >> var;
            A1.changement_S_2(sommets[var]);
            arretes.push_back(A1);
        }

        fichier.close();

    }



        graph Graph{sommets, arretes};



        recuperation_poids(Graph, "manhattan_weights_0.txt");



    return Graph;

}

void affichage_graph (graph Graph)
{
    Svgfile svgdiagrame;
    svgdiagrame.addGrid();
    std::vector<sommet> Sommet = Graph.Get_sommets();
    std::vector<arrete> Arrete = Graph.Get_arretes();
    sommet S1{0,0,0}, S2{0,0,0};
    std::vector<float> Poids;



    for (int i = 0; i < Sommet.size(); ++i)
    {
        svgdiagrame.addDisk(Sommet[i].Get_x(), Sommet[i].Get_y(), 7);
    }
    for (int i = 0; i < Arrete.size(); ++i)
    {
        S1 = Arrete[i].Get_S1();
        S2 = Arrete[i].Get_S2();
        Poids = Arrete[i].Get_poids();
        svgdiagrame.addLine(S1.Get_x(), S1.Get_y(), S2.Get_x(), S2.Get_y(), "black");

    }


}

graph recuperation_poids (graph Graph, std::string nom_graph)
{
    std::ifstream fichier(nom_graph, std::ios::in);
    std::vector<arrete> Arretes = Graph.Get_arretes();
    std::vector<float> Poids;
    int nb_a, nb_poids;
    float var;


    if (fichier)
    {


        fichier >> nb_a >> nb_poids;

        for (int i = 0; i < nb_poids; ++i)
            Poids.push_back(var);

        for (int i = 0; i < nb_a; ++i)
        {

                fichier >> var >> var;
                Poids[0] = var;
                fichier >> var;
                Poids[1] = var;
                Arretes[i].changement_poids(Poids);

        }

        fichier.close();
    }

       Graph.changement_arretes(Arretes);

    return Graph;
}






