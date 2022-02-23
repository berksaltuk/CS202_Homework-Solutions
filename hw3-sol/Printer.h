#ifndef PRINTER_H
#define PRINTER_H

/*
* Title: Printer Interface
* Author: Berk Saltuk Yilmaz
* ID: 21903419
* Section: 3
* Assignment: 3
* Description: This interface provides the information when will a printer be available, is it available now and printer's id.
*/
class Printer
{
    public:
        //Constructors
        Printer();
        Printer( int id, bool isAvailable, int availableAtTime): id(id), isAvailable(isAvailable), availableAtTime(availableAtTime){}

        int getID() //Getters
        {
            return id;
        }
        bool getIsAvailable()
        {
            return isAvailable;
        }
        int getAvailableAtTime()
        {
            return availableAtTime;
        }

        void setId(int givenId) //Setters
        {
            id = givenId;
        }
        void setAvailable(bool given)
        {
            isAvailable = given;
        }
        void setAvailableAtWhichTime(int given)
        {
            availableAtTime = given;
        }

    private:
        int id;
        bool isAvailable;
        int availableAtTime;

};

#endif // PRINTER_H
