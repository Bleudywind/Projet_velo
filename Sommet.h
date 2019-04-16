//
//  Sommet.h
//  Projet velo
//
//  Created by Thomas FLG on 16/04/2019.
//  Copyright © 2019 Thomas FLG. All rights reserved.
//

#ifndef Sommet_h
#define Sommet_h


class sommet
{
    public :
    
    sommet(int x, int y, int nb);
    
    int Get_x();
    int Get_y();
    int Get_nb();
    
    
    
    
    private :
    
    int m_x;
    int m_y;
    int m_nb;
};

#endif /* Sommet_h */
