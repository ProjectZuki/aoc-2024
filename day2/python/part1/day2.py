
import sys

def main():
    """
    AOC 2024 Day 2 Part 1: Reads a series of integer lists from standard input,
    checks if each list meets the safety conditions, and counts how many lists are safe
    or unsafe based on the following conditions:
    
    - The list is safe if it is either strictly increasing or strictly decreasing.
    - Any two adjacent levels in the list must differ by at least 1 and at most 3.
    
    Outputs the count of safe and unsafe levels.
    """
    safe = 0

    while True:
        # parse until no more input from stdin
        try:
            # Parse single line of input
            line = input().strip()

            # Parse the line into a list of integers
            level = list(map(int, line.split()))

            is_safe = True  # tracks if current level is safe
            dec = False     # tracks if level is decreasing
            inc = False     # tracks if level is increasing

            # check conditions
            for i in range(1, len(level)):
                if level[i] > level[i - 1]:
                    inc = True
                elif level[i] < level[i - 1]:
                    dec = True
                else:
                    is_safe = False
                    break

                diff = abs(level[i] - level[i - 1])
                if diff > 3 or diff < 1:
                    is_safe = False
                    break

                if dec and inc:
                    is_safe = False
                    break

            if is_safe:
                safe += 1

        except EOFError:
            break

    # output safe levels
    print(f"# safe levels: {safe}")

if __name__ == "__main__":
    main()
