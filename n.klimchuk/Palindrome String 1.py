string = input("Enter a string to check for palindrome... ")
print()

length = len(string)
reverse = ''

for i in range(length - 1, -1, -1):
    reverse += string[i]

print(reverse == string)
