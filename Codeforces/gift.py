def main():
  """docstring for main"""
  n = int(raw_input().strip())
  li = raw_input().split()
  i = 0
  j = 0
  for s in li:
    if s == '100':
      i = i + 1
    elif s == '200':
      j = j + 1

  if i%2 == 1:
    print 'NO'
    return
  if j%2 == 0:
    print 'YES'
    return
  else:
    if i==0:
      print 'NO'
      return
    else:
      print 'YES'
      return

if __name__ == '__main__':
  main()
