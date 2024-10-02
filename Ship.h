#ifndef SHIP
#define SHIP

#include <vector>

enum SegmentState
{
	INTACT,
	DAMAGED,
	DESTROYED
};

class Ship
{
public:
	enum Orientation
	{
		HORIZONTAL,
		VERTICAL
	};

	struct Segment
	{
		SegmentState state = INTACT;
	};

	Ship(int length);
	~Ship();
	int getOrientation();
	int switchOrientation();
	int getLength(); 
	void changeState(int index);
	Segment& getSegment(int index);
	std::vector<Segment>& getSegments();

private:
	int orientation;
	int length;
	std::vector<Segment> segments;
};

#endif