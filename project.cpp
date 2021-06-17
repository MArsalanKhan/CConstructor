// project.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>


#include <vector>
#include <deque>
#include <list>
#include <set>

using namespace std;


void test_vector()
{
	vector<int> v(6); // Declare a vector of 6 integers. 
	v[0] = 7; 
	v[1] = v[0] + 3; 
	v[2] = v[0] + v[1]; 

	for (int i = 0; i<=5; i++)
	{
		cout << "v[" << i << "]=" << v[i] << endl;
	}
	//Until here, nothing spectacular - behaves like an array....
	
	

	vector<int> vc; // Declare a vector. Note: we do not have to know the size at this time! 
	
	cout << "Let's try some proper vector operations...." << endl;
	cout << "Number of assigned elements: " << vc.size() << endl;
	cout << "Number of free elements: " << vc.capacity() << endl;
	
	//Let's add some data and see how the size and the capacity changes
	for (int i=0;i<10;i++)
	{
		vc.push_back(i);
		cout << "Number of assigned elements: " << vc.size();
		cout << " Number of free elements: " << vc.capacity() << endl;
	}
	//vc[17]=17; // This one leads to a crash, because this element does not exist!

	//Now lets loop through the vector
	int i=0;
	vector<int>::const_iterator constIterator; //Only reading operations, therefore the constiterator is sufficient

	for (constIterator=vc.begin();constIterator < vc.end(); constIterator++)
	{
		cout << "v[" << i++ << "]=" << *constIterator << endl;
	}

	// ALternative Loop
	cout << "Alternative loop..." << endl;
	for (i=0; i<vc.size();i++)
	{
		cout << "v[" << i << "]=" << vc[i] << endl;
	}



}

void test_deque()
{
	cout << "Deque test...." << endl;

	// Create A and fill it with elements 1,2,3,4 and 5
    // using push_back function

    deque<int>  A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);

	A.push_front(2);
	A.push_front(3);

	cout << "Normal order...." << endl;
	deque<int>::iterator pi;
    for(pi= A.begin();  pi !=A.end(); pi++)
    {
        cout << *pi <<" " ;
    }
    cout<<endl;

    // Now print the contents in reverse order using reverse_iterator
    // and functions rbegin() and rend()	

	cout << "Reverse order...." << endl;

    deque<int>::reverse_iterator rpi;
    for(rpi= A.rbegin();  rpi !=A.rend(); rpi++)
    {
        cout << *rpi <<" " ;
    }
    cout<<endl;

}
void printList(string s, list<int> a)
{
	cout <<endl << s << endl;

	list<int>::iterator it; // Iterator

	if (a.empty())
	{
		cout << "List is empty" << endl;
	}
	else
	{
		for (it=a.begin();it != a.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
}

void test_list()
{
	cout << "List operations..." << endl;
	cout << "Enter some integer data, 0 to end" << endl;

	list<int> myList;
	list<int> myList2;
	list<int> myList3;

	int inp = 1;
	do
	{
		cout << "Enter value...(0 to end)";
		cin >> inp;
		cout << endl;
		myList.push_back(inp);
	} while (inp != 0);

	printList("Entered data...",myList);

	myList2=myList; // Copy contet from myList to myList2
	printList("myList2...",myList2);

	myList2.erase(myList2.begin());
	myList2.insert(myList2.begin(),99);
	printList("myList2 after some erase / insert...",myList2);
	myList3=myList2;


	myList.sort();
	printList("myList sorted...",myList);

	myList.unique();
	printList("myList unique...",myList);

	myList.splice(myList.end(),myList2);
	printList("myList spliced with myList2...",myList);
	printList("myList2 after splice",myList2);
	myList2=myList3;

	myList.sort();
	myList2.sort();
	myList.merge(myList2); //Works only with sorted elements
	printList("myList merged with original myList2...",myList);
	printList("myList2 after merge",myList2);
	
	myList2=myList3;
	myList.swap(myList2);
	printList("myList after swap",myList);
	printList("myList2 after swap",myList2);
}

void printSet(string s, multiset<int> a)
{
	cout <<endl << s << endl;

	multiset<int>::iterator it; // Iterator

	if (a.empty())
	{
		cout << "List is empty" << endl;
	}
	else
	{
		for (it=a.begin();it != a.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
}

void test_multiset()
{
	multiset<int> mySet;

	int inp = 1;
	do
	{
		cout << "Enter value...(0 to end)";
		cin >> inp;
		cout << endl;
		mySet.insert(inp);
	} while (inp != 0);

	printSet("Multiset after entering data:",mySet);

	cout << "Let's count some elements..." << endl;
	for (int l = 0; l<10;l++)
	{
		cout << "Value " << l << "  counted " << mySet.count(l) << endl;
	}

	//How can this loop be improved to count between the smallest and the biggest element?
	// Multiset is sorted by nature

	int min;
	min = *mySet.begin(); 
	int max=10;
	max = *(--mySet.end()); //The -- is needed because end() points to one element behind the last one!

	cout << "Let's count some elements using dynamic borders..." << endl;
	
	for (int l = min; l <= max;l++)
	{
		cout << "Value " << l << "  counted " << mySet.count(l) << endl;
	}



}
int main()
{
	int choice;
	do
	{
		cout << endl << endl << "Main Menu" << endl << endl;

		cout << "1 - vector" << endl;
		cout << "2 - deque" << endl;
		cout << "3 - list" << endl;
		cout << "4 - multiset" << endl;
		cout << "0 - end" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1 : 
			test_vector();
			break;
		case 2 : 
			test_deque();
			break;
		case 3 : 
			test_list();
			break;
		case 4 : 
			test_multiset();
			break;
		}
	}while (choice != 0);


	return 0;
}

