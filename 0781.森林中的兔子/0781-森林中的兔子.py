class Solution(object):
    def numRabbits(self, answers):
        count = collections.Counter(answers)
        return sum((count[x] + x) / (x + 1) * (x + 1) for x in count)