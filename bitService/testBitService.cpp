#include "bitService.h"
using namespace std;


int main (int argc, char *argv[]){

    bool *boolArrayToAssign = new bool[5];
    boolArrayToAssign[0] = 0;
    boolArrayToAssign[1] = 0;
    boolArrayToAssign[2] = 0;
    boolArrayToAssign[3] = 0;
    boolArrayToAssign[4] = 1;

    bitService *service = new bitService();

    cout << service->bitsToInt(boolArrayToAssign, 5) << endl;

    boolArrayToAssign = service->intToBits(4, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << boolArrayToAssign[i];
    }
    
    cout << endl;

    service->countSetBits(8, 1, 3);


    return 0;
}
