#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "stack.h"

void test_initStack(void) {
    Stack s;
    initStack(&s);
    CU_ASSERT_PTR_NULL(s.top);
}

void test_push_and_getTop(void) {
    Stack s;
    initStack(&s);

    push(&s, 10);
    CU_ASSERT_PTR_NOT_NULL(s.top);
    CU_ASSERT_EQUAL(getTop(&s)->data, 10);

    push(&s, 20);
    CU_ASSERT_EQUAL(getTop(&s)->data, 20);
}

void test_pop(void) {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);

    pop(&s);
    CU_ASSERT_EQUAL(getTop(&s)->data, 10);

    pop(&s);
    CU_ASSERT_PTR_NULL(getTop(&s));
}

void test_searchByValue(void) {
    Stack s;
    initStack(&s);

    push(&s, 5);
    push(&s, 10);
    push(&s, 15);

    CU_ASSERT_PTR_NOT_NULL(searchByValue(&s, 10));
    CU_ASSERT_PTR_NULL(searchByValue(&s, 999));
}

void test_searchByIndex(void) {
    Stack s;
    initStack(&s);

    push(&s, 1);  // index 0
    push(&s, 2);  // index 1
    push(&s, 3);  // index 2

    CU_ASSERT_EQUAL(searchByIndex(&s, 0)->data, 3);
    CU_ASSERT_EQUAL(searchByIndex(&s, 1)->data, 2);
    CU_ASSERT_EQUAL(searchByIndex(&s, 2)->data, 1);
    CU_ASSERT_PTR_NULL(searchByIndex(&s, 10));
}

void test_isEmpty(void) {
    Stack s;
    initStack(&s);
    CU_ASSERT_TRUE(isEmpty(&s));

    push(&s, 123);
    CU_ASSERT_FALSE(isEmpty(&s));
}

void test_destroyStack(void) {
    Stack s;
    initStack(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    destroyStack(&s);

    CU_ASSERT_PTR_NULL(s.top);
}


int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("Stack tests", 0, 0);

    CU_add_test(suite, "initStack", test_initStack);
    CU_add_test(suite, "push & getTop", test_push_and_getTop);
    CU_add_test(suite, "pop", test_pop);
    CU_add_test(suite, "searchByValue", test_searchByValue);
    CU_add_test(suite, "searchByIndex", test_searchByIndex);
    CU_add_test(suite, "isEmpty", test_isEmpty);
    CU_add_test(suite, "destroyStack", test_destroyStack);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}