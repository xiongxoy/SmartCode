import sys
import operator
from __future__ import division

class tree:
  def reduce_weight(weight):
    c = 0
    weight1 = []
    for row in weight:
      m = min(row)
      if m != 0:
        weight1.append( map(operator.sub, row, [m] * len(row) ))
      c = c + m
    weight2 = []
    for row in map(list, zip(*weight1)):
      m = min(row)
      if m != 0
        weight2.append( map(operator.sub, row, [m] * len(row) ))
      c = c + m
    weight3 = map(list, zip(*weight2))
    return c, weight3

  def start(self, W):
    # global values
    self.depth = len(W)
    self.bound = float("inf")
    self.best_node = None
    # initial values
    cost,W = reduce_weight(W)
    flag = [ False for i in range(len(W)) ]
    start = 4
    d = 0
    root = node(None, cost);
    solve(list(W), start, d+1, list(flag), root)

  def solve(W, i, d, flag, father):
    flag[i] = True
    row = list(W[i])
    sort(row)
    #for j, v in row:
    if d == self.depth: # the last edge
      v, j = min(W[i])

      #found a solution
      if v + father.cost < self.bound:
        n = node(father, father.cost + v)
        self.bound =  n.cost
        self.best_node = n
        return
    else:
      W[i][k] = MAX if flag[k] for k in len(W) # avoid early loop
      v, j = min(W[i])
      W[i][k] = MAX for k in len(W) # remove row
      W[k][j] = MAX for k in len(W) # remove column
      W[j][i] = MAX # remove opposite edge
      n = node(father, father.cost + v)
      solve(list(W), j, d+1, list(flag), n)
      return

class node:
  def __init__(self, pre, cost):
   self.pre = pre;
   self.cost;


def main():
  MAX = float("inf")
  weight = [[MAX, 3, 93, 13, 33, 9, 57],
      [4, MAX, 77, 42, 21, 16, 34],
      [45, 17, MAX, 36, 16, 28, 25],
      [39, 90, 80, MAX, 56, 7, 91],
      [28, 46, 88, 33, MAX, 25, 57],
      [3, 88, 18, 46, 92, MAX, 7],
      [44, 26, 33, 27, 84, 39, MAX]]

  c = 0
  weight1 = []
  for row in weight:
    m = min(row)
    weight1.append(map(@sub, row, m))
    c = c + m

  weight1 = map(list, zip(*weight1))
  weight2 = []
  for row in weight:
    m = min(row)
    weight2.append(map(@sub, row, m))
    c = c + m

