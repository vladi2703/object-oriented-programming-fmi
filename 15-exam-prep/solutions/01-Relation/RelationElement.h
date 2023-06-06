#include <string>
#include <iostream>

template <typename T>
class RelationElement
{
	T subject, object;
	std::string relation;

public:

	RelationElement(const T& subj, const T& obj, const std::string& rel) :
		subject(subj), object(obj), relation(rel)
	{

	}

	void print()
	{
		std::cout << subject << " " << relation << " " << object << std::endl;
	}
};

template <>
class RelationElement<int>
{
	int subject, object;
	std::string relation;

public:

	RelationElement(int subj, int obj, const std::string& rel) :
		subject(subj), object(obj), relation(rel)
	{

	}

	void print()
	{
		std::cout << subject << " " << relation << " " << object << std::endl;
	}

	RelationElement<int> operator*(const RelationElement<int> &other)
	{
		if (object != other.subject)
			return *this;

		std::string temp = relation + " " + std::to_string(object) + ", which " + other.relation;

		RelationElement<int> sol(subject, other.object, temp);
		return sol;
	}
};