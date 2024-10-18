#include <string>
#include<iostream>
#include<vector>
#include "Act2.h"
using namespace std;


    //LIBRO
    Libro::Libro(string _isbn, string _titulo, string _autor, int _anioPubli)
    :isbn(_isbn),titulo(_titulo),autor(_autor),anioPubli(_anioPubli)
    {}
    void Libro::prestado(){
        disp=false;
    }
    void Libro::devuelto(){
        disp=true;
    }
    bool Libro::dispCheck()const{
        return disp;
    }
    string Libro::isbnString(){
        return isbn;
    }
    string Libro::descp(){
        return (titulo+" | "+isbn+" | "+autor);
    }



