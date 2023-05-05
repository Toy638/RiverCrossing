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

        /**
         * @brief Construct a new File Reader object
         * 
         * @param filename 
         */

        FileReader(string filename);
        
        /**
         * @brief Destroy the File Reader object
         * 
         */

        ~FileReader();

        //getters
        /**
         * @brief Get the Filename object
         * 
         * @return string 
         */
        string getFilename();

        /**
         * @brief Get the Quantify Of Drivers object
         * 
         * @return int 
         */
        int getQuantifyOfDrivers();
        
        /**
         * @brief Get the Quantify Of Items object
         * 
         * @return int 
         */
        int getQuantifyOfItems();
        /**
         * @brief Get the Total Of Items object
         * 
         * @return int 
         */
        int getTotalOfItems();
        
        /**
         * @brief Get the Max Capacity Of Boat object
         * 
         * @return int 
         */
        int getMaxCapacityOfBoat();
        
        /**
         * @brief Get the Quantify Of Left Restriction object
         * 
         * @return int 
         */
        int getQuantifyOfLeftRestriction();
        
        /**
         * @brief Get the Quantify Of Right Restriction object
         * 
         * @return int 
         */
        int getQuantifyOfRightRestriction();

        /**
         * @brief Get the Left Restriction object
         * 
         * @return bool**
         */
        bool **getLeftRestriction();

        /**
         * @brief Get the Right Restriction object
         * 
         * @return bool**
         */
        bool **getRightRestriction();

        



};


#endif  