# 1 "dummy.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "dummy.cpp"
class Dummy {
public:
 static int x_;
 int y_;
};



int main()
{
 Dummy a;
 Dummy b;
 Dummy c;

 a.x_ = 100;

 a.y_ = 2;
 b.y_ = 3;
 c.y_ = 4;

 return a.y_ + b.y_ + c.y_;
}
