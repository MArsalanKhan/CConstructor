

#include <iostream>	
#include <string>
#include <stdlib.h>
using namespace std;			

//The following two example do not work
// because no memory is allocated to perform the operation


/*
struct sCoordinate{
	int x = 0;
	int y = 0;
};
*/

/*

class CCoordinate
{
public:
	int m_x = 0;
	int m_y = 0;
};
*/

//Example for an Constructor

class CCoordinate1
{
public:
	int m_x;
	int m_y;

public:
	//What happens if the constructor is commented out?
	CCoordinate1()
	{
		cout << "Just generated a CCoordinate object at " << this << endl;
		this->m_x = 0;	//"This-Pointer" is optional. The compiler "knows" where the object is stored
		m_y = 0;		//Normal way to access member variables
	}
	
};

//Example for Parameters
class CCoordinate2
{
public:
	int m_x;
	int m_y;

public:
	CCoordinate2(int x, int y)
	{
		
		if (x>0 && y>0)
		{
			m_x = x;
			m_y = y;
		}
		else
		{
			m_x = 0;	
			m_y = 0;
		}
		cout << "Just generated a CCoordinate object at " << this << " with the values (" << m_x << ", " << m_y << ")" << endl;
	}
};

//Example for default Parameters
class CCoordinate3
{
public:
	int m_x;
	int m_y;
	string m_name;

public:
	CCoordinate3(int x = 0, int y = 0, string name = "NoName")
	{
		
		m_name = name;

		if (x>0 && y>0)
		{
			m_x = x;
			m_y = y;
		}
		else
		{
			m_x = 0;	
			m_y = 0;
		}
		cout << "Generated a CCoordinate object called " << m_name << " at " << this << " with the values (" << m_x << ", " << m_y << ")" << endl;
	}
};

//Destructor
class CCoordinate4
{
public:
	int m_x;
	int m_y;
	string m_name;

public:
	CCoordinate4(int x = 0, int y = 0, string name = "NoName")
	{
		
		m_name = name;

		if (x>0 && y>0)
		{
			m_x = x;
			m_y = y;
		}
		else
		{
			m_x = 0;	
			m_y = 0;
		}
		cout << "Generated a CCoordinate object called " << m_name << " at " << this << " with the values (" << m_x << ", " << m_y << ")" << endl;
	}
	~CCoordinate4()
	{
		cout << "Destroying CCoordinate4 object at " << this << endl;
		system("Pause");
	}
};

class CCoordinate5
{
public:
	int m_x;
	int m_y;
	string m_name;

public:
	CCoordinate5(int x = 0, int y = 0, string name = "NoName")
	{
		
		m_name = name;

		if (x>0 && y>0)
		{
			m_x = x;
			m_y = y;
		}
		else
		{
			m_x = 0;	
			m_y = 0;
		}
		cout << "Generated a CCoordinate object called " << m_name << " at " << this << " with the values (" << m_x << ", " << m_y << ")" << endl;
	}
	
	CCoordinate5(CCoordinate5& origin)
	{
		cout << "Copy constructor, copying from object " << &origin << " to " << this << endl;
		m_x = origin.m_x;
		m_y = origin.m_y;
		m_name = "Oh, not him again " + origin.m_name; //Just to see the difference
		cout << "        Called " << m_name << " with the values (" << m_x << ", " << m_y << ")" << endl;
	}

	~CCoordinate5()
	{
		cout << "Destroying CCoordinate5 object at " << this << endl;
	}
};

void sampleFunction(CCoordinate5 c)
{
}


int global_a = 12;
int global_b = global_a;

int main (void)
{
	int c = 123;

	cout << "global_a = " << global_a << ", global_b = " << global_b << ", c = " << c << endl;


	//CCoordinate myCoordinate=(0,4); //wrong syntax

	CCoordinate1 myCoordinate; //This calls a constructor, if available
	cout << "myCoordinate.m_x = " << myCoordinate.m_x << ", myCoordinate.m_y = " << myCoordinate.m_y << endl;

	//Use of Parameters for initialisation
	CCoordinate2 myCoordinate21(3,4);
	CCoordinate2 myCoordinate22(-4,3);
	//CCoordinate2 myCoordinate22; //This one does not work, because there is no constructor which takes no arguments


	//Default parameters
	CCoordinate3 myCoordinate31(3,4, "Object 1");
	CCoordinate3 myCoordinate32;
	CCoordinate3 myCoordinate33(5,6); 
	//CCoordinate3 myCoordinate34("Object 2"); //This one does not work, because there is no constructor which takes a string as first parameter arguments

	//This Pointer
	cout << "Adress of the first member variable == value of the corresponding this-Pointer" << endl;
	cout << "&myCoordinate31.m_x = " << &myCoordinate31.m_x << endl;
	cout << "&myCoordinate32.m_x = " << &myCoordinate32.m_x << endl;
	cout << "&myCoordinate33.m_x = " << &myCoordinate33.m_x << endl;

	//Destructore
	CCoordinate4 myCoordinate4;

	//Copy Constructor
	CCoordinate5 myCoordinate51(1,2,"Joe");
	CCoordinate5 myCoordinate52 = myCoordinate51; //Copy constructor called
	CCoordinate5 myCoordinate53(myCoordinate51);  //Copy constructor called

	sampleFunction(myCoordinate53);				  //Copy constructor called

	myCoordinate53 = myCoordinate51;			  //Not called


	system("pause");	
	return EXIT_SUCCESS;		
}