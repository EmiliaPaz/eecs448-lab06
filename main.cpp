/**
*	@author
*	@date
*	@file main.cpp
*	@brief driver for LinkedList demo
*/

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"

#include <iostream>
#include "LinkedListOfInts.h"

// -----------------------------------------------------------------------------
// LinkedListOfInts: isEmpty()
// -----------------------------------------------------------------------------
TEST_CASE("Is empty returns true if the list is empty")
{
    LinkedListOfInts testableList;
    REQUIRE( testableList.isEmpty() == true );
}
// fails: it returns true when it is non empty
TEST_CASE("Is empty returns false if the list is not empty after addFront")
{
    LinkedListOfInts testableList;
    testableList.addFront(000);
    REQUIRE( testableList.isEmpty() == false );
}
// fails: it returns true when it is non empty
TEST_CASE("Is empty returns false if the list is not empty after addBack")
{
    LinkedListOfInts testableList;
    testableList.addBack(999);
    REQUIRE( testableList.isEmpty() == false );
}


// -----------------------------------------------------------------------------
// LinkedListOfInts: size()
// -----------------------------------------------------------------------------
TEST_CASE("Size of empty list is zero")
{
    LinkedListOfInts testableList;
    REQUIRE( testableList.size() == 0 );
}
TEST_CASE("Size returns correct value after 1 addFront")
{
    LinkedListOfInts testableList;
    testableList.addFront(000);
    REQUIRE( testableList.size() == 1 );
}
TEST_CASE("Size returns correct value after 1 addBack:")
{
    LinkedListOfInts testableList;
    testableList.addBack(999);
    REQUIRE( testableList.size() == 1 );
}

// -----------------------------------------------------------------------------
// LinkedListOfInts: search()
// -----------------------------------------------------------------------------
TEST_CASE("Search returns false if the value is not in the list")
{
    LinkedListOfInts testableList;
    REQUIRE( testableList.search(123) == false );
}
TEST_CASE("Search returns true if the value added with addFront is in the list")
{
    LinkedListOfInts testableList;
    testableList.addFront(000);
    REQUIRE( testableList.search(000) == true );
}
TEST_CASE("Search returns true if the value added with addBack is in the list")
{
    LinkedListOfInts testableList;
    testableList.addBack(999);
    REQUIRE( testableList.search(999) == true );
}
TEST_CASE("Search returns true if the value exists more than 1 time in the list")
{
    LinkedListOfInts testableList;
    testableList.addFront(555);
    testableList.addFront(333);
    testableList.addFront(555);
    testableList.addBack(555);
    testableList.addFront(222);
    REQUIRE( testableList.search(555) == true );
}


// -----------------------------------------------------------------------------
// LinkedListOfInts: addBack()
// -----------------------------------------------------------------------------
TEST_CASE("Add back adds value in the correct location in an empty list")
{
    LinkedListOfInts testableList;
    testableList.addBack(999);
    std::vector<int> list = testableList.toVector();
    REQUIRE( list[0] == 999 );
}
// Fails: addBack adds to the front
TEST_CASE("Add back adds value in the correct location in a non empty list")
{
    LinkedListOfInts testableList;
    testableList.addFront(222);
    testableList.addFront(111);
    testableList.addFront(000);
    testableList.addBack(999);
    std::vector<int> list = testableList.toVector();
    REQUIRE( list[list.size()-1] == 999 );
}


// -----------------------------------------------------------------------------
// LinkedListOfInts: addFront()
// -----------------------------------------------------------------------------
TEST_CASE("addFront adds value in the correct location in an empty list")
{
    LinkedListOfInts testableList;
    testableList.addFront(000);
    std::vector<int> list = testableList.toVector();
    REQUIRE( list[0] == 000 );
}
TEST_CASE("addFront adds value in the correct location in a non empty list")
{
    LinkedListOfInts testableList;
    testableList.addBack(111);
    testableList.addBack(222);
    testableList.addBack(333);
    testableList.addFront(000);
    std::vector<int> list = testableList.toVector();
    REQUIRE( list[0] == 000 );
}


// -----------------------------------------------------------------------------
// LinkedListOfInts: removeBack()
// -----------------------------------------------------------------------------
TEST_CASE("removeBack does nothing if the list is empty and returns false")
{
    LinkedListOfInts testableList;
    bool passRemoveBack = testableList.removeBack();
    REQUIRE( passRemoveBack == false );
    REQUIRE( testableList.size() == 0 );
}
// fails: doesn't remove value. Returns false, so it thinks the list is empty (it is not because addFront and size is verified )
TEST_CASE("removeBack removes back node from a non empty list and returns true")
{
    LinkedListOfInts testableList;
    testableList.addFront(000);
    REQUIRE( testableList.size() == 1 );
    bool passRemoveBack = testableList.removeBack();
    REQUIRE( passRemoveBack == true );
    REQUIRE( testableList.size() == 0 );
}


// -----------------------------------------------------------------------------
// LinkedListOfInts: removeFront()
// -----------------------------------------------------------------------------
TEST_CASE("removeFront does nothing if the list is empty and returns false")
{
    LinkedListOfInts testableList;
    bool passRemoveBack = testableList.removeFront();
    REQUIRE( passRemoveBack == false );
    REQUIRE( testableList.size() == 0 );
}
// fails: doesn't remove value. Returns false, so it thinks the list is empty (it is not because addFront and size is verified )
TEST_CASE("removeFront removes front node from a non empty list and returns true")
{
    LinkedListOfInts testableList;
    testableList.addFront(000);
    REQUIRE( testableList.size() == 1 );
    bool passRemoveFront = testableList.removeFront();
    REQUIRE( passRemoveFront == true );
    REQUIRE( testableList.size() == 0 );
}
