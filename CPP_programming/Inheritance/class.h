using namespace std;

class stack
{
	protected:
		int top;
		int *stackArray;
	public:
		stack();
		void createStack();
		~stack();

};

class stackImp: public stack
{
	public:
		stackImp();
		void push();
		void pop();
		void display();
		~stackImp();

};
