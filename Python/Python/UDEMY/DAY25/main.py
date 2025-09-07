import turtle
import pandas as pd
import os

# Set up the screen
screen = turtle.Screen()
screen.title("U.S. States Game")

# Use relative path or check if file exists
image_path = "blank_states_img.gif"
csv_path = "50_states.csv"

# Check if files exist
if not os.path.exists(image_path):
    print(f"Error: Image file '{image_path}' not found!")
    print("Please ensure the blank_states_img.gif file is in the same directory as this script.")
    exit()

if not os.path.exists(csv_path):
    print(f"Error: CSV file '{csv_path}' not found!")
    print("Please ensure the 50_states.csv file is in the same directory as this script.")
    exit()

# Add the image and set up turtle
screen.addshape(image_path)
turtle.shape(image_path)

# Read the CSV data
try:
    data = pd.read_csv(csv_path)
    all_states = data.state.to_list()
    print(f"Loaded {len(all_states)} states from CSV")
except Exception as e:
    print(f"Error reading CSV file: {e}")
    exit()

guessed_states = []

# Main game loop
while len(guessed_states) < 50:
    answer_state = screen.textinput(title=f"{len(guessed_states)}/50 States Correct",
                                    prompt="What's another state's name?")
    
    # Handle case where user cancels or closes dialog
    if answer_state is None:
        break
    
    # Convert to title case for consistent comparison
    answer_state = answer_state.title()
    
    # Check for exit condition
    if answer_state.lower() == "exit":
        missing_states = [state for state in all_states if state not in guessed_states]
        new_data = pd.DataFrame(missing_states, columns=['States to Learn'])
        new_data.to_csv("states_to_learn.csv", index=False)
        print(f"Created states_to_learn.csv with {len(missing_states)} states you missed.")
        break
    
    # Check if the state is correct and not already guessed
    if answer_state in all_states and answer_state not in guessed_states:
        guessed_states.append(answer_state)
        
        # Create turtle to write state name
        state_turtle = turtle.Turtle()
        state_turtle.hideturtle()
        state_turtle.penup()
        state_turtle.speed(0)
        
        # Get coordinates for the state
        state_data = data[data.state == answer_state]
        x_coord = int(state_data.x.iloc[0])
        y_coord = int(state_data.y.iloc[0])
        
        # Go to position and write state name
        state_turtle.goto(x_coord, y_coord)
        state_turtle.write(answer_state, align="center", font=("Arial", 8, "normal"))
        
    elif answer_state in guessed_states:
        print(f"You already guessed {answer_state}!")

# Congratulations message if all states guessed
if len(guessed_states) == 50:
    congratulations = turtle.Turtle()
    congratulations.hideturtle()
    congratulations.penup()
    congratulations.goto(0, 0)
    congratulations.write("Congratulations! You got all 50 states!", 
                         align="center", font=("Arial", 16, "bold"))

# Keep window open
screen.exitonclick()