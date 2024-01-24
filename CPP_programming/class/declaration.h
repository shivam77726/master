using namespace std;
class fDistance
{
	private:
		int feet;
		float inch;
	public:
		int getDistance();
		int getDisplay();
		int addDistances(fDistance,fDistance);
};



class mDistance
{
	private:
		int meter;
		float centimeter;
	public:
		int getDistance();
		int getDisplay();
		int addDistances(mDistance,mDistance);
};



class Menu
{
	private:
		int choice;
	public:
		int mainMenu();
};


class Time12
{
	private:
		int HR;
		int MIN;
		int SEC;
		char MER[2];
	public:
		int getTime();
		int timeDisplay();
		int addTimes(Time12,Time12);
};

class Time24
{
	private:
		int HR;
		int MIN;
		int SEC;
	public:
		int getTime();
		int timeDisplay();
		int addTimes(Time24,Time24);
};
