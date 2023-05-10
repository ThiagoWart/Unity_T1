#include "payment.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(Payment);

TEST_SETUP(Payment){}

TEST_TEAR_DOWN(Payment){}

// limites
TEST(Payment, TestPayment1)
{
  TEST_ASSERT_EQUAL(0, payment(0.01, (char*)"estudante"));
  TEST_ASSERT_EQUAL(0, payment(99999.00, (char*)"regular"));
}

// valores dentro do aceitável
TEST(Payment, TestPayment2)
{
  TEST_ASSERT_EQUAL(0, payment(0.02, (char*)"estudante"));
  TEST_ASSERT_EQUAL(0, payment(99998.99, (char*)"aposentado"));
}

// valores fora do aceitável
TEST(Payment, TestPayment3)
{
  TEST_ASSERT_EQUAL(1, payment(0.009, (char*)"VIP"));
  TEST_ASSERT_EQUAL(1, payment(99999.01, (char*)"estudante"));
}

// valores negativos
TEST(Payment, TestPayment4)
{
  TEST_ASSERT_EQUAL(1, payment(-0.01, (char*)"regular"));
  TEST_ASSERT_EQUAL(1, payment(-99999.00, (char*)"estudante"));
}

// status aceitos
TEST(Payment, TestPayment5)
{
  TEST_ASSERT_EQUAL(0, payment(1.15, (char*)"regular"));
  TEST_ASSERT_EQUAL(0, payment(1.15, (char*)"estudante"));
  TEST_ASSERT_EQUAL(0, payment(1.15, (char*)"aposentado"));
  TEST_ASSERT_EQUAL(0, payment(1.15, (char*)"VIP"));
}

// status não aceitos
TEST(Payment, TestPayment6)
{
  TEST_ASSERT_EQUAL(2, payment(1.15, (char*)"vip"));
  TEST_ASSERT_EQUAL(2, payment(1.15, (char*)"socio"));
  TEST_ASSERT_EQUAL(2, payment(1.15, (char*)"empresario"));
  TEST_ASSERT_EQUAL(2, payment(1.15, (char*)"educador especial"));
  TEST_ASSERT_EQUAL(2, payment(1.15, NULL));
}

// teste de 10 em 10 mil
TEST(Payment, TestPayment7)
{
  TEST_ASSERT_EQUAL(0, payment(5374.00, (char*)"regular"));
  TEST_ASSERT_EQUAL(0, payment(10000.00, (char*)"regular"));
  TEST_ASSERT_EQUAL(0, payment(14234.00, (char*)"regular"));
  TEST_ASSERT_EQUAL(0, payment(20000.00, (char*)"regular"));
  TEST_ASSERT_EQUAL(0, payment(27364.00, (char*)"regular"));
  TEST_ASSERT_EQUAL(0, payment(30000.00, (char*)"regular"));
  TEST_ASSERT_EQUAL(0, payment(33482.00, (char*)"regular"));
  TEST_ASSERT_EQUAL(0, payment(40000.00, (char*)"regular"));
  TEST_ASSERT_EQUAL(0, payment(46523.00, (char*)"regular"));
  TEST_ASSERT_EQUAL(0, payment(49999.99, (char*)"regular"));
  
  TEST_ASSERT_EQUAL(0, payment(50000.00, (char*)"regular"));
  TEST_ASSERT_EQUAL(0, payment(55213.00, (char*)"regular"));
  TEST_ASSERT_EQUAL(0, payment(59999.99, (char*)"regular"));
 
  TEST_ASSERT_EQUAL(0, payment(60000.00, (char*)"regular"));
  TEST_ASSERT_EQUAL(0, payment(62178.00, (char*)"regular"));
  TEST_ASSERT_EQUAL(0, payment(70000.00, (char*)"regular"));
  TEST_ASSERT_EQUAL(0, payment(76523.00, (char*)"regular"));
  TEST_ASSERT_EQUAL(0, payment(80000.00, (char*)"regular"));
  TEST_ASSERT_EQUAL(0, payment(82323.00, (char*)"regular"));
  TEST_ASSERT_EQUAL(0, payment(90000.00, (char*)"regular"));
  TEST_ASSERT_EQUAL(0, payment(97652.00, (char*)"regular"));
  TEST_ASSERT_EQUAL(0, payment(99998.99, (char*)"regular"));
}
