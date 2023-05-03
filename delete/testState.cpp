#include <iostream>
#include <bitset>
#include<cmath>
#include "State.h"
using namespace std;





int main(){

    State *test = new State();
    State *test2 = new State("0101", test);

    test2->print();


    // string binary = "1111111111111111111111111111111111111111111111111111111111111111";

    // bitset<64> bTest(binary);
    // // bitset<64> bTest("111");

    // bTest.reset();
    // bTest.set(1);
    // cout << bTest.to_ulong() << endl;
    // cout<<bTest.to_string() << endl;


    // cout << not(1) << endl;




    // while(true){
    //     cout << test << endl;
    //     test+= 1000000000000000000;
    // }




}