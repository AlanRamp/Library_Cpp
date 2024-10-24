#ifndef Act2
#define Act2
#include <string>
#include<iostream>
#include<vector>
using namespace std;


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
    string isbnString();
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
    //Validar el estado del usuario en la biblioteca
    bool check_usinbib() const;
    void change_usinbib();




//informacion del usuario
    string toString();
    string idString();

//prestamos activos
    vector<Libro*> obtenerPrestamosActivos()const;
//mostrar
    void mostrarPrestamos()const;





private:
    bool usinbib=false;
    vector<Libro*> listLibros;
    string name;
    string id;
    string email;





};
class Biblioteca{
public:
    Bilbioteca();
    bool isbnCheck(Libro*);
    void agregarLibro(Libro*);
    void agregarUsuario(Usuario*);
    void prestarLibro(string, string);
    void devolverLibro(string, string);
    Libro* buscarLibro(string) const;
    Usuario* buscarUsuario(string) const;
    string descLibro(Libro*)const;
    string descUsuario(Usuario*)const;
    void mostrarLibros() const;
    void mostrarUsuarios() const;



private:
    vector <Libro*> LibrosBiblioteca;
    vector <Usuario*>UsuariosBiblioteca;
};




#endif // Act2
