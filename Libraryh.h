#ifndef Libraryh
#define Libraryh
#include <string>
#include<iostream>
#include<vector>
using namespace std;
class Libro;
class LibroFicion;
class LibroNoFicion;
class Usuario;
class UsuarioBibliotecario;
class UsuarioProfesor;
class UsuarioEstudiante;
class Biblioteca{
public:
    Bilbioteca();
    int logger(string, string);
    void menu();
    bool isbnCheck(Libro*);

    void agregarLibro(LibroFicion*);
    void agregarLibro(LibroNoFicion*);

    void agregarUsuario(UsuarioProfesor*);
    void agregarUsuario(UsuarioEstudiante*);
    void agregarUsuario(UsuarioBibliotecario*);
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
    virtual string descp();
    //getters
    string isbnString();
    string tituloString();
    string autorString();
    int anioNum();
private:
    //6 caracteres
    string isbn;
    string titulo;
    string autor;
    int anioPubli;
    bool disp=true;


};
class LibroFicion:public Libro{
public:
    LibroFicion(string _isbn, string _titulo, string _autor, int _aniopubli, string _genero):Libro(_isbn,_titulo,_autor,_aniopubli),genero(_genero)
    {}
    string descp()override;
private:
    string genero;

};
class LibroNoFicion:public Libro{
public:
    LibroNoFicion(string _isbn, string _titulo, string _autor, int _aniopubli,string _tema):Libro(_isbn,_titulo,_autor,_aniopubli),tema(_tema)
    {}
    string descp() override;
private:
    string tema;
};
class Usuario{
public:
    //constructor
    Usuario(string , string , string,string, int );
    //agrega al vector el libro y cambia su estado
    void registrarPrestamo(Libro* libro);

    //elimina el libro del vector de prestamos en base a su descripcion completa
    //cambia el estado a disponible
    void registrarDevolucion(Libro* libro);
    //Validar el estado del usuario en la biblioteca
    bool check_usinbib() const;
    void change_usinbib();
//informacion del usuario
    virtual string toString();
//prestamos activos
    vector<Libro*> obtenerPrestamosActivos()const;
//mostrar
    void mostrarPrestamos()const;
    string idString();
    string nombreString();
    string emailString();
    string passString();
private:
    string pass;
    int timeBook;
    bool usinbib=false;
    vector<Libro*> listLibros;
    string name;
    string id;
    string email;
};
class UsuarioEstudiante: public Usuario{
public:
    UsuarioEstudiante(string _id, string _nombre, string _email, string _carrera,string _pass, int _timeBook):Usuario(_id, _nombre, _email,_pass,_timeBook),carrera(_carrera)
    {}
    string toString() override;
private:

    string carrera;
};
class UsuarioProfesor: public Usuario{
public:
    UsuarioProfesor(string _id, string _nombre, string _email, string _division, string _pass,int _timeBook):Usuario(_id, _nombre, _email,_pass,_timeBook),division(_division)
    {}
    string toString() override;
private:

    string division;
};
class UsuarioBibliotecario:public Usuario, public Biblioteca{
public:
    UsuarioBibliotecario(string _id, string _nombre, string _email, string _pass,int _timeBook):Usuario(_id, _nombre, _email,_pass,_timeBook)
    {}
private:

};






#endif // Act2
