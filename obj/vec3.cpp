    
    #include "vec3.h"
    
    vec3::vec3(float vx, float vy, float vz) 
    {
        vec[0] = vx; 
        vec[1] = vy;
        vec[2] = vz; 
    }


    vec3 vec3::operator+(const vec3 &v1) const  // addition
    {
        return vec3(vec[0] + v1[0], vec[1] + v1[1], vec[2] + v1[2]);
    }


    vec3 vec3::operator-(const vec3 &v1) const  // subtraction
    {
        return vec3(vec[0] - v1[0], vec[1] - v1[1], vec[2] - v1[2]);
    }

    vec3 vec3::operator*(const vec3 &v1) const  // multiplication (element-wise)
    {
        return vec3(vec[0] * v1[0], vec[1] * v1[1], vec[2] * v1[2]);
    }

    vec3 vec3::operator/(const vec3 &v1) const  // division (element-wise)
    {
        return vec3(vec[0] / v1[0], vec[1] / v1[1], vec[2] / v1[2]);
    }

    vec3 vec3::operator* (const float f1) const  // multiplication with a scalar
    {
        return vec3(vec[0] * f1, vec[1] * f1, vec[2] * f1);
    }

    vec3 operator* (const float f1, const vec3 &v1) // (the other way around [non-member fct.])
    {
        return v1*f1;
    }

    vec3 vec3::operator/(const float f1) const  // division with a scalar
    {
        return vec3( vec[0] / f1, vec[1] / f1, vec[2] / f1);
    }

    vec3 operator/ (const float f1, const vec3 &v1) // (the other way around [non-member fct.])
    {
        return v1 / f1;
    }

    // dot product
    float vec3::dot (const vec3 v1) const
    {
        return ( vec[0] * v1[0] +  vec[1] * v1[1] + vec[2] * v1[2]);
    } 

    vec3 vec3::cross (const vec3 v1) const
    {
        return vec3(vec[1] * v1[2] - v1[1] *vec[2], vec[2] * v1[0] - v1[2] * vec[0], vec[0] * v1[1] - v1[0] * vec[1]);
    }

   // I/O operators (friend functions) 
   std::istream& operator>> (std::istream &istr, vec3 &v1)
   {
       istr >> v1.vec[0] >> v1.vec[1] >> v1.vec[2];
       return istr; 
   }

   std::ostream& operator<< (std::ostream &ostr, const vec3 &v1) 
   {
       ostr << "(" <<v1.vec[0] << ", " << v1.vec[1] << ", " << v1.vec[2] << ")";
       return ostr;
   }


  // norm
  float vec3::length() const
  {
      return sqrt(vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);
  }

  float vec3::squaredLength() const
  {
      return (vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);
  }

  // normalize
  void vec3::normalize()
  {
      float vecNorm = this -> length();
      vec[0] = vec[0] / vecNorm;
      vec[1] = vec[1] / vecNorm;
      vec[2] = vec[2] / vecNorm;
  }



    // short-hand addition, subtraction, multiplication, division
   vec3& vec3::operator+= (const vec3 &v1)
   {
       vec[0] = vec[0] + v1[0];
       vec[1] = vec[1] + v1[1];
       vec[2] = vec[2] + v1[2];
       return *this;
    }

   vec3& vec3::operator-= (const vec3 &v1)
   {
       vec[0] = vec[0] - v1[0];
       vec[1] = vec[1] - v1[1];
       vec[2] = vec[2] - v1[2];
       return *this;
   }

   vec3& vec3::operator*= (const vec3 &v1)
   {
       vec[0] = vec[0] * v1[0];
       vec[1] = vec[1] * v1[1];
       vec[2] = vec[2] * v1[2];
       return *this;
   }

   vec3& vec3::operator/= (const vec3 &v1)
   {
       vec[0] = vec[0] / v1[0];
       vec[1] = vec[1] / v1[1];
       vec[2] = vec[2] / v1[2];
       return *this;
   }

   vec3& vec3::operator*= (const float f1)
   {
       vec[0] = vec[0] * f1;
       vec[1] = vec[1] * f1;
       vec[2] = vec[2] * f1;
       return *this;
   }

   vec3& vec3::operator/= (const float f1)
  {
       vec[0] = vec[0] / f1;
       vec[1] = vec[1] / f1;
       vec[2] = vec[2] / f1;
       return *this;
  }

  vec3 normalizeVector(const vec3 &v1)
  {
      float norm = v1.length();
      return v1/norm;
  }
