#include <string>
#include <cassert>
#include <stdlib.h>
#include <iostream>
#include <vector>

class TeamsSelection {
public:
  std::string simulate( std::vector <int> preference1, std::vector <int> preference2 );
};

typedef struct Player {
  int rank1;
  int rank2;
  int name;
} Player;

/* operator <, lhs is largest, rhs is *iter */
bool cmp1(Player lhs, Player rhs) {
 if ( lhs.rank1 > rhs.rank1 )
   return true;
 return false;
}

bool cmp2(Player lhs, Player rhs) {
 if ( lhs.rank2 > rhs.rank2 )
   return true;
 return false;
}

std::string TeamsSelection::simulate( std::vector <int> preference1, std::vector <int> preference2 ) {
  int N;
  /* Build a list of Player, first is rank in pre1, second is rank in pre2 */
  N = preference1.size();
  std::vector<char> ret(N);
  std::vector<Player> players(N);
  for (int i = 0; i < N; i++) {
    players.at(i).name = i;
  }

  for (int i = 0; i < N; i++) {
    int p1 = preference1.at(i)-1;
    int p2 = preference2.at(i)-1;
    players.at(p1).rank1 = i;
    players.at(p2).rank2 = i;
  }

  /* find max in first, delete, find max in second, delete, add to list */
  std::vector<Player>::iterator it;
  int idx;
  for (int i = 0; i < N; i++) {
    if ( i%2 == 0 ) {
      it = std::max_element( players.begin(), players.end(), cmp1 );
      idx = (*it).name;
      ret.at(idx) = '1';
      players.erase(it);
    }
    else {
      it = std::max_element( players.begin(), players.end(), cmp2 );
      idx = (*it).name;
      ret.at(idx) = '2';
      players.erase(it);
    }
  }

  /* create ret string from list1 and list2 */
  return std::string((char *) &ret[0]);
}

template< typename T, size_t N >
std::vector<T> makeVector( const T (&data)[N] ) {
     return std::vector<T>(data, data+N);
}

void test0()
{
  TeamsSelection t;
  int pre1[] =  {1, 2, 3, 4};
  int pre2[] =  {1, 2, 3, 4};
  std::vector<int> preference1 = makeVector( pre1 );
  std::vector<int> preference2 = makeVector( pre2 );

  std::string s = t.simulate( preference1, preference2 );
  assert( s == "1212" );
}
void test1()
{
  TeamsSelection t;
  int pre1[] =  {3, 2, 1};
  int pre2[] =  {1, 3, 2};
  std::vector<int> preference1 = makeVector( pre1 );
  std::vector<int> preference2 = makeVector( pre2 );

  std::string s = t.simulate( preference1, preference2 );
  assert( s == "211" );
}
void test2()
{
  TeamsSelection t;
  int pre1[] =  {6, 1, 5, 2, 3, 4};
  int pre2[] = {1, 6, 3, 4, 5, 2};
  std::vector<int> preference1 = makeVector( pre1 );
  std::vector<int> preference2 = makeVector( pre2 );

  std::string s = t.simulate( preference1, preference2 );
  assert( s == "212211" );
}
void test3()
{
  TeamsSelection t;
  int pre1[] = {8, 7, 1, 2, 4, 5, 6, 3, 9};
  int pre2[] = {7, 2, 4, 8, 1, 5, 9, 6, 3};
  std::vector<int> preference1 = makeVector( pre1 );
  std::vector<int> preference2 = makeVector( pre2 );

  std::string s = t.simulate( preference1, preference2 );
  assert( s == "121121212" );
}

int main(int argc, const char *argv[])
{
  test0();
  test1();
  test2();
  test3();
  return 0;
}
