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
    std::vector<int> aretes;


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
            sommets[var].ajout_arete(i);
            fichier >> var;
            A1.changement_S_2(sommets[var]);
            sommets[var].ajout_arete(i);
            arretes.push_back(A1);
        }

        fichier.close();

    }



        graph Graph{sommets, arretes};



      Graph = recuperation_poids(Graph, "manhattan_weights_0.txt");



    return Graph;

}

void affichage_graph (graph Graph, int decalage, Svgfile& svgdiagrame)
{
    
    
    std::vector<sommet> Sommet = Graph.Get_sommets();
    std::vector<arrete> Arrete = Graph.Get_arretes();
    sommet S1{0,0,0}, S2{0,0,0};
    int x_max = 0, x_min = 0, y_max = 0;
    std::string texte;

    

    for (int i = 0; i < Sommet.size(); ++i)
    {
        svgdiagrame.addDisk(Sommet[i].Get_x() + decalage, Sommet[i].Get_y(), 7);
        if (Sommet[i].Get_x() > x_max)
            x_max = Sommet[i].Get_x();
        if (Sommet[i].Get_x() < x_min)
            x_min = Sommet[i].Get_x();
        if (Sommet[i].Get_y() > y_max)
            y_max = Sommet[i].Get_y();
    }
    for (int i = 0; i < Arrete.size(); ++i)
    {
        S1 = Arrete[i].Get_S1();
        S2 = Arrete[i].Get_S2();
        svgdiagrame.addLine(S1.Get_x() + decalage, S1.Get_y(), S2.Get_x() + decalage, S2.Get_y(), "black");

    }
    
  
    
    svgdiagrame.addText((x_max + x_min + 20)/2 + decalage, y_max + 20, Graph.cout_totale_1() );
    svgdiagrame.addText((x_max + x_min +20)/2 + decalage + 30, y_max + 20, ":" );
    svgdiagrame.addText((x_max + x_min +20)/2 + decalage + 40, y_max + 20, Graph.cout_totale_2() );
    
    
    


}

graph recuperation_poids (graph Graph, std::string nom_graph)
{
    std::ifstream fichier(nom_graph, std::ios::in);
    std::vector<arrete> Arretes = Graph.Get_arretes();
    
    int nb_a, nb_poids, numero;
    float var = 0;


    if (fichier)
    {


        fichier >> nb_a >> nb_poids;

       
        



        for (int i = 0; i < nb_a; ++i)
        {

                fichier >> numero >> var;
                Arretes[numero].changement_poids_1(var);
                fichier >> var;
                Arretes[numero].changement_poids_2(var);
                Arretes[numero].changement_nb(i);
            
        }

        fichier.close();
    }

       Graph.changement_arretes(Arretes);
    Arretes = Graph.Get_arretes();
   

    return Graph;
}






