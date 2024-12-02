import sys

def main():
    """
    AOC Day 1 Part 1: reads pairs of integers from standard input and stores 
         them into two separate lists. It then sorts both lists, compares their 
         corresponding elements, and computes the total difference between 
         mismatched elements across the lists.

    The program reads pairs of integers from standard input, where each pair 
    represents a value `val1` and `val2`. It calculates a similarity score by 
    summing the total differences of each `val1` and 'val2' pair, sorted.

    Input Format:
        Each line contains two integers separated by a space:
        val1 val2

    Usage:
        $ day1.py < ../input.txt

    Example Input:
        3   4
        4   3
        2   5
        1   3
        3   9
        3   3

    Example Output:
        similarity score: 11

    Steps:
        1. Reads pairs of integers from standard input.
        2. Stores both columns.
        3. Computes the similarity score by summing the absolute value of the
            differences of each row in sequential order.

    Returns:
        None. Prints the similarity score to standard output.
    """
    row1 = []
    row2 = []
    total = 0

    # read into two lists
    for line in sys.stdin:
        val1, val2 = map(int, line.split())
        row1.append(val1)
        row2.append(val2)

    # sort
    row1.sort()
    row2.sort()

    # find difference in each index
    for i in range(len(row1)):
        if row1[i] != row2[i]:
            total += abs(row1[i] - row2[i])

    print(f"Total: {total}")

if __name__ == "__main__":
    main()