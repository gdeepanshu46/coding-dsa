topics = {}

topics['input-output'] = 1
topics['operators-and-expressions'] = 2
topics['decision-making'] = 3
topics['iteration-statements'] = 4
topics['arrays'] = 5
topics['back-tracking'] = 6
topics['bit-manipulation'] = 7
topics['divide-and-conquer'] = 8
topics['dynamic-programming'] = 9
topics['game-theory'] = 10
topics['graphs'] = 11
topics['greedy-algo'] = 12
topics['heaps'] = 13
topics['queues'] = 14
topics['recursion'] = 15
topics['searching'] = 16
topics['segment-trees'] = 17
topics['sorting'] = 18
topics['stacks'] = 19
topics['strings'] = 20
topics['trees'] = 22
topics['tries'] = 21
topics['linked-list'] = 23
topics['computational-geometry'] = 24
topics['gcd-lcm'] = 25
topics['modular-arithmetic'] = 26
topics['prime-numbers'] = 27
topics['permutation-and-combination'] = 28

def convert(source):
	topic = source.split('/')[-3]
	code = source.split('/')[-1]
	our = 'https://www.prepbytes.com/panel/mycourses/mentors-coding-program/c++/week/'
	result = our + str(topics[topic]) + '/' + topic +  '/codingAssignment/' + code
	return result


source = string(input())


#source = str(input())
#source = 'https://www.prepbytes.com/panel/mycourses/program-one/dsalgo/week/14/greedy-algo/codingAssignment/KABADDI'
#destination = 'https://www.prepbytes.com/panel/mycourses/mentors-coding-program/c++/week/12/greedy-algo/codingAssignment/KABADDI'
print(convert(source))


