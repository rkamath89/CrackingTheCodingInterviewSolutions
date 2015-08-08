class Distance
{
public:
	void setFeet(int);
	void setInches(int);
	int getFeet();
	int getInnches();
	char* getName();
	void setName(char*);
	Distance add(Distance, Distance);
	Distance &larger(Distance, Distance);
	Distance &largerAdr(Distance&, Distance&);
	Distance Bigger(Distance, Distance);

	int feet;
	int inches;
	char* name;
};
void Distance::setName(char *name1)
{
	name = name1;
}
char* Distance::getName()
{
	return name;
}
void Distance::setFeet(int val)
{
	feet = val;
}
void Distance::setInches(int val)
{
	inches = val;
}
int Distance::getFeet()
{
	return feet;
}
Distance Distance::add(Distance d1, Distance d2)
{
	Distance d3;
	d3.setFeet(d1.getFeet() + d2.getFeet());
	d3.setInches(d1.getInnches() + d2.getInnches());
	return d3;
}
Distance& larger(Distance d1, Distance d2)
{
	if (d1.getFeet() > d2.getFeet())
		return d1;
	else
		return d2;
}
Distance Bigger(Distance d1, Distance d2)
{
	if (d1.getFeet() > d2.getFeet())
		return d1;
	else
		return d2;
}
Distance& largerAdr(Distance &d1, Distance &d2)
{
	if (d1.getFeet() > d2.getFeet())
		return d1;
	else
		return d2;
}
