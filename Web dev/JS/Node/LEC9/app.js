//External packages
const express = require('express');

//Local modules
const { handleUserRequest } = require('./user');

//Main logic
const app = express();

// Global logging middleware
app.use((req, res, next) => {
  console.log("Request:", req.url, req.method);
  next();
});

// Submit details route
app.use("/submit-details", (req, res) => {
  console.log("Processing submit-details");
  res.send(`<p>This is the first paragraph</p>`);
  // No next() call since this is the final handler
});

// Home route
app.get("/", (req, res) => {
  res.send(`<p>Welcome to the home page!</p>`);
});

const PORT = 3000;
app.listen(PORT, () => {
  console.log(`Server running on http://localhost:${PORT}`);
});