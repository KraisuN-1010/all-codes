with open ("LettersSend/Mail Merge Project Start/Input/Names/invited_names.txt", "r") as names_file:
    names = names_file.readlines()

with open ("C:/Coding/Python/Python/UDEMY/LettersSend/Mail Merge Project Start/Input/Letters/starting_letter.txt", "r") as letters_file:
    letter_contents = letters_file.read()

for name in names:
    reaplacing_name = name.strip()
    new_letter = letter_contents.replace("[name]", f"{reaplacing_name}")
    with open (f"C:/Coding/Python/Python/UDEMY/LettersSend/Mail Merge Project Start/Output/ReadyToSend/letter_for_{reaplacing_name}.txt", "w+") as new_file:
        new_file.write(new_letter)