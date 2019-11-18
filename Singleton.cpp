
#include <string>
using namespace std;

class singlton
{
public:
	static singlton * getInstance()
	{
		if (obj == nullptr)
			obj = new singlton();

		return obj;

	}
	

private:
	
	singlton()
	{}

	~singlton()
	{
	}

	singlton(singlton const&) = delete;
	singlton & operator=(singlton const&) = delete;
	static singlton *obj;

};
