#include <iostream>  
using namespace std;  
  
  
//Class for APO  
  
class APO {  
public:  
    struct Region;  
    struct RegionList;  
    struct AnimalList;  
    RegionList* rHead;  
    RegionList* rTail;  
    AnimalList* aHead;  
    AnimalList* aTail;  
      
    APO() {  
        rHead = rTail = NULL;  
        aHead = aTail = NULL;  
    }  
      
public:  
      
     //***************************************There are four structs*******************************  
     // Struct 1 for Regionlist  
       
    struct RegionList {  
        RegionList* next;  
        Region* region;  
  
        RegionList(Region* region, RegionList* next=NULL) {  
            this->region = region;  
            this->next = next;  
        }  
  
    };  
    //Struct 2 For Animal  
      
    struct Animal {  
        string aName;  
        RegionList* regions;  
        Animal(string aName, RegionList* regions) {  
  
            this->aName = aName;  
            this->regions = regions;  
        }  
    };  
    //Struct 3 For Region  
    struct Region {  
        string regionName;  
        int rarity;  
        Region(string regionName,int rarity=-1) {  
            this->regionName = regionName;  
            this->rarity = rarity;  
              
        }  
      
  
    };  
    // Struct 4 for AnimalList  
    struct AnimalList {  
        AnimalList* next;  
        Animal* animal;  
  
        AnimalList(Animal* animal, AnimalList* next = NULL) {  
            this->animal = animal;  
            this->next = next;  
        }  
    };  
public:  
//To Add Region  
    void add_Region(string name) {  
        Region* newRegion = new Region(name);  
        RegionList* rL=new RegionList(newRegion);  
        // If RegionList is empty  
        if (rHead == NULL && rTail == NULL) {  
            rHead = rTail = rL;  
        }  
        //if RegionList is not empty  
        else {  
            rTail->next = rL;  
            rTail = rL;  
        }  
        cout<< "#####################-------Added Successfully-------##################"<<endl;  
  
    }  
      
  
  
// TO display RegionList  
    RegionList* get_RegionList() {  
        if (rHead == NULL) {  
            return NULL;  
        }  
        else {  
            RegionList* rPtr = rHead;  
            cout << "###############################################-----Regions are:-----###############################################"<<endl;  
            cout<<endl;  
            while (rPtr) {  
  
                cout <<"                                                    " <<rPtr->region->regionName<<endl;  
                rPtr = rPtr->next;  
            }  
            cout << endl << endl;  
              
        }  
          
      
          
          
        return copyList(rHead);  
    }  
  
  
    // To Copy RegionList for every animal  
    RegionList* copyList(RegionList* L) {  
  
        RegionList* current = L;  
  
        // If RegionList has 1 element  
        RegionList* copy = new RegionList(NULL);  
        copy->region = new Region(*current->region);  
        copy->next = NULL;  
        RegionList* const head = copy;  
        current = current->next;  
  
        while (current != NULL) {  
            copy = copy->next = new RegionList(NULL);  
            copy->region = new Region(*current->region);  
            copy->next = NULL;  
  
              
            current = current->next;  
        }  
  
        // Return List.  
        return head;  
    }  
  
    AnimalList* copyList2(AnimalList* L) {  
  
        AnimalList* current = L;  
  
        AnimalList* copy = new AnimalList(NULL);  
        copy->animal = new Animal(*current->animal);  
        copy->next = NULL;  
  
  
        AnimalList* const head = copy;  
  
  
        current = current->next;  
  
        while (current != NULL) {  
              
            copy = copy->next = new AnimalList(NULL);  
            copy->animal = new Animal(*current->animal);  
            copy->next = NULL;  
  
  
  
            current = current->next;  
        }  
  
        // Return List  
        return head;  
    }  
      
    //To add Animal  
  
    void addAnimal(string name, RegionList* regions=NULL) {  
        RegionList* regions_head = new RegionList(NULL);  
        regions_head=   get_RegionList();  
        if (regions_head == NULL) {  
            cout << "Add regions first!!";  
        }  
        else {  
            RegionList* rPtr = regions_head;  
            RegionList* rPtr_prev=NULL;  
            while (rPtr) {  
                int rare;  
                cout << "Enter rarity for ";  
                cout << rPtr->region->regionName ;  
                  
                  
                  
                //Check for rarity  
                do  
                {  
                  
                    cout << " ~~ between 1 and 10 (0 for dead) :";  
                    cin >> rare;cout <<endl;  
                    if (rare == 0) {  
                        break;  
                    }  
                } while (rare < 0 || rare >= 10);  
  
                    rPtr->region->rarity = rare;  
                    rPtr_prev = rPtr;  
                    rPtr = rPtr->next;  
                      
                    cout << endl;  
            }  
        }  
        // Initializing the AnimalList database  
        // or incrementing the list  
        Animal* newAnimal = new Animal(name, regions_head);  
        AnimalList* AnimalList_obj = new AnimalList(newAnimal);  
        // AnimalList is empty  
        if (aHead == NULL && aTail == NULL) {  
            aHead = aTail = AnimalList_obj;  
        }  
        //if not, then add to the end of the list  
        else {  
            aTail->next = AnimalList_obj;  
            aTail = AnimalList_obj;  
        }  
  
  
    }  
    //To display Animal List  
      
    void displayAnimalList() {  
        AnimalList* AnimalList_ptr = copyList2(aHead);  
        cout << "###############################################-----Regions are:-----###############################################"<<endl;  
            cout<<endl;  
        while (AnimalList_ptr) {  
              
            cout<<"                                                    " << AnimalList_ptr->animal->aName<<endl;  
              
              
            while (AnimalList_ptr->animal->regions) {  
                  
                AnimalList_ptr->animal->regions = AnimalList_ptr->animal->regions->next;  
            }  
            AnimalList_ptr = AnimalList_ptr->next;  
        }  
        delete AnimalList_ptr;  
    }  
      
    //To search animal by name  
  
    AnimalList* getAnimalInfo(string animalName = "testAnimal") {  
        string aName;  
        if (animalName == "testAnimal") {  
              
            cout << "Enter the name of animal : ";  
            cin >> aName;  
        }  
        else {  
            aName = animalName;  
        }  
        AnimalList* AnimalList_ptr = copyList2(aHead);  
        AnimalList* AnimalList_ptr_n = aHead;  
        while (AnimalList_ptr && AnimalList_ptr->animal->aName!=aName) {  
  
            AnimalList_ptr = AnimalList_ptr->next;  
            AnimalList_ptr_n = AnimalList_ptr_n->next;  
        }  
        if (animalName == "testAnimal") {  
            cout << endl << "Animal Name: " << AnimalList_ptr->animal->aName << endl;  
            // Displaying all the regions and rarities  
  
            while (AnimalList_ptr->animal->regions) {  
                  
                cout << " Rarity of "<<AnimalList_ptr->animal->aName<<" in " <<  
                 AnimalList_ptr->animal->regions->region->regionName<<" is "<<AnimalList_ptr->animal->regions->region->rarity << endl ;  
                AnimalList_ptr->animal->regions = AnimalList_ptr->animal->regions->next;  
            }  
  
            cout << endl;  
        }  
        delete AnimalList_ptr;  
        return  AnimalList_ptr_n;  
    }  
    //To search by rarity  
  
    void getRarityInfo(int rarity=NULL) {  
        int rare;  
        if (rarity == NULL) {  
              
            cout << "Enter Rarity : ";  
            cin >> rare;  
        }  
        else {  
            rare = rarity;  
        }  
        AnimalList* AnimalList_ptr = copyList2(aHead);  
      
        // Finding the animal   
        while (AnimalList_ptr) {  
              
            while (AnimalList_ptr->animal->regions) {  
                if (AnimalList_ptr->animal->regions->region->rarity == rare) {  
                    cout << "Animal found : " << AnimalList_ptr->animal->aName << endl<< "Region Name: " << AnimalList_ptr->animal->regions->region->regionName;  
                    cout << endl;  
              
                }  
                AnimalList_ptr->animal->regions = AnimalList_ptr->animal->regions->next;  
                  
            }  
          
            AnimalList_ptr = AnimalList_ptr->next;  
        }  
          
        delete AnimalList_ptr;  
        cout << endl;  
    }  
  
  
          // To change rarity  
  
    int setRarity() {  
        string animalName;  
        string regionName;  
        int updatedRarity;  
        cout << "Enter Animal Name: ";  
        cin >> animalName;  
        cout << endl;  
        AnimalList* Animal=getAnimalInfo(animalName);  
        cout << "Enter Region Name: ";  
        cin >> regionName;  
        cout << endl;  
        cout << "Enter updated rarity: ";  
        cin >> updatedRarity;  
        cout << endl;  
        while (Animal->animal->regions) {  
            if (Animal->animal->regions->region->regionName == regionName) {  
                Animal->animal->regions->region->rarity = updatedRarity;  
                cout << "Rarity updated to " << updatedRarity<<endl;  
                return 1;  
            }  
            Animal->animal->regions = Animal->animal->regions->next;  
        }  
        return 0;  
  
    }  
  
  
  
//To find dead animals  
  
    void deadAnimals() {  
        cout << "Dead Animals:" << endl;  
      
        int rare=0;  
          
        AnimalList* AnimalList_ptr = copyList2(aHead);  
      
        // Finding the animal  
        while (AnimalList_ptr) {  
              
            while (AnimalList_ptr->animal->regions) {  
                if (AnimalList_ptr->animal->regions->region->rarity == rare) {  
                    cout << "Animal found : " << AnimalList_ptr->animal->aName << endl<< "Region Name: " << AnimalList_ptr->animal->regions->region->regionName;  
                    cout << endl;  
              
                }  
                AnimalList_ptr->animal->regions = AnimalList_ptr->animal->regions->next;  
                  
            }  
          
            AnimalList_ptr = AnimalList_ptr->next;  
        }  
          
        delete AnimalList_ptr;  
        cout << endl;  
      
    }  
      
  
};   
  
  
  
//Main function  
  
int main()  
{  
    int userChoice;  
    APO obj;  
    string region;  
    string aName;  
    exit:  
        //Main Menu   
    while (1) {  
  
        cout << "1.Add region" << endl;  
        cout << "2.Get Region List" << endl;  
        cout << "3.Add Animal " << endl;  
        cout << "4.Display Animal list" << endl;  
        cout << "5.Search animal by name " << endl;  
        cout << "6.Search animal with particular rarity" << endl;  
        cout << "7.Which animals are dead in which regions" << endl;  
        cout << "8.Change rarity of a particular animal" << endl ;  
        cout << "9.Exit" << endl <<endl;   
        cout << "Enter your choice : " ;  
          
        cin >> userChoice;  
        switch (userChoice) {  
        case 1:  
              
            cout << "Region:";  
            cin >> region;  
            obj.add_Region(region);  
            cout << endl;  
  
            break;  
        case 2:  
            obj.get_RegionList();  
            break;  
        case 3:  
            cout << "Please enter animal name: ";  
            cin >> aName;  
            obj.addAnimal(aName);  
            break;  
        case 4:  
            obj.displayAnimalList();  
            break;  
        case 5:  
            obj.getAnimalInfo();  
            break;  
        case 6:  
            obj.getRarityInfo() ;  
            break;  
        case 7:  
            obj.deadAnimals();  
            break;  
        case 8:  
            obj.setRarity();  
            break;  
        case 9:  
            exit(1);  
        default:  
            cout << "Wrong choice" << endl;  
            goto exit;  
        }  
    }  
    return 0;  
  
}  

