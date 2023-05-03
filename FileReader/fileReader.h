#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>


using namespace std;

class FileReader
{
    private:
        string filename;
        int quantifyOfDrivers;
        int quantifyOfItems;
        int totalOfItems;
        int maxCapacityOfBoat;
        int quantifyOfLeftRestriction;
        int quantifyOfRightRestriction;
        bool **leftRestriction;
        bool **rightRestriction;

    public:
        //constructores
        FileReader(string filename);
        ~FileReader();

        //getters
        string getFilename();
        int getQuantifyOfDrivers();
        int getQuantifyOfItems();
        int getTotalOfItems();
        int getMaxCapacityOfBoat();
        int getQuantifyOfLeftRestriction();
        int getQuantifyOfRightRestriction();
        bool **getLeftRestriction();
        bool **getRightRestriction();

        



};


#endif  