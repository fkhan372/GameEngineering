#include <iostream>

class Legs
{
public:
	void Walk() { std::cout << "Robot walking\n"; }
};

class Arms
{
public:
	void Grab() { std::cout << "Robot grabbing\n"; }
};

class InheritanceRobot : public Legs, public Arms
{
public:
	// WalkAround() and GrabThings() methods are implicitly
	// defined for this class since it inherited those
	// methods from its two superclasses
};

class CompositionRobot
{
public:
	void Walk() { m_legs.Walk(); }
	void Grab() { m_arms.Grab(); }

private:
	Legs m_legs;
	Arms m_arms;
};