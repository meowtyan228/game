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


	Ship(int length);
	~Ship();
	int getOrientation();
	void switchOrientation();
	int getLength();
	SegmentState* getSegment(int index);
	std::vector<SegmentState>& getSegments();

private:
	Orientation orientation;
	int length;
	std::vector<SegmentState> segments;
};

#endif