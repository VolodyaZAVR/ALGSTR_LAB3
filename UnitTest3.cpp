#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab3/Tree.h"
#include "../Lab3/Tree.cpp"
#include "../Lab3/Iterator.h"
#include "../Lab3/Iterator.cpp"
#include "../Lab3/Stack.cpp"
#include "../Lab3/Queue.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:
		Tree* bst;

		TEST_METHOD_INITIALIZE(create_list)
		{
			bst = new Tree();
		}

		TEST_METHOD_CLEANUP(MrPropper)
		{
			bst->~Tree();
		}
		TEST_METHOD(ContainsTest1)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(6);
			bst->insert(1);
			bst->insert(7);
			bst->insert(4);
			bst->insert(10);
			bst->insert(13);
			bst->insert(14);
			
			Assert::IsTrue(bst->contains(3));
		}
		TEST_METHOD(ContainsTest2)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(6);
			bst->insert(1);
			bst->insert(7);
			bst->insert(4);
			bst->insert(10);
			bst->insert(13);
			bst->insert(14);

			Assert::IsTrue(bst->contains(13));
		}
		TEST_METHOD(ContainsTest3)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(6);
			bst->insert(1);
			bst->insert(7);
			bst->insert(4);
			bst->insert(10);
			bst->insert(13);
			bst->insert(14);

			Assert::IsTrue(bst->contains(14));
		}
		TEST_METHOD(ContainsTest4)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(6);
			bst->insert(1);
			bst->insert(7);
			bst->insert(4);
			bst->insert(10);
			bst->insert(13);
			bst->insert(14);

			Assert::IsTrue(bst->contains(10));
		}
		TEST_METHOD(ContainsTest5)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(6);
			bst->insert(1);
			bst->insert(7);
			bst->insert(4);
			bst->insert(10);
			bst->insert(13);
			bst->insert(14);

			Assert::IsTrue(!bst->contains(9));
		}
		TEST_METHOD(insert_test1)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(6);
			bst->insert(1);
			bst->insert(7);
			bst->insert(4);
			bst->insert(10);
			bst->insert(13);
			bst->insert(14);
			bst->insert(9);
			Assert::IsTrue(bst->contains(9));
		}
		TEST_METHOD(insert_test2)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(6);
			bst->insert(1);
			bst->insert(7);
			bst->insert(4);
			bst->insert(10);
			bst->insert(13);
			bst->insert(14);
			bst->insert(10);
			Assert::IsTrue(bst->contains(10));
		}
		TEST_METHOD(remove_test1)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(6);
			bst->insert(1);
			bst->insert(7);
			bst->insert(4);
			bst->insert(10);
			bst->insert(13);
			bst->insert(14);
			bst->remove(14);
			Assert::IsTrue(bst->contains(13));
		}
		TEST_METHOD(remove_test2)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(6);
			bst->insert(1);
			bst->insert(7);
			bst->insert(4);
			bst->insert(10);
			bst->insert(13);
			bst->insert(13);
			bst->remove(13);
			Assert::IsTrue(bst->contains(13));
		}
		TEST_METHOD(remove_test3)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(6);
			bst->insert(1);
			bst->insert(7);
			bst->insert(4);
			bst->insert(10);
			bst->insert(13);
			bst->remove(8);
			Assert::IsTrue(!bst->contains(8));
		}
		TEST_METHOD(remove_test4)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(6);
			bst->insert(1);
			bst->insert(7);
			bst->insert(4);
			bst->insert(10);
			bst->insert(13);
			bst->remove(3);
			Assert::IsTrue(!bst->contains(3));
		}
		TEST_METHOD(remove_test5)
		{
			try {
				bst->insert(8);
				bst->insert(3);
				bst->insert(1);
				bst->remove(15);
			}
			catch (char* e) {
				Assert::AreEqual("There is no this element!", e);
			}
		}
		TEST_METHOD(remove_test6)
		{
			try {
				bst->remove(2);
			}
			catch (char* e) {
				Assert::AreEqual("Tree is empty!", e);
			}
		}
		TEST_METHOD(dftIterator_test)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(6);
			bst->insert(1);
			bst->insert(7);
			bst->insert(4);
			bst->insert(10);
			bst->insert(13);
			bst->insert(14);
			int i = 0;
			int array[] = { 8, 3, 1,6, 4, 7, 10, 13, 14 };
			Iterator* dft_iterator = bst->create_dft_iterator();
			while (dft_iterator->has_next()) 
			{
				Assert::AreEqual(dft_iterator->next(), array[i]);
				i++;
			}
		}
/*
		TEST_METHOD(bftIterator_test)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(6);
			bst->insert(1);
			bst->insert(7);
			bst->insert(4);
			bst->insert(10);
			bst->insert(13);
			bst->insert(14);
			int i = 0;
			int array[] = { 8, 3, 10, 1, 6, 13, 4, 7, 14 };
			Iterator* bft_iterator = bst->create_bft_iterator();
			while (bft_iterator->has_next()) 
			{
				Assert::AreEqual(bft_iterator->next(), array[i]);
				i++;
			}
		}*/
	};
}
