# Sheriff
Sheriff is a simple low-overhead header-only library for ground-level error handling/debugging made for c++17 and up.

**DISCLAIMER:** This project is still pretty bare bones, and will improve over time!

## What does it do?
The way Sheriff aims to help with debugging, is by giving integer return types more meaning.
Something you were always able to do is to return a member of an enum as an error code.  
What Sheriff does is make this process more user friendly.

```
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
```

What you see here is how you would implement Sheriff into any class. You first off create a shf::Territory which holds the name of the class(passed in as argument 1) and the no-error code(as the 2nd argument), which is the return code for when no error occured.
Any function/method that would normally return an integer error code will now return a shf::RetV(shf::ReturnValue).  
The first argument to the shf::RetV is a reference to the respective shf::Territory, and the 2nd one the Error Code. I stored them as an enum for ease of use.
  
The return code can either be accessed by accessing the public member m_value or using the int() operator.  
The same for the Territory (in this case the p_territory public member). Though the class name given to the territory can also be accessed with the const char*() operator.  
A shf::ReturnValue can also be read as a boolean (true if no error occured) via the bool() operator.  
  
In practice this isn't even required to know though. Because this is how most of you catch your errors:
```
IF_SHF_ERR(t.test())
	{
		shf::PrintErr(err);
    		// do some error handling
		return -1;
	}
```
IF_SHF_ERR() is a macro definition which expands to ```if (shf::RetV err = t.test(); err)```, allowing for a block afterwards, and providing access to the error for handling.

## The Full example program
```
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
```
