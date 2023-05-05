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

    /**
     * @brief Construct a new River Crossing object
     * 
     * @param filename name of the archive to be read 
     */
    RiverCrossing(string filename);

    /**
     * @brief Destroy the River Crossing object
     * 
     */
    ~RiverCrossing();

    //todo: intentar implementar una especie de arreglo que en caso de 
    // Sobrepasar la cantidad de elementos se aumente el tamaño automaticamente
    // Definir un tamaño inicial de manera tal que sea poco probable tener que aumentar el tamaño
    // trabajar con una variable auxiliar fuera de inser operation es decir en generateOperations

    /**
     * @brief Generate the Operations of the problem
     * 
     * @param operation 
     */
    void generateOperations();


    /**
     * @brief Generate the Restrictions of the problem
     * 
     * @param restriction 
     */
    void generateRestrictions();


    /**
     * @brief Generate the Sucessors of the problem
     * 
     * @param state 
     */
    void successors(State *e);

    /**
     * @brief solve the problem
     * 
     * @param state 
     */

    void solve();



};




