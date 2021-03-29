//#include "NumberlikeArray.hh"
//#include "BigUnsigned.hh"
#include "BigInteger2.h" //Это я поставил, а то закомментил

#include <string>

/*
* A BigUnsignedInABase object represents a nonnegative integer of size limited
* only by available memory, represented in a user-specified base that can fit
* in an `unsigned short' (most can, and this saves memory).
*
* BigUnsignedInABase is intended as an intermediary class with little
* functionality of its own.  BigUnsignedInABase objects can be constructed
* from, and converted to, BigUnsigneds (requiring multiplication, mods, etc.)
* and `std::string's (by switching digit values for appropriate characters).
*
* BigUnsignedInABase is similar to BigUnsigned.  Note the following:
*
* (1) They represent the number in exactly the same way, except that
* BigUnsignedInABase uses ``digits'' (or Digit) where BigUnsigned uses
* ``blocks'' (or Blk).
*
* (2) Both use the management features of NumberlikeArray.  (In fact, my desire
* to add a BigUnsignedInABase class without duplicating a lot of code led me to
* introduce NumberlikeArray.)
*
* (3) The only arithmetic operation supported by BigUnsignedInABase is an
* equality test.  Use BigUnsigned for arithmetic.
*/

class BigUnsignedInABase : protected NumberlikeArray<unsigned short> {

public:
    // The digits of a BigUnsignedInABase are unsigned shorts.
    typedef unsigned short Digit;
    // That's also the type of a base.
    typedef Digit Base;

protected:
    // The base in which this BigUnsignedInABase is expressed
    Base base;

    // Creates a BigUnsignedInABase with a capacity; for internal use.
    BigUnsignedInABase(int, Index c) : NumberlikeArray<Digit>(0, c) {}

    // Decreases len to eliminate any leading zero digits.
    void zapLeadingZeros() {
        while (len > 0 && blk[len - 1] == 0)
            len--;
    }

public:
    // Constructs zero in base 2.
    BigUnsignedInABase() : NumberlikeArray<Digit>(), base(2) {}

    // Copy constructor
    BigUnsignedInABase(const BigUnsignedInABase &x) : NumberlikeArray<Digit>(x), base(x.base) {}

    // Assignment operator
    void operator =(const BigUnsignedInABase &x) {
        NumberlikeArray<Digit>::operator =(x);
        base = x.base;
    }

    // Constructor that copies from a given array of digits.
    BigUnsignedInABase(const Digit *d, Index l, Base base);

    // Destructor.  NumberlikeArray does the delete for us.
    ~BigUnsignedInABase() {}

    // LINKS TO BIGUNSIGNED
    BigUnsignedInABase(const BigUnsigned &x, Base base);
    operator BigUnsigned() const;

    /* LINKS TO STRINGS
    *
    * These use the symbols ``0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'' to
    * represent digits of 0 through 35.  When parsing strings, lowercase is
    * also accepted.
    *
    * All string representations are big-endian (big-place-value digits
    * first).  (Computer scientists have adopted zero-based counting; why
    * can't they tolerate little-endian numbers?)
    *
    * No string representation has a ``base indicator'' like ``0x''.
    *
    * An exception is made for zero: it is converted to ``0'' and not the
    * empty string.
    *
    * If you want different conventions, write your own routines to go
    * between BigUnsignedInABase and strings.  It's not hard.
    */
    operator std::string() const;
    BigUnsignedInABase(const std::string &s, Base base);

public:

    // ACCESSORS
    Base getBase() const { return base; }

    // Expose these from NumberlikeArray directly.
    using NumberlikeArray<Digit>::getCapacity;
    using NumberlikeArray<Digit>::getLength;

    /* Returns the requested digit, or 0 if it is beyond the length (as if
    * the number had 0s infinitely to the left). */
    Digit getDigit(Index i) const { return i >= len ? 0 : blk[i]; }

    // The number is zero if and only if the canonical length is zero.
    bool isZero() const { return NumberlikeArray<Digit>::isEmpty(); }

    /* Equality test.  For the purposes of this test, two BigUnsignedInABase
    * values must have the same base to be equal. */
    bool operator ==(const BigUnsignedInABase &x) const {
        return base == x.base && NumberlikeArray<Digit>::operator ==(x);
    }
    bool operator !=(const BigUnsignedInABase &x) const { return !operator ==(x); }

};

//#include "BigUnsignedInABase.hh"

BigUnsignedInABase::BigUnsignedInABase(const Digit *d, Index l, Base base)
    : NumberlikeArray<Digit>(d, l), base(base) {
    // Check the base
    if (base < 2)
        throw "BigUnsignedInABase::BigUnsignedInABase(const Digit *, Index, Base): The base must be at least 2";

    // Validate the digits.
    for (Index i = 0; i < l; i++)
        if (blk[i] >= base)
            throw "BigUnsignedInABase::BigUnsignedInABase(const Digit *, Index, Base): A digit is too large for the specified base";

    // Eliminate any leading zeros we may have been passed.
    zapLeadingZeros();
}

namespace {
    unsigned int bitLen(unsigned int x) {
        unsigned int len = 0;
        while (x > 0) {
            x >>= 1;
            len++;
        }
        return len;
    }
    unsigned int ceilingDiv(unsigned int a, unsigned int b) {
        return (a + b - 1) / b;
    }
}

BigUnsignedInABase::BigUnsignedInABase(const BigUnsigned &x, Base base) {
    // Check the base
    if (base < 2)
        throw "BigUnsignedInABase(BigUnsigned, Base): The base must be at least 2";
    this->base = base;

    // Get an upper bound on how much space we need
    int maxBitLenOfX = x.getLength() * BigUnsigned::N;
    int minBitsPerDigit = bitLen(base) - 1;
    int maxDigitLenOfX = ceilingDiv(maxBitLenOfX, minBitsPerDigit);
    len = maxDigitLenOfX; // Another change to comply with `staying in bounds'.
    allocate(len); // Get the space

    BigUnsigned x2(x), buBase(base);
    Index digitNum = 0;

    while (!x2.isZero()) {
        // Get last digit.  This is like `lastDigit = x2 % buBase, x2 /= buBase'.
        BigUnsigned lastDigit(x2);
        lastDigit.divideWithRemainder(buBase, x2);
        // Save the digit.
        blk[digitNum] = lastDigit.toUnsignedShort();
        // Move on.  We can't run out of room: we figured it out above.
        digitNum++;
    }

    // Save the actual length.
    len = digitNum;
}

BigUnsignedInABase::operator BigUnsigned() const {
    BigUnsigned ans(0), buBase(base), temp;
    Index digitNum = len;
    while (digitNum > 0) {
        digitNum--;
        temp.multiply(ans, buBase);
        ans.add(temp, BigUnsigned(blk[digitNum]));
    }
    return ans;
}

BigUnsignedInABase::BigUnsignedInABase(const std::string &s, Base base) {
    // Check the base.
    if (base > 36)
        throw "BigUnsignedInABase(std::string, Base): The default string conversion routines use the symbol set 0-9, A-Z and therefore support only up to base 36.  You tried a conversion with a base over 36; write your own string conversion routine.";
    // Save the base.
    // This pattern is seldom seen in C++, but the analogous ``this.'' is common in Java.
    this->base = base;

    // `s.length()' is a `size_t', while `len' is a `NumberlikeArray::Index',
    // also known as an `unsigned int'.  Some compilers warn without this cast.
    len = Index(s.length());
    allocate(len);

    Index digitNum, symbolNumInString;
    for (digitNum = 0; digitNum < len; digitNum++) {
        symbolNumInString = len - 1 - digitNum;
        char theSymbol = s[symbolNumInString];
        if (theSymbol >= '0' && theSymbol <= '9')
            blk[digitNum] = theSymbol - '0';
        else if (theSymbol >= 'A' && theSymbol <= 'Z')
            blk[digitNum] = theSymbol - 'A' + 10;
        else if (theSymbol >= 'a' && theSymbol <= 'z')
            blk[digitNum] = theSymbol - 'a' + 10;
        else
            throw "BigUnsignedInABase(std::string, Base): Bad symbol in input.  Only 0-9, A-Z, a-z are accepted.";

        if (blk[digitNum] >= base)
            throw "BigUnsignedInABase::BigUnsignedInABase(const Digit *, Index, Base): A digit is too large for the specified base";
    }
    zapLeadingZeros();
}

BigUnsignedInABase::operator std::string() const {
    if (base > 36)
        throw "BigUnsignedInABase ==> std::string: The default string conversion routines use the symbol set 0-9, A-Z and therefore support only up to base 36.  You tried a conversion with a base over 36; write your own string conversion routine.";
    if (len == 0)
        return std::string("0");
    // Some compilers don't have push_back, so use a char * buffer instead.
    char *s = new char[len + 1];
    s[len] = '\0';
    Index digitNum, symbolNumInString;
    for (symbolNumInString = 0; symbolNumInString < len; symbolNumInString++) {
        digitNum = len - 1 - symbolNumInString;
        Digit theDigit = blk[digitNum];
        if (theDigit < 10)
            s[symbolNumInString] = char('0' + theDigit);
        else
            s[symbolNumInString] = char('A' + theDigit - 10);
    }
    std::string s2(s);
    delete[] s;
    return s2;
}

