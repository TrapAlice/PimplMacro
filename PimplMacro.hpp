#ifndef PIMPLMACRO_HPP
#define PIMPLMACRO_HPP

#include <memory>
using std::unique_ptr;

#define HAS_PRIVATE_VARIABLES struct PrivateVariables; unique_ptr<PrivateVariables> m;
#define PRIVATE_VARIABLES(CLASS)\
	struct CLASS::PrivateVariables

#define INIT_PRIVATE_VARIABLES(...) m(new PrivateVariables(__VA_ARGS__))

#define HAS_PRIVATE_FUNCTIONS struct PrivateFunctions; friend PrivateFunctions;
#define PRIVATE_FUNCTIONS(CLASS, ...)\
	using PrivateClassType = CLASS;\
	struct CLASS::PrivateFunctions{\
		__VA_ARGS__\
	};
#define PRIVATE_FUNCTION_DECLARE(RETURN, NAME, ...)\
	static RETURN NAME(PrivateClassType* This, ##__VA_ARGS__)
#define PRIVATE(FUNCTION, ...) PrivateFunctions::FUNCTION(this, ##__VA_ARGS__);

#endif
