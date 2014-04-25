class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        li = filter(lambda x:len(x) > 0, s.split(' '))
        li = li[::-1]
        return ' '.join(li)
