class Solution:
    def maxNumOfSubstrings(self, s: str) -> list[str]:
        n  = len(s)

        first = [n] * 26

        last = [-1] * 26

        # First and last occurrence of each character

        for i, c in enumerate(s):

            x = ord(c) - ord('a')

            first[x] = min(first[x], i)

            last[x] = i

        ans = []

        for i in range(n):

            x = ord(s[i]) - ord('a')

            # Only first occurrence can start a minimal valid substring

            if first[x] != i:

                continue

            end = last[x]

            j = i

            valid = True

            # Expand interval if characters inside require it

            while j <= end:

                y = ord(s[j]) - ord('a')

                # This character started before our interval,

                # so interval starting at i cannot be valid

                if first[y] < i:

                    valid = False

                    break

                end = max(end, last[y])

                j += 1

            if not valid:

                continue

            # Greedy:

            # If this interval overlaps the previous selected one,

            # replace previous with this smaller-ending interval.

            if ans and i <= ans[-1][1]:

                ans[-1] = (i, end)

            else:

                ans.append((i, end))

        return [s[l:r + 1] for l, r in ans]