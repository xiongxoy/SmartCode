#include <cstdio>

static bool eflag = false;
static bool pflag = false;
bool valid(char c) {
  // 数字有效
  if ( c>='0' && c<='9' )
  {
    return true;
  } else if ( (c == '+') || (c == '-') ) { // +，-只能出现一次
    if (pflag)
      return false;  // 出现过
    else  {
      pflag = true;
      return true;
    }
  } else if ( (c == 'E') || (c == 'e') ) { // e, E只能出现一次
    if (eflag)
      return false;  // 出现过
    else {
      eflag = true;
      return true;
    }
  } else  {
    return false;  // 其它情况
  }
}
int atoi (const char *a, int &val) {
  char b[100] = {0};
  // 整理数据
  int i = 0, c=0;
  for (i = 0, c=0; a[i]; i++) {
    if (valid(a[i])) {
      b[c++] = a[i];
    } else if(' ' == a[i]){
      ;
    } else {
      return -1;
    }
  }
  b[c] = '\0';

  // 解析数据
  int tmp = 0;
  int exp = 0;
  int state = 0;
  bool flag_neg = false;
  bool flag_exp = false;
  bool stop = false;
  for (i = 0; b[i] && !stop; i++) {
    switch(state) {
      case 0:
        if (b[i] == '-') {
          flag_neg = true;
          state = 1;
        } else if (b[i] == '+') {
          state = 1;
        } else {
          state = 2;
          tmp = b[i] - '0';
        }
        break;
      case 1: // expecting number
        if (b[i] >= '0' && b[i] <= '9') {
          tmp = b[i] - '0';
          state = 2;
        } else {
          stop = true;
        }
        break;
      case 2: // accept
        if (b[i] == 'E' || b[i] == 'e') {
          state = 3;
          flag_exp = true;
        } else {
          tmp *= 10;
          tmp += b[i] - '0';
        }
       break;
      case 3: // expecting number
        if (b[i] >= '0' && b[i] <= '9') {
          exp = b[i] - '0';
          state = 4;
        } else {
          stop = true;
        }
        break;
      case 4: // accept
        exp *= 10;
        exp += b[i] - '0';
        break;
      default:
        return -1;
        break;
    }
  }
  if (stop || state == 3 || state == 1 || state == 0) {
    return -1;
  }
  // 转换数据
  val = flag_neg?-tmp:tmp;
  if (flag_exp) {
    for(i=0; i<exp; i++) {
      val *= 10;
    }
  }
  return 0;
}
void test(const char *s) {
  // reset global variable
  eflag = false;
  pflag = false;

  int val;
  atoi(s, val);
  printf("ret: %d\n", val);
}
int main(int argc, const char *argv[])
{
  int val = 0;
  const char * s1 = "-100";
  const char * s2 = "100";
  const char * s3 = "100e1";
  const char * s4 = "1e5";
  const char * s5 = "100e01";
  test(s1);
  test(s2);
  test(s3);
  test(s4);
  test(s5);

  return 0;
}
