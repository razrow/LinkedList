//p7 LinkedList
//Rowan Briggs
//May 17, 2018 - May 18, 2018
/* Description:
Part 1) Write the Complete Link List (shown on pages 1-14 above)
             The Link class and The LinkList class:

Part 2) Test the Link List:

Part 3) Show your Results (as a multiline comment at the bottom of your code):

Part 4) Add the following 3 new methods to LinkList:
int sumData() – returns the sum of iData of all links
int min() – returns the smallest iData of all links
int numLinks() – returns the total number of links in the list

Part 5) Test the new methods from the main()

Part 6) Show your results
*/

#include <iostream>
using namespace std;

class Link{
    public:
        int iData; //data
        double dData; //data
        Link *pNext; //pointer to next link

        Link(int id, double dd){ //constructor
            iData = id;
            dData = dd;
            pNext = NULL; //refers to nothing
            //until connected to other link
        }

        void displayLink(){
            cout << "{" << iData << ", ";
            cout << dData << "} ";
        }
};

class LinkList{
    private:
        Link *pFirst; //pointer to first link on list

    public:
        LinkList(){
            pFirst = NULL; //no links on list yet
        }

        bool isEmpty(){
            return pFirst == NULL; //true iff list is empty
        }

        void insertFirst(int id, double dd){
            Link *pNewLink = new Link(id, dd); //make new link
            pNewLink->pNext = pFirst; //newLink --> old first (1)
            pFirst = pNewLink; //first --> newLink (2)
        }

        Link *getFirst() {
            return pFirst;
        }

        void removeFirst() {    //delete first link
            Link *pTemp = pFirst; //save first
            pFirst = pFirst->pNext; //unlink it: first -> old next
            delete pTemp;
        }

        void displayList() {
            cout << "List (first-->last): ";
            Link *pCurrent = pFirst; //start at beginning of list
            while (pCurrent != NULL) { //until end of list
                pCurrent->displayLink(); //show the link
                pCurrent = pCurrent->pNext;
            }
            cout << endl;
        }

        Link *find(int key){    //find a link given key
            Link *pCurrent = pFirst;//start at 'first'
            while(pCurrent->iData != key){
                if(pCurrent->pNext == NULL){ //if end of list
                    return NULL;
                }
                else{
                    pCurrent = pCurrent->pNext;
                }
            }
            return pCurrent;
        }

        bool remove(int key) {  //remove link with given key
            Link *pCurrent = pFirst;
            Link *pPrevious = pFirst;
            while(pCurrent->iData != key){  //search for link
                if(pCurrent->pNext == NULL){
                    return false;       //did not find it
                }
                else{
                    pPrevious = pCurrent;       //goes to next link
                    pCurrent = pCurrent->pNext;
                }
            }
            //if key was found
            if(pCurrent == pFirst){ //if first link
                pFirst = pFirst->pNext; //change first
            }
            else{ //otherwise
                pPrevious->pNext = pCurrent->pNext; //bypass current Link
            }

            delete pCurrent;

            return true;
        }

        int sumIdata(){
            int sum = 0; //sets sum equal to 0 at beginning
            Link *pCurrent = pFirst; //start at beginning of list
            while (pCurrent != NULL) { //until end of list
                sum = sum + pCurrent->iData; //adds current iData value each time it hits one
                pCurrent = pCurrent->pNext;
            }
            return sum;
        }

        int min(){
            Link *pCurrent = pFirst; //start at beginning of list
            int min = pCurrent->iData; //sets first iData equal to min
            while (pCurrent != NULL) { //until end of list
                if (pCurrent->iData < min){
                    min = pCurrent->iData;
                }
                pCurrent = pCurrent->pNext;
            }
            return min;
        }

        int numLinks() {
            int count = 0;
            Link *pCurrent = pFirst; //start at beginning of list
            while (pCurrent != NULL) { //until end of list
                count++; //keeps a count after hitting each link
                pCurrent = pCurrent->pNext;
            }
            return count;
        }
};

int main() {
    LinkList theList; //make new list
    theList.insertFirst(22, 2.99); //insert 4 items
    theList.insertFirst(44, 4.99);
    theList.insertFirst(66, 6.99);
    theList.insertFirst(88, 8.99);

    theList.displayList(); //show the list
    //List (first-->last): {88, 8.99} {66, 6.99} (44, 4.99} {22, 2.99}

    while(!theList.isEmpty()){
        Link *pTemp = theList.getFirst(); //get first link
        cout << "\nRemoving link with data ";
        pTemp->displayLink(); //display links data
        theList.removeFirst(); //remove it
    }
    cout << endl << "Empty list: ";
    theList.displayList(); //List (first-->last):

    theList.insertFirst(22, 2.99); //reinsert 4 items
    theList.insertFirst(44, 4.99);
    theList.insertFirst(66, 6.99);
    theList.insertFirst(88, 8.99);
    cout << "\nReinserting the links back" << endl;
    theList.displayList();

    int findKey = 44;
    Link *pFind = theList.find(findKey);
    if(pFind != NULL){
        cout << "Found link with key: " << pFind->iData << endl;
    }
    else{
        cout << "Can't find link with key " << findKey << endl;
    }

    if (theList.remove(findKey)){
        cout << "Deleted " << findKey << " from the list.\n";
    }
    else{
        cout << "Did not delete " << findKey << " from the list.\n";
    }

    cout << "Link list after deletion\n";
    theList.displayList();

    cout << "\nThe sum of all links is: " << theList.sumIdata() << endl;
    cout << "The smallest link is: " << theList.min() << endl;
    cout << "The number of links is: " << theList.numLinks() << endl;
}

/* Output 1:
List (first-->last): {88, 8.99} {66, 6.99} {44, 4.99} {22, 2.99}

Removing link with data {88, 8.99}
Removing link with data {66, 6.99}
Removing link with data {44, 4.99}
Removing link with data {22, 2.99}
Empty list: List (first-->last):

Reinserting the links back
List (first-->last): {88, 8.99} {66, 6.99} {44, 4.99} {22, 2.99}
Found link with key: 44
Deleted 44 from the list.
Link list after deletion
List (first-->last): {88, 8.99} {66, 6.99} {22, 2.99}

Process finished with exit code 0
 */

/* Output 2:
List (first-->last): {88, 8.99} {66, 6.99} {44, 4.99} {22, 2.99}

Removing link with data {88, 8.99}
Removing link with data {66, 6.99}
Removing link with data {44, 4.99}
Removing link with data {22, 2.99}
Empty list: List (first-->last):

Reinserting the links back
List (first-->last): {88, 8.99} {66, 6.99} {44, 4.99} {22, 2.99}
Found link with key: 44
Deleted 44 from the list.
Link list after deletion
List (first-->last): {88, 8.99} {66, 6.99} {22, 2.99}

The sum of all links is: 176
The smallest link is: 22
The number of links is: 3

Process finished with exit code 0
 */