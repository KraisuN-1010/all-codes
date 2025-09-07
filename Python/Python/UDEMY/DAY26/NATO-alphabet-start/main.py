import pandas

nato_phonetic_data = pandas.read_csv("DAY 26/NATO-alphabet-start/nato_phonetic_alphabet.csv")
nato_dict = {row.letter : row.code for (index, row) in nato_phonetic_data.iterrows()}

word = input("enter a word: ")
nato_phonetic_discription = [nato_dict[letter.upper()] for letter in word]

print(nato_phonetic_discription)


