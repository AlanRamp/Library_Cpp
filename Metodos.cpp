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
    string Libro::descp(){
        return (titulo+" | "+isbn+" | "+autor);
    }


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
                cout<<"Prestamo recibido!"<<endl;

                }else{
                    cout<<"El libro ya fue prestado!"<<endl;
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
                    cout<<"Devolucion realizada con exito!"<<endl;

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




