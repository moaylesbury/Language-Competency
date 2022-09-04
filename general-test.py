from math import floor

# question 1

def isEven(num):
    return num % 2 == 0

def nEvenFibonacciSum(n: int) -> int:

    if n < 0: raise ValueError("n must be greater or equal to zero")
    if n == 1 or n == 2: return 1

    fibonacci = [1, 1]

    sum = 0

    for i in range(2, n):

        nextElement = fibonacci[i-1] + fibonacci[i-2]
        fibonacci += [nextElement]

        if next % 2 == 0:
            sum += nextElement

    return sum 

# question 2

def updateListPointers(intersection: list, list1: list, list2: list, left1: int, left2: int, right1: int, right2: int) -> list:


    # leftpointers are incremented in order to find equal numbers (sorted numbers are ASCENDING)
    # right pointers are decremented in order to find equal numbers (sorted numbers are DESCENDING)

    valueComparisons = [list1[left1] < list2[left2], \
                        list1[left1] > list2[left2], \
                        list1[left1] == list2[left2] and list1[left1] not in intersection, \
                        list1[right1] == list2[right2] and list1[right1] not in intersection \
                        ]

    if valueComparisons[0]:
        left1 += 1
        right2 -= 1

    if valueComparisons[1]:
        left2 += 1
        right1 -= 1

    if valueComparisons[2]:
        intersection += [list1[left1]] 
        left1 += 1
        left2 += 1

    if valueComparisons[3]:
        intersection += [list1[right1]] 
        right1 -= 1
        right2 -= 1

    return intersection, left1, left2, right1, right2


def listIntersection(list1: list, list2: list) -> list:

    # edge cases
    if list1 == list2: return list1
    if not list1 or not list2: return []

    intersection = []

    # left pointers (head pointers)
    left1 = 0
    left2 = 0

    # right pointers (tail pointers)
    right1 = len(list1)-1
    right2 = len(list2)-1

    # iterate until a set of pointers meet
    while left1 != right1 and left2 != right2:
        intersection, left1, left2, right1, right2 = \
            updateListPointers(intersection, list1, list2, left1, left2, right1, right2)
        

    # check if final element is an intersection        
    if list1[right1] == list2[right2] and list1[right1] not in intersection:
                intersection += [list1[right1]]

    return intersection


# Question 3
def isEven(num):
    return num % 2 == 0

def oddDigitInNumber(num):
    numOfDigits = len(str(num))

    # first item only uses modulo operator, not divison
    list = [isEven(num % (10 ** (numOfDigits - 2)))]

    for i in range(1, numOfDigits): 
        # indexing shifted right by 1 as 10 ** 0 = 1 gives trivial division
        list += [isEven(floor(num / (10 ** i)) % 10)]
    
    return all(list)

    
# Question 4
def repeatedDigitAddition(digit, repititions):
    # returns X+XX+XXX+XXXX if repititions = 4
    if repititions == 1:
        return digit
    return int(str(digit)*repititions) + repeatedDigitAddition(digit, repititions-1)


    

