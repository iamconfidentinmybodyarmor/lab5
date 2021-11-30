#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Sergey\source\repos\лр3_ОИПЗ\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(calc_Tests)
	{
	public:
		TEST_METHOD(calc_get_12and6_return_990)
		{
			double x1 = 12;
			int n = 6;
			double expected = 990;

			double actual = calc(x1, n);

			Assert::AreEqual(expected, actual);
		}
	public:

		TEST_METHOD(calc_get_6and9_return_0)
		{
			double x1 = 6;
			int n = 9;
			double expected = 0;

			double actual = calc(x1, n);

			Assert::AreEqual(expected, actual);
		}
	public:
		TEST_METHOD(calc_get_minus4and5_return_minus2)
		{
			double x1 = -4;
			int n = 5;
			double expected = -2;

			double actual = calc(x1, n);

			Assert::AreEqual(expected, actual);
		}
	};

	TEST_CLASS(Input_Tests)
	{
	public:
		TEST_METHOD(Input_N_5)
		{
			int n = 5;
			try
			{
				checkN(n);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail;
			}
		}
	public:
		TEST_METHOD(Input_N_2)
		{
			int n = 2;
			try
			{
				checkN(n);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	public:
		TEST_METHOD(Input_step_3)
		{
			double step = 3;
			try
			{
				checkStep(step);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	public:
		TEST_METHOD(Input_step_0)
		{
			double step = 0;
			try
			{
				checkStep(step);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	public:
		TEST_METHOD(Input_x1andx2_minus4and6)
		{
			double x1 = -4;
			double x2 = 6;
			try
			{
				checkX(x1, x2);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	public:
		TEST_METHOD(Input_x1andx2_2andminus2)
		{
			double x1 = 2;
			double x2 = -2;
			try
			{
				checkX(x1, x2);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	};
}

