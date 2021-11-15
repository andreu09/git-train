string = input("Enter the ticket number for verification... ")
print()

while len(string) % 2 != 0 or len(string) <= 0:
    print("Hey, that's the wrong number!")

    string = input("Enter the correct number... ")
    print()

half_line = int(len(string) / 2)

part_one = [int(i) for i in string[:half_line]]
part_two = [int(i) for i in string[half_line:]]

print(sum(part_one) == sum(part_two))
