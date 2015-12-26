#include <iostream>
#include <cmath>
using namespace std;

class Polynomial
{
public:
    //***** constructor *****
    //1.default constructor, initialize the polynomial to 0
    //2.Initialize the polynomial with the given constant
    //3.parameterized construction
	//Input1: Coeffs[] is the coefficient array of polynomial
	//Input2: N_terms is the number of elements in Coeffs[]
  //4.the copy construcor
    Polynomial( double Coeffs[], int N_terms );
    Polynomial(Polynomial & Sum);
    Polynomial();
    //***** destructor *****
    ~Polynomial();// destructor
	
    //***** functions *****
    double evaluate(double x);//find the value of P(x)
    void assign_coeff(double value, int index);//assign coefficient indexed by exponent
    double extract_coeff(int index);//extract coefficient indexed by exponent
    void print(void);//print the polynomial in descending order
private:
    double* P_Coeff;//dynamic array of coefficients
    int N_elements;//number of elements in coefficient array
};
void Test(Polynomial& p1, Polynomial& p2);//Test Function
Polynomial::Polynomial(double Coeffs[],int N_terms)
{
  N_elements = N_terms;
  P_Coeff = new double[N_elements];
  for(int i = 0;i < N_elements;i++)
    P_Coeff[i] = Coeffs[i];
}
Polynomial::Polynomial(Polynomial &Sum)
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
Polynomial::~Polynomial()
{
  delete P_Coeff;
}
double Polynomial::evaluate(double x)
{
  double answer = 0.0;
  for(int i = 0;i < N_elements;i++)
    answer += P_Coeff[i] * pow(x,(double)i);
  return answer;
}
void Polynomial::assign_coeff(double value,int index)
{
  if(index < 0)
    cout<<"Can't assign value to coefficient by negative index!"<<endl;
  else if(index > N_elements - 1)
  {
    double temp_coeff[index];
    for(int i = 0;i < N_elements;i++)
      temp_coeff[i] = P_Coeff[i];
    delete P_Coeff;
    P_Coeff = new double[index+1];
    for(int i = 0;i < N_elements;i++)
      P_Coeff[i] = temp_coeff[i];
    P_Coeff[index] = value;
    N_elements = sizeof(P_Coeff) / sizeof(double);
  }
  else 
    P_Coeff[index] = value;
}
double Polynomial::extract_coeff(int index)
{
  if(index > N_elements - 1 || index < 0)
    cout<<"Illegal index! You should extract the coefficient by the index between 0 to "<<N_elements - 1<<"."<<endl;
  else
    return P_Coeff[index];
}
void Polynomial::print(void)
{
  bool print_zero = true;
  for(int i = 0;i < N_elements;i++)
  {
    if(P_Coeff[i] != 0)
      print_zero = false;
  }
  if(print_zero)
    cout<<"0"<<endl;
  else if(!print_zero)
  {
    for(int i = N_elements - 1;i >= 0;i--)
    {
      if(i != 0 && P_Coeff[i] != 0)
        cout<<" "<<P_Coeff[i]<<"x^"<<i<<"  +";
      else if(i != 0 && P_Coeff == 0)
        i--;
      if(i == 0 && P_Coeff[i] != 0)
        cout<<" "<<P_Coeff[i]<<"x^"<<i<<endl;
      else if(i == 0 &&P_Coeff[i] == 0)
        break;
    }
  }
}
int main(void)
{
    double Coeff1[4] = {12.5, 3.0, 0.0, 5.0};
    double Coeff2[3] = { 6.5, -5.5, -3.0};
    Polynomial P1 (Coeff1, sizeof(Coeff1) / sizeof(double));
    Polynomial P2 (Coeff2, sizeof(Coeff2) / sizeof(double));
    //Test(P1,P2);
    return 0;
}
/*void Test(Polynomial &p1, Polynomial &p2)
{
    //Constructor
    cout << "[ Constructor ]" << endl;
    Polynomial Default_Sum;
    cout << "Default_Sum = ";
    Default_Sum.print();
    Polynomial Sum(p1);
    cout << "Copy_Sum = ";
    Sum.print();
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
}*/
