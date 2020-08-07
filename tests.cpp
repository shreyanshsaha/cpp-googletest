/**
 * Code to test functions we made.
 * ===============================
 *
 * Points:
 * 1. ASSERT_* generates fatal failure and retuns from function
 * 2. EXPECT_* generates nonfatal failues and continues the function
 * 3. Excepts allow more than one failure to be reported in test, assert should
 * be used it it doesnt make sense for the function to continue if a condition
 * fails.
 * 4. ASSERT failure skips cleanup code in that function which may lead to leaks
 * 
 * @author Shreyansh Saha
 */

// tests.cpp
#include <gtest/gtest.h>

#include "CustomVector.cpp"
#include "isEven.cpp"
#include "squareRoot.cpp"

// TEST squareRoot Function
// format is (TestSuit, TestName)
TEST(SquareRootTest, PositiveNos) {
  ASSERT_EQ(6, squareRoot(36.0));
  ASSERT_EQ(18.0, squareRoot(324.0));
  ASSERT_EQ(25.4, squareRoot(645.16));
  ASSERT_EQ(0, squareRoot(0.0));
}

TEST(SquareRootTest, NegativeNos) {
  ASSERT_EQ(-1.0, squareRoot(-15.0));
  ASSERT_EQ(-1.0, squareRoot(-0.2));
}

// TEST isEven function
TEST(EvenTest, EvenNos) {
  ASSERT_EQ(true, isEven(10));
  ASSERT_EQ(true, isEven(2));
  ASSERT_EQ(true, isEven(0));
  ASSERT_EQ(true, isEven(-2));
}

TEST(EvenTest, OddNos) {
  ASSERT_EQ(false, isEven(9));

  // EXPECT_EQ(true, isEven(9));
  // ASSERT_EQ(true, isEven(9));

  ASSERT_EQ(false, isEven(3));
  ASSERT_EQ(false, isEven(-3));
}

// To disable a test add DISABLED_ prefix
TEST(EvenTest, DISABLED_EvenNos) { ASSERT_EQ(false, isEven(10)); }

// Floating point compares
TEST(SquareRootTest, FloatingTest) {
  ASSERT_NEAR(50.3321, squareRoot(2533.310224), 0.001);
}

// Testing class
TEST(VectorTest, TestsAllFunctionsInClass) {
  CustomVector *obj = new CustomVector();
  std::vector<int> a = obj->getA();
  std::vector<int> b = obj->getB();

  ASSERT_EQ(a.size(), b.size());

  // change EXPECT_EQ to ASSERT_EQ and notice how we only get
  // one result
  for (int i = 0; i < a.size(); i++) {
    EXPECT_EQ(a[i], b[i]) << "Vectors differ at index " << i;
  }

  // this code won't run if ASSERT_EQ fails
  // cleanup code
  free(obj);
}

// =============
// TEST Fixtures
// =============

// Test fixtures allows us to operate on similar data
// lets test our class using test fixture

class CustomVectorTest : public ::testing::Test {
 protected:
  void SetUp() override {
    a = obj.getA();
    b = obj.getB();
  }

  // We dont need teardown as descructor cleans up automatically
  // void TearDown() override {}

  CustomVector obj;
  std::vector<int> a;
  std::vector<int> b;
};

// same code but now resuing data
TEST_F(CustomVectorTest, testingSize) { 
	ASSERT_EQ(a.size(), b.size()); 
}

TEST_F(CustomVectorTest, testingValues) {
  for (int i = 0; i < a.size(); i++) {
    EXPECT_EQ(a[i], b[i]) << "Vectors differ at index " << i;
  }
}

// =============
// Main Function
// =============

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}