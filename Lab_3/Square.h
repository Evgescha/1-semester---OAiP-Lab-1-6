
class Square{

public:
    float Angl;
	float x1, y1, storona;
	Square ();
	Square (float storona);
	Square(float x, float y, float storona);
	float SFig();
	float PFig();
	void RotateFig(float Angle);
};

class Cube : public Square {

public:
float z;
	Cube(float  x, float y, float storona);
	float SPoverhnosti();

	float Objom();

	void RotateFig(float Angle);
};

