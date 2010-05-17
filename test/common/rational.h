#include <cxxtest/TestSuite.h>

#include "common/rational.h"

class RationalTestSuite : public CxxTest::TestSuite {
public:
	void test_operators() {
		Common::Rational r0(6, 3);
		Common::Rational r1(1, 2);

		Common::Rational r2(62, 2);
		Common::Rational r3(34, 4);

		Common::Rational r4 = (r0 + r1) * 3;
		Common::Rational r5 = (r2 - r3) / 3;

		Common::Rational r6 = r5 - 1;

		TS_ASSERT(r4 == r5);

		TS_ASSERT(-r4 == -r5);

		TS_ASSERT(  r4 >  r6);
		TS_ASSERT(  r4 >= r6);
		TS_ASSERT(!(r4 <  r6));
		TS_ASSERT(!(r4 <= r6));

		TS_ASSERT(  r4 >  7);
		TS_ASSERT(  r4 >= 7);
		TS_ASSERT(!(r4 <  7));
		TS_ASSERT(!(r4 <= 7));

		TS_ASSERT(  7 <  r4);
		TS_ASSERT(  7 <= r4);
		TS_ASSERT(!(7 >  r4));
		TS_ASSERT(!(7 >= r4));
	}

	void test_assign() {
		Common::Rational r0(6, 3);
		Common::Rational r1(1, 2);

		TS_ASSERT(r0 == 2);
		TS_ASSERT(r1 == Common::Rational(1, 2));

		r0 = r1;
		TS_ASSERT(r0 == r1);
		TS_ASSERT(r0 == Common::Rational(1, 2));
	}

	void test_negative() {
		Common::Rational r0(6, 3);
		Common::Rational r1(1, 2);

		r0 = -r0;
		r1 = -r1;
		TS_ASSERT(r0 == -2);
		TS_ASSERT(r1 == Common::Rational(-1, 2));
		TS_ASSERT(r1 == Common::Rational(1, -2));
	}

	void test_add_sub() {
		const Common::Rational r0(6, 3);
		const Common::Rational r1(1, 2);

		TS_ASSERT(r0 + r1 == Common::Rational(5, 2));
		TS_ASSERT(r1 + r0 == Common::Rational(5, 2));
		TS_ASSERT(r0 - r1 == Common::Rational(3, 2));
		TS_ASSERT(r1 - r0 == Common::Rational(-3, 2));
	}

	void test_mul() {
		const Common::Rational r0(6, 3);
		const Common::Rational r1(1, 2);

		const Common::Rational r2(15, 14);
		const Common::Rational r3(7,3);
		const Common::Rational r4(5,2);

		TS_ASSERT_EQUALS(r0 * r1, 1);

		TS_ASSERT_EQUALS(r2 * r3, r4);
		TS_ASSERT_EQUALS((-r2) * r3, -r4);
		TS_ASSERT_EQUALS(r2 * (-r3), -r4);
		TS_ASSERT_EQUALS((-r2) * (-r3), r4);
	}

	void test_div() {
		Common::Rational r0(6, 3);
		Common::Rational r1(1, 2);

		TS_ASSERT(r0 / r1 == 4);
	}
};
