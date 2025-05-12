import re

def starts_and_ends_with_a(s: str) -> bool:
    return bool(re.match(r'^(?:[ab]|ab)?$', s))

# Tests
for s in ["a", "aba", "abca", "ab", "baa"]:
    print(f"{s!r}: {starts_and_ends_with_a(s)}")
