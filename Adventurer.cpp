#include "Adventurer.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;
//Implement or define your class here

	int Adventurer::numberOfAdventurers = 0;

    Adventurer::Adventurer()
    {
    	
    	
    	//Set normal attributes to zero
    	
    	name = " ";

    	maxCarryWeight = 100.0;

    	currentCarryWeight = 0.0;

    	currentNumberOfItems = 0;

    	maxNumberOfItems = 100;

    	health = 100;

    	items = new string **[maxNumberOfItems];

        for(int x = 0; x < maxNumberOfItems;x++)
        {
            items[x] = new string *[2];
        }

        for(int a =0; a<maxNumberOfItems;a++)
        {
            for(int b = 0; b<2;b++)
            {
                items[a][b] = new string;
            }
        }

    	
    	numberOfAdventurers++;

    } //default constructor

    Adventurer::Adventurer(const Adventurer& a)
    {
    	this->name = a.name;
    	this->maxCarryWeight = a.maxCarryWeight;
    	this-> currentCarryWeight = a.currentCarryWeight;
    	this->currentNumberOfItems = a.currentNumberOfItems;
    	this->maxNumberOfItems = a.maxNumberOfItems;
    	this->health = a.health;

    	items = new string **[maxNumberOfItems];

    	for(int x = 0; x<maxNumberOfItems;x++)
        {
            items[x] = new string *[2];
        }

        for(int a =0; a<maxNumberOfItems;a++)
        {
            for(int b = 0; b<2;b++)
            {
                items[a][b] = new string;
            }
        }

        for (int q = 0; q < a.currentNumberOfItems; q++)
        {
            for (int r = 0; r < 2; r++)
            {
                *(this->items[q][r]) = *(a.items[q][r]);
            }
        }

    
    	numberOfAdventurers++;
    } //copy constructor

    Adventurer::~Adventurer()
    {
    	for (int a = 0; a < maxNumberOfItems; a++)
        {
            for (int z = 0; z< 2; z++)
            {
                delete items[a][z];
            }
        
            delete [] items[a];
        }
    
    delete [] items;    
    items = nullptr;
    numberOfAdventurers = numberOfAdventurers - 1;
   	}//Destructor


    bool Adventurer::pickUpItem(string it, double weight)
    {
        if (currentNumberOfItems == maxNumberOfItems)
        {
            return false;
        }

    	else if ( (this->currentCarryWeight + weight) > maxCarryWeight)
        {
            return false;
        }        
        
        else
        {
        
            *(this->items[currentNumberOfItems][1]) = static_cast<ostringstream*>(&(ostringstream() << weight))->str();//Convert weight to string
            *(this->items[currentNumberOfItems][0]) = it; //Assign description       
        
        
            currentNumberOfItems = currentNumberOfItems + 1 ;
            currentCarryWeight = currentCarryWeight + weight;
            return true;
        }
    }


    bool Adventurer::dropItem(string it)
    {        

        bool item  = false;

        double weight = 0.0;

        for (int y = 0; y < (maxNumberOfItems - 1); y++)
        {
            if (*(items[y][0]) == it)
            {
                weight = stod(*(items[y][1]));
                
                for (int x = y; x < (this->maxNumberOfItems - 1); x++)
                {
                    *(items[x][0]) = *(items[x + 1][0]);
                    *(items[x][1]) = *(items[x + 1][1]);
                }      
                
                item = true;

                currentNumberOfItems = currentNumberOfItems - 1;

                currentCarryWeight = currentCarryWeight - weight;
            }

        }

        if (item == false)
        {
            return false;
        }

        else if (item == true)
        {
            return true;
        }
    
    }
    
    bool Adventurer::dropItem(int index)
    {
       

        if ((index > currentNumberOfItems) || (index<0))
        {
            return false;
        }

        else
        {
                        
            double weight = stod(*(items[index][1]));
            
            for (int x = index; (x < (currentNumberOfItems-1)); x++)
            {
                items[x] = items[x + 1];
            }
            
            currentNumberOfItems = (currentNumberOfItems - 1);

            currentCarryWeight = (currentCarryWeight - weight);

            items[currentNumberOfItems - 1] = nullptr;

            return true;
        }
    }

    void Adventurer::setName(string n)
    {
    	//Set name to parameter
    	name = n;
    }

    string Adventurer::getName() const
    {
    	//return name of the object
    	return name;
    }

    void Adventurer::setMaxCarryWeight(double w)
    {
    	//set maximum weight object can carry to parameter passed
    	maxCarryWeight = w;
    }

    double Adventurer::getMaxCarryWeight() const
    {
    	return maxCarryWeight;
    }

    void Adventurer::setCurrentCarryWeight(double w)
    {
    	currentCarryWeight = w;
    }

    double Adventurer::getCurrentCarryWeight() const
    {
    	return currentCarryWeight;
    } 

    void Adventurer::setMaxNumberOfItems(int n)
    {
    	maxNumberOfItems = n;

        string *** buffer = nullptr;

        buffer = new string ** [maxNumberOfItems];

        for (int x = 0; x < maxNumberOfItems; x++)
        {
            buffer[x] = new string * [2];            
        }

        for (int y = 0; y < maxNumberOfItems; y++)
        {
            for (int z = 0; z < 2; z++)
            {
                buffer[y][z] = new string;
            }
        }

        for (int x = 0; x < currentNumberOfItems; x++)
        {
            for (int y = 0; y < 2; y++)
            {
                *(buffer[x][y]) = *(items[x][y]);
            }
        }
        
        
        for (int x = 0; x < maxNumberOfItems; x++)
        {
            for (int n = 0; n< 2; n++)
            {
                delete items[x][n];
            }       
        }

        for (int x = 0; x < maxNumberOfItems; x++)
        {                      
            delete [] items[x];
        }
        
        delete [] items;    
        
        items = buffer;
    }

    int Adventurer::getMaxNumberOfItems() const
    {
    	return maxNumberOfItems;
    }

    void Adventurer::setCurrentNumberOfItems(int n)
    {
    	if(n > maxNumberOfItems)
    	{
    		cout << "ERROR, value exceeds maximum number of items of " << maxNumberOfItems << ".\n";

    		exit(1);

    	}

    	else
    	{
    		currentNumberOfItems = n;
    	}
    	
    }

    int Adventurer::getCurrentNumberOfItems() const
    {
    	return currentNumberOfItems;
    }

    int Adventurer::getNumberOfAdventurers() const
    {
    	return numberOfAdventurers;
    }

    void Adventurer::setHealth(double h)
    {
    	if(h <= 100)
    	{
            if(h<0)
            {
                health = 0;
            }

            else if(h >= 0)
    		{
                health = h;
            }
    	}

    	else
    	{
    		health = 100;
    	}
    	
    }

    double Adventurer::getHealth() const
    {
    	return health;
    }

    string** Adventurer::getItem(int index) const
    {
        return items[index];
    }

    Adventurer& Adventurer::operator = (const Adventurer& a)
    {
        if (this == &a)
        {
           return *this; 
        }
        
        else 
        {
            for (int x = 0; x < maxNumberOfItems; x++)
            {
                for (int y = 0; y< 2; y++)
                {
                    delete items[x][y];
                }             
            }

            for (int x = 0; x < maxNumberOfItems; x++)
            {
                delete [] items[x];   
            }
            
            delete [] items;    
                
            name = a.name;

            maxNumberOfItems = a.maxNumberOfItems;

            maxCarryWeight = a.maxCarryWeight;             
            
            currentCarryWeight = a.currentCarryWeight;

            health = a.health;           
            
            currentNumberOfItems = a.currentNumberOfItems;
            
            
            items = new string ** [a.maxNumberOfItems];

            for (int k = 0; k < maxNumberOfItems; k++)
            {
                items[k] = new string * [2];                
            }

            for (int q = 0; q < maxNumberOfItems; q++)
            {
                for (int z = 0; z < 2; z++)
                {
                    items[q][z] = new string;
                }
            }


            for (int x = 0; (x < a.currentNumberOfItems); x++)
            {
                for (int p = 0; (p < 2); p++)
                {
                    *(items[x][p]) = *(a.items[x][p]);
                }//end inner
            }//end outer

            return *this;
        }//end else
    }