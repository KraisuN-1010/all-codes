import tkinter

# GUI window
window = tkinter.Tk()
window.title("My first GUI program")
window.minsize(width=500, height=300)

# Label
my_label = tkinter.Label(text="I am a label", font=("Arial", 45))
my_label.pack()

# Entry
input_field = tkinter.Entry(width=10)
input_field.pack()

# Button
def button_clicked():
    user_input = input_field.get()  
    my_label.config(text = user_input)

my_button = tkinter.Button(text = "Click me", command = button_clicked)
my_button.pack()

window.mainloop()