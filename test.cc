#include "gtest/gtest.h"

#include "type.h"
#include "operation/math.h"
#include "conditional/if.h"
#include "list/cons.h"
#include "list/list.h"

class TypeAsValueTest : public ::testing::Test { };

TEST_F(TypeAsValueTest, Value) {
	ASSERT_TRUE(( std::is_same<int, tav::Int<1>::value_type>::value ));
}

TEST_F(TypeAsValueTest, BasicMath) {
	EXPECT_EQ(3,  ( tav::Add<tav::Int<1>, tav::Int<2>>::value ));
	EXPECT_EQ(4,  ( tav::Substract<tav::Int<10>, tav::Int<6>>::value ));
	EXPECT_EQ(42, ( tav::Multiply<tav::Int<2>, tav::Int<21>>::value ));
	EXPECT_EQ(5,  ( tav::Divide<tav::Int<10>, tav::Int<2>>::value ));
}

TEST_F(TypeAsValueTest, Conditional) {
	EXPECT_EQ(1, ( tav::If<true,  tav::Int<1>, tav::Int<2>>::value ));
	EXPECT_EQ(2, ( tav::If<false, tav::Int<1>, tav::Int<2>>::value ));
}

TEST_F(TypeAsValueTest, Cons) {
	EXPECT_EQ(1, ( tav::Car<tav::Cons<tav::Int<1>, void>>::value ));
	EXPECT_EQ(1, ( tav::Car<tav::Cons<tav::Int<1>, tav::Int<2>>>::value ));
	EXPECT_EQ(2, ( tav::Cdr<tav::Cons<tav::Int<1>, tav::Int<2>>>::value ));
	EXPECT_EQ(2, ( tav::Car<tav::Cdr<tav::Cons<tav::Int<1>, tav::Cons<tav::Int<2>, tav::Int<3>>>>>::value ));
}

TEST_F(TypeAsValueTest, List) {
	EXPECT_EQ(1, ( tav::Car<tav::List<tav::Int<1>>::type>::value ));
	EXPECT_EQ(1, ( tav::Car<tav::List<tav::Int<1>, tav::Int<2>>::type>::value ));
	EXPECT_EQ(2, ( tav::Car<tav::Cdr<tav::List<tav::Int<1>, tav::Int<2>>::type>>::value ));
	EXPECT_EQ(2, ( tav::Car<tav::Cdr<tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type>>::value ));
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
