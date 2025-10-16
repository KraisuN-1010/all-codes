from tkinter import *
import pandas as pd
import random as rd
BACKGROUND_COLOR = "#B1DDC6"

# ---------------------------- LOGIC ------------------------------- #
to_learn = []
try:
  words_csv = pd.read_csv("./data/words_to_learn.csv")
except FileNotFoundError:
  original_data = pd.read_csv("./data/french_words.csv")
  to_learn = original_data.to_dict(orient="records")
else:
  to_learn = words_csv.to_dict(orient="records")
  
  
current_card = {}

def is_known():
  to_learn.remove(current_card)
  data_to_learn = pd.DataFrame(to_learn)
  data_to_learn.to_csv("./data/Words_to_learn.csv")
  next_card()
  

def next_card():
  global current_card, flip_timer
  window.after_cancel(flip_timer)
  current_card = rd.choice(to_learn)
  canvas.itemconfig(card_bg, image = front_image)
  canvas.itemconfig(card_title, text="French")
  canvas.itemconfig(card_word, text=current_card["French"])

  flip_timer = window.after(3000, func=flip_card)

def flip_card():
  canvas.itemconfig(card_bg, image = back_image)
  canvas.itemconfig(card_title, text="English")
  canvas.itemconfig(card_word, text=current_card["English"])
# ---------------------------- UI SETUP ------------------------------- #

window = Tk()
window.title("FlashY")
window.config(bg=BACKGROUND_COLOR, padx=50, pady=50)
flip_timer = window.after(3000, func=flip_card)

front_image = PhotoImage(file="./images/card_front.png")
back_image = PhotoImage(file = "./images/card_back.png")
wrong_image = PhotoImage(file = "./images/wrong.png")
right_image = PhotoImage(file = "./images/right.png")

canvas = Canvas(width=800, height=526, highlightthickness=0, bg=BACKGROUND_COLOR)
card_bg = canvas.create_image(400, 263, image=front_image)  
card_title = canvas.create_text(400, 150, text = "", font = ("Ariel", 40, "italic"))
card_word = canvas.create_text(400, 263, text = "", font = ("Ariel", 40, "bold"))
canvas.grid(row=1, column=1, columnspan = 2)

wrong_button = Button(image = wrong_image, highlightthickness=0,command = next_card)
wrong_button.grid(row = 2, column = 1)

right_button = Button(image = right_image, highlightthickness=0,command = is_known)
right_button.grid(row = 2, column = 2)

next_card()

window.mainloop()