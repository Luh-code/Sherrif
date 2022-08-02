
#include "sheriff-base.h"

class Test
{
public:
	enum Errors : uint32_t {
		NONE = 0,
		UNDEFINED = 1,
		SOME_THING = 2,
		SOME_THING_ELSE = 3,
	};

	shf::Territory* shfTerritory = new shf::Territory("Test");

	shf::RetV test()
	{
		// execute some code
		return shf::RetV(*shfTerritory, SOME_THING);
	}
};

//shf::Territory* shfTerriory = new shf::Territory("Main");

int main()
{
	//Test* t = new Test();
	Test t;

	IF_SHF_ERR(t.test())
	{
		shf::PrintErr(err);
		return -1; // err can also be returned
	}
	return 0;
}