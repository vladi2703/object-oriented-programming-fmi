#include "RelationElement.h"

int main()
{
	RelationElement<double> r0(1.5, 3, "is half of");
	r0.print();
	
	RelationElement<int> r1(2, 6, "is smaller than"), r2(6, 3, "is divisible by");
	RelationElement<int> r(0,0," ");
	r = r1 * r2;
	r.print();

}