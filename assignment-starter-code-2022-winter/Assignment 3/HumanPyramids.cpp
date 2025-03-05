#include "HumanPyramids.h"
#include "error.h"
#include "map.h"
using namespace std;

/* TODO: Refer to HumanPyramids.h for more information about what this function should do.
 * Then, delete this comment.
 */

double weightOnBackOfRec(int row, int col, int pyramidHeight, Map<pair<int, int>, double> &weightdata) {
    pair<int, int> position = {row, col};
    if (row == 0 && col == 0){
        return 0;
    } else if (weightdata.containsKey(position)){
        return weightdata[position];
    } else {
        if (col == 0) {
            double temp = weightOnBackOfRec(row - 1, col, pyramidHeight-1, weightdata) + 80;
            weightdata[position] = temp;
            return temp;
        } else if (row == col) {
            double temp = weightOnBackOfRec(row - 1, col - 1, pyramidHeight-1, weightdata) + 80;
            weightdata[position] = temp;
            return temp;
        } else {
            double temp = weightOnBackOfRec(row - 1, col - 1, pyramidHeight-1, weightdata)/2 +weightOnBackOfRec(row - 1, col, pyramidHeight-1, weightdata)/2 + 160;
            weightdata[position] = temp;
            return temp;
        }
    }
}
double weightOnBackOf(int row, int col, int pyramidHeight) {
    if (row < 0 || col < 0 || col > row || row+1 > pyramidHeight || col+1 > pyramidHeight){
        error("position wrong");
    }
    Map <pair<int, int>, double> weightdata;
    return weightOnBackOfRec(row, col, pyramidHeight, weightdata);
}





/* * * * * * Test Cases * * * * * */
#include "GUI/SimpleTest.h"

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.*/
STUDENT_TEST("for test"){
    EXPECT(weightOnBackOf(1000, 333, 1500) >=10000 );
}













/* * * * * * Test cases from the starter files below this point. * * * * * */

PROVIDED_TEST("Check Person E from the handout.") {
    /* Person E is located at row 2, column 1. */
    EXPECT_EQUAL(weightOnBackOf(2, 1, 5), 240);
}

PROVIDED_TEST("Function reports errors in invalid cases.") {
    EXPECT_ERROR(weightOnBackOf(-1, 0, 10));
    EXPECT_ERROR(weightOnBackOf(10, 10, 5));
    EXPECT_ERROR(weightOnBackOf(-1, 10, 20));
}

PROVIDED_TEST("Stress test: Memoization is implemented (should take under a second)") {
    /* TODO: Yes, we are asking you to make a change to this test case! Delete the
     * line immediately after this one - the one that starts with SHOW_ERROR - once
     * you have implemented memoization to test whether it works correctly.
     */

    /* Do not delete anything below this point. :-) */

    /* This will take a LONG time to complete if memoization isn't implemented.
     * We're talking "heat death of the universe" amounts of time. :-)
     *
     * If you did implement memoization but this test case is still hanging, make
     * sure that in your recursive function (not the wrapper) that your recursive
     * calls are to your new recursive function and not back to the wrapper. If you
     * call the wrapper again, you'll get a fresh new memoization table rather than
     * preserving the one you're building up in your recursive exploration, and the
     * effect will be as if you hadn't implemented memoization at all.
     */
    EXPECT(weightOnBackOf(100, 50, 200) >= 10000);
}

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */
