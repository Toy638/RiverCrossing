#include "../State/State.h"
#include "../bitService/bitService.h"
#include "../Operation/Operation.h"
#include "../Restriction/Restriction.h"
#include "../FileReader/fileReader.h"
#include "../Hashtable/Hashtable.h"
#include "../LinkedList/LinkedList.h"
#include "../Node/Node.h"
#include <vector>


class RiverCrossing
{
private:
    FileReader *archive;
    // Restriction **leftRestriction;
    // Restriction **rightRestriction;

    // vector<Restriction> leftRestriction;
    // vector<Restriction> rightRestriction;

    LinkedList *leftRestriction;
    LinkedList *rightRestriction;
    LinkedList *Operations;

    LinkedList *open;
    Hashtable *closed;
    int quantifyOfOperations; // se almacena en vector //todo: borrar

public:

    RiverCrossing(string filename);
    ~RiverCrossing();

    //todo: intentar implementar una especie de arreglo que en caso de 
    // Sobrepasar la cantidad de elementos se aumente el tamaño automaticamente
    // Definir un tamaño inicial de manera tal que sea poco probable tener que aumentar el tamaño
    // trabajar con una variable auxiliar fuera de inser operation es decir en generateOperations

    void generateOperations();
    void generateRestrictions();

    void successors(State *e);
    void solve();



};




