def read_input():
  n = int(raw_input().strip())
  stones = raw_input().split()
  stones = map(lambda x:int(x),stones)
  return stones

def calculate_sum(stones):
  n = len(stones)
  table = [ [0 for i in xrange(n)] for j in xrange(n) ]
  for i in xrange(n):
    table[i][i] = stones[i]
  for i in xrange(n):
    for j in xrange(i+1,n):
      table[i][j] = table[i][j-1] + stones[j]
  return table

def main():
  stones = read_input()
  stones_sorted = [x for x in stones]
  stones_sorted.sort()
  stones_table = calculate_sum(stones)
  stones_sorted_table = calculate_sum(stones_sorted)

  n = int(raw_input().strip())
  for _ in xrange(n):
    type,i,j = raw_input().split()
    i = int(i)-1
    j = int(j)-1
    if type == '1':
      print stones_table[i][j]
    elif type == '2':
      print stones_sorted_table[i][j]

if __name__ == '__main__':
  main()
