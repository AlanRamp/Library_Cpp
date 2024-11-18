#include <string>
#include<iostream>
#include<vector>
#include "Libraryh.h"
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
    int Biblioteca::logger(string id, string pass){
        Usuario* user = buscarUsuario(id);
        int exit=5;
        if(user->idString() == "0000000" && pass == user->passString()){
            exit = 0;
        }else if(user->idString() != "0000000" && pass == user->passString()){
            exit = 1;
        }else{
            exit = 2;
        }
        return exit;
    }
    void Biblioteca::menu(){

        string id, pass;
        //variables de estado del logger y el menu
        bool menuCont=true, loggCont=true;
        int log_exit;//salida del logger
        int opc;//opcion para el reingreso de datos
        int menuChan;//opcion del menu
        //logger implementado
        while(loggCont){
            cout<<"Ingrese su id de usuario: "<<endl;
            cin>>id;
            cout<<"Ingrese su contraseña de usuario: "<<endl;
            cin>>pass;
            log_exit = logger(id, pass);
            if(log_exit==0 || log_exit == 1){
                loggCont=false;
            }else{
                cout<<"Datos no encontrados"<<endl;
                cout<<"Desea ingresar de nuevo?1.-SÍ 2.-NO"<<endl;
                cin>>opc;
                if(opc!=1){
                    loggCont=false;
                }
            }
        }

        //impresion de menú
        while(menuCont){
            string isbn, idus;
            int selector;
            int time = 7;
            system("cls");
                    if(log_exit==0){
                        cout<<"--Admin menu--"<<endl;
                        cout<<"1.-Prestamo"<<endl<<"2.-Devolución"<<endl<<"3.-Buscar libro"<<endl<<"4.-Mostrar libros"<<endl<<"5.-Salir"<<endl<<"Opciones de administrador"<<endl<<"6.-Mostrar usuarios"<<endl<<"7.-Agregar usuario"<<endl<<"8.-Agregar libro"<<endl<<"9.-Buscar usuario"<<endl;
                        cin>>menuChan;
                    }else if(log_exit==1){
                        cout<<"--User menu--"<<endl;
                        cout<<"1.-Prestamo"<<endl<<"2.-Devolución"<<endl<<"3.-Buscar libro"<<endl<<"4.-Mostrar libros"<<endl<<"5.-Salir"<<endl;
                        cin>>menuChan;
                    }else{
                        system("cls");
                        menuCont=false;
                    }
                    if(log_exit<2){
                        switch (menuChan){
                        system("cls");
                        case 1:{
                            //prestamo
                            system("cls");
                            cout<<"Ingrese el isbn del libro a prestar: "<<endl;
                            cin>>isbn;
                            cout<<"Ingrese el id del usuario que solicita: "<<endl;
                            cin>>idus;
                            prestarLibro(isbn, idus);
                            system("pause");
                            break;}
                        case 2:{
                            //devolucion
                            system("cls");
                            cout<<"Ingrese el isbn del libro a devolver: "<<endl;
                            cin>>isbn;
                            cout<<"Ingrese el id del usuario que devuelve: "<<endl;
                            cin>>idus;
                            devolverLibro(isbn, idus);
                            system("pause");
                            break;}
                        case 3:{
                            //buscar libro
                            system("cls");
                            cout<<"Ingrese el isbn del libro a buscar: "<<endl;
                            cin>>isbn;
                            buscarLibro(isbn);
                            system("pause");
                            break;}
                        case 4:{
                            //mostrar libros
                            system("cls");
                            mostrarLibros();
                            system("pause");
                            break;}
                        case 5:{
                            system("cls");
                            menuCont=false;
                            break;}
                        case 6:{
                            //mostrar Usuarios
                            if(log_exit==0){
                                system("cls");
                                mostrarUsuarios();
                                system("pause");
                            }else{
                                cout<<"opcion invalida"<<endl;
                            }
                            break;}
                        case 7:{
                            //agregar libro
                            if(log_exit==0){
                            system("cls");
                            string titulo,autor,tema;
                            int anio;
                            cout<<"ingrese el isbn del libro"<<endl;
                            cin>>isbn;
                            cout<<"ingrese el titulo del libro"<<endl;
                            cin>>titulo;
                            cout<<"ingrese el autor del libro"<<endl;
                            cin>>autor;
                            cout<<"ingrese año de publicacion"<<endl;
                            cin>>anio;
                            cout<<"El libro es de ficcion o de otro tema? 1.-Ficcion 2.-Otro"<<endl;
                            cin>>selector;
                            if(selector == 1){
                                LibroFicion* libF = new LibroFicion(isbn, titulo, autor, anio, "Ficcion");
                                agregarLibro(libF);
                                cout<<"Libro de ficcion agregado con exito!"<<endl;
                            }else if(selector == 2){
                                cout<<"ingrese el tema del libro"<<endl;
                                cin>>tema;
                                LibroNoFicion* libO = new LibroNoFicion(isbn, titulo, autor, anio, tema);
                                agregarLibro(libO);
                                cout<<"Libro agregado con exito!"<<endl;
                            }else{
                                cout<<"Opcion de libro invalida"<<endl;
                            }
                            system("pause");}else{cout<<"opcion invalida"<<endl;}

                            break;

                            }
                        case 8:{
                            //agregar usuario
                            if(log_exit==0){
                                system("cls");
                                string id, name,email,pass,carrera,division;
                                cout<<"ingrese el id del usuario"<<endl;
                                cin>>id;
                                cout<<"ingrese el nombre del usuario"<<endl;
                                cin>>name;
                                cout<<"ingrese el email del usuario"<<endl;
                                cin>>email;
                                cout<<"ingrese la contraseña del usuario"<<endl;
                                cin>>pass;
                                cout<<"El usuario es estudiante o profesor? 1.-Estudiante 2.-Profesor"<<endl;
                                cin>>selector;
                                if(selector == 0){
                                    cout<<"ingrese la carrera del usuario"<<endl;
                                    cin>>carrera;
                                    UsuarioEstudiante* usE = new UsuarioEstudiante(id, name, email, carrera, pass, time);
                                    agregarUsuario(usE);
                                    cout<<"Estudiante agregado con exito!"<<endl;
                                }else if(selector == 2){
                                    cout<<"ingrese la division del usuario"<<endl;
                                    cin>>division;
                                    UsuarioProfesor* usP = new UsuarioProfesor(id, name, email, division, pass, time);
                                    agregarUsuario(usP);
                                    cout<<"Profesor agregado con exito!"<<endl;
                            }else{
                                cout<<"Opcion de usuario invalida"<<endl;
                            }
                            system("pause");
                            }else{cout<<"opcion invalida"<<endl;}

                            break;}

                        case 9:{
                            //buscar usuarios;
                            if(log_exit==0){
                                cout<<"Ingrese el id del usuario a buscar: "<<endl;
                                cin>>idus;
                                buscarUsuario(idus);
                                system("pause");
                            }else{cout<<"opcion invalida"<<endl;}

                            break;}
                        }
                    }
                }
            }

    void Biblioteca::agregarLibro(LibroFicion* libro){
        if(libro->dispCheck()&&isbnCheck(libro)){
            LibrosBiblioteca.push_back(libro);
            cout<<"Libro agregado con exito"<<endl;
        }else{
            cout<<"Libro no disponible para agregar!"<<endl;
        }
    }
    void Biblioteca::agregarLibro(LibroNoFicion* libro){
        if(libro->dispCheck()&&isbnCheck(libro)){
            LibrosBiblioteca.push_back(libro);
            cout<<"Libro agregado con exito"<<endl;
        }else{
            cout<<"Libro no disponible para agregar!"<<endl;
        }
    }
    void Biblioteca::agregarUsuario(UsuarioBibliotecario* usuario){
        if(!usuario->check_usinbib()){
            UsuariosBiblioteca.push_back(usuario);
            cout<<"Usuario agregado con exito"<<endl;
            usuario->change_usinbib();
        }else{
            cout<<"Usuario no disponible para agregar!"<<endl;
            }
    }
    void Biblioteca::agregarUsuario(UsuarioEstudiante* usuario){
        if(!usuario->check_usinbib()){
            UsuariosBiblioteca.push_back(usuario);
            cout<<"Usuario agregado con exito"<<endl;
            usuario->change_usinbib();
        }else{
            cout<<"Usuario no disponible para agregar!"<<endl;
            }
    }
    void Biblioteca::agregarUsuario(UsuarioProfesor* usuario){
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
    string Biblioteca::descLibro(Libro* libro)const{
        return libro->descp();
    }
    string Biblioteca::descUsuario(Usuario* usuario)const{
        return usuario->toString();
    }
    void Biblioteca::mostrarLibros()const{
        for(int i = 0; i<LibrosBiblioteca.size();i++){
            string desc = descLibro(LibrosBiblioteca[i]);
            cout<<desc<<endl;
        }
    }
    void Biblioteca::mostrarUsuarios()const{
        for(int i = 0; i<UsuariosBiblioteca.size();i++){
            string desc = descUsuario(UsuariosBiblioteca[i]);
            cout<<desc<<endl;
        }

    }
