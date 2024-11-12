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
            cout<<"Ingrese su id de usuario: "endl;
            cin>>id;
            cout<<"Ingrese su contraseña de usuario: "endl;
            cin>>pass;
            log_exit = logger(id, pass);
            if(log_exit==0 || log exit == 1){
                loggCont=false;
            }else{
                cout<<"Datos no encontrados"<<endl;
                cout<<"Desea ingresar de nuevo?1.-SÍ 2.-NO"<<endl;
                cin>>opc;
                if(opc!=1){
                    loggCont=false
                }
            }
        }

        //impresion de menú
        while(menuCont){

            switch log_exit{
                case 0:
                    cout<<"--Admin menu--"<<endl;
                    cout<<"1.-Agregar usuario"<<endl<<"2.-Agregar libro"<<endl<<"3.-Prestamo"<<endl<<"4.-Devolución"<<endl<<"5.-Buscar libro"<<endl<<"6.-Buscar usuario"<<endl<<"7.-Salir"<<endl
                    cin>>menuChan<<endl;
                    switch menuChan{
                    case 1:
                        int selector;
                        string id, name,email,pass,carrera,division;
                        int time = 7;
                        cout<<"ingrese el id del usuario"<<endl;
                        cin>>id<<endl;
                        cout<<"ingrese el nombre del usuario"<<endl;
                        cin>>name<<endl;
                        cout<<"ingrese el email del usuario"<<endl;
                        cin>>email<<endl;
                        cout<<"ingrese la contraseña del usuario"<<endl;
                        cin>>pass<<endl;
                        cout<<"El usuario es estudiante o profesor? 1.-Estudiante 2.-Profesor"<<endl;
                        cin>>selector<<endl;
                        if(selector == 1){
                            cout<<"ingrese la carrera del usuario"<<endl;
                            cin>>carrera<<endl;
                            UsuarioEstudiante* usE = new UsuarioEstudiante(id, name, email, carrera, pass, time);
                            agregarUsuario(usE);
                        }else if(selector == 2){
                            cout<<"ingrese la division del usuario"<<endl;
                            cin>>division<<endl;
                            UsuarioProfesor* usP = new UsuarioProfesor(id, name, email, division, pass, time);
                            agregarUsuario(usP);
                        }else{
                            cout<<"Opcion de usuario invalida"<<endl;
                        }
                        break;
                    case 2:
                        string isbn, titulo,autor,tema;
                        int anio;
                        int selector;
                        cout<<"ingrese el isbn del libro"<<endl;
                        cin>>isbn<<endl;
                        cout<<"ingrese el titulo del libro"<<endl;
                        cin>>titulo<<endl;
                        cout<<"ingrese el autor del libro"<<endl;
                        cin>>autor<<endl;
                        cout<<"ingrese año de publicacion"<<endl;
                        cin>>anio<<endl;
                        cout<<"El libro es de ficcion o de otro tema? 1.-Ficcion 2.-Otro"<<endl;
                        cin>>selector<<endl;
                        if(selector == 1){
                            LibroFicion* libF = new LibroFicion(isbn, titulo, autor, anio, "Ficcion");
                            agregarUsuario(usE);
                        }else if(selector == 2){
                            cout<<"ingrese el tema del libro"<<endl
                            cin>>tema<<endl;
                            LibroNoFicion* libO = new LibroNoFicion(isbn, titulo, autor, anio, tema);
                            agregarUsuario(usP);
                        }else{
                            cout<<"Opcion de libro invalida"<<endl;
                        }
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                    }
                    break;
                case 1:
                    cout<<"--Admin menu--"<<endl;
                    cout<<"1.-Prestamo"<<endl<<"2.-Devolución"<<endl<<"3.-Buscar libro"<<endl<<"4.-Buscar usuario"<<endl<<"5.-Salir"<<endl
                    cin>>menuChan<<endl;
                    switch menuChan{
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    break;
                case 2:
                    menuCont=false;
                    break;
            }
        }
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
