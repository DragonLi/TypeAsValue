#include "gtest/gtest.h"

#include "type.h"
#include "operation.h"

class TypeAsValueTest : public ::testing::Test { };

TEST_F(TypeAsValueTest, Value) {
	ASSERT_TRUE(( std::is_same<int, tav::Int<1>::value_type>::value ));
}

TEST_F(TypeAsValueTest, BasicMath) {
	EXPECT_EQ(3, ( tav::add<tav::Int<1>, tav::Int<2>>::type::value ));
	EXPECT_EQ(4, ( tav::substract<tav::Int<10>, tav::Int<6>>::type::value ));
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
