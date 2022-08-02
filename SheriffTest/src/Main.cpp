#include "sheriff-base.h"

class Test
{
public:
	enum Errors : int32_t {
		NONE = 0,
		UNDEFINED = 1,
		SOME_THING = 2,
		SOME_THING_ELSE = 3,
	};

	shf::Territory shfTerritory = shf::Territory("Test");

	shf::RetV test()
	{
		// execute some code
		return shf::RetV(shfTerritory, SOME_THING);
	}
};

shf::Territory shfTerriory = shf::Territory("Main");

int main()
{
	Test t;

	IF_SHF_ERR(t.test())
	{
		shf::PrintErr(err);
		return -1;
	}

	return 0;
}