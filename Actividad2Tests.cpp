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
    //Declaracion de libros para el uso del programa
    Libro Libro1("8402103472", "Noches blancas", "Fiódor Dostoyevski", 1235);
    Libro Libro2("8475300219", "Crimen y castigo", "Fiódor Dostoyevski", 671);
    Libro Libro3("0000003", "Los hermanos Karamazov", "Fiódor Dostoyevski", 824);
    Libro Libro4("0000004", "El idiota", "Fiódor Dostoyevski", 656);
    Libro Libro5("0000005", "El jugador", "Fiódor Dostoyevski", 207);
    Libro Libro6("0000006", "Memorias del subsuelo", "Fiódor Dostoyevski", 160);
    Libro Libro7("0000007", "Los demonios", "Fiódor Dostoyevski", 768);
    Libro Libro8("0000008", "El adolescente", "Fiódor Dostoyevski", 606);
    Libro Libro9("0000009", "Humillados y ofendidos", "Fiódor Dostoyevski", 360);
    Libro Libro10("0000010", "La vuelta al mundo en 80 dias", "Julio Verne", 1234);
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

    cout<<"Agregar libros a biblioteca"<<endl;
    biblioteca.agregarLibro(&Libro1);
    biblioteca.agregarLibro(&Libro2);
    biblioteca.agregarLibro(&Libro3);
    biblioteca.agregarLibro(&Libro4);
    biblioteca.agregarLibro(&Libro5);
    biblioteca.agregarLibro(&Libro6);
    cout<<endl;
    cout<<"agregar Usuarios a biblioteca"<<endl;
    biblioteca.agregarUsuario(&User1);
    biblioteca.agregarUsuario(&User2);
    cout<<endl;
    cout<<"Buscar libro"<<endl;
    biblioteca.buscarLibro("8402103472");
    biblioteca.buscarLibro("0000010000");
    cout<<endl;
    cout<<"Buscar usuario"<<endl;
    biblioteca.buscarUsuario("0000001");
    biblioteca.buscarUsuario("0000003");
    cout<<endl;
    cout<<"Prestamos"<<endl;
    biblioteca.prestarLibro("8402103472","0000001");
    biblioteca.prestarLibro("8402103472","0000003");
    cout<<endl;
    cout<<"Devoluciones"<<endl;
    biblioteca.devolverLibro("8402103472","0000001");
    biblioteca.devolverLibro("8402103472","0000003");
    cout<<endl;
    cout<<"libros"<<endl;
    biblioteca.mostrarLibros();
    cout<<endl;
    cout<<"usuarios"<<endl;
    biblioteca.mostrarUsuarios();


    return 0;

}

