#include <iostream>
#include <string>
#include "mytime3.h"

class Human
{
	std::string m_name;
	weak_ptr<Human> m_partner;

public:
	
	Human(const std::string& name) : m_name(name)
	{
		std::cout << m_name << " created\n";
	}
	~Human()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(shared_ptr<Human>& h1, shared_ptr<Human>& h2)
	{
		if (!h1 || !h2)
			return false;

		(*h1).m_partner = h2;
		(*h2).m_partner = h1;

		std::cout << (*h1).m_name << " is now partnered with " << (*h2).m_name << "\n";
		std::cout << &(*h1).m_partner << "\t" << &(*h2).m_partner << std::endl;
		return true;
	}
};

int main()
{
	shared_ptr<Human> anton(new Human("Antorn"));
	shared_ptr<Human> ivan(new Human("Ivan"));

	partnerUp(anton, ivan);

	return 0;
}