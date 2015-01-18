#include "gtest/gtest.h"

#include "type.h"
#include "operation/math.h"
#include "conditional/if.h"
#include "list/cons.h"
#include "list/list.h"
#include "list/operation/higher/fold.h"

class TypeAsValueTest : public ::testing::Test { };

TEST_F(TypeAsValueTest, BasicMath) {
	// (+ 1 2)
	EXPECT_EQ(3,  ( tav::Add<tav::Int<1>, tav::Int<2>>::value ));
	// (- 10 6)
	EXPECT_EQ(4,  ( tav::Substract<tav::Int<10>, tav::Int<6>>::value ));
	// (* 2 21)
	EXPECT_EQ(42, ( tav::Multiply<tav::Int<2>, tav::Int<21>>::value ));
	// (/ 10 2)
	EXPECT_EQ(5,  ( tav::Divide<tav::Int<10>, tav::Int<2>>::value ));
}

TEST_F(TypeAsValueTest, Conditional) {
	// (if #t 1 2)
	EXPECT_EQ(1, ( tav::If<true,  tav::Int<1>, tav::Int<2>>::type::value ));
	// (if #f 1 2)
	EXPECT_EQ(2, ( tav::If<false, tav::Int<1>, tav::Int<2>>::type::value ));
}

TEST_F(TypeAsValueTest, Cons) {
	// (car (cons 1 void))
	EXPECT_EQ(1, ( tav::Car<tav::Cons<tav::Int<1>, void>>::value ));
	// (car (cons 1 2))
	EXPECT_EQ(1, ( tav::Car<tav::Cons<tav::Int<1>, tav::Int<2>>>::value ));
	// (cdr (cons 1 2))
	EXPECT_EQ(2, ( tav::Cdr<tav::Cons<tav::Int<1>, tav::Int<2>>>::value ));
	// (car (cdr (cons 1 (cons 2 3))))
	EXPECT_EQ(2, ( tav::Car<tav::Cdr<tav::Cons<tav::Int<1>, tav::Cons<tav::Int<2>, tav::Int<3>>>>>::value ));
}

TEST_F(TypeAsValueTest, List) {
	// (length (list 1))
	EXPECT_EQ(1, ( tav::Length<tav::List<tav::Int<1>>::type>::type::value ));
	// (length (list 1 2))
	EXPECT_EQ(2, ( tav::Length<tav::List<tav::Int<1>, tav::Int<2>>::type>::type::value ));

	// (head (list 1))
	EXPECT_EQ(1, ( tav::Head<tav::List<tav::Int<1>>::type>::value ));
	// (head (list 1 2))
	EXPECT_EQ(1, ( tav::Head<tav::List<tav::Int<1>, tav::Int<2>>::type>::value ));
	// (head (tail (list 1 2)))
	EXPECT_EQ(2, ( tav::Head<tav::Tail<tav::List<tav::Int<1>, tav::Int<2>>::type>>::value ));
	// (head (tail (list 1 2 3)))
	EXPECT_EQ(2, ( tav::Head<tav::Tail<tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type>>::value ));
}

TEST_F(TypeAsValueTest, ListNth) {
	// (nth 0 (list 1))
	EXPECT_EQ(1, ( tav::Nth<tav::Size<0>, tav::List<tav::Int<1>>::type>::type::value ));
	// (nth 0 (list 1 2))
	EXPECT_EQ(1, ( tav::Nth<tav::Size<0>, tav::List<tav::Int<1>, tav::Int<2>>::type>::type::value ));
	// (nth 1 (list 1 2))
	EXPECT_EQ(2, ( tav::Nth<tav::Size<1>, tav::List<tav::Int<1>, tav::Int<2>>::type>::type::value ));
}

TEST_F(TypeAsValueTest, ListTake) {
	// (length (take 1 (list 1 2)))
	EXPECT_EQ(1, ( tav::Length<tav::Take<tav::Size<1>, tav::List<tav::Int<1>, tav::Int<2>>::type>::type>::type::value ));
	// (length (take 2 (list 1 2)))
	EXPECT_EQ(2, ( tav::Length<tav::Take<tav::Size<2>, tav::List<tav::Int<1>, tav::Int<2>>::type>::type>::type::value ));
	// (length (take 3 (list 1 2)))
	EXPECT_EQ(2, ( tav::Length<tav::Take<tav::Size<3>, tav::List<tav::Int<1>, tav::Int<2>>::type>::type>::type::value ));
}

TEST_F(TypeAsValueTest, ListConcatenate) {
	// (length (concatenate (list 1) (list 2)))
	EXPECT_EQ(2, ( tav::Length<tav::Concatenate<tav::List<tav::Int<1>>::type, tav::List<tav::Int<2>>::type>::type>::type::value ));
	// (length (concatenate (list 1 2) (list 3 4)))
	EXPECT_EQ(4, ( tav::Length<tav::Concatenate<tav::List<tav::Int<1>, tav::Int<2>>::type, tav::List<tav::Int<3>, tav::Int<4>>::type>::type>::type::value ));

	// (head (concatenate (list 1) (list 2)))
	EXPECT_EQ(1, ( tav::Head<tav::Concatenate<tav::List<tav::Int<1>>::type, tav::List<tav::Int<2>>::type>::type>::value ));
	// (head (tail (concatenate (list 1) (list 2))))
	EXPECT_EQ(2, ( tav::Head<tav::Tail<tav::Concatenate<tav::List<tav::Int<1>>::type, tav::List<tav::Int<2>>::type>::type>>::value ));
}

TEST_F(TypeAsValueTest, ListFold) {
	// (fold + 0 (list 1 2 3))
	EXPECT_EQ(6, ( tav::Fold<tav::Add, tav::Int<0>, tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type>::type::value ));
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
