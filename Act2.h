#ifndef Act2
#define Act2
#include <string>
#include<iostream>
#include<vector>
using namespace std;

class Biblioteca{
public:
    Bilbioteca();
    void agregarLibro(Libro*);
    void agregarUsuario(Usuario*);


private:
    vector <Libro*> LibrosBiblioteca;
    vector <Usuario*>UsuariosBiblioteca;
};
class Libro{
public:
    //constructor
    Libro(string, string , string , int );
    //cambiar estado del libro
    void prestado();
    //cambiar estado del libro
    void devuelto();
    //devolver el estado del libro
    bool dispCheck()const;
    //descripcion en el retorno del metodo
    string descp();
private:
    //6 caracteres
    string isbn;
    string titulo;
    string autor;
    int anioPubli;
    bool disp=true;


};
class Usuario{
public:
    //constructor
    Usuario(string , string , string );
    //agrega al vector el libro y cambia su estado
    void registrarPrestamo(Libro* libro);

    //elimina el libro del vector de prestamos en base a su descripcion completa
    //cambia el estado a disponible
    void registrarDevolucion(Libro* libro);




//informacion del usuario
    string toString();
    vector<Libro*> obtenerPrestamosActivos()const;
    void mostrarPrestamos()const;





private:
    vector<Libro*> listLibros;
    string name;
    //6 caracteres
    string id;
    string email;





};




#endif // Act2
