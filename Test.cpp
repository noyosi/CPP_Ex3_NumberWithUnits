/**
 * 
 * AUTHORS: Noy Osi
 * 
 */

#include "doctest.h"
#include "NumberWithUnits.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace ariel;
using namespace std;


ifstream units_file{"file.txt"};

TEST_CASE("(+)(-) operators") {
	NumberWithUnits::read_units(units_file);

  NumberWithUnits a{2, "km"};
  NumberWithUnits b{2000, "m"};
  NumberWithUnits c{1, "sec"};
  NumberWithUnits d{1, "km"};
  NumberWithUnits e{4, "kg"};
  NumberWithUnits f{1, "ton"};
  NumberWithUnits g{100000, "cm"};
  NumberWithUnits h{1000, "g"};
  NumberWithUnits i{120, "min"};
  NumberWithUnits j{2, "hour"};
  NumberWithUnits k{1, "ILS"};
  NumberWithUnits l{2, "USD"};
  NumberWithUnits m{1, "USD"};
  NumberWithUnits n{100, "min"};
  NumberWithUnits o{5, "kg"};
  NumberWithUnits p{3000, "kg"};

  CHECK_EQ(a+b, NumberWithUnits{4, "km"});
  CHECK_EQ(b+a, NumberWithUnits{4000, "m"});
  CHECK_EQ(e+h, NumberWithUnits{5, "kg"});
  CHECK_EQ(e+f, NumberWithUnits{1004, "kg"});
  CHECK_EQ(j+i, NumberWithUnits{4, "hour"});
  CHECK_EQ(k+l, NumberWithUnits{9.99, "ILS"});
  CHECK_EQ(l-m, NumberWithUnits{1, "USD"});
  CHECK_EQ(i-n, NumberWithUnits{20, "min"});
  CHECK_EQ(h+o, NumberWithUnits{6000, "g"});
  CHECK_EQ(g+b, NumberWithUnits{300000, "cm"});
  CHECK_EQ(f+p, NumberWithUnits{4, "ton"});
  CHECK_EQ(c+i, NumberWithUnits{7201, "sec"});
 }

TEST_CASE("(+=)(-=)(*=) operators") {
	NumberWithUnits::read_units(units_file);

  NumberWithUnits a{2, "km"};
  NumberWithUnits b{2000, "m"};
  NumberWithUnits c{1, "km"};
  NumberWithUnits d{2, "kg"};

  CHECK_EQ(a+=c, NumberWithUnits{3, "km"});
  CHECK_EQ(a-=c, NumberWithUnits{1, "km"});
  CHECK_EQ(a+=b, NumberWithUnits{4, "km"});
  CHECK_EQ(b+=a, NumberWithUnits{4000, "m"});
  CHECK_EQ((d*=2.5), NumberWithUnits{12.5, "kg"});
 }

TEST_CASE("(++)(--) operators") {
  NumberWithUnits::read_units(units_file);

  NumberWithUnits a{2, "km"}; //postfix a++ 
  CHECK_EQ(a++, NumberWithUnits{2, "km"}); 
  CHECK_EQ(a, NumberWithUnits{3, "km"});

  NumberWithUnits b{1999, "m"}; //prefix ++b
  CHECK_EQ(++b, NumberWithUnits{2000, "m"});
  CHECK_EQ(b, NumberWithUnits{2000, "m"});

  NumberWithUnits c{2, "sec"}; //postfix c--
  CHECK_EQ(c--, NumberWithUnits{2, "sec"});
  CHECK_EQ(c, NumberWithUnits{1, "sec"});

  NumberWithUnits d{2, "kg"}; //prefix --d
  CHECK_EQ(--d, NumberWithUnits{1, "kg"});
  CHECK_EQ(d, NumberWithUnits{1, "kg"});
}

TEST_CASE("(*) operator") {
  NumberWithUnits::read_units(units_file);

  NumberWithUnits a{2, "kg"};
  CHECK_EQ((a*2.5), NumberWithUnits{5.0, "kg"});
  CHECK_EQ((3.5*a), NumberWithUnits{7.0, "kg"});
}

TEST_CASE("(>)(>=)(<)(<=)(==)(!=) operators") {
  NumberWithUnits::read_units(units_file);

  NumberWithUnits a{2, "km"};
  NumberWithUnits b{2000, "m"};
  NumberWithUnits c{4, "km"};
  NumberWithUnits d{800, "kg"};
  NumberWithUnits e{1, "ton"};
  NumberWithUnits f{1000, "kg"};
    
  //>
  CHECK_GT(NumberWithUnits{1, "km"}, NumberWithUnits{50, "m"});
  CHECK_GT(NumberWithUnits{1, "ton"}, NumberWithUnits{50, "kg"});
  CHECK(c>a);

  //>=
  CHECK_GE(NumberWithUnits{1, "hour"}, NumberWithUnits{25, "min"});
  CHECK(b>=a);

  //<
  CHECK_LT(NumberWithUnits{1, "km"}, NumberWithUnits{2000, "m"});
  CHECK_LT(NumberWithUnits{1, "g"}, NumberWithUnits{2000, "kg"});
  CHECK(d<e);

  //<=
  CHECK_LE(NumberWithUnits{1, "hour"}, NumberWithUnits{120, "min"});
  CHECK(f<=e);

  //==
  CHECK_EQ(NumberWithUnits{1, "min"}, NumberWithUnits{60, "sec"});
  CHECK_EQ(NumberWithUnits{1, "USD"}, NumberWithUnits{3.33, "ILS"});
  CHECK(a==b);

  //!=
  CHECK_NE(NumberWithUnits{1, "m"}, NumberWithUnits{400, "cm"});
  CHECK_NE(NumberWithUnits{1, "kg"}, NumberWithUnits{400, "g"}); 
  CHECK(b!=c);   
}

TEST_CASE("Input & Output") {
  NumberWithUnits a{5, "kg"};
  NumberWithUnits b{50, "kg"};

  istringstream in1{"500 [ kg ]"};
  istringstream in2{"1000 [ kg ]"};
  in1 >> a;
  in2 >> b;
  CHECK_EQ(a, NumberWithUnits{500, "kg"});
  CHECK_EQ(b, NumberWithUnits{1000, "kg"});
  CHECK_EQ(a+b, NumberWithUnits{1500, "kg"});
  
  ostringstream out1;
  ostringstream out2;
  out1 << a;
  out2 << b;
  CHECK_EQ(out1.str(), "500[kg]");
  CHECK_EQ(out2.str(), "1000[kg]");  
}

TEST_CASE("Units don't match") {
	NumberWithUnits::read_units(units_file);

  NumberWithUnits a{2, "km"};
  NumberWithUnits b{1, "sec"};

  CHECK_THROWS(a+b);
  CHECK_THROWS(b+a);
}

TEST_CASE("Other cases") {
  //Upper & Lower
  CHECK_THROWS(NumberWithUnits(1, "KM"));
  CHECK_THROWS(NumberWithUnits(1, "Km"));
  CHECK_THROWS(NumberWithUnits(1, "kM"));
  //Incorrect input
  CHECK_THROWS(NumberWithUnits(1, "other"));
}