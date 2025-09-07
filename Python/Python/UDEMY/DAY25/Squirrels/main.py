import pandas 

squirrel_data = pandas.read_csv("DAY25/2018_Central_Park_Squirrel_Census_-_Squirrel_Data.csv")

red_count = len(squirrel_data[squirrel_data["Primary Fur Color"] == "Cinnamon"])
gray_count = len(squirrel_data[squirrel_data["Primary Fur Color"] == "Gray"])
black_count = len(squirrel_data[squirrel_data["Primary Fur Color"] == "Black"])

new_squirrel_data_dict = {
    "Color" : ["Red" , "Gray", "Black"],
    "Count" : [red_count, gray_count, black_count]
}

# Create DataFrame from dictionary
new_df = pandas.DataFrame(new_squirrel_data_dict)

# Save it to CSV
new_df.to_csv("C:/Coding/Python/Python/UDEMY/DAY25/Squirrel_data.csv")