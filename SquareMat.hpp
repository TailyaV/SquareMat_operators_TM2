//taliyariel1@gmail.com
#pragma once

#include <iostream>

using namespace std;

namespace mat{
//Class that represent square matrix that contain size and 2D array. The class include operators that make action on the matix.
    class SquareMat{
        private:
            int size;
            double** matrix;
        public:
            SquareMat(int s);
            SquareMat(int s , double arr[], int sArr);
            ~SquareMat();
            SquareMat(const SquareMat& other);
            SquareMat& operator=(const SquareMat& other);
            int getSize()const{return size;}
            double** getMarix()const{return matrix;}
            double**& setMatrix(){return matrix;}
            SquareMat operator-()const;
            friend SquareMat operator+ (const SquareMat& a, const SquareMat& b);
            friend SquareMat operator- (const SquareMat& a, const SquareMat& b);
            friend SquareMat operator* (const SquareMat& a, const SquareMat& b);
            friend ostream& operator<< (ostream& output ,const SquareMat& a);
            SquareMat operator*(double scalar);
            friend SquareMat operator*(double scalar, const SquareMat& a);
            friend SquareMat operator%(const SquareMat& a, const SquareMat& b);
            SquareMat operator%(int scalar);
            SquareMat operator/(double scalar);
            SquareMat operator^(int sqr);
            SquareMat& operator++();
            SquareMat operator++(int i);
            SquareMat& operator--();
            SquareMat operator--(int);
            SquareMat operator+(double t);
            SquareMat operator~()const;
            const double* operator[](uint index)const;
            double*& operator[](uint index);
            friend bool operator==(const SquareMat& a, const SquareMat& b);
            friend bool operator!=(const SquareMat& a, const SquareMat& b);
            friend bool operator>(const SquareMat& a, const SquareMat& b);
            friend bool operator<(const SquareMat& a, const SquareMat& b);
            friend bool operator>=(const SquareMat& a, const SquareMat& b);
            friend bool operator<=(const SquareMat& a, const SquareMat& b);
            double operator!()const;
            SquareMat& operator+=(const SquareMat& other);
            SquareMat& operator-=(const SquareMat& other);
            SquareMat& operator/=(double scalar);
            SquareMat& operator*=(const SquareMat& other);
            SquareMat& operator%=(const SquareMat& other);
            SquareMat& operator*=(double scalar);
            SquareMat& operator%=(int scalar);
    };
}