#include <iostream>

//Bringing cout and endl to current namespace
using std::cout;
using std::endl;

// change the type of the complex number as per need. 
typedef float type;

//Adding a template class to support all types of numerical complex numbers
template<class T>
class Complex
{
    T m_real;
    T m_imag;
    
    public:
    Complex(){}
    /**
     * @brief Construct a new Complex object
     * 
     * @param real 
     * @param imag 
     */
    Complex(T real,T imag)
    {
        m_real=real;
        m_imag=imag;
    }
    /**
     * @brief Operator overloading to add two complex number object.
     * 
     * @param C - Complex Class object 
     * @return Complex object
     * 
     * Takes in an object of the class Complex as reference.
     * Create a new class object to store the Sum of real and imaginary number values.
     * Return the class object
     */
    Complex operator+(const Complex& C)
    {
        Complex result;
        result.m_real=this->m_real+C.m_real;
        result.m_imag=this->m_imag+C.m_imag;
        
        return result;
    }
    //Prints the value of real and imaginary values
    void print()
    {
     cout<<m_real<<" + i"<<m_imag<<endl;   
    }
};
int main()
{
    //Instantiating objects with real and imaginary values.
    Complex<type> c(10.7,6);
    Complex<type> c1(17,8);
    //Operator '+' takes in c1 object as parameter while the current object being 'c' and returns the Complex class object after 
    //calculating the sum of the both the Complex objects. 
    Complex<type> c3=c+c1;
    c3.print();
    return 0;
}