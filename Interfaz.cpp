#include <iostream>
#include <iostream>
#include<stdlib.h>
#include <string>
#include "Act2.h"


int main(){
    Biblioteca biblioteca = Biblioteca();
    //Declaracion del usuario
    Usuario User1 = Usuario("0000001","Usuario1","usuario1@user.com","pass1", 7);
    Usuario User2 = Usuario("0000002","Usuario2","usuario2@user.com","pass2", 7);
    Usuario User3 = Usuario("0000003","Usuario3","usuario3@user.com","pass3", 7);
    UsuarioEstudiante User4 = UsuarioEstudiante("0000004","Usuario4","usuario4@user.com", "Computacion","pass4", 7);
    UsuarioProfesor User5 = UsuarioProfesor("0000005","Usuario5","usuario5@user.com", "DIVTIC","pass5", 7);
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


    return 0;
}








