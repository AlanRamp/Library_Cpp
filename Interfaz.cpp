#include <iostream>
#include <iostream>
#include<stdlib.h>
#include <string>
#include "Libraryh.h"


int main(){
    Biblioteca biblioteca = Biblioteca();
    //agregacion de libros y usuarios para pruebas
    LibroNoFicion Libro1("8402103472", "Noches blancas", "Fi�dor Dostoyevski", 1235,"Novela psicol�gica");
    LibroNoFicion Libro2("8475300219", "Crimen y castigo", "Fi�dor Dostoyevski", 671, "Novela psicol�gica");
    LibroNoFicion Libro3("8422543001", "Los hermanos Karamazov", "Fi�dor Dostoyevski", 824, "Novela psicol�gica");
    LibroNoFicion Libro4("6073168136", "El idiota", "Fi�dor Dostoyevski", 656, "Novela psicol�gica");
    LibroNoFicion Libro5("8481301310", "El jugador", "Fi�dor Dostoyevski", 207, "Novela psicol�gica");
    LibroNoFicion Libro6("8417782753", "Memorias del subsuelo", "Fi�dor Dostoyevski", 160, "Novela psicol�gica");
    LibroNoFicion Libro7("8476570090", "Los demonios i", "Fi�dor Dostoyevski", 768, "Novela psicol�gica");
    LibroNoFicion Libro8("8426155340", "El adolescente", "Fi�dor Dostoyevski", 606, "Novela psicol�gica");
    LibroNoFicion Libro9("8466305831", "Humillados y ofendidos", "Fi�dor Dostoyevski", 360, "Novela psicol�gica");
    LibroNoFicion Libro10("8496246116", "La vuelta al mundo en 80 dias", "Julio Verne", 1234, "Novela psicol�gica");
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








