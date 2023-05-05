#include "RiverCrossing.h"
using namespace std;

RiverCrossing::RiverCrossing(string fileName)
{
    FileReader *archive = new FileReader(fileName);
    this->archive = archive;
    this->open = new LinkedList();
    this->Operations = new LinkedList();
    this->leftRestriction = new LinkedList();
    this->rightRestriction = new LinkedList();
    this->closed = new Hashtable(this->archive->getTotalOfItems());
    // operaciones y restricciones se inicializan después
}

RiverCrossing::~RiverCrossing()
{
}

void RiverCrossing::generateOperations()
{

    int totalOfOperations = pow(2, this->archive->getTotalOfItems());
    int numberOfDrivers = this->archive->getQuantifyOfDrivers();
    int totalOfItems = this->archive->getTotalOfItems();
    int quantifyOfItems = this->archive->getQuantifyOfItems();
    int maxCapacityBoat = this->archive->getMaxCapacityOfBoat();
    int positionOfFirstDriver = pow(2, quantifyOfItems);

    bitService *bitServ = new bitService();

    // Comenzamos a iterar desde el elemento numero 2^quantifyOfItems
    // ya que los elementos anteriores no tienen sentido

    for (int i = 0; i < totalOfOperations; i++)
    {
        // cout << "Convirtiendo el numero: " << i << endl;
        cout<< "-----" << endl;
        cout << "Generando la operacion: " << i << endl;

        int *ItemsInBoatAndDrivers = bitServ->countSetBits(i, numberOfDrivers, quantifyOfItems);
        cout << "cantidad de Items contados" << ItemsInBoatAndDrivers[0] << endl;
        cout << "cantidad de Drivers contados" << ItemsInBoatAndDrivers[0] << endl;

        //! bug cantidad de drivers y items en el bote
        if (ItemsInBoatAndDrivers[0] > maxCapacityBoat || ItemsInBoatAndDrivers[1] < 1)
        {
            continue;
        }
        Operation *auxOp = new Operation(i, ItemsInBoatAndDrivers[0], totalOfItems);

        this->Operations->insertBegin(new Node(auxOp));
        cout << "operacion" << i << " creada" << endl;
    }

    //*impresion de operaciones
    Node *aux = this->Operations->getHead();

    while (aux != NULL)
    {
        aux->getOperation()->print(this->archive->getTotalOfItems());
        aux = aux->getNextNode();
    }

}

void RiverCrossing::generateRestrictions()
{

    bitService *bitServ = new bitService();

    bool *binaryLeftRestriction = new bool[this->archive->getTotalOfItems()];
    bool *binaryRightRestriction = new bool[this->archive->getTotalOfItems()];

    // Generamos las restricciones de la orilla izquierda y derecha al mismo tiempo
    for (int i = 0; i < this->archive->getQuantifyOfLeftRestriction(); i++)
    {
        for (int j = 0; j < this->archive->getTotalOfItems(); j++)
        {
            binaryLeftRestriction[j] = this->archive->getLeftRestriction()[i][j];
            binaryRightRestriction[j] = this->archive->getRightRestriction()[i][j];
        }
        // transformamos de binario a decimal
        int leftNumRestriction = bitServ->bitsToInt(binaryLeftRestriction, this->archive->getTotalOfItems());
        int rightNumRestriction = bitServ->bitsToInt(binaryRightRestriction, this->archive->getTotalOfItems());
        // creamos Restriccion y asignamos en el arreglo de restricciones

        Node *auxNode = new Node(new Restriction(binaryLeftRestriction, leftNumRestriction, this->archive->getTotalOfItems(), LEFT));
        this->leftRestriction->insertBegin(auxNode);

        auxNode = new Node(new Restriction(binaryRightRestriction, rightNumRestriction, this->archive->getTotalOfItems(), RIGHT));
        this->rightRestriction->insertBegin(auxNode);
    }

    cout << "Imprimiendo restricciones izquierdas:" << endl;

    struct Node *aux = this->leftRestriction->getHead();
    for (int i = 0; i < this->leftRestriction->getSize(); i++)
    {
        aux->getRestriction()->print(this->archive->getTotalOfItems());
        aux = aux->getNextNode();
    }

    // cout << "Imprimiendo restricciones derechas:" << endl;
    // for (int i = 0; i < this->rightRestriction.size(); i++)
    // {
    //     rightRestriction[i].print(this->archive->getTotalOfItems());
    // }
}

// todo: trabajar con la lista enlazada
void RiverCrossing::successors(State *e)
{
    //! bug

    int totalOfItems = this->archive->getTotalOfItems();
    int quantifyOfItems = this->archive->getQuantifyOfItems();
    int quantifyOfDrivers = this->archive->getQuantifyOfDrivers();


    Node *auxNodeOp = this->Operations->getHead();

    State *ts = new State(totalOfItems);
    for (int i = 0; i < this->Operations->getSize(); i++)
    {
        ts = auxNodeOp->getOperation()->move(e, totalOfItems);
        auxNodeOp = auxNodeOp->getNextNode();
        if (ts == nullptr)
        {
            continue;
            cout << "No se puede mover" << endl;
        }

        // Se verifican restricciones
        Node *auxNodeRightRes = this->rightRestriction->getHead();
        Node *auxNodeLeftRes = this->leftRestriction->getHead();
        for (int j = 0; j < this->rightRestriction->getSize(); j++)
        {
            //cout << "Probando con la restricion: " << endl;
            //Todo: analizar restricciones izquierdas y derechas al mismo tiempo

            if (auxNodeLeftRes->getRestriction()->isValid(ts) == false || 
            auxNodeRightRes->getRestriction()->isValid(ts) == false)
            {
                delete ts;
                cout << "Restriccion invalida";
                ts = nullptr;
                break;
            }
            auxNodeLeftRes = auxNodeLeftRes->getNextNode();
            auxNodeRightRes = auxNodeRightRes->getNextNode();
        }


        if (ts == nullptr)
        {
            continue;
        }

        if (this->closed->searchState(new Node(ts)) == false)
        {
            cout << "estado valido: " << endl;
            ts->print(totalOfItems);
            this->open->insertEnd(new Node(ts));
        }
    }
}

void RiverCrossing::solve()
{
    int i = 0;

    int totalOfItems = this->archive->getTotalOfItems();
    int quantifyOfDrivers = this->archive->getQuantifyOfDrivers();
    int quantifyOfItems = this->archive->getQuantifyOfItems();

    State *initialState = new State(totalOfItems);

    this->open->insertEnd(new Node(initialState));

    while (!this->open->isEmpty())
    {
        cout << "Abiertos: " << open->getSize() << endl;
        State *e = open->pop()->getState();


        if (e->isFinal(quantifyOfDrivers, quantifyOfItems, totalOfItems))
        {
            cout << "Solucion encontrada" << endl;
            e->printPath(totalOfItems);
            // todo: imprimir solucion
            break;
        }

        cout << "Cantidad de nodos en Abiertos: " << open->getSize() << endl;
        cout << "Generando sucesores: "<< endl;
        cout << "Del estado:";
        e->print(totalOfItems);
        successors(e);
        i++;
        cout << "flag 1" << endl;
        closed->insert(new Node(e));
    }
}
