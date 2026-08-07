import sys

def solve():
    data = sys.stdin.read().split()
    t = int(data[0])
    idx = 1
    out = []

    for _ in range(t):
        n = int(data[idx])
        idx += 1
        s = data[idx]
        idx += 1

        groups = 1
        for i in range(1, n):
            if s[i] != s[i - 1]:
                groups += 1

        max_redn = 0

        # Check every position ()
        for i in range(1, n - 1):
            if s[i - 1] == s[i + 1]:
                if s[i] != s[i - 1]:
                    redn = 2
                else:
                    redn = 0
            else:
                if s[i] != s[i - 1] and s[i] != s[i + 1]:
                    redn = 1
                else:
                    redn = 0

            max_redn = max(max_redn, redn)

        out.append(str(groups - max_redn))

    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    solve()