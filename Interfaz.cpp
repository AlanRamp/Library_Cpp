#include <iostream>
#include <iostream>
#include<stdlib.h>
#include <string>
#include "Libraryh.h"


int main(){
    Biblioteca biblioteca = Biblioteca();
    //agregacion de libros y usuarios para pruebas
    LibroNoFicion Libro1("8402103472", "Noches blancas", "Fiódor Dostoyevski", 1235,"Novela psicológica");
    LibroNoFicion Libro2("8475300219", "Crimen y castigo", "Fiódor Dostoyevski", 671, "Novela psicológica");
    LibroNoFicion Libro3("8422543001", "Los hermanos Karamazov", "Fiódor Dostoyevski", 824, "Novela psicológica");
    LibroNoFicion Libro4("6073168136", "El idiota", "Fiódor Dostoyevski", 656, "Novela psicológica");
    LibroNoFicion Libro5("8481301310", "El jugador", "Fiódor Dostoyevski", 207, "Novela psicológica");
    LibroNoFicion Libro6("8417782753", "Memorias del subsuelo", "Fiódor Dostoyevski", 160, "Novela psicológica");
    LibroNoFicion Libro7("8476570090", "Los demonios i", "Fiódor Dostoyevski", 768, "Novela psicológica");
    LibroNoFicion Libro8("8426155340", "El adolescente", "Fiódor Dostoyevski", 606, "Novela psicológica");
    LibroNoFicion Libro9("8466305831", "Humillados y ofendidos", "Fiódor Dostoyevski", 360, "Novela psicológica");
    LibroNoFicion Libro10("8496246116", "La vuelta al mundo en 80 dias", "Julio Verne", 1234, "Novela psicológica");
    UsuarioEstudiante Alan = UsuarioEstudiante("0000004","Alan","alan@user.com", "Computacion","pass4", 7);
    UsuarioEstudiante Karla = UsuarioEstudiante("0000005","Karla","karla@user.com", "Quimico Farmaco Biologo","pass5", 7);
    UsuarioBibliotecario UserAdmin = UsuarioBibliotecario("0000000","UsuarioAdm","usuario5@user.com", "adminAdmin", 7);
    system("cls");
    biblioteca.agregarUsuario(&UserAdmin);
    biblioteca.agregarUsuario(&Alan);
    biblioteca.agregarUsuario(&Karla);
    biblioteca.agregarLibro(&Libro1);
    biblioteca.agregarLibro(&Libro2);
    biblioteca.agregarLibro(&Libro3);
    biblioteca.agregarLibro(&Libro4);
    biblioteca.agregarLibro(&Libro5);
    biblioteca.agregarLibro(&Libro6);
    biblioteca.agregarLibro(&Libro7);
    biblioteca.agregarLibro(&Libro8);
    biblioteca.agregarLibro(&Libro9);
    biblioteca.agregarLibro(&Libro10);
    system("cls");




    //inicio de programa
    biblioteca.menu();
    return 0;
}








