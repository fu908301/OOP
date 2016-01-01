/*
 * TITLE: OOP HW5
 * PURPOSE:Using dynamic arrays,implement a polynomial class with polynomial addition,subtraction,and multiplication
 * AUTHOR:CHENG-AN FU 
 * ID NUMBER:B023040018
 * DATE:2015/12/26
 * VERSION:3.0 fixed some invisible bug
 * LANGUAGE:C++
 */
#include <iostream>
#include <cmath>
using namespace std;

class Polynomial
{
public:
    //***** constructor *****
    Polynomial( double *Coeffs, int N_terms );
    Polynomial(const Polynomial & Sum);
    Polynomial();
    //***** destructor *****
    ~Polynomial();// destructor
    //***** functions *****
    double evaluate(double x);//find the value of P(x)
    void assign_coeff(double value, int index);//assign coefficient indexed by exponent
    double extract_coeff(int index);//extract coefficient indexed by exponent
    void print(void);//print the polynomial in descending order
    void kill(void);
    friend Polynomial operator + (Polynomial & P1,Polynomial & P2);
    friend Polynomial operator + (double value,Polynomial & P);
    friend Polynomial operator + (Polynomial & P,double value);
    friend Polynomial operator - (Polynomial & P1,Polynomial & P2);
    friend Polynomial operator - (double value,Polynomial & P);
    friend Polynomial operator - (Polynomial & P,double value);
    friend Polynomial operator * (Polynomial & P1,Polynomial & P2);
    friend Polynomial operator * (double value,Polynomial & P);
    friend Polynomial operator * (Polynomial & P,double value);
private:
    double* P_Coeff;//dynamic array of coefficients
    int N_elements;//number of elements in coefficient array
};
void Test(Polynomial& p1, Polynomial& p2);//Test Function
Polynomial::Polynomial(double *Coeffs,int N_terms)
{
  N_elements = N_terms;//malloc a new space for P_Coeff
  P_Coeff = new double[N_elements];
  for(int i = 0;i < N_elements;i++)
    P_Coeff[i] = Coeffs[i];
}
Polynomial::Polynomial(const Polynomial & Sum)//copy a class from Sum
{
  N_elements = Sum.N_elements;
  P_Coeff = new double [N_elements];
  for(int i = 0;i < N_elements;i++)
    P_Coeff[i] = Sum.P_Coeff[i];
}
Polynomial::Polynomial()//Default the polynomial to zero.
{
  P_Coeff = new double [1];
  N_elements = 1;
  P_Coeff[0] = 0.0;
}
Polynomial::~Polynomial()//delete P_Coeff
{
  delete P_Coeff;
}
void Polynomial::kill(void)
{
  delete P_Coeff;
}
double Polynomial::evaluate(double x)
{
  double answer = 0.0;//default
  for(int i = 0;i < N_elements;i++)
    answer += P_Coeff[i] * pow(x,(double)i);//answer = answer + coeffient * x ^ i;
  return answer;
}
void Polynomial::assign_coeff(double value,int index)
{
  double *temp_coeff;
  if(index < 0)//error handling
    cout<<"Can't assign value to coefficient by negative index!"<<endl;
  else if(index > N_elements - 1)//if the designated position is bigger than the original space
  {
    temp_coeff = new double[index + 1];//malloc a temp space to store what in P_Coeff
    for(int i = 0;i < N_elements;i++)
      temp_coeff[i] = P_Coeff[i];//store to the temp array
    P_Coeff = new double[index + 1];//malloc a new P_Coeff
    for(int i = 0;i < N_elements;i++)
      P_Coeff[i] = temp_coeff[i];//temp store back to P_Coeff
    P_Coeff[index] = value;//assign the new coefficient
    N_elements = index + 1;//N_elements change to the new index + 1 
    delete temp_coeff;//Kill the temp space
  }
  else//if the designated position is smaller than the original space 
    P_Coeff[index] = value;//directed change the value.
}
double Polynomial::extract_coeff(int index)
{
  if(index > N_elements - 1 || index < 0)//error handling
    cout<<"Illegal index! You should extract the coefficient by the index between 0 to "<<N_elements - 1<<"."<<endl;
  else
    return P_Coeff[index];//extract the element
}
void Polynomial::print(void)
{
  bool print_zero = true;
  for(int i = 0;i < N_elements;i++)//check if the array are all zero or not
  {
    if(P_Coeff[i] != 0)
      print_zero = false;
  }
  if(print_zero)//if the array are all array 
    cout<<"0"<<endl;//print zero
  else if(!print_zero)//the array not all elements are all 0
  {
    for(int i = N_elements - 1;i >= 0;i--)//print the standard output
    {
      if(i != 0 && P_Coeff[i] != 0)
        cout<<P_Coeff[i]<<"x^"<<i<<" + ";
      else if(i != 0 && P_Coeff == 0)
        i--;
      if(i == 0 && P_Coeff[i] != 0)
        cout<<P_Coeff[i]<<"x^"<<i<<endl;
      else if(i == 0 &&P_Coeff[i] == 0)
        break;
    }
  }
}
Polynomial operator + (Polynomial & P1,Polynomial & P2)//+ overload
{
  int N_terms;
  double *coeffs;
  if(P1.N_elements >= P2.N_elements)//if the elements in P1 > P2
  {
    N_terms = P1.N_elements;//take the count of the elements in P1
    coeffs = new double [N_terms];//new temp array
    for(int i = 0;i < N_terms;i++)
      coeffs[i] = P1.P_Coeff[i];//P1 -> temp
    for(int i = 0;i < P2.N_elements;i++)
      coeffs[i] += P2.P_Coeff[i];//temp = temp + P2 
    delete coeffs;
  }
  else if(P1.N_elements < P2.N_elements)//else if the elements in P2 > P1
  {
    N_terms = P2.N_elements;//do like front,just P1 change to P2,P2 change to P1
    coeffs = new double [N_terms];
    for(int i = 0;i < N_terms;i++)
      coeffs[i] = P2.P_Coeff[i];
    for(int i = 0;i < P1.N_elements;i++)
      coeffs[i] += P1.P_Coeff[i];
    delete coeffs;
  }
  return Polynomial(coeffs,N_terms);
}
Polynomial operator +(double value,Polynomial & P)//if value + P  
{ 
  double *coeffs = new double[P.N_elements];//malloc a temp space
  for(int i = 0;i < P.N_elements;i++)
    coeffs[i] = P.P_Coeff[i];//P -> temp
  coeffs[0] += value;//constant + value
  delete coeffs;//Kill the temp space
  return Polynomial(coeffs,P.N_elements);//return 
}
Polynomial operator +(Polynomial & P,double value)
{
  double *coeffs = new double[P.N_elements];//do as front
  for(int i = 0;i < P.N_elements;i++)
    coeffs[i] = P.P_Coeff[i];
  coeffs[0] += value;
  delete coeffs;
  return Polynomial(coeffs,P.N_elements);
}
Polynomial operator - (Polynomial & P1,Polynomial & P2)//do like what it do on + overload 
{
  int N_terms;
  double *coeffs;
  double *temp;
  if(P1.N_elements >= P2.N_elements)
  {
    N_terms = P1.N_elements;
    coeffs = new double [N_terms];
    for(int i = 0;i < N_terms;i++)
      coeffs[i] = P1.P_Coeff[i];
    for(int i = 0;i < P2.N_elements;i++)
      coeffs[i] -= P2.P_Coeff[i];
    delete coeffs;
  }
  else if(P1.N_elements < P2.N_elements)
  {
    N_terms = P2.N_elements;
    coeffs = new double[N_terms];
    temp = new double[N_terms];
    for(int i = 0;i < P1.N_elements;i++)
      temp[i] = P1.P_Coeff[i];
    for(int i = 0;i < N_terms;i++)
      coeffs[i] = P2.P_Coeff[i];
    for(int i = 0;i < N_terms;i++)
      coeffs[i] = temp[i] - coeffs[i];
    delete coeffs;
    delete temp;
  }
  return Polynomial(coeffs,N_terms);
}
Polynomial operator - (double value,Polynomial & P)//do like what it do on + overload
{
  double *coeffs = new double [P.N_elements];
  double *temp = new double [P.N_elements];
  temp[0] = value;
  for(int i = 0;i < P.N_elements;i++)
    coeffs[i] =temp[i] - P.P_Coeff[i];
  delete coeffs;
  delete temp;
  return Polynomial(coeffs,P.N_elements);
}
Polynomial operator - (Polynomial & P,double value)
{
  double *coeffs = new double [P.N_elements];
  for(int i = 0;i < P.N_elements;i++)
    coeffs[i] = P.P_Coeff[i];
  coeffs[0] -= value;
  delete coeffs;
  return Polynomial(coeffs,P.N_elements);
}
Polynomial operator * (Polynomial & P1,Polynomial & P2)//* overload
{
  int N_terms = (P1.N_elements - 1) + (P2.N_elements - 1) + 1;//max space
  double *coeffs = new double [N_terms];//malloc new space
  for (int i = 0;i < N_terms;i++)//default
    coeffs[i] = 0;
  for(int i = 0;i < P1.N_elements;i++)
  {
    for(int j = 0;j < P2.N_elements;j++)
    {
      coeffs[i + j] += P1.P_Coeff[i] * P2.P_Coeff[j];
    }
  }
  delete coeffs;//Kill temp space
  return Polynomial(coeffs,N_terms);//return 
}
Polynomial operator * (double value,Polynomial & P)//just multiply every elements
{
  double *coeffs = new double[P.N_elements];
  for(int i = 0;i < P.N_elements;i++)
    coeffs[i] = P.P_Coeff[i] * value;
  delete coeffs;
  return Polynomial(coeffs,P.N_elements);
}
Polynomial operator * (Polynomial & P,double value)
{
  double *coeffs = new double[P.N_elements]; 
  for(int i = 0;i < P.N_elements;i++)
   coeffs[i] = P.P_Coeff[i] * value;
  delete coeffs;
  return Polynomial(coeffs,P.N_elements);
}
int main(void)
{
    double Coeff1[4] = {12.5, 3.0, 0.0, 5.0};
    double Coeff2[3] = { 6.5, -5.5, -3.0};
    Polynomial P1 (Coeff1, sizeof(Coeff1) / sizeof(double));
    Polynomial P2 (Coeff2, sizeof(Coeff2) / sizeof(double));
    Test(P1,P2);
    return 0;
}
void Test(Polynomial &p1, Polynomial &p2)
{
    //Constructor
    cout << "[ Constructor ]" << endl;
    Polynomial Default_Sum;
    Polynomial Sum;
    cout << "Default_Sum = ";
    Default_Sum.print();
    Polynomial Sum1(p1);
    cout << "Copy_Sum = ";
    Sum1.print();
    cout << endl;
    //Show Polynomial Function 1 and 2
    cout << "[ Show Polynomial Function ]" << endl;
    cout << "P1 = ";
    p1.print();
    cout << "P2 = ";
    p2.print();
    cout << endl;
    cout << "[ Polynomial Addition ]" << endl;
    //P1 + P2
    Sum = p1 + p2;
    cout << "P1 + P2 = ";
    Sum.print();
    //Evaluate (P1 + P2) Function at x = 2.0
    cout << "P1 + P2(x=2.0) = " << Sum.evaluate(2.0) << endl;
    //P2 + P1
    Sum = p2 + p1;
    cout << "P2 + P1 = ";
    Sum.print();
    //Evaluate (P2 + P1) Function at x = 2.0
    cout << "P2 + P1(x=2.0) = " << Sum.evaluate(2.0) << endl;
    //constant + P1
    Sum = 100 + p1;
    cout << "100 + P1 = ";
    Sum.print();
    //P1 + constant
    Sum = p1 + (-100);
    cout << "P1 + (-100) = ";
    Sum.print();
    cout << endl;
    cout << "[ Polynomial Subtraction ]" << endl;
    //P1 - P2
    Sum = p1 - p2;
    cout << "P1 - P2 = ";
    Sum.print();
    //Evaluate (P1 - P2) Function at x = 2.0
    cout << "P1 - P2(x=2.0) = " << Sum.evaluate(2.0) << endl;
    //P2 - P1
    Sum = p2 - p1;
    cout << "P2 - P1 = ";
    Sum.print();
    //Evaluate (P2 - P1) Function at x = 2.0
    cout << "P2 - P1(x=2.0) = " << Sum.evaluate(2.0) << endl;
    //constant - P2
    Sum = 100 - p2;
    cout << "100 - P2 = ";
    Sum.print();
    //P2 - constant
    Sum = p2 - 100;
    cout << "P2 - 100 = ";
    Sum.print();
    cout << endl;
    cout << "[ Polynomial Multiplication ]" << endl;
    //P1 * P2
    Sum = p1 * p2;
    cout << "P1 * P2 = ";
    Sum.print();
    //Evaluate (P1 * P2) Function at x = 2.0
    cout << "P1 * P2(x=2.0) = " << Sum.evaluate(2.0) << endl;
    //P2 * P1
    Sum = p2 * p1;
    cout << "P2 * P1 = ";
    Sum.print();
    //Evaluate (P2 * P1) Function at x = 2.0
    cout << "P2 * P1(x=2.0) = " << Sum.evaluate(2.0) << endl;
    //constant * P1
    Sum = -100 * p1;
    cout << "-100 * P1 = ";
    Sum.print();
    //P1 * constant
    Sum = p1 * 10;
    cout << "P1 * 10 = ";
    Sum.print();
    cout << endl;
    //==========================================================

    //============== Assign and extract coefficients ==============
    cout << "[ Assign And Extract Coefficients ]" << endl;
    double temp_coeff;
    temp_coeff = Sum.extract_coeff(1);
    Sum.assign_coeff(temp_coeff,3);
    cout << "Sum = ";
    Sum.print();
    Sum.assign_coeff(temp_coeff,6);
    cout << "Sum = ";
    Sum.print();
    cout << "Sum(x=2.0) = " << Sum.evaluate(2.0) << endl;
    cout << endl;
    //=============================================================

    //========= Error Handling =========
    cout << "[ Error Handling ]" << endl;
    Sum.assign_coeff(1.234,-1);
    temp_coeff = Sum.extract_coeff(7);
    //==================================
}
