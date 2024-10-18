#include <string>
#include<iostream>
#include<vector>
#include "Act2.h"
using namespace std;

//USUARIO
        //constructor
    Usuario::Usuario(string _id, string _nombre, string _email)
    :id(_id), name(_nombre), email(_email)
    {}
        //registro Libros
    void Usuario::registrarPrestamo(Libro* libro){
            if(libro->dispCheck()){
                listLibros.push_back(libro);
                libro->prestado();
    }
    }
    void Usuario::registrarDevolucion(Libro* libro){

        if(libro->dispCheck()){
            cout<<"El libro ya fue devuelto!";
        }else{
            bool flag=true;
            for(int n=0;n<listLibros.size()&&flag;n++){
                if(libro->descp()==listLibros[n]->descp()){
                    listLibros.erase(listLibros.begin()+n);
                    libro->devuelto();
                    flag=false;
            }
        }
    }
}
    string Usuario::toString(){
        int prestamos = listLibros.size();
        string sprest = to_string(prestamos);
        return (name+" "+id+" "+email+" "+"Libros en prestamo: "+sprest);
    }
    vector<Libro*> Usuario::obtenerPrestamosActivos()const{
        return listLibros;
    }
    void Usuario::mostrarPrestamos()const{
        if(obtenerPrestamosActivos().size()>0){
            cout<<"Prestamos del usuario"<<endl;
            for(int n=0; n<obtenerPrestamosActivos().size(); n++){
            string Descp = obtenerPrestamosActivos()[n]->descp();
            cout<<n+1<<"-"<<Descp<<endl;
            cout<<endl;
            }
        }else{
            cout<<"Prestamos del usuario"<<endl;
            for(int n=0; n<=obtenerPrestamosActivos().size(); n++){
            string Descp = obtenerPrestamosActivos()[n]->descp();
            cout<<n+1<<"-"<<Descp<<endl;
            cout<<endl;
        }
    }

    }
    bool Usuario::check_usinbib()const{
        return usinbib;
    }
    void Usuario::change_usinbib(){
        usinbib=true;
    }
    string Usuario::idString(){
        return id;
    }





