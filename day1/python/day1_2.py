
import sys
from collections import defaultdict

def main():
    """
    AOC Day 1 Part 2: Checks the number of occurences which each value of
           the left column appears in the right, and outputs the total similarities.

    The program reads pairs of integers from standard input, where each pair 
    represents a value `val1` and `val2`. It calculates a similarity score by 
    summing the product of each `val1` in the first column and its frequency 
    in the second column.

    The similarity score is defined as:
        similarity_score = sum(val1 * frequency(val2 == val1))

    Input Format:
        Each line contains two integers separated by a space:
        val1 val2

    Usage:
        $ day1_2.py < ../input.txt

    Example Input:
        3   4
        4   3
        2   5
        1   3
        3   9
        3   3

    Example Output:
        similarity score: 31

    Steps:
        1. Reads pairs of integers from standard input.
        2. Stores the first column in a list.
        3. Counts the frequency of integers in the second column using a defaultdict.
        4. Computes the similarity score by checking if elements from the first column 
           exist in the frequency map and summing their product.

    Returns:
        None. Prints the similarity score to standard output.
    """
    similarity_score = 0
    value_map = defaultdict(int)
    row1 = []

    for line in sys.stdin:
        val1, val2 = map(int, line.split())
        row1.append(val1)
        value_map[val2] += 1

    for val in row1:
        if val in value_map:
            similarity_score += val * value_map[val]

    print(f"similarity score: {similarity_score}")

if __name__ == "__main__":
    main()