from tkinter import *

BACKGROUND_COLOR = "#B1DDC6"

# ---------------------------- UI SETUP ------------------------------- #

window = Tk()
window.title("FlashY")
window.config(bg=BACKGROUND_COLOR, padx=50, pady=50)

front_image = PhotoImage(file="DAY31/images/card_front.png")
wrong_image = PhotoImage(file = "DAY31/images/wrong.png")
right_image = PhotoImage(file = "DAY31/images/right.png")

canvas = Canvas(width=800, height=526, highlightthickness=0, bg=BACKGROUND_COLOR)
canvas.create_image(400, 263, image=front_image)  
canvas.create_text(400, 150, text = "Title", font = ("Ariel", 40, "italic"))
canvas.create_text(400, 263, text = "Word", font = ("Ariel", 40, "bold"))
canvas.grid(row=1, column=1, columnspan = 2)

wrong_button = Button(image = wrong_image, highlightthickness=0)
wrong_button.grid(row = 2, column = 1)

right_button = Button(image = right_image, highlightthickness=0)
right_button.grid(row = 2, column = 2)



window.mainloop()