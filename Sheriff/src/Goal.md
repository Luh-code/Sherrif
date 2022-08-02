# Goal

enum Errors : uint32_t {
	NONE = 0,
	UNDEFINED = 1,
	SOME_THING = 2,
	SOME_THING_ELSE = 3,
}

shf::Territory shfTerriory<Errors>("Main");

shf::RetV test()
{
	// execute some code
	return shf::RetV(shfTerritory, SOME_THING);
}

int main()
{
	IF_SHF_ERR(test())
	{
		shf::PrintErr(err);
		return -1; // err can also be returned
	}
	return 0;
}