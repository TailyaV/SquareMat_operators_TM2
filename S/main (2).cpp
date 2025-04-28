//taliyariel1@gmail.com
#include <iostream>
#include <cmath>
#include "SquareMat.hpp"

using namespace mat;

int main(){
    double arr1[4] = {4,6,10,2};
    SquareMat mat1(2, arr1, 4);
    double arr2[4] = {-2,7.5,-0.25,16};
    SquareMat mat2(2, arr2, 4);
    SquareMat res1 = mat1 + mat2;
    cout << "Result operator +: \n" << res1;
    SquareMat res2 = mat1 - mat2;
    cout << "Result operator -: \n" << res2;
    SquareMat res3 = -mat2;
    cout << "Result operator -: \n" << res3;
    SquareMat res4 = mat1 * mat2;
    cout << "Result operator *: \n" << res4;
    SquareMat res5 = mat2 * 5.5;
    cout << "Result operator *s: \n" << res5;
    SquareMat res6 = 5.5 * mat2;
    cout << "Result operator s*: \n" << res6;
    SquareMat res7 = mat1 % mat2;
    cout << "Result operator m%m: \n" << res7;
    SquareMat res8 = mat2 % 2;
    cout << "Result operator %: \n" << res8;
    SquareMat res9 = mat2 / 2;
    cout << "Result operator /: \n" << res9;
    SquareMat res10 = mat2 ^ 2;
    cout << "Result operator ^: \n" << res10;
    SquareMat res11 = mat2++;
    cout << "Result operator m++: \n" << res11;
    cout << "Matrix after operator m++: \n" << mat2;
    SquareMat res12 = ++mat2;
    cout << "Result operator ++m: \n" << res12;
    SquareMat res13 = mat2--;
    cout << "Result operator m--: \n" << res13;
    cout << "Matrix after operator m--: \n" << mat2;
    SquareMat res14 = --mat2;
    cout << "Result operator --m: \n" << res14;
    double arr3[9] = {-2,7.5,-0.25,16,4,-8,3.65,7.2,-9};
    SquareMat mat4(3, arr3, 9);
    cout << "mat4: \n" << mat4;
    SquareMat res15 = ~mat4;
    cout << "Result mat4 operator ~m: \n" << res15;
    SquareMat mat9(2, arr2, 4);
    double r = mat9[1][0];
    cout << "mat9 in index [1][0]:\n" << r << endl;
    mat9[0][0] = -3;
    cout << "print mat9 after  mat9[0][0] = -3\n" << mat9; 
    if(mat1 == mat2){
        cout << "Result operator mat1 == mat2: \n" << "true \n";
    }
    else
        cout << "Result operator mat1 == mat2: \n" << "false \n";
    if(mat1 != mat2){
        cout << "Result operator mat1 != mat2: \n" << "true \n";
    }
    else
        cout << "Result operator mat1 != mat2: \n" << "false \n";
    if(mat1 > mat2){
        cout << "Result operator mat1 > mat2: \n" << "true \n";
    }
    else
        cout << "Result operator mat1 > mat2: \n" << "false \n";
    if(mat1 < mat2){
        cout << "Result operator mat1 < mat2: \n" << "true \n";
    }
    else
        cout << "Result operator mat1 < mat2: \n" << "false \n";
    if(mat1 >= mat2){
        cout << "Result operator mat1 >= mat2: \n" << "true \n";
    }
    else
        cout << "Result operator mat1 >= mat2: \n" << "false \n";
    if(mat1 <= mat2){
        cout << "Result operator mat1 <= mat2: \n" << "true \n";
    }
    else
        cout << "Result operator mat1 <= mat2: \n" << "false \n";
    double res16 = !mat4;
    cout << "Result mat4 operator !m: \n" << round(res16 * 100.0) / 100.0 << endl;
    mat2 += mat1;
    cout << "Result mat2 operator +=: \n" << mat2;
    SquareMat mat5(2, arr2, 4);
    mat5 -= mat1;
    cout << "Result mat2 operator -=: \n" << mat5;
    SquareMat mat6(2, arr2, 4);
    mat6 /= 2.3;
    cout << "Result mat2 operator /=: \n" << mat6;
    SquareMat mat7(2, arr2, 4);
    mat7 *= mat1;
    cout << "Result mat2 operator *=: \n" << mat7;
    SquareMat mat8(2, arr2, 4);
    mat8 %= mat1;
    cout << "Result mat2 operator %=: \n" << mat8;
    SquareMat mat10(2, arr2, 4);
    mat10 *= -3.7;
    cout << "Result mat2 operator *=: \n" << mat10;
    SquareMat mat11(2, arr2, 4);
    mat11 %= 4;
    cout << "Result mat2 operator %=: \n" << mat11;
    return 0;
};