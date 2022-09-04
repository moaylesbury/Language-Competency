# question 1

def divisible_pos_ints_sum(n: int, div: int) -> int:
    # generates the positive integers up to and including a supplied value
    # which are divisible by another supplied positive integer

    if n < 0 or div < 0: raise ValueError("Supplied integers must be positive")

    sum = 0
    curr_val = 0

    # increment sum by n*div until n*div > n
    # n*div will always be divisible by div
    while (curr_val < n):
        curr_val += div
        sum += curr_val
    
    return sum        

if __name__ == '__main__':
    print(divisible_pos_ints_sum(102029, 3))

# question 2 

def list_of_n_lists(n:int) -> list:
    # from i to n generate n lists, with each list containing i numbers

    inner_list = []
    outer_list = []

    for outer_list_n in range(1, n+1):
        inner_list = []
        for inner_list_n in range(1, outer_list_n+1):
            inner_list += [inner_list_n]
        outer_list += [inner_list]

    return outer_list



    
    
    

