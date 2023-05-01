#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("check the constractors && reduce"){

    Fraction a(1,4);
    Fraction b(2,3);
    Fraction c = a * b;
    c.reduce();
    
    CHECK_THROWS_AS(Fraction(1,0),invalid_argument);
    CHECK_NOTHROW(Fraction(0,1));
    CHECK(a.getNumerator()==1);
    CHECK(a.getDenominator()==4);
    CHECK(b.getNumerator()==2);
    CHECK(b.getDenominator()==3);
    
    CHECK(c==Fraction(1,6));
    
}

TEST_CASE("check the operators with 2 fructions"){

    Fraction a(1,4);
    Fraction b(2,3);
    Fraction c(2,8);
    c.reduce();

    CHECK((a+b)==Fraction(11,12));
    CHECK((b+a)==Fraction(11,12));

    CHECK((a-b)==Fraction(-5,12));
    CHECK((b-a)==Fraction(5,12));

    CHECK((a*b)==Fraction(1,6));
    CHECK((b*a)==Fraction(1,6));

    CHECK((a/b)==Fraction(3,8));
    CHECK((b/a)==Fraction(8,3));

    CHECK((a==c)==true);
    CHECK((a==b)==false);

    CHECK((a>b)==false);
    CHECK((b>a)==true);
    CHECK((b<a)==false);
    CHECK((a<b)==true);

    CHECK((a>=b)==false);
    CHECK((b>=a)==true);
    CHECK((b<=a)==false);
    CHECK((a<=b)==true);

    a++;
    b--;
    
    CHECK(a==Fraction(5,4));
    CHECK(b==Fraction(-1,3));

}

TEST_CASE("check the operators with 1 fraction & 1 float"){

    Fraction a(1,4);
    

    CHECK((a+0.25)==Fraction(1,2));
    CHECK((0.5+a)==Fraction(3,4));

    CHECK((a-0.5)==Fraction(-1,4));
    CHECK((0.75-a)==Fraction(1,2));

    CHECK((a*0.25)==Fraction(1,16));
    CHECK((0.5*a)==Fraction(1,8));

    CHECK((a/0.25)==Fraction(1,1));
    CHECK((0.5/a)==Fraction(2,1));

    CHECK((a==0.25)==true);
    CHECK((a==0.5)==false);

    CHECK((a>0.5)==false);
    CHECK((a>0.05)==true);
    CHECK((0.5<a)==false);
    CHECK((0.05<a)==true);

    CHECK((a>=0.5)==false);
    CHECK((a>=0.05)==true);
    CHECK((0.5<=a)==false);
    CHECK((0.05<=a)==true);
}

TEST_CASE("check the operators with fractions & floats"){

    Fraction a(1,4);
    Fraction b(1,2);

    CHECK((a+b+0.25+0.5)==Fraction(3,2));
    CHECK((0.25+0.5+a+b)==Fraction(3,2));

    CHECK((b-a-0.25-0.5)==Fraction(-1,2));
    CHECK((0.25-0.5-a-b)==Fraction(-1,1));

    CHECK((a*b*0.5*0.25)==Fraction(1,64));
    CHECK((0.5*0.25*a*b)==Fraction(1,64));

    CHECK((a/b/0.5/0.25)==Fraction(4,1));
    CHECK((0.5/0.25/a/b)==Fraction(16,1));

    CHECK_EQ((a+0.25),b);
    CHECK_EQ((b-0.25),a);
    CHECK_NE((b+0.25),a);
    CHECK_NE((a-0.25),b);
    CHECK_EQ((a*0.25),Fraction(1,16));
    CHECK_EQ((b/0.25),Fraction(2,1));
    CHECK_NE((a*0.25),Fraction(1,8));
    CHECK_NE((b/0.25),Fraction(1,16));


    CHECK((a+b>0.5)==true);
    CHECK((a-b>0.5)==false);
    CHECK((0.5<a+b)==true);
    CHECK((0.5<a-b)==false);

    CHECK((b-a>=0.5)==false);
    CHECK((a+b>=0.5)==true);
    CHECK((0.5<=a+b)==true);
    CHECK((0.5<=b-a)==false);

    
}
