#include "stdafx.h"
#include "CppUnitTest.h"
#include "../HW4/OneDimHash.cpp"
#include "../HW4/TwoDimHash.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTableTests
{
	TEST_CLASS(HashTableTests)
	{
	public:

		TEST_METHOD(TestOneDimInsert)
		{
			srand(NULL);
			OneDimHash testHash1D;

			// inserting when the table is empty 
			// inserting when the first checked spot is available
			int checked = testHash1D.insert(5);
			Assert::AreEqual(1, testHash1D.getLength());
			Assert::AreEqual(1, testHash1D.find(5));
			Assert::AreEqual(1, checked);

			// inserting when the spot is already occupied
			checked = testHash1D.insert(5);
			Assert::AreEqual(2, testHash1D.getLength());
			Assert::AreEqual(1, testHash1D.find(5));
			Assert::AreEqual(2, checked);

			// inserting random values until the table is full
			int vals[498];
			int count = 0;
			while (count < 498) {
				int val = rand() % 20000;
				vals[count] = val;
				count = count + 1;
			}
			count = 0;
			while (count < 498) {
				testHash1D.insert(vals[count]);
				count = count + 1;
			}

			Assert::AreEqual(500, testHash1D.getLength());
		}

		TEST_METHOD(TestOneDimRemove)
		{
			srand(NULL);
			OneDimHash testHash1D;

			// removing one item 
			testHash1D.insert(5);
			int checked = testHash1D.remove(5);
			Assert::AreEqual(0, testHash1D.getLength());
			Assert::AreEqual(0, testHash1D.remove(5));
			Assert::AreEqual(1, checked);

			// removing an item that was inserted when it's spot was occupied
			testHash1D.insert(5);
			testHash1D.insert(5);
			checked = testHash1D.remove(5);
			Assert::AreEqual(1, testHash1D.getLength());
			Assert::AreEqual(2, testHash1D.remove(5));
			Assert::AreEqual(1, checked);

			// inserting random values until the table is full
			int vals[500];
			int count = 0;
			while (testHash1D.getLength() != 500) {
				int val = rand() % 20000;
				vals[count] = val;
				testHash1D.insert(val);
				count = count + 1;
			}

			// emptying the table by removing all of the inserted values 
			count = 0;
			while (count < 500) {
				testHash1D.remove(vals[count]);
				count = count + 1;
			}

			Assert::AreEqual(0, testHash1D.getLength());

		}

		TEST_METHOD(TestOneDimFind)
		{
			OneDimHash testHash1D;

			// finding a value that is in it's expected spot
			testHash1D.insert(5);
			int checked = testHash1D.find(5);
			Assert::AreEqual(1, testHash1D.getLength());
			Assert::AreEqual(1, testHash1D.remove(5));
			Assert::AreEqual(1, checked);

			// finding a value that was inserted when it's spot was occupied
			testHash1D.insert(578);
			testHash1D.insert(703);
			checked = testHash1D.find(703);
			Assert::AreEqual(2, testHash1D.getLength());
			Assert::AreEqual(1, testHash1D.remove(578));
			Assert::AreEqual(2, testHash1D.remove(703));
			Assert::AreEqual(2, checked);
		}

		TEST_METHOD(TestTwoDimInsert)
		{
			srand(NULL);
			TwoDimHash testHash2D;

			// inserting when the table is empty 
			// inserting when the first checked spot is available
		    int checked = testHash2D.insert(5);
			Assert::AreEqual(1, testHash2D.getLength());
			Assert::AreEqual(1, testHash2D.find(5));
			Assert::AreEqual(1, checked);

			// inserting into the same bucket
			checked = testHash2D.insert(5);
			Assert::AreEqual(2, testHash2D.getLength());
			Assert::AreEqual(1, testHash2D.find(5));
			Assert::AreEqual(2, checked);

			// inserting random values until the table is full
			int vals[498];
			int count = 0;
			while (count < 498) {
				int val = rand() % 20000;
				vals[count] = val;
				count = count + 1;
			}
			count = 0;
			while (count < 498) {
				testHash2D.insert(vals[count]);
				count = count + 1;
			}

			Assert::AreEqual(500, testHash2D.getLength());
		}

		TEST_METHOD(TestTwoDimRemove)
		{
			srand(NULL);
			TwoDimHash testHash2D;

			// removing one item 
			testHash2D.insert(5);
			int checked = testHash2D.remove(5);
			Assert::AreEqual(0, testHash2D.getLength());
			Assert::AreEqual(0, testHash2D.remove(5));
			Assert::AreEqual(1, checked);

			// removing two items that were in the same bucket 
			testHash2D.insert(5);
			testHash2D.insert(5);
			checked = testHash2D.remove(5);
			Assert::AreEqual(1, testHash2D.getLength());
			Assert::AreEqual(2, testHash2D.remove(5));
			Assert::AreEqual(1, checked);

			// inserting random values until the table is full
			int vals[500];
			int count = 0;
			while (testHash2D.getLength() != 500) {
				int val = rand() % 20000;
				vals[count] = val;
				testHash2D.insert(val);
				count = count + 1;
			}

			// emptying the table by removing all of the inserted values 
			count = 0;
			while (count < 500) {
				testHash2D.remove(vals[count]);
				count = count + 1;
			}

			Assert::AreEqual(0, testHash2D.getLength());
		}

		TEST_METHOD(TestTwoDimFind)
		{
			TwoDimHash testHash2D;

			// finding a value that is in it's expected spot
			testHash2D.insert(5);
			int checked = testHash2D.find(5);
			Assert::AreEqual(1, testHash2D.getLength());
			Assert::AreEqual(1, testHash2D.remove(5));
			Assert::AreEqual(1, checked);

			// finding a value that was inserted when it's spot was occupied
			testHash2D.insert(578);
			testHash2D.insert(703);
			checked = testHash2D.find(703);
			Assert::AreEqual(2, testHash2D.getLength());
			Assert::AreEqual(1, testHash2D.remove(578));
			Assert::AreEqual(2, testHash2D.remove(703));
			Assert::AreEqual(2, checked);
		}

	};
}
