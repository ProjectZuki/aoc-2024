import sys

def main():
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