#include "pch.h"
#include "gtest/gtest.h"

TEST(SortFunctionTest, normal) {
	vector<int> v = { 4, 3, 2, 1 };
	selectionSort(v);
	EXPECT_EQ(v[0], 1);
	EXPECT_EQ(v[1], 2);
	EXPECT_EQ(v[2], 3);
	EXPECT_EQ(v[3], 4);
}

TEST(SortFunctionTest, dejasortat) {
    vector<int> v = { 1, 2, 3, 4, 5 };
    vector<int> expected = { 1, 2, 3, 4, 5 };
    selectionSort(v);
    EXPECT_EQ(v, expected); 
}

TEST(SortFunctionTest, invers) {
    vector<int> v = { 5, 4, 3, 2, 1 };
    vector<int> expected = { 1, 2, 3, 4, 5 };
    selectionSort(v);
    EXPECT_EQ(v, expected);
}

TEST(SortFunctionTest, mix) {
	vector<int> v = { 3, 1, 4, 2, 5 };
	vector<int> expected = { 1, 2, 3, 4, 5 };
	selectionSort(v);
	EXPECT_EQ(v, expected);
}

TEST(SortFunctionTest, empty) {
	vector<int> v = {};
	vector<int> expected = {};
	selectionSort(v);
	EXPECT_EQ(v, expected);
}

TEST(SortFunctionTest, OneElementOnly) {
	vector<int> v = { 42 };
	vector<int> expected = { 42 };
	selectionSort(v);
	EXPECT_EQ(v, expected);
}