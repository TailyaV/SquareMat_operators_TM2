//taliyarial1@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "SquareMat.hpp"
#include <string>
#include "doctest.h"

using namespace mat;

double EP = 1e-9;

//Class BeforeEach is for building a function that will happend befor each test.
class BeforeEach {
public:
double arr1[4] = {4.5,6,10,0};
double arr2[4] = {-2,7.5,-0.25,16};
    SquareMat mat1;
    SquareMat mat2;


    BeforeEach(): mat1(2, arr1, 4),mat2(2, arr2, 4) {}
};

TEST_CASE_FIXTURE(BeforeEach, "constractor") {
    double arr3[8] = {23,-7.5,-0.25,3.2, 8.8,-50,7,-5.1};
    CHECK_THROWS_AS(SquareMat mat3(3, arr3, 8), invalid_argument);
}

TEST_CASE_FIXTURE(BeforeEach, "operator +") {
    SquareMat res = mat1 + mat2;
    CHECK_EQ(res.getMarix()[0][1] , 13.50);
    double arr3[4] = {2.5,13.5,9.75,16};
    SquareMat mat3(2, arr3, 4);
    CHECK(res == mat3);
    double arr4[9] = {23,-7.5,-0.25,3.2, 8.8,-50,7,-5.1,6};
    SquareMat mat4(3, arr4, 9);
    CHECK_THROWS_AS(mat4 + mat1, invalid_argument);
}

TEST_CASE_FIXTURE(BeforeEach, "operator -") {
    SquareMat res = mat1 - mat2;
    CHECK_EQ(res.getMarix()[1][1] , -16.00);
    double arr3[4] = {6.5,-1.5,10.25,-16};
    SquareMat mat3(2, arr3, 4);
    CHECK(res == mat3);
    double arr4[9] = {23,-7.5,-0.25,3.2, 8.8,-50,7,-5.1,6};
    SquareMat mat4(3, arr4, 9);
    CHECK_THROWS_AS(mat4 - mat1, invalid_argument);
}

TEST_CASE_FIXTURE(BeforeEach, "operator -"){
    SquareMat res = -mat2;
    double arr3[4] = {2,-7.5,0.25,-16};
    SquareMat mat3(2, arr3, 4);
    CHECK(res == mat3);
}

TEST_CASE_FIXTURE(BeforeEach, "operator *"){
    SquareMat res = mat1 * mat2;
    double arr3[4] = {-10.5,129.75,-20,75};
    SquareMat mat3(2, arr3, 4);
    CHECK(res == mat3);
    double arr4[9] = {23,-7.5,-0.25,3.2, 8.8,-50,7,-5.1,6};
    SquareMat mat4(3, arr4, 9);
    CHECK_THROWS_AS(mat4 * mat1, invalid_argument);
}

TEST_CASE_FIXTURE(BeforeEach, "operator * s"){
    SquareMat res1 = 7.5 * mat2;
    SquareMat res2 = mat2 * 7.5;
    CHECK(res1 == res2);
    double arr3[4] = {-15,56.25,-1.875,120};
    SquareMat mat3(2, arr3, 4);
    CHECK(res1 == mat3);
}

TEST_CASE_FIXTURE(BeforeEach, "operator m%m"){
    SquareMat res = mat1 % mat2;
    double arr3[4] = {-9,45,-2.5,0};
    SquareMat mat3(2, arr3, 4);
    CHECK(res == mat3);
    double arr4[9] = {23,-7.5,-0.25,3.2, 8.8,-50,7,-5.1,6};
    SquareMat mat4(3, arr4, 9);
    CHECK_THROWS_AS(mat4 * mat1, invalid_argument);
}

TEST_CASE_FIXTURE(BeforeEach, "operator %"){
    SquareMat res1 = mat2 % 3;
    double arr3[4] = {1,1.5,2.75,1};
    SquareMat mat3(2, arr3, 4);
    CHECK(res1 == mat3);
}

TEST_CASE_FIXTURE(BeforeEach, "operator / s"){
    SquareMat res = mat2 / 3.2;
    double arr3[4] = {-0.625,2.34375,-0.078125,5};
    SquareMat mat3(2, arr3, 4);
    CHECK(res == mat3);
}

//what hapend with zero?
TEST_CASE_FIXTURE(BeforeEach, "operator ^ s"){
    SquareMat res = mat2 ^ 3;
    double arr3[4] = {-30.5,1695.9375,-56.53125,4039.75};
    SquareMat mat3(2, arr3, 4);
    CHECK(res == mat3);
    SquareMat res1 = mat2 ^ 1;
    CHECK(res1 == mat2);
    // SquareMat res2 = mat2 ^ 0;
    // CHECK_FALSE(!(res2 == mat2));
}

TEST_CASE_FIXTURE(BeforeEach, "operator ++"){
    SquareMat res1 = ++mat2;
    SquareMat res2 = mat2++;
    CHECK(res1 == res2);
    CHECK_FALSE(res2 == mat2);
    double arr3[4] = {0,9.5,1.75,18};
    SquareMat mat3(2, arr3, 4);
    CHECK(mat2 == mat3);
}

TEST_CASE_FIXTURE(BeforeEach, "operator --"){
    SquareMat res1 = --mat2;
    SquareMat res2 = mat2--;
    CHECK(res1 == res2);
    CHECK_FALSE(res2 == mat2);
    double arr3[4] = {-4,5.5,-2.25,14};
    SquareMat mat3(2, arr3, 4);
    CHECK(mat2 == mat3);
}

TEST_CASE_FIXTURE(BeforeEach, "operator +"){
    double arr3[4] = {0,9.5,1.75,18};
    SquareMat mat3(2, arr3, 4);
    SquareMat res1 = mat2 + 2;
    CHECK(mat3 == res1);
}

TEST_CASE_FIXTURE(BeforeEach, "operator ~"){
    double arr3[9] = {23,-7.5,-0.25,3.2, 8.8,-50,7,-5.1,6};
    SquareMat mat3(3, arr3, 9);
    SquareMat res1 = ~mat3;
    double arr4[9] = {23,3.2,7,-7.5,8.8,-5.1,-0.25,-50,6};
    SquareMat mat4(3, arr4, 9);
    CHECK(mat3 == mat4);
}

TEST_CASE_FIXTURE(BeforeEach, "operator []"){
    SquareMat matTemp(2, arr2, 4);
    double res = matTemp[0][1];
    CHECK(7.5 == res);
    matTemp[0][1] = -3.2;
    double res2 = matTemp[0][1];
    CHECK(-3.2 == res2);
    CHECK_THROWS_AS(matTemp[2][0], out_of_range);
}

TEST_CASE_FIXTURE(BeforeEach, "operator =="){
    SquareMat matTemp(2, arr2, 4);
    CHECK(mat2 == matTemp);
}

TEST_CASE_FIXTURE(BeforeEach, "operator !="){
    double arr2t[4] = {-2.0,7.5,-0.25,16};
    SquareMat matTemp(2, arr2t, 4);
    CHECK_FALSE(mat2 != matTemp);
}

TEST_CASE_FIXTURE(BeforeEach, "operator >"){
    double arr3[9] = {23,-7.5,-0.25,3.2, 8.8,-50,7,-5.1,6};
    SquareMat mat3(3, arr3, 9);
    CHECK(mat2 > mat3);
}

TEST_CASE_FIXTURE(BeforeEach, "operator <"){
    double arr3[9] = {23,-7.5,-0.25,3.2, 8.8,-50,7,-5.1,6};
    SquareMat mat3(3, arr3, 9);
    CHECK_FALSE(mat2 < mat3);
}

TEST_CASE_FIXTURE(BeforeEach, "operator >="){
    double arr3[9] = {23,-7.5,-0.25,3.2, 8.8,-50,7,-5.1,6};
    SquareMat mat3(3, arr3, 9);
    SquareMat mat4(3, arr3, 9);
    CHECK(mat2 >= mat3);
    CHECK(mat4 >= mat3);
}

TEST_CASE_FIXTURE(BeforeEach, "operator <="){
    double arr3[9] = {23,-7.5,-0.25,3.2, 8.8,-50,7,-5.1,6};
    SquareMat mat3(3, arr3, 9);
    SquareMat mat4(3, arr3, 9);
    CHECK_FALSE(mat2 <= mat3);
    CHECK(mat4 <= mat3);
}

TEST_CASE_FIXTURE(BeforeEach, "operator !"){
    double arr3[9] = {23,-7.5,-0.25,3.2, 8.8,-50,7,-5.1,6};
    SquareMat mat3(3, arr3, 9);
    double res = -1862.12;
    double res1 = !mat3;
    CHECK((res1 - res) < EP);
}

TEST_CASE_FIXTURE(BeforeEach, "operator +="){
    mat1 += mat2;
    double arr2t[4] = {2.5,13.5,9.75,16};
    SquareMat matTemp(2, arr2t, 4);
    CHECK_FALSE(mat1 != matTemp);
    double arr4[9] = {23,-7.5,-0.25,3.2, 8.8,-50,7,-5.1,6};
    SquareMat mat4(3, arr4, 9);
    CHECK_THROWS_AS(mat4 += mat1, invalid_argument);
}

TEST_CASE_FIXTURE(BeforeEach, "operator -="){
    mat1 -= mat2;
    double arr2t[4] = {6.5,-1.5,10.25,-16};
    SquareMat matTemp(2, arr2t, 4);
    CHECK_FALSE(mat1 != matTemp);
    double arr4[9] = {23,-7.5,-0.25,3.2, 8.8,-50,7,-5.1,6};
    SquareMat mat4(3, arr4, 9);
    CHECK_THROWS_AS(mat4 -= mat1, invalid_argument);
}

TEST_CASE_FIXTURE(BeforeEach, "operator *="){
    mat1 *= mat2;
    double arr2t[4] = {-10.5,129.75,-20,75};
    SquareMat matTemp(2, arr2t, 4);
    CHECK_FALSE(mat1 != matTemp);
    double arr4[9] = {23,-7.5,-0.25,3.2, 8.8,-50,7,-5.1,6};
    SquareMat mat4(3, arr4, 9);
    CHECK_THROWS_AS(mat4 *= mat1, invalid_argument);
}

TEST_CASE_FIXTURE(BeforeEach, "operator *="){
    mat2 *= 5.5;
    double arr2t[4] = {-11,41.25,-1.375,88};
    SquareMat matTemp(2, arr2t, 4);
    CHECK(mat2 == matTemp);
}

TEST_CASE_FIXTURE(BeforeEach, "operator /="){
    mat1 /= -2;
    double arr2t[4] = {-2.25,-3,-5,0};
    SquareMat matTemp(2, arr2t, 4);
    CHECK(mat1 == matTemp);
    CHECK_THROWS_AS(mat1 /= 0, invalid_argument);
}

TEST_CASE_FIXTURE(BeforeEach, "operator %="){
    mat1 %= mat2;
    double arr2t[4] = {-9,45,-2.5,0};
    SquareMat matTemp(2, arr2t, 4);
    CHECK_FALSE(mat1 != matTemp);
    double arr4[9] = {23,-7.5,-0.25,3.2, 8.8,-50,7,-5.1,6};
    SquareMat mat4(3, arr4, 9);
    CHECK_THROWS_AS(mat4 *= mat1, invalid_argument);
}

TEST_CASE_FIXTURE(BeforeEach, "operator %="){
    mat2 %= 5;
    double arr2t[4] = {3,2.5,4.75,1};
    SquareMat matTemp(2, arr2t, 4);
    CHECK(mat2 == matTemp);
}

TEST_CASE_FIXTURE(BeforeEach, "operator <<"){
    ostringstream osRes1;
    osRes1 << mat2;
    string res1 = osRes1.str();
    ostringstream osRes2;
    for(int i = 0; i < mat2.getSize(); i++){
        for(int j = 0; j < mat2.getSize(); j++){
            osRes2 << std::fixed << std::setprecision(2) << mat2.getMarix()[i][j] << " ";
        }
        osRes2 << endl;
    }
    string res2 = osRes2.str();
    CHECK(res1 == res2);
}

