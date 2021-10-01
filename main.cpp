#include <iostream>

using namespace std;

class Tutorados {
private:
    string matricula;
    string nombre;
    int semestre;
public:
    Tutorados();

    Tutorados(string _matricula, string _nombre, int _semestre);

//    ~Tutorados();

    string getNombre();

    string getMatricula();

    int getSemestre();

    void setNombre(string);

    void setMatricula(string);

    void setSemestre(int);

    void preguntarDatos();
};

Tutorados::Tutorados() {
    this->matricula = "";
    this->nombre = "";
    this->semestre = 0;
}

Tutorados::Tutorados(string _matricula, string _nombre, int _semestre) {
    this->matricula = _matricula;
    this->nombre = _nombre;
    this->semestre = _semestre;

}
void Tutorados::preguntarDatos(){
    string matricula, nombre;
    int semestre;
    cout<<"Inserte matricula: ";
    cin>>matricula;
    cout<<"Inserte nombre: ";
    cin>>nombre;
    cout<<"Inserte semestre: ";
    cin>>semestre;
    this->matricula = matricula;
    this->nombre = nombre;
    this->semestre = semestre;
}

string Tutorados::getNombre() {
    return nombre;
}

string Tutorados::getMatricula() {
    return matricula;
}

int Tutorados::getSemestre() {
    return semestre;
}

void Tutorados::setNombre(string _nombre) {
    this->nombre = _nombre;
}

void Tutorados::setMatricula(string _matricula) {
    this->matricula = _matricula;
}

void Tutorados::setSemestre(int _semestre) {
    this->semestre = _semestre;
}


class Nodo {// un nodo se conforma un dato y una apuntador de tipo nodo
    Tutorados tutorado;
    Nodo *sig;
public:
    Nodo();

    Nodo(Tutorados _tutorado);

    void setSig(Nodo *Sig);

    Nodo *getSig();

    void setTutorado(Tutorados _tutorado);

    Tutorados getTutorado();
};

Nodo::Nodo() { //Inicializar los datos
    this->sig = NULL;
    this->tutorado = *new Tutorados();
}

Nodo::Nodo(Tutorados _tutorado) {
    this->tutorado = _tutorado;
}


void Nodo::setSig(Nodo *sig) {
    this->sig = sig;
}

void Nodo::setTutorado(Tutorados _tutorado) {
    this->tutorado = _tutorado;
}

Nodo *Nodo::getSig() {
    return sig;
}

Tutorados Nodo::getTutorado() {
    return tutorado;
}


class Lista {
    Nodo *cab;//cabeza
public:
    Lista();

    ~Lista();//Destructor
    //Metodos básicos
    void eliminar();//Listo
    int estaVacia();//Listo
    void insertarPorMatricula(Tutorados _tutorado);

    void insertarPorSemestre(Tutorados _tutorado);

    void insertarPrincipio(Tutorados _tutorado);

    void mostrar();

    void eliminarPorSemestre(int semestre);

    void eliminarPorNombre(string nombre);

    void eliminarPorMatricula(string _matricula);

    void insertarPorNombre(Tutorados _tutorado);


    void insertarPorPrioridad(int prioridad, int n);

    void eliminarPorPrioridad(int prioridad);
};

Lista::Lista() {
    this->cab = NULL;
}

void Lista::eliminar() {
    if (cab != NULL) {
        Nodo *p = cab;//1ro situarme en la cabeza de la lista
        cab = p->getSig();//cab = cab->getSig();
        delete p;
    }
}


Lista::~Lista() {
    while (!estaVacia()) {
        eliminar();
    }
}

int Lista::estaVacia() {
    return cab == NULL;
}

void Lista::mostrar() {
    cout << "Cab->" << endl;
    Nodo *p = cab; //1ro situarme en la cabeza de la lista
    while (p != NULL) {
        cout << "Nombre: " << p->getTutorado().getNombre() << " Semestre: " << p->getTutorado().getSemestre()
             << " Matricula: " << p->getTutorado().getMatricula() << "  " << "->" << endl << endl;
        p = p->getSig();
    }
    cout << "NULL" << endl;
}

void Lista::insertarPrincipio(Tutorados _tutorado) {
    Nodo *p = new Nodo();
    p->setTutorado(_tutorado);
    p->setSig(cab);
    cab = p;
}

void Lista::insertarPorSemestre(Tutorados _tutorado) {//de menor a mayor
    Nodo *p = cab;
    if (estaVacia()) {
        insertarPrincipio(_tutorado);
    } else {
        Nodo *aux = new Nodo();
        Nodo *tutorado = new Nodo(_tutorado);
        while ((p != NULL) && (p->getTutorado().getSemestre() < _tutorado.getSemestre())) {
            aux = p;//Es el dato anterior a p
            p = p->getSig();
        }
        aux->setSig(tutorado);//situamos a el dato anterior de p al tutorado
        tutorado->setSig(p);//volvemos a la lista
    }
    if (p == cab) {//esto pasa cuando insertamos un valor menor al primer dato que insertamos
        insertarPrincipio(_tutorado);
    }

}

void Lista::insertarPorNombre(Tutorados _tutorado) {//alfabeticamente
    Nodo *p = cab;
    if (estaVacia()) {
        insertarPrincipio(_tutorado);
    } else {
        Nodo *aux = new Nodo();
        Nodo *tutorado = new Nodo(_tutorado);
        while ((p != NULL) && (p->getTutorado().getNombre() < _tutorado.getNombre())) {
            aux = p;//Es el dato anterior a p
            p = p->getSig();
        }
        aux->setSig(tutorado);//situamos a el dato anterior de p al tutorado
        tutorado->setSig(p);//volvemos a la lista
    }
    if (p == cab) {//esto pasa cuando insertamos un valor menor al primer dato que insertamos
        insertarPrincipio(_tutorado);
    }

}
void Lista::insertarPorMatricula(Tutorados _tutorado) {
    Nodo *p = cab;
    if (estaVacia()) {
        insertarPrincipio(_tutorado);
    } else {
        Nodo *aux = new Nodo();
        Nodo *tutorado = new Nodo(_tutorado);
        while ((p != NULL) && (p->getTutorado().getMatricula() < _tutorado.getMatricula())) {
            aux = p;//Es el dato anterior a p
            p = p->getSig();
        }
        aux->setSig(tutorado);//situamos a el dato anterior de p al tutorado
        tutorado->setSig(p);//volvemos a la lista
    }
    if (p == cab) {//esto pasa cuando insertamos un valor menor al primer dato que insertamos
        insertarPrincipio(_tutorado);
    }
}



void Lista::eliminarPorSemestre(int semestre) {
    Nodo *p = cab;
    Nodo *aux;
    while (p != NULL && p->getTutorado().getSemestre() != semestre) {
        aux = p;
        p = p->getSig();
    }
    if (cab->getTutorado().getSemestre() ==
        semestre) {//eliminamoas la cabeza y la sustituimos por el siguiente en caso de que la coincidencia se encuentre en la cabeza
        aux = p->getSig();
        delete p;
        cab = aux;
    } else {
        if (p != NULL) {
            aux->setSig(p->getSig());
            delete p;
        } else {
            cout << "No se encontraron coincidencias en eliminar por semestre " << endl;
        }
    }

}

void Lista::eliminarPorNombre(string nombre) {
    Nodo *p = cab;
    Nodo *aux;
    while (p != NULL && p->getTutorado().getNombre() != nombre) {
        aux = p;
        p = p->getSig();
    }
    if (cab->getTutorado().getNombre() ==
        nombre) {//eliminamoas la cabeza y la sustituimos por el siguiente en caso de que la coincidencia se encuentre en la cabeza
        aux = p->getSig();
        delete p;
        cab = aux;
    } else {
        if (p != NULL) {
            aux->setSig(p->getSig());
            delete p;
        } else {
            cout << "No se encontraron coincidencias en eliminar por nombre " << endl;
        }
    }
}

void Lista::eliminarPorMatricula(string _matricula) {
    Nodo *p = cab;
    Nodo *aux;
    while (p != NULL && p->getTutorado().getMatricula() != _matricula) {
        aux = p;
        p = p->getSig();
    }
    if (cab->getTutorado().getMatricula() ==
        _matricula) {//eliminamoas la cabeza y la sustituimos por el siguiente en caso de que la coincidencia se encuentre en la cabeza
        aux = p->getSig();
        delete p;
        cab = aux;
    } else {
        if (p != NULL) {
            aux->setSig(p->getSig());
            delete p;
        } else {
            cout << "No se encontraron coincidencias en eliminar por matricula" << endl;
        }
    }

}
void Lista::insertarPorPrioridad(int prioridad,int n){
    switch (prioridad) {
        case 1:
            for (int i = 0; i < n; ++i) {
                Tutorados a = *new Tutorados();
                a.preguntarDatos();
                insertarPorMatricula(a);
            }
            break;
        case 2:
            for (int i = 0; i < n; ++i) {
                Tutorados a = *new Tutorados();
                a.preguntarDatos();
                insertarPorNombre(a);
            }
            break;
        case 3:
            for (int i = 0; i < n; ++i) {
                Tutorados a = *new Tutorados();
                a.preguntarDatos();
                insertarPorSemestre(a);
            }
            break;
        default:
            cout<<"Opcion no valida";
            break;
    }
}
void Lista::eliminarPorPrioridad(int prioridad){
    string matricula, nombre;
    int semestre;
    switch (prioridad) {
        case 1:
            cout<<"Inserte su matricula\n";
            cin>>matricula;
            eliminarPorMatricula(matricula);
            break;
        case 2:
            cout<<"Inserte su nombre\n";
            cin>>nombre;
            eliminarPorNombre(nombre);
            break;
        case 3:
            cout<<"Inserte su semestre\n";
            cin>>semestre;
            eliminarPorSemestre(semestre);
            break;
        default:
            cout<<"Opcion no valida\n";
            cout<<"Inserte una nueva prioridad del 1 al 3\n";
            int nuevaPrioridad;
            cin>>nuevaPrioridad;
            eliminarPorPrioridad(prioridad);
            break;
    }

}

int main() {
    int n, prioridad,opcion;
    cout<<"Inserte el numero de tutorados que ingresara\n";
    cin>>n;
    cout<<"Elija la prioridad\n"
            "I-Matricula (string)\n"
          "II-Nombre (string)\n"
          "III-semestre (int)\n";
    cin>>prioridad;
    Lista li;
    li.insertarPorPrioridad(prioridad,n);
    do {
        cout<<"Que desea hacer\n"
              "1.- Insertar un nuevo tutorado\n"
              "2.- Eliminar un tutorado por alguna prioridad que el usuario desee\n"
              "3.- Mostrar la lista de tutorados.\n"
              "4.- Salir\n";
        cin>>opcion;
        switch (opcion) {
            case 1:
                li.insertarPorPrioridad(prioridad,1);
                break;
            case 2:
                int prioridadEliminar;
                cout<<"Elija la prioridad\n"
                      "I-Matricula (string)\n"
                      "II-Nombre (string)\n"
                      "III-semestre (int)\n";
                cin>>prioridadEliminar;
                li.eliminarPorPrioridad(prioridadEliminar);
                break;
            case 3:
                li.mostrar();
                break;
            case 4:
                cout<<"Hasta luego\n";
                break;
            default:
                cout<<"Opcion no valida\n";
        }
    }while (opcion!=4);


    return 0;
}
