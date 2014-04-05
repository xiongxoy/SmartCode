#include <string>
#include <vector>

#include <fstream>
#include <assert.h>
#include <stdio.h>

typedef std::vector<std::string> str_arr;

class BinaryCode {
public:
  str_arr decode( std::string text );
};

void assert_str_array_equal(str_arr a1, str_arr a2) {
  assert( a1.size() == 2 && a2.size() == 2);
  for (int i=0; i<2; i++) {
    printf( "str1: %s\nstr2: %s\n", a1[i].c_str(), a2[i].c_str() );
    assert( a1[i] == a2[i] );
  }
  printf("\n");
}

int main(int argc, const char *argv[])
{
  BinaryCode bc;

  //std::string s1 = "123210122";
  //std_arr a1 = { std::string("011100011"), std::string("NONE") };
  //assert_str_array_equal( bc.decode(s1), a1 );

  //std::string s2 = "11";
  //str_arr a2 = { std::string("01"), std::string("10") };
  //assert_str_array_equal( bc.decode(s2), a2 );

  std::string s3 = "22111";
  str_arr a3;
  a3.push_back( std::string("NONE") );
  a3.push_back( std::string("11001") );
  assert_str_array_equal( bc.decode(s3), a3 );

  std::string s4 = "123210120";
  str_arr a4;
  a4.push_back( std::string("NONE") );
  a4.push_back( std::string("NONE") );
  assert_str_array_equal( bc.decode(s4), a4 );

  std::string s5 = "3";
  str_arr a5;
  a5.push_back( std::string("NONE") );
  a5.push_back( std::string("NONE") );
  assert_str_array_equal( bc.decode(s5), a5 );

  std::string s6 = "12221112222221112221111111112221111";
  str_arr a6;
  a6.push_back( std::string("01101001101101001101001001001101001") );
  a6.push_back( std::string("10110010110110010110010010010110010") );
  assert_str_array_equal( bc.decode(s6), a6 );

  return 0;
}

str_arr BinaryCode::decode( std::string text ) {
  str_arr ans = str_arr(2);
  std::string s0, s1;
  int d1, d2, d3, i;

  /*!-- case extreme: 1 digit --*/
  if ( text.length() == 1) {
    if ( text == "1" ) {
      ans[0] = "NONE"; ans[1] = "1";
      return ans;
    }
    else if ( text == "0" ) {
      ans[0] = "0"; ans[1] = "NONE";
      return ans;
    }
    else {
      ans[0] = "NONE"; ans[1] = "NONE";
      return ans;
    }
  }

  /*!-- case 0 --*/
  s0 = std::string("0");
  if ( text[0] == '0' )
    s0 += ('0');
  else if ( text[0] == '1' )
    s0 += '1';
  else
    s0 = "NONE";

  for ( i=1; i<text.length()-1; i++ ) {
    d1 = s0[i-1] - '0';
    d2 = s0[i] - '0';
    d3 = text[i] - '0';
    if ( d3 - d1 - d2 == 0 )
      s0 += '0';
    else if ( d3 - d1 - d2 == 1 )
      s0 += '1';
    else {
      s0 = "NONE";
      break;
    }
  }

  // check for tail
  if ( s0 != "NONE" and i == text.length()-1 ) {
    d1 = text[i] - '0';
    d2 = s0[i] - '0';
    d3 = s0[i-1] - '0';
    if ( d1 != d2 + d3 ) // last digit not right;
      s0 = "NONE";
  }

  /*!-- case 1 --*/
  //std::string s3 = "22111";
  // ret is "11001"
  s1 = std::string("1");
  if ( text[0] == '1' )
    s1 += '0';
  else if ( text[0] == '2' )
    s1 += '1';
  else
    s1 = "NONE";

  for ( i=1; i<text.length()-1; i++ ) {
    d1 = s1[i-1] - '0';
    d2 = s1[i] - '0';
    d3 = text[i] - '0';
    if ( d3 - d1 - d2 == 0 )
      s1 += '0';
    else if ( d3 - d1 - d2 == 1 )
      s1 += '1';
    else {
      s1 = "NONE";
      break;
    }
  }

   if ( s1 != "NONE" and i == text.length()-1 ) {
    d1 = text[i] - '0';
    d2 = s1[i] - '0';
    d3 = s1[i-1] - '0';
    if ( d1 != d2 + d3 ) // last digit not right;
      s1 = "NONE";
  }
  /*!-- end --*/
  ans[0] = s0; ans[1] = s1;
  return ans;
}

