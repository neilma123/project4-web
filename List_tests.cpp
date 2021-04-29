// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"

using namespace std;

// Add your test cases here

TEST(test_empty) {
        List<int> empty_list;
    ASSERT_TRUE(empty_list.empty());
    empty_list.push_back(43);
    ASSERT_FALSE(empty_list.empty());
}
TEST(test_big_three) {
    List<int> *empty_list = new List<int>;
    empty_list->push_back(1);
    delete empty_list;
    List<int> test_ints;
    test_ints.push_back(7);
    test_ints.push_back(8);
    List<int> test_ints1(test_ints);
    
    ASSERT_EQUAL(test_ints1.size(), 2);
}

TEST(test_size) {
    List<int> test_ints;
    test_ints.push_back(7);
    test_ints.push_back(33);
    test_ints.push_back(5);
    test_ints.push_back(18);
    test_ints.push_back(10);
    test_ints.push_back(14);
    ASSERT_TRUE(test_ints.size() == 6);
}
TEST(test_size_one_none) {
    List<int> test_ints;
    test_ints.push_back(7);
    ASSERT_TRUE(test_ints.size() == 1);
    List<int> test_ints1;
    ASSERT_TRUE(test_ints1.size() == 0);
}

TEST(test_front) {
    List<int> test_ints;
    test_ints.push_back(7);
    test_ints.push_back(33);
    test_ints.push_back(5);
    test_ints.push_back(18);
    test_ints.push_back(10);
    test_ints.push_back(14);
    ASSERT_TRUE(test_ints.front() == 7);
}

TEST(test_back) {
    List<int> test_ints;
    test_ints.push_back(7);
    test_ints.push_back(33);
    test_ints.push_back(5);
    test_ints.push_back(18);
    test_ints.push_back(10);
    test_ints.push_back(14);
    ASSERT_TRUE(test_ints.back() == 14);
}


TEST(test_pushFront) {
    List<int> test_ints;
    test_ints.push_back(7);
    test_ints.push_back(33);
    test_ints.push_back(5);
    test_ints.push_back(18);
    test_ints.push_back(10);
    test_ints.push_back(14);
    test_ints.push_front(55);
    ASSERT_TRUE(test_ints.back() == 14);
    ASSERT_TRUE(test_ints.front() == 55);
}

TEST(test_pushBack) {
    List<int> test_ints;
    test_ints.push_back(7);
    test_ints.push_back(33);
    test_ints.push_back(5);
    test_ints.push_back(18);
    test_ints.push_back(10);
    test_ints.push_back(14);
    test_ints.push_back(55);
    ASSERT_TRUE(test_ints.back() == 55);
}

TEST(test_popBack) {
    List<int> test_ints;
    test_ints.push_back(7);
    test_ints.push_back(33);
    test_ints.push_back(5);
    test_ints.push_back(18);
    test_ints.push_back(10);
    test_ints.push_back(14);
    test_ints.pop_back();
    ASSERT_TRUE(test_ints.back() == 10);
}

TEST(test_popFront) {
    List<int> test_ints;
    test_ints.push_back(7);
    test_ints.push_back(33);
    test_ints.push_back(5);
    test_ints.push_back(18);
    test_ints.push_back(10);
    test_ints.push_back(14);
    test_ints.pop_front();
    ASSERT_TRUE(test_ints.front() == 33);
}


TEST(test_clear) {
    List<int> test_ints;
    test_ints.push_back(7);
    test_ints.push_back(33);
    test_ints.push_back(5);
    test_ints.push_back(18);
    test_ints.push_back(10);
    test_ints.push_back(14);
    test_ints.clear();
    ASSERT_TRUE(test_ints.empty() == true);
}
TEST(test_clear_one_none) {
    List<int> test_ints;
    test_ints.push_back(7);
    test_ints.clear();
    ASSERT_TRUE(test_ints.empty() == true);
    List<int> test_ints1;
    test_ints1.clear();
    ASSERT_TRUE(test_ints.empty() == true);
    ASSERT_TRUE(test_ints.size() == 0);
}

TEST(test_assignment_operator) {
    List<int> test_ints;
    test_ints.push_back(7);
    test_ints.push_back(33);
    test_ints.push_back(5);
    test_ints.push_back(18);
    test_ints.push_back(10);
    test_ints.push_back(14);
    
    List<int> test_assign;
    test_assign.push_back(7);
    test_assign.push_back(86);
    test_assign.push_back(43);
    test_assign.push_back(36);
    test_assign.push_back(92);
    test_assign.push_back(99);
    test_ints = test_assign;
    ASSERT_TRUE(test_ints.back() == 99);
    ASSERT_TRUE(test_ints.front() == 7);
    test_ints.clear();
    test_ints = test_assign;
    List<int>::Iterator i = test_ints.begin();
    List<int>::Iterator j = test_assign.begin();
    while(i != test_ints.end() && j != test_assign.end()){
        ASSERT_EQUAL(*i, *j);
        ++i;
        ++j;
    }
}
TEST(test_assignment_operator_one) {
    List<int> test_ints;
    test_ints.push_back(8);
    test_ints.push_back(7);
    test_ints.push_back(86);
    test_ints.push_back(43);
    test_ints.push_back(36);
    test_ints.push_back(92);
    test_ints.push_back(99);
    
    List<int> test_assign;
    test_assign.push_back(7);
    test_ints = test_assign;
    ASSERT_TRUE(test_ints.back() == 7);
    ASSERT_TRUE(test_ints.front() == 7);
    test_ints.clear();
    test_ints = test_assign;
    List<int>::Iterator i = test_ints.begin();
    List<int>::Iterator j = test_assign.begin();
    while(i != test_ints.end() && j != test_assign.end()){
        ASSERT_EQUAL(*i, *j);
        ++i;
        ++j;
    }
}


TEST(test_one_back_IsFront) {
    List<int> test_ints;
    test_ints.push_back(7);
    ASSERT_TRUE(test_ints.back() == 7 && test_ints.front() == 7);
    
}

TEST(test_one_pop_back) {
    List<int> test_ints;
    test_ints.push_back(7);
    test_ints.pop_back();
    ASSERT_TRUE(test_ints.empty());
}
TEST(test_one_pop_back_front) {
    List<int> test_ints;
    test_ints.push_front(7);
    test_ints.pop_back();
    ASSERT_TRUE(test_ints.empty());
}

TEST(test_one_pop_front) {
    List<int> test_ints;
    test_ints.push_back(7);
    test_ints.pop_front();
    ASSERT_TRUE(test_ints.empty());
}
TEST(test_one_pop_front_front) {
    List<int> test_ints;
    test_ints.push_front(7);
    test_ints.pop_front();
    ASSERT_TRUE(test_ints.empty());
}
TEST(test_empty_clear) {
    List<int> empty_list;
    empty_list.clear();
    ASSERT_TRUE(empty_list.empty());
}

TEST(test_two_element_popfront) {
    List<int> test_ints;
    test_ints.push_back(19);
    test_ints.push_back(33);
    test_ints.pop_front();
    ASSERT_TRUE(test_ints.front() == 33 && test_ints.back() == 33);
}
TEST(test_two_element_popfront_front) {
    List<int> test_ints;
    test_ints.push_front(19);
    test_ints.push_front(33);
    test_ints.pop_front();
    ASSERT_TRUE(test_ints.front() == 19 && test_ints.back() == 19);
}
TEST(test_two_element_popback) {
    List<int> test_ints;
    test_ints.push_back(19);
    test_ints.push_back(33);
    test_ints.pop_back();
    ASSERT_TRUE(test_ints.front() == 19 && test_ints.back() == 19);
}
TEST(test_two_element_popback_front) {
    List<int> test_ints;
    test_ints.push_front(19);
    test_ints.push_front(33);
    test_ints.pop_back();
    ASSERT_TRUE(test_ints.front() == 33 && test_ints.back() == 33);
}

TEST(test_size_gone) {
    //error --- the bitch runs one over
    List<int> test_ints;
    ASSERT_TRUE(test_ints.size() == 0);
}

TEST(test_iterator_1) {
    List<int> test_ints;
    test_ints.push_back(7);
    test_ints.push_back(33);
    test_ints.push_back(5);
    test_ints.push_back(18);
    List<int>::Iterator i = test_ints.begin();
    ASSERT_TRUE(*i == test_ints.front());
}

TEST(test_iterator_2) {
    List<int> test_ints;
    test_ints.push_back(7);
    test_ints.push_back(33);
    test_ints.push_back(5);
    test_ints.push_back(18);
    int counter = 0;
    for(List<int>::Iterator i = test_ints.begin(); i != test_ints.end(); ++i){
        ++counter;
    }
    ASSERT_TRUE(counter == 4);
}
TEST(test_iterator_1_element) {
    List<int> test_ints;
    test_ints.push_back(7);
    int counter = 0;
    for(List<int>::Iterator i = test_ints.begin(); i != test_ints.end(); ++i){
        ++counter;
    }
    ASSERT_TRUE(counter == 1);
}
TEST(test_iterator_no_elements) {
    List<int> test_ints;
    int counter = 0;
    for(List<int>::Iterator i = test_ints.begin(); i != test_ints.end(); ++i){
        ++counter;
    }
    ASSERT_TRUE(counter == 0);
}
TEST(test_iterator_increment) {
    List<int> test_ints;
    test_ints.push_back(7);
    test_ints.push_back(33);
    List<int>::Iterator i = test_ints.begin();
    ++i;
    ASSERT_TRUE(*i == test_ints.back());
}
TEST(test_iterator_increment_one_element) {
    List<int> test_ints;
    test_ints.push_back(7);
    List<int>::Iterator i = test_ints.begin();
    ++i;
    ASSERT_TRUE(i == test_ints.end());
}
TEST(test_iterator_begin_end_no_elements) {
    List<int> test_ints;
    List<int>::Iterator i = test_ints.begin();
    ASSERT_TRUE(i == test_ints.end());
}

TEST(test_iterator_erase) {
    List<int> test_ints;
    test_ints.push_back(7);
    test_ints.push_back(33);
    List<int>::Iterator i  = test_ints.begin();
    int k = test_ints.back();
    test_ints.erase(i);
    ASSERT_TRUE(test_ints.front() == k) ;
    ASSERT_TRUE(k == 33);
}
TEST(test_iterator_erase_one_elt) {
    List<int> test_ints;
    test_ints.push_back(7);
    List<int>::Iterator i  = test_ints.begin();
    test_ints.erase(i);
    int counter = 0;
    for(List<int>::Iterator i = test_ints.begin(); i != test_ints.end(); ++i){
        ++counter;
    }
    ASSERT_TRUE(counter == 0) ;
}

TEST(test_iterator_insert) {
    List<int> test_ints;
    test_ints.push_back(33);
    List<int>::Iterator i  = test_ints.begin();
    int k = 11;
    test_ints.insert(i, k);
    ASSERT_TRUE(test_ints.front() == k);
}

TEST(test_iterator_insert_zero) {
    List<int> test_ints;
    List<int>::Iterator i  = test_ints.begin();
    int k = 11;
    test_ints.insert(i, k);
    ASSERT_TRUE(test_ints.back() == k);
    ASSERT_TRUE(test_ints.front() == k);
    test_ints.clear();
    k = 12;
    i = test_ints.end();
    test_ints.insert(i, k);
    ASSERT_TRUE(test_ints.back() == k);
    ASSERT_TRUE(test_ints.front() == k);
}

TEST(test_iterator_equality) {
    List<int> test_ints;
    test_ints.push_back(18);
    test_ints.push_back(10);
    List<int>::Iterator i  = test_ints.begin();
     List<int>::Iterator k  = test_ints.begin();
    bool master = false;
    if (i == k){
        master = true;
    }
    ASSERT_TRUE(master == true);
    test_ints.clear();
    i  = test_ints.end();
    k  = test_ints.end();
    ASSERT_EQUAL(i, k);
}
TEST(test_iterator_equality_one_elt) {
    List<int> test_ints;
    test_ints.push_back(18);
    List<int>::Iterator i  = test_ints.begin();
     List<int>::Iterator k  = test_ints.end();
    bool master = false;
    ++i;
    if (i == k){
        master = true;
    }
    ASSERT_TRUE(master == true);
}

TEST(test_iterator_inequality) {
    List<int> test_ints;
    test_ints.push_back(18);
    test_ints.push_back(10);
    List<int>::Iterator i  = test_ints.begin();
    List<int>::Iterator k  = test_ints.end();
    bool master = false;
    if (i != k){
        master = true;
    }
    ASSERT_TRUE(master == true);
}

TEST(test_iterator_unary) {
    List<int> test_ints;
    test_ints.push_back(18);
    test_ints.push_back(10);
    List<int>::Iterator i  = test_ints.begin();
    int king = *i;
    ASSERT_TRUE(king == 18);
}
TEST_MAIN()
