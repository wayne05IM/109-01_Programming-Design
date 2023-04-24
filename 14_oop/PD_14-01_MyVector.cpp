// ===========================================================================
// MyVector, MyVector2D, and NNMyVector2D
// ===========================================================================
#include <iostream>
#include <cstdlib>
using namespace std;

// The definition of MyVector
class MyVector
{
friend const MyVector operator+(const MyVector& v, double d);
protected:
  int n; 
  double* m; 
public:
  MyVector();
  MyVector(int n, double m[]);  
  MyVector(const MyVector& v);
  ~MyVector();
  void print() const; 
  
  bool operator==(const MyVector& v) const;
  bool operator!=(const MyVector& v) const;
  bool operator<(const MyVector& v) const;
  double operator[](int i) const;
  double& operator[](int i);
  const MyVector& operator=(const MyVector& v);
  const MyVector& operator+=(const MyVector& v);
};

MyVector::MyVector(): n(0), m(nullptr)
{
}
MyVector::MyVector(int n, double m[])
{
  this->n = n;
  this->m = new double[n];
  for(int i = 0; i < n; i++)
    this->m[i] = m[i];
}
MyVector::MyVector(const MyVector& v)
{
  this->n = v.n;
  this->m = new double[n];
  for(int i = 0; i < n; i++)
    this->m[i] = v.m[i];	
}
MyVector::~MyVector() 
{ 
  delete [] m; 
}
void MyVector::print() const 
{
  cout << "(";
  for(int i = 0; i < n - 1; i++)
    cout << m[i] << ", ";
  cout << m[n-1] << ")\n";
}
bool MyVector::operator==(const MyVector& v) const
{
  if(this->n != v.n)
    return false;
  else
  {
    for(int i = 0; i < n; i++)
    {
      if(this->m[i] != v.m[i])
      return false;
    }
  }	
  return true;
}
bool MyVector::operator!=(const MyVector& v) const
{
  return !(*this == v);
}
bool MyVector::operator<(const MyVector& v) const
{
  if(this->n != v.n)
    return false;
  else
  {
  	for(int i = 0; i < n; i++)
  	{
  	  if(this->m[i] >= v.m[i])
  	    return false;
  	}
  }	
  return true;
}
double MyVector::operator[](int i) const
{
  if(i < 0 || i >= n)
    exit(1);
  return m[i];
}
double& MyVector::operator[](int i) 
{
  if(i < 0 || i >= n)
    exit(1);
  return m[i];
}
const MyVector& MyVector::operator=(const MyVector& v)
{
  if(this != &v)
  {
    if(this->n != v.n)
    {
      delete [] this->m;
      this->n = v.n;
      this->m = new double[this->n];
    }
    for(int i = 0; i < n; i++)
      this->m[i] = v.m[i];
  }  
  return *this;
}
const MyVector& MyVector::operator+=(const MyVector& v)
{
  if(this->n == v.n)
  {
    for(int i = 0; i < n; i++)
      this->m[i] += v.m[i]; 
  }
  return *this;
}
// end of the definition of MyVector






// The definition of MyVector2D
class MyVector2D : public MyVector
{
public:
  MyVector2D();
  MyVector2D(double m[]);  
  void setValue(double i1, double i2);
};

MyVector2D::MyVector2D()
{
  this->n = 2;
}
MyVector2D::MyVector2D(double m[]) : MyVector(2, m)
{
}
void MyVector2D::setValue(double i1, double i2)
{
  if(this->m == nullptr)
  {
    this->m = new double[2];
  }
  this->m[0] = i1;
  this->m[1] = i2;
}
// end of the definition of MyVector2D










// The definition of NNVector2D
class NNVector2D : public MyVector2D
{
public:
  NNVector2D(); 
  NNVector2D(double m[]);  
  void setValue(double i1, double i2);
};

NNVector2D::NNVector2D()
{
}
NNVector2D::NNVector2D(double m[])
{
  this->m = new double[2];
  this->m[0] = m[0] >= 0 ? m[0] : 0;
  this->m[1] = m[1] >= 0 ? m[1] : 0;  
}
void NNVector2D::setValue(double i1, double i2)
{
  if(this->m == nullptr)
    this->m = new double[2];
  this->m[0] = i1 >= 0 ? i1 : 0;
  this->m[1] = i2 >= 0 ? i2 : 0;  
}
// end of the definition of NNVector2D






// Global functions headers
const MyVector operator+(const MyVector& v, double d);
const MyVector operator+(double d, const MyVector& v);
const MyVector operator+(const MyVector& v1, const MyVector& v2);
// end of global function headers









// Global function definitions
const MyVector operator+(const MyVector& v, double d)
{
  MyVector sum(v);
  for(int i = 0; i < v.n; i++)
    sum[i] += d;
  return sum;
}
const MyVector operator+(double d, const MyVector& v)
{
  return v + d;
}
const MyVector operator+(const MyVector& v1, const MyVector& v2)
{
  MyVector sum(v1); 
  return sum += v2;
}
// end of global function definitions
// ===========================================================================
// End of MyVector, MyVector2D, and NNMyVector2D
// ===========================================================================