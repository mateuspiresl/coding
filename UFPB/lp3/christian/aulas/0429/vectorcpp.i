# 1 "vector.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "vector.cpp"
class Vector {

 float v_[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
 float mean_ = 0.0f;

 void setMean() {
  mean_ = (v_[0] + v_[1] + v_[2] + v_[3]) * 0.25f;
 }

public:
# 26 "vector.cpp"
 Vector(float v0, float v1, float v2, float v3) :
  v_ { v0, v1, v2, v3 } {
  setMean();
 }

 Vector() { }
 ~Vector() { }

 void setValues(float v0, float v1, float v2, float v3) {
  v_[0] = v0;
  v_[1] = v1;
  v_[2] = v2;
  v_[3] = v3;
  setMean();
 }

 void getValues(float* v0, float* v1, float* v2, float* v3) const {
  *v0 = v_[0];
  *v1 = v_[1];
  *v2 = v_[2];
  *v3 = v_[3];
 }

 float getMean() {
  return mean_;
 }

 void copyFrom(const Vector* a) {
  v_[0] = a->v_[0];
  v_[1] = a->v_[1];
  v_[2] = a->v_[2];
  v_[3] = a->v_[3];
  mean_ = a->mean_;
 }

 void sum(const Vector* a) {
  v_[0] += a->v_[0];
  v_[1] += a->v_[1];
  v_[2] += a->v_[2];
  v_[3] += a->v_[3];
  mean_ += a->mean_;
 }
};


class Color {
public:
 const Vector rgba_;
};


int main()
{
 Color c;


 return c.rgba_.getMean() * 100;
}
