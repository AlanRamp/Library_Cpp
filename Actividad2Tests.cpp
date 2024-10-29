#include <iostream>
#include <iostream>
#include<stdlib.h>
#include <string>
#include "Act2.h"
/*
ALAN EDUARDO RAMIREZ PLASCENCIA 26/09/24
ACTIVIDAD 2 IMPLEMENTA CLASES LIBRO Y USUARIO
D20 POO MIGUEL ANGEL GUERRERO SEGURA RAMIREZ
*/

int main(){
    Biblioteca biblioteca = Biblioteca();
    //Declaracion del usuario
    Usuario User1 = Usuario("0000001","Usuario1","usuario1@user.com");
    Usuario User2 = Usuario("0000002","Usuario2","usuario2@user.com");
    Usuario User3 = Usuario("0000003","Usuario3","usuario3@user.com");
    UsuarioEstudiante User4 = UsuarioEstudiante("0000004","Usuario4","usuario4@user.com", "Computacion");
    UsuarioProfesor User5 = UsuarioProfesor("0000005","Usuario5","usuario5@user.com", "DIVTIC");
    //Declaracion de libros para el uso del programa
    Libro Libro1("8402103472", "Noches blancas", "Fiódor Dostoyevski", 1235);
    Libro Libro2("8475300219", "Crimen y castigo", "Fiódor Dostoyevski", 671);
    Libro Libro3("8422543001", "Los hermanos Karamazov", "Fiódor Dostoyevski", 824);
    Libro Libro4("6073168136", "El idiota", "Fiódor Dostoyevski", 656);
    Libro Libro5("8481301310", "El jugador", "Fiódor Dostoyevski", 207);
    Libro Libro6("8417782753", "Memorias del subsuelo", "Fiódor Dostoyevski", 160);
    Libro Libro7("8476570090", "Los demonios i", "Fiódor Dostoyevski", 768);
    Libro Libro8("8426155340", "El adolescente", "Fiódor Dostoyevski", 606);
    Libro Libro9("8466305831", "Humillados y ofendidos", "Fiódor Dostoyevski", 360);
    Libro Libro10("8496246116", "La vuelta al mundo en 80 dias", "Julio Verne", 1234);
    LibroFicion libro11("8402103472", "Noches blancas", "Fiódor Dostoyevski", 1235,"ficcion");
    //Marcar todos como prestados para probar el vector de apuntadores
    //User1.registrarPrestamo(&Libro1);
    User1.registrarPrestamo(&Libro2);
    User1.registrarPrestamo(&Libro3);
    User1.registrarPrestamo(&Libro4);
    User1.registrarPrestamo(&Libro5);
    User1.registrarPrestamo(&Libro6);
    User1.registrarPrestamo(&Libro7);
    User1.registrarPrestamo(&Libro8);
    User1.registrarPrestamo(&Libro9);
    User1.registrarPrestamo(&Libro10);
    //obtener vector con todos los libros agregados
    User1.mostrarPrestamos();
    //Marcar una espera para limpiar la pantalla
    system("pause");
    system("cls");
    //retornar un libro para elimiinar del vector
    User1.registrarDevolucion(&Libro3);
    User1.registrarDevolucion(&Libro4);
    User1.registrarDevolucion(&Libro5);
    User1.registrarDevolucion(&Libro6);
    User1.registrarDevolucion(&Libro7);
    User1.registrarDevolucion(&Libro8);
    User1.registrarDevolucion(&Libro9);
    User1.registrarDevolucion(&Libro10);
    //Marcar una espera para limpiar la pantalla
    system("pause");
    system("cls");
    //mostrar el vector con la devolucion aplicada
    User1.mostrarPrestamos();
    //datos del usuario
    cout<<User1.toString();
    cout<<endl;
    system("pause");
    system("cls");




    //BIBLIOTECA


    cout<<"Agregar libros a biblioteca"<<endl;
    biblioteca.agregarLibro(&Libro1);
    biblioteca.agregarLibro(&Libro2);
    biblioteca.agregarLibro(&Libro3);
    biblioteca.agregarLibro(&Libro4);
    biblioteca.agregarLibro(&Libro5);
    biblioteca.agregarLibro(&Libro6);
    system("pause");
    system("cls");
    cout<<"Agregar Usuarios a biblioteca"<<endl;
    biblioteca.agregarUsuario(&User1);
    biblioteca.agregarUsuario(&User2);
    system("pause");
    system("cls");
    cout<<"Buscar libro"<<endl;
    cout<<"1"<<endl;
    cout<<biblioteca.buscarLibro("8402103472")<<endl;
    cout<<"2"<<endl;
    cout<<biblioteca.buscarLibro("0000010000")<<endl;
    system("pause");
    system("cls");
    cout<<"Buscar usuario"<<endl;
    cout<<"1"<<endl;
    cout<<biblioteca.buscarUsuario("0000001")<<endl;
    cout<<"2"<<endl;
    cout<<biblioteca.buscarUsuario("0000003")<<endl;
    system("pause");
    system("cls");
    cout<<"Prestamos"<<endl;
    cout<<"1"<<endl;
    biblioteca.prestarLibro("8402103472","0000001");
    cout<<"2"<<endl;
    biblioteca.prestarLibro("8402103472","0000003");
    cout<<endl;
    system("pause");
    system("cls");
    cout<<"Devoluciones"<<endl;
    cout<<"1"<<endl;
    biblioteca.devolverLibro("8402103472","0000001");
    cout<<"2"<<endl;
    biblioteca.devolverLibro("8402103472","0000003");
    cout<<endl;
    system("pause");
    system("cls");
    cout<<"Libros"<<endl;
    biblioteca.mostrarLibros();
    cout<<endl;
    system("pause");
    system("cls");
    cout<<"Usuarios"<<endl;
    biblioteca.mostrarUsuarios();
    cout<<endl;
    system("pause");
    system("cls");
    cout<<"Libro ficcion"<<endl;
    cout<<libro11.descp()<<endl;
    system("pause");
    system("cls");
    cout<<"Usuario Estudiante"<<endl;
    cout<<User4.toString()<<endl;
    cout<<"Usuario Profesor"<<endl;
    cout<<User5.toString()<<endl;
    return 0;

}

