#include <iostream>
#include <cmath>

struct Vector3D
{
	double x, y, z;

	double getVectorLength()
	{
		return sqrt( x*x + y*y + z*z );
	}

	Vector3D plus(Vector3D v)
	{
		Vector3D sum;
		sum.x = x + v.x;
		sum.y = y + v.y;
		sum.z = z + v.z;
		return sum;
	}

	void print() const
	{
		std::cout << "x: " << x << std::endl;
		std::cout << "y: " << y << std::endl;
		std::cout << "z: " << z << std::endl;
	}

};

double getScalarProduct(Vector3D first, Vector3D second)
{
	return  first.x * second.x +
			first.y * second.y +
			first.z * second.z;
}

bool arePerpendicular(Vector3D first, Vector3D second)
{
	return getScalarProduct(first, second) == 0;
}

int main()
{
	Vector3D a{ 1, 7, 5 }, b{ -12, 1, 1 };

	std::cout << b.getVectorLength() << std::endl;

	std::cout << getScalarProduct(a, b) << std::endl;
	std::cout << arePerpendicular(a, b) << std::endl;

	//Vector3D c( a.plus(b) );

	Vector3D c;
	c = a.plus(b);
	c.print();

	// това също работи: a.plus(b).print();
	std::cout << std::endl;

	const Vector3D u{ 5,6,7 };
	u.print();

}
