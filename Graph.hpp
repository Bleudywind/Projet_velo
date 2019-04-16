//
//  Graph.hpp
//  Projet velo
//
//  Created by Thomas FLG on 16/04/2019.
//  Copyright © 2019 Thomas FLG. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include "Sommet.h"
#include "Arretes.hpp"

class graph
{
public:
  
    graph (std::vector <sommet> sommets, std::vector<arrete> m_arretes);
    
private:
    
    std::vector <sommet> m_sommets;
    std::vector<arrete> m_arretes;
    
};

#endif /* Graph_hpp */
