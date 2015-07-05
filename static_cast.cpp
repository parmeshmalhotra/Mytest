static_cast
static_cast can perform conversions between pointers to related classes, not only upcasts (from pointer-to-derived to pointer-to-base), but also downcasts (from pointer-to-base to pointer-to-derived). No checks are performed during runtime to guarantee that the object being converted is in fact a full object of the destination type. Therefore, it is up to the programmer to ensure that the conversion is safe. On the other side, it does not incur the overhead of the type-safety checks of dynamic_cast.


	

class Base {};
class Derived: public Base {};
Base * a = new Base;
Derived * b = static_cast<Derived*>(a);

	


This would be valid code, although b would point to an incomplete object of the class and could lead to runtime errors if dereferenced.

Therefore, static_cast is able to perform with pointers to classes not only the conversions allowed implicitly, but also their opposite conversions.

static_cast is also able to perform all conversions allowed implicitly (not only those with pointers to classes), and is also able to perform the opposite of these. It can:

    Convert from void* to any pointer type. In this case, it guarantees that if the void* value was obtained by converting from that same pointer type, the resulting pointer value is the same.
    Convert integers, floating-point values and enum types to enum types.


Additionally, static_cast can also perform the following:

    Explicitly call a single-argument constructor or a conversion operator.
    Convert to rvalue references.
    Convert enum class values into integers or floating-point values.
    Convert any type to void, evaluating and discarding the value.


