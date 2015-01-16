#include "gtest/gtest.h"

#include "type.h"
#include "operation/math.h"
#include "conditional/if.h"

class TypeAsValueTest : public ::testing::Test { };

TEST_F(TypeAsValueTest, Value) {
	ASSERT_TRUE(( std::is_same<int, tav::Int<1>::value_type>::value ));
}

TEST_F(TypeAsValueTest, BasicMath) {
	EXPECT_EQ(3,  ( tav::add<tav::Int<1>, tav::Int<2>>::value ));
	EXPECT_EQ(4,  ( tav::substract<tav::Int<10>, tav::Int<6>>::value ));
	EXPECT_EQ(42, ( tav::multiply<tav::Int<2>, tav::Int<21>>::value ));
	EXPECT_EQ(5,  ( tav::divide<tav::Int<10>, tav::Int<2>>::value ));
}

TEST_F(TypeAsValueTest, Conditional) {
	EXPECT_EQ(1, ( tav::If<true,  tav::Int<1>, tav::Int<2>>::value ));
	EXPECT_EQ(2, ( tav::If<false, tav::Int<1>, tav::Int<2>>::value ));
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
