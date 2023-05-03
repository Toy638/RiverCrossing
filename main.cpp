#include "./RiverCrossing/RiverCrossing.h"
#include "Node/Node.h"
#include <ctime>
#include <string>


using namespace std;

int main (){

    clock_t t_ini, t_fin;
    double secs=0;

    RiverCrossing *RiverProblem;
    int k, quantifyOfTimes;
    string fileName;

    cout << "Cuantas veces desea ejecutar el programa?" << endl;
    cin >> quantifyOfTimes;


    cout << "Ingrese el nombre del archivo a ejecutar" << endl;
    cin >> fileName;

    cout << "Resolviendo el problema" << fileName <<endl;

    for (int k = 0; k < quantifyOfTimes; k++)
    {
        RiverProblem = new RiverCrossing(fileName);
        RiverProblem->generateOperations(); //? esto debe ir en el momento de crear un riverCrossing
        RiverProblem->generateRestrictions();
        t_ini = clock();
        RiverProblem->solve();
        t_fin = clock();
        secs = secs + (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
        delete RiverProblem;

    }
    
    cout << endl <<"Tiempo promedio de ejecucion: " << secs/quantifyOfTimes << endl;

    return 0;


}