//taliyariel1@gmail.com
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "SquareMat.hpp"

using namespace mat;

namespace mat{

// Constructor - Creates a square matrix of given size with all elements initialized to 0.
SquareMat::SquareMat(int s){
    size = s;
    matrix = new double*[s];
    for(int i = 0; i < size; i++){
        matrix[i] = new double[s];
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matrix[i][j] = 0.00;
        }
    }
}

// Constructor- Creates a square matrix from a given array.
SquareMat::SquareMat(int s , double arr[], int sArr){
    if((s*s) != sArr){
        throw invalid_argument("Arry and matrix size is not valid for square matrix");
    }
    size = s;
    matrix = new double*[s];
    for(int i = 0; i < size; i++){
        matrix[i] = new double[s];
    }
    int k = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(k > sArr){
                matrix[i][j] = 0.00;
            }
            else{
                matrix[i][j] = arr[k];
            }
            k++;
        }
    }
}

// Destructor- free memory used by the matrix.
SquareMat::~SquareMat(){
    for(int i = 0; i < size; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Copy constructor- Creates a deep copy of another SquareMat.
SquareMat::SquareMat(const SquareMat& other){
    size = other.size;
    matrix = new double*[size];
    for(int i = 0; i < size; i++){
        matrix[i] = new double[size];
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matrix[i][j] = other.matrix[i][j];
        }
    }

}

// Placement operator: Assigns one SquareMat to another.
SquareMat& SquareMat::operator=(const SquareMat& other){
    if(this == &other){
        return *this;
    }
    size = other.size;
    for(int i = 0; i < size; i++){
        delete[] matrix[i];
    }
    delete[] matrix;

    matrix = new double*[size];
    for(int i = 0; i < size; i++){
        matrix[i] = new double[size];
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matrix[i][j] = other.matrix[i][j];
        }
    }
    return *this;
}

// Operator +, Adds two matrices element-wise.
SquareMat operator+(const SquareMat& a, const SquareMat& b){
    if(a.getSize() != b.getSize()){
        throw std::invalid_argument("matrix are not the same size");
    }
    int s = a.getSize();
    int sArr = s*s;
    double arr[s*s];
    int k = 0;
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            arr[k] = a.getMarix()[i][j] + b.getMarix()[i][j];
            k++;
        }
    }
    SquareMat res(s, arr, sArr);
    return res;
}

// Operator -, Subtracts matrix b from matrix a element-wise.
SquareMat operator-(const SquareMat& a, const SquareMat& b){
    if(a.getSize() != b.getSize()){
        throw std::invalid_argument("matrix are not the same size");
    }
    int s = a.getSize();
    int sArr = s*s;
    double arr[s*s];
    int k = 0;
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            arr[k] = a.getMarix()[i][j] - b.getMarix()[i][j];
            k++;
        }
    }
    SquareMat res(s, arr, sArr);
    return res;
}

// Unary operator -, Negates all elements of the matrix.
SquareMat SquareMat::operator-()const {
    SquareMat res(*this);
    for (int i = 0; i < res.size; ++i) {
        for (int j = 0; j < res.size; ++j) {
            res.matrix[i][j] = -(res.matrix[i][j]);
        }
    }
    return res;
}

// Operator *, Multiplies two square matrices.
SquareMat operator*(const SquareMat& a, const SquareMat& b){
    if(a.getSize() != b.getSize()){
        throw std::invalid_argument("matrix are not the same size");
    }
    int s = a.getSize();
    SquareMat res(s);
    double sum = 0;
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            for(int k = 0; k < s; k++){
                 sum = sum + (a.getMarix()[i][k] * b.getMarix()[k][j]);
            }
            res.setMatrix()[i][j] = sum;
            sum = 0;
        }
    }
    return res;
}

// Scalar multiplication, Multiplies matrix by a scalar.
SquareMat SquareMat::operator*(double scalar){
    SquareMat res(*this);
    int s = res.getSize();
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            res.matrix[i][j] = scalar * this->matrix[i][j];
        }
    }
    return res;
}

// Scalar multiplication, Multiplies matrix by a scalar (scalar * matrix).
SquareMat operator*(double scalar, const SquareMat& a){
    SquareMat res(a);
    return (res * scalar);
}

// Element-wise multiplication using % operator.
SquareMat operator%(const SquareMat& a, const SquareMat& b){
    if(a.getSize() != b.getSize()){
        throw invalid_argument("Matrix ate not the same size");
    }
    int s = a.getSize();
    int sArr = s*s;
    double arr[s*s];
    int k = 0;
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            arr[k] = a.getMarix()[i][j] * b.getMarix()[i][j];
            k++;
        }
    }
    SquareMat res(s, arr, sArr);
    return res;
}

// Element-wise modulo of matrix with scalar.
SquareMat SquareMat::operator%(int scalar){
    SquareMat res(*this);
    int s = res.getSize();
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            res.matrix[i][j] = fmod(this->matrix[i][j], scalar);
            if(res.matrix[i][j] < 0){
                res.matrix[i][j] = res.matrix[i][j] + scalar;
            }
        }
    }
    return res;
}

// Scalar division, Divides all matrix elements by a scalar.
SquareMat SquareMat::operator/(double scalar){
    if(scalar == 0){
        throw invalid_argument("Cant divide in zero");
    }
    SquareMat res(*this);
    int s = res.getSize();
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            res.matrix[i][j] = this->matrix[i][j] / scalar;
        }
    }
    return res;
}

// Matrix exponentiation, Raises the matrix to the power of an integer.
SquareMat SquareMat::operator^(int sqr){
    SquareMat res(*this);
    int s = this->getSize();
    if(sqr == 0){
        for(int i = 0; i < s; i++){
            for(int j = 0; j < s; j++){
                res.matrix[i][j] = 1;
            }
        }
        return res;
    }
    for(int i = 0; i < sqr - 1; i++){
        res = res * (*this);
    }
    return res;
}

// Scalar addition, Adds a scalar to each element in the matrix.
SquareMat SquareMat::operator+(double t){
    SquareMat res(*this);
    int s = this->getSize();
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            res.matrix[i][j] = res.matrix[i][j] + t;
        }
    }
    return res;
}

// Prefix increment, Increases all elements of the matrix by 1.
SquareMat& SquareMat::operator++(){
    *this = *this + 1;
    return *this;
}

// Postfix increment, Increases all elements of the matrix by 1 (returns original).
SquareMat SquareMat::operator++(int){
    SquareMat temp(*this);
    *this = *this + 1;
    return temp;
}

// Prefix decrement, Decreases all elements of the matrix by 1.
SquareMat& SquareMat::operator--(){
    *this = *this + (-1);
    return *this;
}


// Postfix decrement, Decreases all elements of the matrix by 1 (returns original).
SquareMat SquareMat::operator--(int){
    SquareMat temp(*this);
    *this = *this + (-1);
    return temp;
}

// Transpose operator, Returns the transpose of the matrix.
SquareMat SquareMat::operator~()const{
    SquareMat res(*this);
    int s = this->getSize();
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            res.matrix[i][j] = this->matrix[j][i];
        }
    }
    return res;
}

// Indexing operator, Returns reference to a specific row (non-const) for seting.
double*& SquareMat::operator[](uint index){
    if((int)index >= this->getSize()){
        throw out_of_range("given invalid index");
    }
    return this->matrix[index];
}

// Indexing operator, Returns const pointer to a specific row (const) for get.
const double* SquareMat::operator[](uint index)const{
    if((int)index >= this->getSize()){
        throw out_of_range("given invalid index");
    }
    return this->matrix[index];
}

// Equality operator, Compares matrices based on sum of all elements.
bool operator==(const SquareMat& a, const SquareMat& b){
    if(a.getSize() != b.getSize()){
        throw std::invalid_argument("matrix are not the same size");
    }
    double sum1 = 0;
    double sum2 = 0;
    int s = a.getSize();
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            sum1 = sum1 + a.matrix[i][j];
            sum2 = sum2 + b.matrix[i][j];
        }
    }
    return (sum1 == sum2);
}

// Inequality operator, Opposite of equality.
bool operator!=(const SquareMat& a, const SquareMat& b){
    return !(a == b);
}

// Greater than operator, Compares matrices based on sum of all elements.
bool operator>(const SquareMat& a, const SquareMat& b){
    double sum1 = 0;
    double sum2 = 0;
    int s = a.getSize();
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            sum1 = sum1 + a.matrix[i][j];
        }
    }
    int s2 = b.getSize();
    for(int i = 0; i < s2; i++){
        for(int j = 0; j < s2; j++){
            sum2 = sum2 + b.matrix[i][j];
        }
    }
    return (sum1 > sum2);
}

// Less than or equal to operator.
bool operator<=(const SquareMat& a, const SquareMat& b){
    return !(a > b);
}

// Less than operator.
bool operator<(const SquareMat& a, const SquareMat& b){
    double sum1 = 0;
    double sum2 = 0;
    int s = a.getSize();
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            sum1 = sum1 + a.matrix[i][j];
        }
    }
    int s2 = b.getSize();
    for(int i = 0; i < s2; i++){
        for(int j = 0; j < s2; j++){
            sum2 = sum2 + b.matrix[i][j];
        }
    }
    return (sum1 < sum2);
}

// Greater than or equal to operator.
bool operator>=(const SquareMat& a, const SquareMat& b){
    return !(a < b);
}

// Determinant operator, Calculates the determinant of the matrix.
double SquareMat::operator!()const{
    int s = this->getSize();
    if (s == 1)
        return this->matrix[0][0];
    if (s == 2)
        return this->matrix[0][0]*this->matrix[1][1] - this->matrix[0][1]*this->matrix[1][0];
    double det = 0;
    for (int col = 0; col < s; col++) {
        double subMat[(s - 1)*(s - 1)];
        int index = 0;
        for (int i = 1; i < s; i++) {
            for (int j = 0; j < s; j++) {
                if (j != col) {
                subMat[index] = this->matrix[i][j];
                index = index + 1;
                }
            }
        }
        SquareMat temp(s - 1, subMat, (s - 1)*(s - 1));
        if(col % 2 == 0){
            det = det + this->matrix[0][col] * !(temp);
        }
        else{
            det = det + (-1) * this->matrix[0][col] * !(temp);
        }
    }
    return det;
}

// In-place matrix addition.
SquareMat& SquareMat::operator+=(const SquareMat& other){
    if(this->getSize() != other.getSize()){
        throw invalid_argument("Matrix ate not the same size");
    }
    int s = this->getSize();
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            this->matrix[i][j] = this->matrix[i][j] + other.matrix[i][j];
        }
    }
    return *this;
}

// In-place matrix subtraction.
SquareMat& SquareMat::operator-=(const SquareMat& other){
    if(this->getSize() != other.getSize()){
        throw invalid_argument("Matrix ate not the same size");
    }
    int s = this->getSize();
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            this->matrix[i][j] = this->matrix[i][j] - (other.matrix[i][j]);
        }
    }
    return *this;
}

// In-place division by scalar(throws if scalar is 0).
SquareMat& SquareMat::operator/=(double scalar){
    if(scalar == 0){
        throw invalid_argument("Divide marix cant include zero");
    }
    int s = this->getSize();
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            this->matrix[i][j] = this->matrix[i][j] / scalar;
        }
    }
    return *this;
}

// In-place matrix multiplication.
SquareMat& SquareMat::operator*=(const SquareMat& other){
    if(this->getSize() != other.getSize()){
        throw invalid_argument("Matrix ate not the same size");
    }
    SquareMat temp = (*this) * other;
    *this = temp;
    return *this;
}

// In-place element-wise multiplication.
SquareMat& SquareMat::operator%=(const SquareMat& other){
    if(this->getSize() != other.getSize()){
        throw invalid_argument("Matrix ate not the same size");
    }
    SquareMat temp = (*this) % other;
    *this = temp;
    return *this;
}

// In-place power by scalar.
SquareMat& SquareMat::operator*=(double scalar){
    int s = this->getSize();
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            this->matrix[i][j] = this->matrix[i][j] * scalar;
        }
    }
    return *this;
}

// In-place modol by scalar.
SquareMat& SquareMat::operator%=(int scalar){
    int s = this->getSize();
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            this->matrix[i][j] = fmod(this->matrix[i][j], scalar);
            if(this->matrix[i][j] < 0){
                this->matrix[i][j] = this->matrix[i][j] + scalar;
            }
        }
    }
    return *this;
}

// Stream output operator, Outputs the matrix as a formatted string.
ostream& operator<<(ostream& output ,const SquareMat& a){
    int size = a.getSize();
    std::ostringstream s;
    for(int j = 0; j < size; j++){
        for(int k = 0; k < size; k++){
            s << std::fixed << std::setprecision(2) << a.getMarix()[j][k] << " ";
        }
        s << endl;
    }
    string str = s.str();
    return (output << str);
}

}
