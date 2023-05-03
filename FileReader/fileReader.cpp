#include "fileReader.h"
using namespace std;
//constructores

FileReader::FileReader(string filename){

    ifstream *input = new ifstream(filename); // abrir el archivo
    if (input->is_open()) { // verificar que el archivo se abrio correctamente
        std::cout << "archivo abierto" << std::endl;

    } else {
        std::cout << "archivo no encontrado" << std::endl;
        exit(1);
    }

    string line; // linea de texto
    stringstream ss; // stream de caracteres

    // variables a leer del archivo
    int C,I,b,N; // cantidad de conductores, cantidad de item, capacidad del bote, cantidad total de item mas conductores
    int cantidadRestriccionesIzq, cantidadRestriccionesDer; // cantidad de restricciones de cada lado
    bool **restriccionesIzq, **restriccionesDer; // matriz de restricciones de cada lado


    // leer la primera linea
    getline(*input, line);
    ss << line; // copiar la linea al stream
    ss >> C >> I >> b; // leer los datos del stream
    N = C + I;
    cout <<"C:"<< C << " I:" << I << " b:" << b << endl;

    // leer la segunda linea
    getline(*input, line);
    cantidadRestriccionesIzq=atoi(line.c_str()) ; // c_str convierte el string a un arreglo de caracteres
    cout<<"cantidadRestriccionesIzq:"<<cantidadRestriccionesIzq<<endl;
    restriccionesIzq = new bool*[cantidadRestriccionesIzq]; // crear la matriz de restricciones
    for (int i = 0; i < cantidadRestriccionesIzq; i++) {
        restriccionesIzq[i] = new bool[N];
        for (int j = 0; j < N; j++) {
            restriccionesIzq[i][j] = 0;
        }
    }

    // leer las restricciones del lado izquierdo
    for (int i = 0; i < cantidadRestriccionesIzq; i++) {
        getline(*input, line);
        ss.clear(); // NO OLVIDAR ESTO: limpiar el stream de caracteres, porque ya viene con cosas
        ss << line; // llenar el stream con linea
        while (!ss.eof()) { // mientras no termine esta linea
            int a;
            ss >> a;
            restriccionesIzq[i][a-1] = 1; // a-1 porque los indices empiezan en 0
            cout << a << " ";
        }
        cout << endl;
    }
    
    
    // leer las restricciones del lado derecho
    getline(*input, line);
    ss.clear(); // limpiar el stream de caracteres
    ss << line; // copiar la linea al stream
    ss >> cantidadRestriccionesDer ;
    cout<<"cantidadRestriccionesDer:"<<cantidadRestriccionesDer<<endl;
    restriccionesDer = new bool*[cantidadRestriccionesDer]; // crear la matriz de restricciones
    for (int i = 0; i < cantidadRestriccionesDer; i++) {
        restriccionesDer[i] = new bool[N];
        for (int j = 0; j < N; j++) { // inicialmente en 0
            restriccionesDer[i][j] = 0;
        }
    }

    for (int i = 0; i < cantidadRestriccionesDer; i++) {
        getline(*input, line);
        ss.clear(); // limpiar el stream de caracteres
        ss << line; // copiar la linea al stream
        while (!ss.eof()) { // mientras no termine esta linea
            int a;
            ss >> a;
            restriccionesDer[i][a-1] = 1; // recuerden que los elementos de los archivos empiezan en 1, pero los indices en 0
            cout << a << " ";
        }
        cout << endl;
    }

    // cerrar el archivo
    input->close();

    // veamos como quedan las matrices

    cout<<"restriccionesIzq:"<<endl;
    for(int i=0;i<cantidadRestriccionesIzq;i++){
        for(int j=0;j<N;j++){
            cout<<restriccionesIzq[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"restriccionesDer:"<<endl;
    for(int i=0;i<cantidadRestriccionesDer;i++){
        for(int j=0;j<N;j++){
            cout<<restriccionesDer[i][j]<<" ";
        }
        cout<<endl;
    }

    //asignar cada una de las lecturas a cada uno de los elementos del archivo


    this->filename = filename;
    this->quantifyOfDrivers = C;   
    this->quantifyOfItems = I; 
    this->totalOfItems = C+I;
    this->maxCapacityOfBoat = b;
    this->quantifyOfLeftRestriction = cantidadRestriccionesIzq;
    this->quantifyOfRightRestriction = cantidadRestriccionesDer;
    this->leftRestriction = restriccionesIzq;
    this->rightRestriction = restriccionesDer;


}

FileReader::~FileReader(){
    //destructor
}

//getters

string FileReader::getFilename(){
    return this->filename;
}

int FileReader::getQuantifyOfDrivers(){
    return this->quantifyOfDrivers;
}

int FileReader::getQuantifyOfItems(){
    return this->quantifyOfItems;
}

int FileReader::getTotalOfItems(){
    return this->totalOfItems;
}

int FileReader::getMaxCapacityOfBoat(){
    return this->maxCapacityOfBoat;
}

int FileReader::getQuantifyOfLeftRestriction(){
    return this->quantifyOfLeftRestriction;
}

int FileReader::getQuantifyOfRightRestriction(){
    return this->quantifyOfRightRestriction;
}

bool** FileReader::getLeftRestriction(){
    return this->leftRestriction;
}

bool** FileReader::getRightRestriction(){
    return this->rightRestriction;
}



