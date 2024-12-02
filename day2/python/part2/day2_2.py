
import sys

def main():
    """
    AOC 2024 Day 2 Part 2: Reads each level of input and checks if they are safe.
    If not safe, checks if removing a single element makes the level safe. Counts how many levels
    are safe based on the following onditions:

    - Sequence must either be strictly increasing or strictly decreasing.
    - The difference between adjacent values must be between 1 and 3.
    - If the level is unsafe, attempts to remove one element at a time and check if the resulting
      sequence is safe.

    Outputs the count of safe levels.
    """
    safe = 0  # Counter for safe levels

    while True:
        try:
            # Read a line of input, strip leading/trailing whitespace
            line = input().strip()
            if not line:
                break  # break if empty

            # parse the line into a list of integers
            level = list(map(int, line.split()))

            # check if safe, else attempt to remove
            if check_safe(level):
                safe += 1
            elif check_removal(level):
                safe += 1

        except EOFError:
            break  # end loop on EOF

    # output count
    print(f"# safe levels: {safe}")


def check_safe(level):
    """
    Checks if the given level is safe based on the following conditions:
    - Sequence must either be strictly increasing or strictly decreasing.
    - The difference between adjacent values must be between 1 and 3.
    
    Args:
    - level (list of int): List of integers representing the report level.

    Returns:
    - bool: True if the level is safe, False otherwise.
    """
    dec = False  # track if the sequence is decreasing
    inc = False  # track if the sequence is increasing

    for i in range(1, len(level)):
        # Check if incrementing or decrementing, unsafe if neither
        if level[i] > level[i - 1]:
            inc = True
        elif level[i] < level[i - 1]:
            dec = True
        else:
            return False  # Sequence is neither increasing nor decreasing

        # Check if the difference is within the threshold of 1 to 3
        diff = abs(level[i] - level[i - 1])
        if diff > 3 or diff < 1:
            return False

        # Unsafe if both increasing and decreasing trends are found
        if dec and inc:
            return False

    return True


def check_removal(vec):
    """
    Tries removing a single element from the vector and checks if the resulting level is safe.
    
    Args:
    - vec (list of int): List of integers representing the report level.

    Returns:
    - int: 1 if the level is safe after removal of one element, 0 otherwise.
    """
    for idx in range(len(vec)):
        # Create a temporary vector and remove the element at index 'idx'
        temp = vec[:idx] + vec[idx+1:]

        # Check if the level is safe after removal
        if check_safe(temp):
            return 1  # The level is safe after removal

    return 0  # The level is unsafe even after removal


if __name__ == "__main__":
    main()
