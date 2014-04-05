#include <string>
#include <cassert>
#include <stdlib.h>
#include <iostream>

class Time
{
public:
  std::string whatTime( int seconds );

private:
  /* data */
};


std::string Time::whatTime( int seconds ) {
  int h, m, s;
  std::string ret;
  char h_str[10], m_str[10], s_str[10];

  h = seconds / (60 * 60);
  seconds = seconds - h * (60 * 60);
  m = seconds / (60);
  seconds = seconds - m * (60);
  s = seconds;

  sprintf(h_str, "%d", h);
  sprintf(m_str, "%d", m);
  sprintf(s_str, "%d", s);

  ret = "";
  ret = std::string(h_str) + ":" + m_str + ":" + s_str;
  return ret;
}

int main(int argc, const char *argv[])
{
  Time t;
  int i;
  std::string s;

  i = 0;
  s = "0:0:0";
  assert( t.whatTime(i) == s );

  i = 3661;
  s = "1:1:1";
  assert( t.whatTime(i) == s );

  i = 5436;
  s = "1:30:36";
  assert( t.whatTime(i) == s );

  i = 86399;
  s = "23:59:59";
  assert( t.whatTime(i) == s );

  return 0;
}
