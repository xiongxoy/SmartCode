#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>

typedef std::vector<std::string> VS;
typedef std::string S;
typedef std::vector<std::string> str_arr;

class Lottery;
class Rule;
class RuleProcessor;
namespace Combinatorics {
  long long comb( int n, int r );
}

template< typename T, size_t N >
std::vector<T> makeVector( const T (&data)[N] ) {
  if ( "" == data[0] ) {
    return std::vector<T>();
  }
  else {
    return std::vector<T>(data, data+N);
  }
}

void assert_str_array_equal(str_arr a1, str_arr a2) {
  assert( a1.size() == a2.size() );
  for (int i=0; i<a1.size(); i++) {
    printf( "str1: %s\nstr2: %s\n", a1[i].c_str(), a2[i].c_str() );
    assert( a1[i] == a2[i] );
  }
  printf("\n");
}

class Lottery {
public:
  VS sortByOdds( VS rule_texts );
};

class Rule {
public:
  /* members are properly set */
  Rule( S head, int c, int b, bool sorted, bool unique );
  bool operator< ( const Rule &rho ) const;
  S toString() const;
  long long getCombinations() const;
  std::string getHead() const;
private:
  S head;
  int c;
  int b;
  bool sorted;
  bool unique;
  long long combinations;

  long long calculateCombinations();
};

class RuleProcessor {
public:
  void operator() ( S rule_text );
  void sortRules();
  std::vector<Rule> getRules();
private:
  Rule decodeRule( S rule_text );
  std::vector<Rule> rules;
};

template< typename T, size_t N, typename U, size_t M >
void test( const T (&input)[N], const U (&expected)[M] ) {
  std::vector<T> in_v, expected_v;
  Lottery lty;

  in_v = makeVector( input );
  expected_v = makeVector( expected );

  assert_str_array_equal( expected_v, lty.sortByOdds( in_v ) );
}

void test0() {
  std::string input[] = {
    "PICK ANY TWO: 10 2 F F",
    "PICK TWO IN ORDER: 10 2 T F",
    "PICK TWO DIFFERENT: 10 2 F T",
    "PICK TWO LIMITED: 10 2 T T"
  };
  std::string expected[] = {
    "PICK TWO LIMITED",
    "PICK TWO IN ORDER",
    "PICK TWO DIFFERENT",
    "PICK ANY TWO"
  };
  test( input, expected );
}

void test1() {
  std::string input[] = {
    "INDIGO: 93 8 T F",
    "ORANGE: 29 8 F T",
    "VIOLET: 76 6 F F",
    "BLUE: 100 8 T T",
    "RED: 99 8 T T",
    "GREEN: 78 6 F T",
    "YELLOW: 75 6 F F"
  };
  std::string expected[] = {
    "RED", "ORANGE", "YELLOW", "GREEN", "BLUE", "INDIGO", "VIOLET"
  };
  test( input, expected );
}

void test2() {
  std::string input[] = {
    ""
  };
  std::string expected[] = {
   ""
  };
  test( input, expected );
}

void test3() {
  assert( Combinatorics::comb(10, 1) == 10 );
  assert( Combinatorics::comb(10, 0) == 1 );
  assert( Combinatorics::comb(5, 2) == 10 );
  assert( Combinatorics::comb(5, 5) == 1 );
  assert( Combinatorics::comb(10, 1) == 10 );
}

void test4() {

}

void (*pf[128])(void)  = {test3, test0, test1, test2, 0};

void runAllTests()
{
  for (int i = 0; pf[i] != NULL; i++) {
    std::cout << "Test case " <<i+1 <<":"<< std::endl;
    pf[i]();
    std::cout << std::endl;
  }
}

int main(int argc, const char *argv[]) {
  runAllTests();
}

template< typename T >
std::string toString( T obj ) {
  return obj.toString();
}

int CombinationsIter(int iN, int iR) {
    if (iR < 0 || iR > iN) {
        return 0;
    }
    int iComb = 1;
    int i = 0;
    while (i < iR) {
        ++i;
        iComb *= iN - i + 1;
        iComb /= i;
    }
    return iComb;
}

namespace Combinatorics {
#define M 1000
#define N 1000
  long long comb( int n, int r ) {
    static long long C[M][N] = {0};
    int i, j;

    if ( C[n][r] > 0 ) {
      return C[n][r];
    }

    for ( i = 0; i <= n; i++ ) {
      for ( j = 0; j <= std::min(i, r); j++ ) {
        if ( C[i][j] > 0 )
          continue;

        if ( 0==j || j==i ) {
          C[i][j] = 1;
        }
        else {
          C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
      }
    }

    return C[n][r];
  }
};

/*--! Implementation of Lottery */
VS Lottery::sortByOdds( VS rule_texts ) {
  RuleProcessor rule_processor;
  VS ret( rule_texts.size() );
  std::vector<Rule> rules;

  rule_processor = std::for_each( rule_texts.begin(), rule_texts.end(), rule_processor );
  rule_processor.sortRules();
  rules = rule_processor.getRules();
  std::transform( rules.begin(), rules.end(), ret.begin(), toString<Rule> );
  return ret;
}

/*--! Implementation of Rule */
Rule::Rule( S head, int c, int b, bool sorted, bool unique ) {
  this->head = head;
  this->c = c;
  this->b = b;
  this->sorted = sorted;
  this->unique = unique;
  this->combinations = calculateCombinations();
}

long long Rule::calculateCombinations() {
  long long ret;
  if ( !sorted && !unique ) {
    ret = 1;
    for (int i = 0; i < b; i++) {
      ret *= c;
    }
  }
  else if ( !sorted && unique ) {
    ret = 1;
    for (int i = 0; i < b; i++) {
      ret *= c-i;
    }
  }
  else if ( sorted && !unique ) {
    // i don't know
    // see [stars and bars]http://en.wikipedia.org/wiki/Stars_and_bars_%28combinatorics%29
    // see http://math.stackexchange.com/questions/213755/\
    // how-many-ways-to-place-n-balls-in-k-bins-with-the-minimum-number-of-balls-in
    ret = Combinatorics::comb( c+b-1, b );
  }
  else if ( sorted && unique ) {
    // combinations
    ret = Combinatorics::comb( c, b );
  }
  return ret;
}

long long Rule::getCombinations() const {
  return combinations;
}

std::string Rule::getHead() const {
  return head;
}

bool Rule::operator< ( const Rule &rho ) const  {
  if ( this->combinations != rho.getCombinations() ) {
    //larger combinations lead to smaller probabilities
    return this->combinations < rho.getCombinations();
  }
  else {
    return this->head < rho.getHead();
  }
}

S Rule::toString() const {
  return head;
}

/*--! Implementation of RuleProcessor */
void RuleProcessor::operator() ( S rule_text ) {
  rules.push_back( decodeRule( rule_text ) );
}
void RuleProcessor::sortRules() {
  std::sort( rules.begin(), rules.end() );
}
std::vector<Rule> RuleProcessor::getRules() {
  return rules;
}
Rule RuleProcessor::decodeRule( S rule_text ) {
  std::string head;
  int c,b;
  unsigned pos;
  char sorted, unique;

  pos = rule_text.find( ':' );
  head = rule_text.substr( 0, pos );
  std::sscanf( rule_text.substr(pos).c_str(), ": %d %d %c %c",
      &c, &b, &sorted, &unique );

  return Rule( std::string( head ), c, b, sorted == 'T', unique == 'T' );
}
