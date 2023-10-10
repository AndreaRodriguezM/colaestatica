#ifndef COLA_H
#define COLA_H
#include <iostream>

const int TAM = 100;

//**********Definición de la clase alumno********
class alumno
{
private:
    std::string nombre;
    std::string nombreCarrera;
    int materiasAprobadas;
    float promedioGeneral;

public:
    alumno() : nombre(""), nombreCarrera(""), materiasAprobadas(0), promedioGeneral(0.0) {}
    alumno(std::string n, std::string nc, int ma, float pg) : nombre(n), nombreCarrera(nc), materiasAprobadas(ma), promedioGeneral(pg) {}

    void operator=(alumno& x)
    {
        nombre = x.nombre;
        nombreCarrera = x.nombreCarrera;
        materiasAprobadas = x.materiasAprobadas;
        promedioGeneral = x.promedioGeneral;
    }

    friend std::ostream& operator<<(std::ostream& os, const alumno& a)
    {
        os << "\tNombre: " << a.nombre
           << ", Carrera: " << a.nombreCarrera
           << ", Materias Aprobadas: " << a.materiasAprobadas
           << ", Promedio General: " << a.promedioGeneral;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, alumno& a)
    {
        std::cout << "\tIngrese nombre del alumno: ";
        is >> a.nombre;
        std::cout << "\tIngrese nombre de la carrera: ";
        is >> a.nombreCarrera;
        std::cout << "\tIngrese cantidad de materias aprobadas: ";
        is >> a.materiasAprobadas;
        std::cout << "\tIngrese promedio general: ";
        is >> a.promedioGeneral;
        return is;
    }
};

//**********Definición de la clase Cola********
class Cola
{
private:
    alumno datos[TAM];
    int ult;

public:
    Cola() : ult(-1) {}

    bool vacia() const { return ult == -1; }
    bool llena() const { return ult == TAM - 1; }
    int ultimo() const { return ult; }

    friend std::ostream& operator<<(std::ostream& os, Cola& c)
    {
        os << "\tContenido de la cola" << std::endl;
        for (int i = 0; i <= c.ultimo(); i++)
        {
            os << c.datos[i] << std::endl;
        }
        return os;
    }

    void enqueue(alumno& elem)
    {
        if (!llena())
        {
            datos[++ult] = elem;
            std::cout << "\t¡Alumn@ agregado a la cola!." << std::endl;
        }
        else
        {
            std::cout << "\tLa cola está llena, no se puede agregar más alumnos." << std::endl;
        }
    }

alumno dequeue()
{
    if (!vacia())
    {
        alumno eliminado = datos[0]; // Almacenar el primer alumno
        for (int i = 0; i < ult; i++)
        {
            datos[i] = datos[i + 1];
        }
        ult--;
        return eliminado;
    }
    else
    {
        std::cout << "\tLa cola está vacía, no se puede eliminar ningún alumno." << std::endl;
        return alumno(); // Devolver un alumno por defecto en caso de cola vacía
    }
}

};
//*****************************

#endif // COLA_H
