const express = require('express');

const app = express();

// Add body parser middleware for form data
app.use(express.urlencoded({ extended: true }));

// Logging middleware
app.use((req, res, next) => {
  console.log(req.url);
  next();
});

app.use((req, res, next) => {
  console.log(req.method);
  next();
});

// Route handlers
app.get("/", (req, res) => {
  console.log("Arrived on home page");
  res.send(`<p>Hello world - Home Page</p>`);
});

app.get("/contact-us", (req, res) => {
  console.log("Arrived on contact-us page");
  const htmlContactForm = `
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Contact Form</title>
        <style>
            body {
                font-family: Arial, sans-serif;
                max-width: 500px;
                margin: 50px auto;
                padding: 20px;
                background-color: #f5f5f5;
            }
            
            .form-container {
                background: white;
                padding: 30px;
                border-radius: 8px;
                box-shadow: 0 2px 10px rgba(0,0,0,0.1);
            }
            
            h2 {
                text-align: center;
                color: #333;
                margin-bottom: 30px;
            }
            
            .form-group {
                margin-bottom: 20px;
            }
            
            label {
                display: block;
                margin-bottom: 5px;
                color: #555;
                font-weight: bold;
            }
            
            input[type="text"],
            input[type="email"] {
                width: 100%;
                padding: 12px;
                border: 2px solid #ddd;
                border-radius: 4px;
                font-size: 16px;
                transition: border-color 0.3s;
                box-sizing: border-box;
            }
            
            input[type="text"]:focus,
            input[type="email"]:focus {
                outline: none;
                border-color: #4CAF50;
            }
            
            .submit-btn {
                width: 100%;
                padding: 12px;
                background-color: #4CAF50;
                color: white;
                border: none;
                border-radius: 4px;
                font-size: 16px;
                cursor: pointer;
                transition: background-color 0.3s;
            }
            
            .submit-btn:hover {
                background-color: #45a049;
            }
            
            .submit-btn:active {
                background-color: #3d8b40;
            }
        </style>
    </head>
    <body>
        <div class="form-container">
            <h2>Contact Form</h2>
            <form action="/contact-us" method="POST">
                <div class="form-group">
                    <label for="name">Name:</label>
                    <input type="text" id="name" name="name" required>
                </div>
                
                <div class="form-group">
                    <label for="email">Email:</label>
                    <input type="email" id="email" name="email" required>
                </div>
                
                <button type="submit" class="submit-btn">Submit</button>
            </form>
        </div>
    </body>
    </html>
  `;
  res.send(htmlContactForm);
  // Remove next() - not needed here
});

app.post("/contact-us", (req, res) => {
  console.log("Form data received:", req.body);
  
  // Access the form data
  const { name, email } = req.body;
  console.log(`Name: ${name}, Email: ${email}`);
  
  // Send a response back to the user
  res.send(`
    <h2>Thank you!</h2>
    <p>Name: ${name}</p>
    <p>Email: ${email}</p>
    <a href="/contact-us">Go back</a>
  `);
});

const PORT = 3000;
app.listen(PORT, () => {
  console.log(`Server running on: http://localhost:${PORT}`);
});