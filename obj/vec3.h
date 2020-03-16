#include <math.h>
#include <stdlib.h>
#include <iostream>

#ifndef VEC3_H
#define VEC3_H

class vec3
{

 private:
    float vec[3];

 public:
    // constructor 1
    vec3() {}

    // constructor 2 (with float input)
    vec3(float vx, float vy, float vz);

    // element return functions
    inline float x() const { return vec[0]; }   // vec3.x()
    inline float y() const { return vec[1]; }
    inline float z() const { return vec[2]; }

    inline float r() const { return vec[0]; }
    inline float g() const { return vec[1]; }
    inline float b() const { return vec[2]; }


    // acessing elements '[]'
    inline float operator[](int i) const{ return vec[i]; }
    inline float& operator[](int i) { return vec[i]; }
    

    // +/- sign operators
    inline const vec3& operator+() const {return *this; };
    inline vec3 operator-() const { return vec3(-vec[0], -vec[1], -vec[2]); };

    // basic vector math
    vec3 operator+(const vec3 &v1) const;  // addition
    vec3 operator-(const vec3 &v1) const;  // subtraction
    vec3 operator*(const vec3 &v1) const;  // multiplication (element wise)
    vec3 operator/(const vec3 &v1) const;  // division (element wise)

    vec3 operator* (const float f1) const; // multiplication with a scalar
    vec3 operator/(const float f1) const; // division with a scalar

   // dot product
   float dot (const vec3 v1) const; 

   // cross product
   vec3 cross (const vec3 v1) const;

   // vector norm
   float length() const;
   float squaredLength() const;

   // normalize vector
   void normalize();

   // iostream connection
   friend std::istream& operator>> (std::istream &istr, vec3 &v1);
   friend std::ostream& operator<< (std::ostream &ostr, const vec3 &v1);

   // short-hand addition, subtraction, multiplication, division
   vec3& operator+= (const vec3 &v1);
   vec3& operator-= (const vec3 &v1);
   vec3& operator*= (const vec3 &v1);
   vec3& operator/= (const vec3 &v1);
   vec3& operator*= (const float f1);
   vec3& operator/= (const float f1);      
};


// non-member functions
vec3 operator* (const float f1,  const vec3 &v1);  // multiplication with scalar (other way around)
vec3 operator/ (const float f1,  const vec3 &v1);  // division with scalar (other way around)

vec3 normalizeVector(const vec3 &v1);

#endif