import sys
from collections import defaultdict

def main():
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