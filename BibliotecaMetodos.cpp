#include <string>
#include<iostream>
#include<vector>
#include "Act2.h"
using namespace std;

bool Biblioteca::isbnCheck(Libro* libro){
        int i;
        // de string a entero
        string Isbn = libro->isbnString();
        int validador=0;
        //valida el largo
        if (Isbn.length() != 10) {
        return false;
        }
        //transforma cada digito individual y los deja en forma para evaluar el isbn
        //sin llegar al ultimo debido a que puede ser un caracter
        for(i=0;i<9;i++){
            //separa por digitos y multiplica de manera significativa de izquierda a derecha decendiendo desde 10 a 0
            validador+=(Isbn[i]-'0')*(10-i);
            //suma de valores ya trabajados
        }
        char ultimo = Isbn[9];
        //el ultimo caracter puede ser un caracter X que expresa 10
        if (ultimo == 'X') {
            validador += 10;
        } else if (isdigit(ultimo)) {
            validador += (ultimo - '0');
        } else {
            return false;
        }


        return (validador%11==0);
    }
    void Biblioteca::agregarLibro(Libro* libro){
        if(libro->dispCheck()&&isbnCheck(libro)){
            LibrosBiblioteca.push_back(libro);
            cout<<"Libro agregado con exito"<<endl;
        }else{
            cout<<"Libro no disponible para agregar!"<<endl;
        }
    }
    void Biblioteca::agregarUsuario(Usuario* usuario){
        if(!usuario->check_usinbib()){
            UsuariosBiblioteca.push_back(usuario);
            cout<<"Usuario agregado con exito"<<endl;
            usuario->change_usinbib();
        }else{
            cout<<"Usuario no disponible para agregar!"<<endl;
            }
    }
    Libro* Biblioteca::buscarLibro(string isbn)const{
        bool flag=true;
        Libro* ret=0;
        for(int i=0; i<LibrosBiblioteca.size() && flag; i++){
            if(LibrosBiblioteca[i]->isbnString()==isbn){
                ret = LibrosBiblioteca[i];
                flag=false;
            }

        }
        return ret;
    }
    Usuario* Biblioteca::buscarUsuario(string id)const{
        Usuario* ret=0;
        bool flag = true;
        for(int i=0; i<UsuariosBiblioteca.size()&& flag; i++){

            if(UsuariosBiblioteca[i]->idString()==id){
                ret = UsuariosBiblioteca[i];
                flag=false;
            }
        }

    return ret;
    }
    void Biblioteca::prestarLibro(string isbnlib, string idus){
        Libro* lib = buscarLibro(isbnlib);
        Usuario* user = buscarUsuario(idus);
        if(lib!=0&&user!=0){
            user->registrarPrestamo(lib);
            lib->prestado();
            cout<<"Prestamo registrado!"<<endl;

        }else{
            cout<<"Alguno de los datos proporcionados es incorrecto"<<endl;

        }

    }
    void Biblioteca::devolverLibro(string isbnlib, string idus){
        Libro* lib = buscarLibro(isbnlib);
        Usuario* user = buscarUsuario(idus);
        if(lib!=0&&user!=0){
            user->registrarDevolucion(lib);
            lib->devuelto();
            cout<<"Devolucion registrada!"<<endl;
        }else{
            cout<<"Alguno de los datos proporcionados es incorrecto"<<endl;

        }
    }
    string Biblioteca::mostrarLibros()const{
        for(int i = 0; i<LibrosBiblioteca.size();i++){
            string desc = LibrosBiblioteca[i]->descp();
            cout<<desc<<endl;
        }
    }
    string Biblioteca::mostrarUsuarios()const{
        for(int i = 0; i<UsuariosBiblioteca.size();i++){
            string desc = UsuariosBiblioteca[i]->toString();
            cout<<desc<<endl;
        }
    }
