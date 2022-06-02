#include "pch.h"
#include "CppUnitTest.h"
#include "..\Ford-Fulcerson\FordFulcerson.h"
#define TEST_CASE_DIRECTORY GetDirectoryName(__FILE__)

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FordFulcersonTest
{
	TEST_CLASS(FordFulcersonTest)
	{
		string GetDirectoryName(string path) {
			const size_t last_slash_idx = path.rfind('\\');
			if (std::string::npos != last_slash_idx)
			{
				return path.substr(0, last_slash_idx + 1);
			}
			return "";
		}

	public:
		
		TEST_METHOD(FordFulc1)
		{
			string fileName = string(TEST_CASE_DIRECTORY) + "testInput/input.txt";
			FordFulcerson test;
			test.readFromFile(fileName);
			int ans = test.findMaxFlow();
			int expected = 5;
			Assert::AreEqual(expected, ans);
		}

		TEST_METHOD(FordFulc2)
		{
			string fileName = string(TEST_CASE_DIRECTORY) + "testInput/input2.txt";
			FordFulcerson test;
			test.readFromFile(fileName);
			int ans = test.findMaxFlow();
			int expected = 22;
			Assert::AreEqual(expected, ans);
		}
	};
}
